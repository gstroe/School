using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AsciiToHex
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btToAscii_Click(object sender, EventArgs e)
        {
            // Store data and clear hex
            string data = tbHex.Text;
            tbAscii.Text = "";
            
            int in1 = 0, in2 = 0;
            do
            {
                in1 = data.IndexOf("0x");
                in2 = data.IndexOf(",");
                if (in2 == -1)
                    break;
                if (in1 == -1 || in1 > in2)
                {
                    if (data.Substring(0, data.IndexOf(",")).Contains("0"))
                        tbAscii.AppendText("");

                }
                else
                {
                    string temp = data.Substring(in1 + 2, in2 - in1 - 2);
                    int value = Convert.ToInt32(temp, 16);
                    byte[] array = { Convert.ToByte(value) };
                    string append = System.Text.Encoding.ASCII.GetString(array);
                    tbAscii.AppendText(append);
                }
                data = data.Substring(in2 + 1);
            } while (in1 < data.Length && in1 != -1);
        } 

        private void btToHex_Click(object sender, EventArgs e)
        {
            // Store data and clear hex
            string data = tbAscii.Text;
            tbHex.Text = "";

            int counter = 0;
            foreach (char chr in data)
            {
                string temp = Convert.ToByte(chr).ToString("x");
                tbHex.AppendText("0x"+temp+", ");
                counter++;
                if (counter >= 16)
                {
                    tbHex.AppendText("\r\n");
                    counter = 0;
                }
            }
        }
    }
}
