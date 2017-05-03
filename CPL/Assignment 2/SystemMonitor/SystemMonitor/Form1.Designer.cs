namespace SystemMonitor
{
    partial class SystemMonitor
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
            this.clockLabel = new System.Windows.Forms.Label();
            this.voltLabel = new System.Windows.Forms.Label();
            this.loadButton = new System.Windows.Forms.Button();
            this.voltBox = new System.Windows.Forms.TextBox();
            this.clockBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // clockLabel
            // 
            this.clockLabel.AutoSize = true;
            this.clockLabel.Location = new System.Drawing.Point(12, 21);
            this.clockLabel.Name = "clockLabel";
            this.clockLabel.Size = new System.Drawing.Size(62, 13);
            this.clockLabel.TabIndex = 0;
            this.clockLabel.Text = "CPU Clock:";
            // 
            // voltLabel
            // 
            this.voltLabel.AutoSize = true;
            this.voltLabel.Location = new System.Drawing.Point(9, 74);
            this.voltLabel.Name = "voltLabel";
            this.voltLabel.Size = new System.Drawing.Size(71, 13);
            this.voltLabel.TabIndex = 2;
            this.voltLabel.Text = "CPU Voltage:";
            // 
            // loadButton
            // 
            this.loadButton.Location = new System.Drawing.Point(12, 121);
            this.loadButton.Name = "loadButton";
            this.loadButton.Size = new System.Drawing.Size(86, 23);
            this.loadButton.TabIndex = 3;
            this.loadButton.Text = "Load Current";
            this.loadButton.UseVisualStyleBackColor = true;
            this.loadButton.Click += new System.EventHandler(this.loadButton_Click);
            // 
            // voltBox
            // 
            this.voltBox.Location = new System.Drawing.Point(90, 74);
            this.voltBox.Name = "voltBox";
            this.voltBox.ReadOnly = true;
            this.voltBox.Size = new System.Drawing.Size(100, 20);
            this.voltBox.TabIndex = 4;
            // 
            // clockBox
            // 
            this.clockBox.Location = new System.Drawing.Point(90, 21);
            this.clockBox.Name = "clockBox";
            this.clockBox.ReadOnly = true;
            this.clockBox.Size = new System.Drawing.Size(100, 20);
            this.clockBox.TabIndex = 6;
            // 
            // SystemMonitor
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(236, 161);
            this.Controls.Add(this.clockBox);
            this.Controls.Add(this.voltBox);
            this.Controls.Add(this.loadButton);
            this.Controls.Add(this.voltLabel);
            this.Controls.Add(this.clockLabel);
            this.Name = "SystemMonitor";
            this.Text = "SystemMonitor";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label clockLabel;
        private System.Windows.Forms.Label voltLabel;
        private System.Windows.Forms.Button loadButton;
        private System.Windows.Forms.TextBox voltBox;
        private System.Windows.Forms.TextBox clockBox;
    }
}

