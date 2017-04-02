using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Management;
using System.Management.Instrumentation;
using System.Collections.Specialized;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SystemMonitor
{
    public partial class SystemMonitor : Form
    {
        // Globals
        Icon Write;
        Icon Idle;
        NotifyIcon notifyIcon;
        Thread hardDriveWorker;


        public SystemMonitor()
        {
            InitializeComponent();

            // start in sytem try
            WindowState = FormWindowState.Minimized;
            ShowInTaskbar = false;

            // load icons images
            Write = new Icon("write.ico");
            Idle = new Icon("idle.ico");

            // notify icon fro the system tray
            notifyIcon = new NotifyIcon();
            notifyIcon.Icon = Idle;
            notifyIcon.Visible = true;

            // Create menu for bringing up UI and exiting
            ContextMenu menu = new ContextMenu();
            MenuItem openItem = new MenuItem("Show System Diagnostics");
            MenuItem exitItem = new MenuItem("Exit");
            menu.MenuItems.Add(openItem);
            menu.MenuItems.Add(exitItem);

            // set context menu to the notification icon for when it is clicked on
            notifyIcon.ContextMenu = menu;

            // quit button to close application
            exitItem.Click += exitItem_Click;
            // open menu button to close application
            openItem.Click += openItem_Click;

            // Start worker thread to monitor the hard drive activity
            hardDriveWorker = new Thread(new ThreadStart(hardDriveThread));
            hardDriveWorker.IsBackground = true; // if program crashes or closes from menu this will close it from the 
            hardDriveWorker.Start();
        }


        // exits the application from the context menu
        void exitItem_Click(object sender, EventArgs e)
        {
            hardDriveWorker.Abort(); // kill thread
            notifyIcon.Dispose(); // dispose icon otherwise it will stay until the use hovers over it.
            this.Close();
        }

        // show the sytem diag menu
        void openItem_Click(object sender, EventArgs e)
        {
            WindowState = FormWindowState.Normal;
        }


        // Scans the harddrive to see if it is writing. Will show user by changing the icon
        void hardDriveThread()
        {
            ManagementClass hardDriveData = new ManagementClass("Win32_PerfFormattedData_PerfDisk_PhysicalDisk");

            
            try // try block for when the program closes mid process
            {
                // Loop for constantly pulling the hard drive data
                while (true)
                {
                    // pull the drivbe data
                    ManagementObjectCollection driveDataClassCollection = hardDriveData.GetInstances();
                    foreach (ManagementObject obj in driveDataClassCollection)
                    {
                        // Only pull _Total instance and ignore all other instances
                        if (obj["Name"].ToString() == "_Total")
                        {
                            if (Convert.ToUInt64(obj["DiskWriteBytesPersec"]) > 0) // if the total bytes written is greater then show write otherwise show idle.
                            {
                                // Show write icon
                                notifyIcon.Icon = Write;
                            }
                            else
                            {
                                // Show idle icon
                                notifyIcon.Icon = Idle;
                            }
                        }
                    }

                    // Sleep for 100 miliseconds to not consume resources
                    Thread.Sleep(100);
                }
            }
            catch (ThreadAbortException e)
            {
                // Dispose the management class            
                hardDriveData.Dispose();
                
            }
        }
    



        private void Form1_Load(object sender, EventArgs e)
        {

        }

       
    }
}

