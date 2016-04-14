namespace AsciiToHex
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
            this.tbHex = new System.Windows.Forms.RichTextBox();
            this.lbHex = new System.Windows.Forms.Label();
            this.btToAscii = new System.Windows.Forms.Button();
            this.tbAscii = new System.Windows.Forms.RichTextBox();
            this.lbAscii = new System.Windows.Forms.Label();
            this.btToHex = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // tbHex
            // 
            this.tbHex.Location = new System.Drawing.Point(12, 12);
            this.tbHex.Name = "tbHex";
            this.tbHex.Size = new System.Drawing.Size(616, 158);
            this.tbHex.TabIndex = 0;
            this.tbHex.Text = "";
            // 
            // lbHex
            // 
            this.lbHex.AutoSize = true;
            this.lbHex.Location = new System.Drawing.Point(13, 177);
            this.lbHex.Name = "lbHex";
            this.lbHex.Size = new System.Drawing.Size(32, 17);
            this.lbHex.TabIndex = 1;
            this.lbHex.Text = "Hex";
            // 
            // btToAscii
            // 
            this.btToAscii.Location = new System.Drawing.Point(553, 177);
            this.btToAscii.Name = "btToAscii";
            this.btToAscii.Size = new System.Drawing.Size(75, 23);
            this.btToAscii.TabIndex = 2;
            this.btToAscii.Text = "Convert";
            this.btToAscii.UseVisualStyleBackColor = true;
            this.btToAscii.Click += new System.EventHandler(this.btToAscii_Click);
            // 
            // tbAscii
            // 
            this.tbAscii.Location = new System.Drawing.Point(12, 206);
            this.tbAscii.Name = "tbAscii";
            this.tbAscii.Size = new System.Drawing.Size(616, 158);
            this.tbAscii.TabIndex = 3;
            this.tbAscii.Text = "";
            // 
            // lbAscii
            // 
            this.lbAscii.AutoSize = true;
            this.lbAscii.Location = new System.Drawing.Point(9, 367);
            this.lbAscii.Name = "lbAscii";
            this.lbAscii.Size = new System.Drawing.Size(37, 17);
            this.lbAscii.TabIndex = 4;
            this.lbAscii.Text = "Ascii";
            // 
            // btToHex
            // 
            this.btToHex.Location = new System.Drawing.Point(553, 370);
            this.btToHex.Name = "btToHex";
            this.btToHex.Size = new System.Drawing.Size(75, 23);
            this.btToHex.TabIndex = 5;
            this.btToHex.Text = "Convert";
            this.btToHex.UseVisualStyleBackColor = true;
            this.btToHex.Click += new System.EventHandler(this.btToHex_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(640, 444);
            this.Controls.Add(this.btToHex);
            this.Controls.Add(this.lbAscii);
            this.Controls.Add(this.tbAscii);
            this.Controls.Add(this.btToAscii);
            this.Controls.Add(this.lbHex);
            this.Controls.Add(this.tbHex);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox tbHex;
        private System.Windows.Forms.Label lbHex;
        private System.Windows.Forms.Button btToAscii;
        private System.Windows.Forms.RichTextBox tbAscii;
        private System.Windows.Forms.Label lbAscii;
        private System.Windows.Forms.Button btToHex;
    }
}

