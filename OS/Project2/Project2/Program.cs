using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Project2
{
    
    // enums for status types
    class Program
    {
        static void Main(string[] args)
        {
            // create the scheduler class
            Scheduler scheduler = new Scheduler();
            string input = "";
            while(input != "exit")
            {
                string func = ""; // the requested function
                Console.Write("> ");
                input = Console.ReadLine(); // read input
                if (input.Contains(" "))
                    func = input.Substring(0, input.IndexOf(" "));
                else
                    func = input;
                switch(func)
                {
                    // parses the input and sees if correct, if not prints it out that is incorrect. if it is then runs the create function
                    case "cr":
                        input = input.Substring(input.IndexOf(" ") + 1);
                        string name;
                        int prior;
                        if (input.Contains(" "))
                        {
                            name = input.Substring(0, input.IndexOf(" "));
                        }
                        else
                        {
                            Console.WriteLine("* Not a valid request");
                            break;
                        }
                        input = input.Substring(input.IndexOf(" ") + 1);
                        if (!int.TryParse(input, out prior))
                        {
                            Console.WriteLine("* Not a valid request");
                            break;
                        }
                        scheduler.Create(name, prior);
                        break;


                    // creates the resources
                    case "crr":
                        input = input.Substring(input.IndexOf(" ") + 1);                     
                        scheduler.CreateResource(input);
                        break;

                    // deletes the process
                    case "del":
                        input = input.Substring(input.IndexOf(" ") + 1);
                        scheduler.Destroy(input);
                        break;
                    
                        // deletes the resources
                    case "delr":
                        input = input.Substring(input.IndexOf(" ") + 1);
                        scheduler.DestroyResource(input);
                        break;

                    // request the resource
                    case "req":
                        input = input.Substring(input.IndexOf(" ") + 1);
                        scheduler.Request(input);
                        break;

                    // releases the resource
                    case "rel":
                        input = input.Substring(input.IndexOf(" ") + 1);
                        scheduler.Release(input);
                        break;

                    // list all the processes and resources
                    case "list":
                        scheduler.List();
                        break;

                    // exit the program
                    case "exit":
                        break;

                    // Bad data entered
                    default:
                        Console.WriteLine("* Not a valid request");
                        break;
                }

            }

        }
    }

    class Scheduler
    {
        public PCB current;
        public List<PCB> Processes = new List<PCB>();
        public List<RCB> Resources = new List<RCB>();

        /// <summary>Destro
        /// constrctor
        /// </summary>
        public Scheduler()
        {
            Create("Init", 0);
        }

        /// <summary>
        /// List all the processes by there name, status and priority.
        /// </summary>
        public void List()
        {
            foreach (PCB process in Processes)
            {
                if (process.status.type != "blocked")
                    Console.WriteLine("* Process " + process.ID + " is " + process.status.type + " with priority " + process.getPriority() + ".");
                else
                {
                    Console.Write("* Process " + process.ID + " is " + process.status.type + " by resources: ");
                    foreach (RCB resource in process.status.blockingList)
                    {
                        Console.Write(resource.ID + " ");
                    }
                    Console.WriteLine("with priority " + process.getPriority() + ".");
                }
            }
            foreach (RCB resource in Resources)
            {
                if (resource.status == "free") 
                    Console.WriteLine("* Resource " + resource.ID + " is " + resource.status + ".");
                else
                    Console.WriteLine("* Resource " + resource.ID + " is " + resource.status + " to process " + resource.currentAllocation.ID + ".");
            }
        }

        /// <summary>
        /// creates the new process
        /// </summary>
        /// <param name="input"></param>
        public void Create(string id, int prior)
        {
            // check and make sure the process id is unique
            for (int i = 0; i < Processes.Count; i++)
            {
                if (Processes[i].ID == id)
                {
                    Console.WriteLine("* Process already exist with that ID!");
                    return;
                }
            }

            // create the process
            PCB temp = new PCB(id, prior);
            Processes.Add(temp);

            Console.WriteLine("* Process " + temp.ID + " has been created.");
            Start();
        }

        /// <summary>
        /// Starts running a process base on when it was created and its priority, will also call start.
        /// </summary>
        public void Start()
        {
            // check all waiting list and see if the process can be given requested resources
            foreach(RCB resource in Resources)
            {
                if (resource.status == "free" && resource.waitingList.Count > 0)
                {
                    resource.waitingList[0].getRCB(resource); // this gives the first proces in the waiting list the resource
                }
            }

            // get the highest priority
            int highest = 0;
            for (int i = 0; i < Processes.Count; i++)
            {
                if (Processes[i].getPriority() > Processes[highest].getPriority() && Processes[i].status.type != "blocked")
                    highest = i;
            }

            // see if its the same process that was current running
            if (Processes[highest] != current)
            {
                // set the current process to ready
                if (current != null)
                {
                    if (current.status.type != "blocked")
                        current.status.type = "ready";
                }
                current = Processes[highest];
               
            }

            // make sure the init is not blocked
            if (current != null)
            {
                if (current.status.type != "blocked")
                    current.status.type = "running";
                else // if it is call all process blocked and request a new one created
                {
                    Console.WriteLine("* All processes are blocked, please create a new one and release some resources!");
                    return;
                }
            }
            else
            {
                current.status.type = "running";
            }
            // write out current process
            Console.WriteLine("* Process " + current.ID + " is running.");
        }

        public void CreateResource(string id)
        {
            // check for duplicates
            for (int i = 0; i < Resources.Count; i++)
            {
                if (Resources[i].ID == id)
                {
                    Console.WriteLine("* Resource already exist with that ID!");
                    return;
                }
            }

            // create the resources
            RCB temp = new RCB(id);
            Resources.Add(temp);

            Console.WriteLine("* Resource " + temp.ID + " has been created.");
            Start();
        }


        /// <summary>
        /// destroys the process and unlinks any resources
        /// </summary>
        /// <param name="id"></param>
        public void Destroy(string id)
        {
            for (int i = 0; i < Processes.Count; i++)
            {
                if (Processes[i].ID == id)
                {

                    // unallocated resources and remove from wating list
                    PCB temp = Processes[i];
                    foreach(RCB resource in temp.resources)
                    {
                        resource.unAllocate();
                        resource.waitingList.Remove(temp);
                    }                    

                    Console.WriteLine("* Deleted Process " + temp.ID + ".");
                    Processes.Remove((Processes[i]));
                    temp = null;
                    Start();
                    return;
                }

            }
            Console.WriteLine("* Process not found with that ID!");
        }

        /// <summary>
        /// destroys the resource and unlinks any process
        /// </summary>
        /// <param name="id"></param>
        public void DestroyResource(string id)
        {
            for (int i = 0; i < Resources.Count; i++)
            {
                if (Resources[i].ID == id)
                {
                    // unallocated process and remove from wating list
                    RCB temp = Resources[i];
                    foreach (PCB process in temp.waitingList)
                    {
                        process.status.blockingList.Remove(temp);
                        process.status.type = "ready";
                    }
                    temp.currentAllocation.resources.Remove(temp);

                    Console.WriteLine("* Deleted  " + temp.ID + ".");
                    Resources.Remove((Resources[i]));
                    temp = null;
                    Start();
                    return;
                }

            }
            Console.WriteLine("* Resource not found with that ID!");
        }

        public void Request(string id)
        {
            for (int i = 0; i < Resources.Count; i++)
            {
                if (Resources[i].ID == id)
                {
                    if (!current.getRCB(Resources[i]))
                    {
                        Console.Write("* Process " + current.ID + " is now blocked waiting for resources: ");
                        for (int j = 0; j < current.status.blockingList.Count; j++)
                        {
                            Console.Write(current.status.blockingList[j].ID + " ");
                        }
                        Console.WriteLine();
                        Start();
                        return;
                    }
                    Console.Write("* Process " + current.ID + " is now has the following resources: ");
                    for (int j = 0; j < current.resources.Count; j++)
                    {
                        Console.Write(current.resources[j].ID + " ");
                    }
                    Console.WriteLine();
                    Start();
                    return;
                }
                
            }
            Console.WriteLine("* Resource not found with that ID!");
            
        }


        public void Release(string id)
        {
            for (int i = 0; i < Resources.Count; i++)
            {
                if (Resources[i].ID == id)
                {
                    if (Resources[i].status == "allocated")
                    {
                        Console.WriteLine("* Resource " + Resources[i].ID + " has been released from Process " + Resources[i].currentAllocation.ID + ".");
                        Resources[i].unAllocate();
                    }
                    else
                    {
                        Console.WriteLine("* Resource is not currently allocated!");
                    }
                    Start();
                    return;
                }

            }
            Console.WriteLine("* Resource not found with that ID!");
        }
    }

    class PCB
    {
        public string ID; // the ID of the process as defined by the user
        public List<RCB> resources = new List<RCB>(); // a list of all the resouces on this process
        public Status status; // the current status
        private int priority; // the priority of the system

        /// <summary>
        /// The base fucntion for creating this process
        /// </summary>
        /// <param name="id"></param>
        /// <param name="prior"></param>
        public PCB(string id, int prior)
        {

            ID = id;
            priority = prior;
            status.type = "ready";
            status.blockingList = new List<RCB>();

        }

        public int getPriority()
        {
            return priority;
        }

        /// <summary>
        /// trys to grab an resource, if failed it goes on the blocking list and the process is block
        /// </summary>
        /// <param name="resource"></param>
        /// <returns></returns>
        public bool getRCB (RCB resource)
        {
            if (resource.Allocate(this))
            {
                if (!resources.Contains(resource)) // adds the resource to the list
                    resources.Add(resource);
                if (status.blockingList.Contains(resource)) // removes it from the blocking list if it was there
                    status.blockingList.Remove(resource);
                if (status.blockingList.Count == 0) // if the are no more this blocking this reset the status
                    status.type = "ready";
                return true;
            }
            else
            {
                status.type = "blocked";
                if (!status.blockingList.Contains(resource))
                    status.blockingList.Add(resource);
                return false;
            }
        }


        // status and class
        public struct Status
        {
            public string type;
            public List<RCB> blockingList;
        }

    }

    class RCB
    {
        public string ID; // the id of the resource
        public string status; // the status of the RCB
        public PCB currentAllocation = null;
        public List<PCB> waitingList = new List<PCB>(); // list of process wating on this resource

        /// <summary>
        /// The base fucntion for creating this resource
        /// </summary>
        /// <param name="id"></param>
        public RCB(string id)
        {
            ID = id;
            status = "free";
        }


        /// <summary>
        /// attemps to let process allocate to the resource, returns false if allocation fails 
        /// </summary>
        /// <param name="process"></param>
        /// <returns></returns>
        public bool Allocate(PCB process)
        {
            if (process == currentAllocation)
                return true;

            if (status == "free")
            {
                currentAllocation = process;
                status = "allocated";
                if (waitingList.Contains(process))
                    waitingList.Remove(process);
                return true;
            }
            else
            {
                if (!waitingList.Contains(process))
                    waitingList.Add(process);
                return false;
            }

            
        }

        /// <summary>
        /// unallocate the resource
        /// </summary>
        /// <returns></returns>
        public void unAllocate()
        {
            currentAllocation = null;
            status = "free"; ;
        }
    }


}
