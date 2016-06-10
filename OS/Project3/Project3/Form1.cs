using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project3
{
    public partial class Form1 : Form
    {
        private Thread workerThread;
        private volatile Seats waitingSeats;
        bool isSleeping = false;
        private volatile bool doorInUse = false;
        private volatile bool newCustomer = false;
        private volatile Customer currentCustomer = null;
        private volatile int customerCounter = 0;
        private volatile int cutTime = 5;

        public Form1()
        {
            InitializeComponent();

            // initiate objects
            waitingSeats = new Seats(7);

            // create backgroud worker thread
            workerThread = new Thread(workerFunction);
            workerThread.IsBackground = true;
            Application.DoEvents(); // needs to happen before the worker thread starts
            workerThread.Start();
        }


        /// <summary>
        /// The worker thread that loops and constantly checks for costumers. Also hands the basic moving and status of clients
        /// </summary>
        void workerFunction()
        {
            while (CloseBackgroundWorker != true)
            {
                if (isSleeping == false && waitingSeats.Line.Count == 0) // sleep if nobody waiting
                {
                    isSleeping = true;
                    pbBarberSeat.Image = Properties.Resources.Barber;
                    pbSleep.Image = Properties.Resources.Sleep;
                    pbBarberSpot.Image = null;
                    Application.DoEvents();
                    updateChat("* The barber starts to fall asleep as he waits for a customer... *");
                }

                if (isSleeping == true && (waitingSeats.Line.Count != 0 || newCustomer)) // wake customer if either is true
                {
                    isSleeping = false;
                    pbBarberSeat.Image = null;
                    pbSleep.Image = null;
                    pbBarberSpot.Image = Properties.Resources.Barber;
                    Application.DoEvents();
                    updateChat("* The barber wakes up! *");
                }

                if (waitingSeats.Line.Count > 0)
                {
                    int seatNum;
                    currentCustomer = waitingSeats.getNext(out seatNum);
                    switch (seatNum) // seat seat to empty as customer steps up
                    {
                        case 1:
                            pbSeat1.Image = null;
                            break;
                        case 2:
                            pbSeat2.Image = null;
                            break;
                        case 3:
                            pbSeat3.Image = null;
                            break;
                        case 4:
                            pbSeat4.Image = null;
                            break;
                        case 5:
                            pbSeat5.Image = null;
                            break;
                        case 6:
                            pbSeat6.Image = null;
                            break;
                        case 7:
                            pbSeat7.Image = null;
                            break;
                    }
                    updateChat("Barber: \"Next!\"");
                    Thread.Sleep(100);
                    updateChat("* The customer in the seat that is " + seatNum + " space away from the door gets up. *");
                    Thread.Sleep(100);
                    updateChat("* The customer sits in the barber's chair. *");
                    Thread.Sleep(100);
                    updateChat("* The barber begins to cut the hair *");
                    pbBarberSeat.Image = Properties.Resources.noShavedHead;
                    Application.DoEvents();

                    // do work
                    cutHair();

                }

                if (newCustomer) // if new customer flag is true grab the new customer;
                {
                    currentCustomer = new Customer(customerCounter++);


                    // update visual
                    pbEnterShop.Image = null;
                    updateChat("Barber: \"Step right up!\"");
                    Thread.Sleep(100);
                    updateChat("* The customer sits in the barber's chair. *");
                    Thread.Sleep(100);
                    updateChat("* The barber begins to cut the hair *");
                    pbBarberSeat.Image = Properties.Resources.noShavedHead;
                    Application.DoEvents();
                    newCustomer = false;
                    doorInUse = false;

                    // do work
                    cutHair();
                }




                Thread.Sleep(100);
            }

        }

        void cutHair()
        {
            // do work
            for (int i = 0; i < cutTime; i++)
            {
                increamentBar(false);
                Application.DoEvents();
                Thread.Sleep(1000);
            }

            // update hair and leave
            pbBarberSeat.Image = Properties.Resources.shavedHead;
            Application.DoEvents();
            updateChat("Customer: \"Thanks for the hair cut! It looks great!\" ");
            Thread.Sleep(1000);
            while (doorInUse) { { Thread.Sleep(100); } } // wait till customer in door way moves
            doorInUse = true;
            increamentBar(true); // set the status bar to 0
            pbBarberSeat.Image = null;
            pbEnterShop.Image = Properties.Resources.shavedHead;
            updateChat("Barber: \"Of course! Come back soon!\" ");
            Application.DoEvents();
            Thread.Sleep(1000);
            updateChat("* The customer leaves the shop. *");
            pbEnterShop.Image = null;
            pbLeaveShop.Image = Properties.Resources.shavedHead;
            Application.DoEvents();
            Thread.Sleep(1000);
            pbLeaveShop.Image = null;
            Application.DoEvents();
            currentCustomer = null; // no longer a current customer

            doorInUse = false;
        }

        delegate void UpdateChatCallback(string text);

        /// <summary>
        /// Uses a delegate to update the chatbox
        /// </summary>
        /// <param name="text"></param>
        private void updateChat(string text)
        {
            if (this.tbInfoBox.InvokeRequired)
            {
                UpdateChatCallback d = new UpdateChatCallback(updateChat);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.tbInfoBox.AppendText(text);
                this.tbInfoBox.AppendText("\r\n");
                this.tbInfoBox.SelectionStart = this.tbInfoBox.Text.Length;
                this.tbInfoBox.ScrollToCaret();
                Application.DoEvents();
            }
        }

        delegate void increamentBarCallback(bool reset);

        /// <summary>
        /// uses a delegate to increment the status bar
        /// </summary>
        private void increamentBar(bool reset)
        {
            if (this.pbarCutting.InvokeRequired)
            {
                increamentBarCallback d = new increamentBarCallback(increamentBar);
                this.Invoke(d, new object[] { reset });
            }
            else
            {
                if (reset)
                    this.pbarCutting.Value = 0;
                else
                    this.pbarCutting.Increment(1);
            }
        }

        /// <summary>
        /// Adds a new customer in the que, handles where they goe first
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btNewCustomer_Click(object sender, EventArgs e)
        {
            if (doorInUse)
            {
                updateChat("~~~ The door is crowded, please try again when door is clear ~~~ ");
                return;
            }

            btNewCustomer.Enabled = false; // disable to prevent from being spammed
            doorInUse = true;

            // update text
            updateChat("* A new customer has entered the shop. *");

            pbLeaveShop.Image = Properties.Resources.noShavedHead;
            Application.DoEvents();
            Thread.Sleep(500);
            pbLeaveShop.Image = null;
            pbEnterShop.Image = Properties.Resources.noShavedHead;
            Application.DoEvents();

            if (currentCustomer != null) // if there is a current customer see if one can grame a chair
            {
                Customer tempCust = new Customer(customerCounter++);
                int temp = waitingSeats.addCustomer(tempCust);
                if (temp != 0)
                {
                    updateChat("* The customer sees the barber working and waits in the chair " + temp + " spaces away from the door. *");
                    pbEnterShop.Image = null;
                    switch (temp) // add the image to the seat
                    {
                        case 1:
                            pbSeat1.Image = Properties.Resources.noShavedHead;
                            break;
                        case 2:
                            pbSeat2.Image = Properties.Resources.noShavedHead;
                            break;
                        case 3:
                            pbSeat3.Image = Properties.Resources.noShavedHead;
                            break;
                        case 4:
                            pbSeat4.Image = Properties.Resources.noShavedHead;
                            break;
                        case 5:
                            pbSeat5.Image = Properties.Resources.noShavedHead;
                            break;
                        case 6:
                            pbSeat6.Image = Properties.Resources.noShavedHead;
                            break;
                        case 7:
                            pbSeat7.Image = Properties.Resources.noShavedHead;
                            break;
                    }
                    Application.DoEvents();
                }
                else // if they cant the customer leaves
                {
                    updateChat("* The customer sees the barber working and that all the seats are full. They grunt angerly and leave. *");
                    tempCust = null; // set the new customer to null als they leave.
                    pbEnterShop.Image = null;
                    pbLeaveShop.Image = Properties.Resources.noShavedHead;
                    Application.DoEvents();
                    Thread.Sleep(500);
                    pbLeaveShop.Image = Properties.Resources.noShavedHead;
                    Application.DoEvents();
                    Thread.Sleep(500);
                    pbLeaveShop.Image = null;
                    Application.DoEvents();
                }

            }
            else
            {
                newCustomer = true; // let the barber know if a new customer is waiting.
                btNewCustomer.Enabled = true;
                return;
            }

            doorInUse = false;
            btNewCustomer.Enabled = true; // renable the button
        }



        /// <summary>
        /// updates the cuttime
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void nudCutTime_ValueChange(object sender, EventArgs e)
        {
            cutTime = (int)nudCutTime.Value;
            pbarCutting.Maximum = cutTime;
        }


        /// <summary>
        /// closes the worker thread when the program exits
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            // Signal the BackgroundWorkerThread to end
            CloseBackgroundWorker = true;
            if (workerThread.IsAlive)
                workerThread.Abort();

        }


        public class Customer
        {
            public bool hairCut = false;
            private int custNum;

            public Customer(int number)
            {
                custNum = number;
            }

        }

        public class Seats
        {
            public Customer[] Chairs;
            public List<Customer> Line = new List<Customer>();

            public Seats(int numberOfChairs)
            {
                Chairs = new Customer[numberOfChairs];
            }


            /// <summary>
            /// adds the customer to the list of chairs and the line; iWill returnt he chair the customer sat in starting at 1. Otherwise it returns 0 if the customer leaves.
            /// </summary>
            /// <param name="cust"></param>
            /// <returns></returns>
            public int addCustomer(Customer cust)
            {
                for (int i = 0; i < Chairs.Length; i++)
                {
                    if (Chairs[i] == null)
                    {
                        Chairs[i] = cust;
                        Line.Add(cust);
                        return i + 1;
                    }
                }
                return 0;
            }

            /// <summary>
            /// removes the next customer from list and returns it. returns null if list is empty and 0 for the number
            /// </summary>
            /// <returns></returns>
            public Customer getNext(out int number)
            {
                if (Line.Count != 0)
                {
                    Customer temp = Line.First();
                    Line.Remove(temp);
                    number = 0;
                    for (int i = 0; i < Chairs.Length; i++)
                    {
                        if (temp == Chairs[i])
                        {
                            number = i + 1;
                            Chairs[i] = null;
                        }
                    }

                    return temp;
                }
                else
                {
                    number = 0;
                    return null;
                }
            }
        }
    }
}
