namespace Project3
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.tbInfoBox = new System.Windows.Forms.RichTextBox();
            this.plBarberShop = new System.Windows.Forms.Panel();
            this.nudCutTime = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.btNewCustomer = new System.Windows.Forms.Button();
            this.pbSleep = new System.Windows.Forms.PictureBox();
            this.pbBarberSpot = new System.Windows.Forms.PictureBox();
            this.pbBarberSeat = new System.Windows.Forms.PictureBox();
            this.pbSeat7 = new System.Windows.Forms.PictureBox();
            this.pbSeat6 = new System.Windows.Forms.PictureBox();
            this.pbSeat5 = new System.Windows.Forms.PictureBox();
            this.pbSeat4 = new System.Windows.Forms.PictureBox();
            this.pbSeat3 = new System.Windows.Forms.PictureBox();
            this.pbSeat2 = new System.Windows.Forms.PictureBox();
            this.pbSeat1 = new System.Windows.Forms.PictureBox();
            this.pbLeaveShop = new System.Windows.Forms.PictureBox();
            this.pbarCutting = new System.Windows.Forms.ProgressBar();
            this.pbEnterShop = new System.Windows.Forms.PictureBox();
            this.plBarberShop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudCutTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSleep)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbBarberSpot)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbBarberSeat)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat7)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat6)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat5)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbLeaveShop)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbEnterShop)).BeginInit();
            this.SuspendLayout();
            // 
            // tbInfoBox
            // 
            this.tbInfoBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tbInfoBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tbInfoBox.Location = new System.Drawing.Point(12, 12);
            this.tbInfoBox.Name = "tbInfoBox";
            this.tbInfoBox.ReadOnly = true;
            this.tbInfoBox.Size = new System.Drawing.Size(520, 131);
            this.tbInfoBox.TabIndex = 1;
            this.tbInfoBox.Text = "";
            // 
            // plBarberShop
            // 
            this.plBarberShop.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.plBarberShop.BackgroundImage = global::Project3.Properties.Resources.BarberShop;
            this.plBarberShop.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.plBarberShop.Controls.Add(this.nudCutTime);
            this.plBarberShop.Controls.Add(this.label1);
            this.plBarberShop.Controls.Add(this.btNewCustomer);
            this.plBarberShop.Controls.Add(this.pbSleep);
            this.plBarberShop.Controls.Add(this.pbBarberSpot);
            this.plBarberShop.Controls.Add(this.pbBarberSeat);
            this.plBarberShop.Controls.Add(this.pbSeat7);
            this.plBarberShop.Controls.Add(this.pbSeat6);
            this.plBarberShop.Controls.Add(this.pbSeat5);
            this.plBarberShop.Controls.Add(this.pbSeat4);
            this.plBarberShop.Controls.Add(this.pbSeat3);
            this.plBarberShop.Controls.Add(this.pbSeat2);
            this.plBarberShop.Controls.Add(this.pbSeat1);
            this.plBarberShop.Controls.Add(this.pbLeaveShop);
            this.plBarberShop.Controls.Add(this.pbarCutting);
            this.plBarberShop.Controls.Add(this.pbEnterShop);
            this.plBarberShop.Location = new System.Drawing.Point(12, 150);
            this.plBarberShop.MaximumSize = new System.Drawing.Size(518, 342);
            this.plBarberShop.MinimumSize = new System.Drawing.Size(518, 342);
            this.plBarberShop.Name = "plBarberShop";
            this.plBarberShop.Size = new System.Drawing.Size(518, 342);
            this.plBarberShop.TabIndex = 0;
            // 
            // nudCutTime
            // 
            this.nudCutTime.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.nudCutTime.Font = new System.Drawing.Font("Microsoft Sans Serif", 28F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.nudCutTime.Location = new System.Drawing.Point(422, 70);
            this.nudCutTime.Maximum = new decimal(new int[] {
            300,
            0,
            0,
            0});
            this.nudCutTime.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.nudCutTime.Name = "nudCutTime";
            this.nudCutTime.Size = new System.Drawing.Size(74, 50);
            this.nudCutTime.TabIndex = 15;
            this.nudCutTime.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            this.nudCutTime.ValueChanged += new System.EventHandler(this.nudCutTime_ValueChange);
            // 
            // label1
            // 
            this.label1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(235, 70);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(181, 48);
            this.label1.TabIndex = 14;
            this.label1.Text = "Number of seconds \r\nit takes to cut hair:";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btNewCustomer
            // 
            this.btNewCustomer.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btNewCustomer.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btNewCustomer.Location = new System.Drawing.Point(233, 13);
            this.btNewCustomer.Name = "btNewCustomer";
            this.btNewCustomer.Size = new System.Drawing.Size(263, 42);
            this.btNewCustomer.TabIndex = 13;
            this.btNewCustomer.Text = "Generate New Customer";
            this.btNewCustomer.UseVisualStyleBackColor = true;
            this.btNewCustomer.Click += new System.EventHandler(this.btNewCustomer_Click);
            // 
            // pbSleep
            // 
            this.pbSleep.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbSleep.BackColor = System.Drawing.Color.Transparent;
            this.pbSleep.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbSleep.Location = new System.Drawing.Point(14, 34);
            this.pbSleep.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbSleep.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbSleep.Name = "pbSleep";
            this.pbSleep.Size = new System.Drawing.Size(30, 30);
            this.pbSleep.TabIndex = 12;
            this.pbSleep.TabStop = false;
            // 
            // pbBarberSpot
            // 
            this.pbBarberSpot.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbBarberSpot.BackColor = System.Drawing.Color.Transparent;
            this.pbBarberSpot.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbBarberSpot.Location = new System.Drawing.Point(101, 50);
            this.pbBarberSpot.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbBarberSpot.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbBarberSpot.Name = "pbBarberSpot";
            this.pbBarberSpot.Size = new System.Drawing.Size(30, 30);
            this.pbBarberSpot.TabIndex = 11;
            this.pbBarberSpot.TabStop = false;
            // 
            // pbBarberSeat
            // 
            this.pbBarberSeat.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbBarberSeat.BackColor = System.Drawing.Color.Transparent;
            this.pbBarberSeat.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbBarberSeat.Location = new System.Drawing.Point(52, 50);
            this.pbBarberSeat.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbBarberSeat.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbBarberSeat.Name = "pbBarberSeat";
            this.pbBarberSeat.Size = new System.Drawing.Size(30, 30);
            this.pbBarberSeat.TabIndex = 10;
            this.pbBarberSeat.TabStop = false;
            // 
            // pbSeat7
            // 
            this.pbSeat7.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbSeat7.BackColor = System.Drawing.Color.Transparent;
            this.pbSeat7.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbSeat7.Location = new System.Drawing.Point(15, 264);
            this.pbSeat7.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbSeat7.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbSeat7.Name = "pbSeat7";
            this.pbSeat7.Size = new System.Drawing.Size(30, 30);
            this.pbSeat7.TabIndex = 9;
            this.pbSeat7.TabStop = false;
            // 
            // pbSeat6
            // 
            this.pbSeat6.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbSeat6.BackColor = System.Drawing.Color.Transparent;
            this.pbSeat6.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbSeat6.Location = new System.Drawing.Point(71, 264);
            this.pbSeat6.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbSeat6.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbSeat6.Name = "pbSeat6";
            this.pbSeat6.Size = new System.Drawing.Size(30, 30);
            this.pbSeat6.TabIndex = 8;
            this.pbSeat6.TabStop = false;
            // 
            // pbSeat5
            // 
            this.pbSeat5.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbSeat5.BackColor = System.Drawing.Color.Transparent;
            this.pbSeat5.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbSeat5.Location = new System.Drawing.Point(128, 264);
            this.pbSeat5.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbSeat5.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbSeat5.Name = "pbSeat5";
            this.pbSeat5.Size = new System.Drawing.Size(30, 30);
            this.pbSeat5.TabIndex = 7;
            this.pbSeat5.TabStop = false;
            // 
            // pbSeat4
            // 
            this.pbSeat4.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbSeat4.BackColor = System.Drawing.Color.Transparent;
            this.pbSeat4.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbSeat4.Location = new System.Drawing.Point(184, 264);
            this.pbSeat4.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbSeat4.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbSeat4.Name = "pbSeat4";
            this.pbSeat4.Size = new System.Drawing.Size(30, 30);
            this.pbSeat4.TabIndex = 6;
            this.pbSeat4.TabStop = false;
            // 
            // pbSeat3
            // 
            this.pbSeat3.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbSeat3.BackColor = System.Drawing.Color.Transparent;
            this.pbSeat3.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbSeat3.Location = new System.Drawing.Point(239, 264);
            this.pbSeat3.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbSeat3.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbSeat3.Name = "pbSeat3";
            this.pbSeat3.Size = new System.Drawing.Size(30, 30);
            this.pbSeat3.TabIndex = 5;
            this.pbSeat3.TabStop = false;
            // 
            // pbSeat2
            // 
            this.pbSeat2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbSeat2.BackColor = System.Drawing.Color.Transparent;
            this.pbSeat2.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbSeat2.Location = new System.Drawing.Point(295, 264);
            this.pbSeat2.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbSeat2.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbSeat2.Name = "pbSeat2";
            this.pbSeat2.Size = new System.Drawing.Size(30, 30);
            this.pbSeat2.TabIndex = 4;
            this.pbSeat2.TabStop = false;
            // 
            // pbSeat1
            // 
            this.pbSeat1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbSeat1.BackColor = System.Drawing.Color.Transparent;
            this.pbSeat1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbSeat1.Location = new System.Drawing.Point(350, 264);
            this.pbSeat1.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbSeat1.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbSeat1.Name = "pbSeat1";
            this.pbSeat1.Size = new System.Drawing.Size(30, 30);
            this.pbSeat1.TabIndex = 3;
            this.pbSeat1.TabStop = false;
            // 
            // pbLeaveShop
            // 
            this.pbLeaveShop.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbLeaveShop.BackColor = System.Drawing.Color.Transparent;
            this.pbLeaveShop.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbLeaveShop.Location = new System.Drawing.Point(427, 305);
            this.pbLeaveShop.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbLeaveShop.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbLeaveShop.Name = "pbLeaveShop";
            this.pbLeaveShop.Size = new System.Drawing.Size(30, 30);
            this.pbLeaveShop.TabIndex = 2;
            this.pbLeaveShop.TabStop = false;
            // 
            // pbarCutting
            // 
            this.pbarCutting.BackColor = System.Drawing.Color.White;
            this.pbarCutting.Location = new System.Drawing.Point(41, 13);
            this.pbarCutting.Maximum = 5;
            this.pbarCutting.Name = "pbarCutting";
            this.pbarCutting.Size = new System.Drawing.Size(52, 14);
            this.pbarCutting.Step = 1;
            this.pbarCutting.TabIndex = 1;
            // 
            // pbEnterShop
            // 
            this.pbEnterShop.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.pbEnterShop.BackColor = System.Drawing.Color.Transparent;
            this.pbEnterShop.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.pbEnterShop.Location = new System.Drawing.Point(427, 264);
            this.pbEnterShop.MaximumSize = new System.Drawing.Size(30, 30);
            this.pbEnterShop.MinimumSize = new System.Drawing.Size(30, 30);
            this.pbEnterShop.Name = "pbEnterShop";
            this.pbEnterShop.Size = new System.Drawing.Size(30, 30);
            this.pbEnterShop.TabIndex = 0;
            this.pbEnterShop.TabStop = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(544, 506);
            this.Controls.Add(this.tbInfoBox);
            this.Controls.Add(this.plBarberShop);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MinimumSize = new System.Drawing.Size(560, 545);
            this.Name = "Form1";
            this.Text = "Barber Simulator 2K16";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.plBarberShop.ResumeLayout(false);
            this.plBarberShop.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudCutTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSleep)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbBarberSpot)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbBarberSeat)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat7)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat6)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat5)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSeat1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbLeaveShop)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbEnterShop)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel plBarberShop;
        private System.Windows.Forms.RichTextBox tbInfoBox;
        private volatile System.Windows.Forms.PictureBox pbEnterShop;
        private System.Windows.Forms.ProgressBar pbarCutting;
        private volatile System.Windows.Forms.PictureBox pbBarberSeat;
        private volatile System.Windows.Forms.PictureBox pbSeat7;
        private volatile System.Windows.Forms.PictureBox pbSeat6;
        private volatile System.Windows.Forms.PictureBox pbSeat5;
        private volatile System.Windows.Forms.PictureBox pbSeat4;
        private volatile System.Windows.Forms.PictureBox pbSeat3;
        private volatile System.Windows.Forms.PictureBox pbSeat2;
        private volatile System.Windows.Forms.PictureBox pbSeat1;
        private volatile System.Windows.Forms.PictureBox pbLeaveShop;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btNewCustomer;
        private volatile System.Windows.Forms.PictureBox pbSleep;
        private volatile System.Windows.Forms.PictureBox pbBarberSpot;
        private System.Windows.Forms.NumericUpDown nudCutTime;
        private bool CloseBackgroundWorker = false;
    }
}

