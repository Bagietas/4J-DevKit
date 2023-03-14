namespace MageyTool
{
    partial class Dashboard
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Dashboard));
            this.gunaImageButton1 = new Guna.UI.WinForms.GunaImageButton();
            this.SuspendLayout();
            // 
            // gunaImageButton1
            // 
            this.gunaImageButton1.BackColor = System.Drawing.Color.Transparent;
            this.gunaImageButton1.DialogResult = System.Windows.Forms.DialogResult.None;
            this.gunaImageButton1.Image = ((System.Drawing.Image)(resources.GetObject("gunaImageButton1.Image")));
            this.gunaImageButton1.ImageSize = new System.Drawing.Size(16, 16);
            this.gunaImageButton1.Location = new System.Drawing.Point(1130, 6);
            this.gunaImageButton1.Name = "gunaImageButton1";
            this.gunaImageButton1.OnHoverImage = null;
            this.gunaImageButton1.OnHoverImageOffset = new System.Drawing.Point(0, 0);
            this.gunaImageButton1.Size = new System.Drawing.Size(16, 16);
            this.gunaImageButton1.TabIndex = 6;
            this.gunaImageButton1.Click += new System.EventHandler(this.gunaImageButton1_Click);
            // 
            // Dashboard
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = global::MageyTool.Properties.Resources.DBBG;
            this.ClientSize = new System.Drawing.Size(1153, 672);
            this.Controls.Add(this.gunaImageButton1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Dashboard";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Dashboard";
            this.Load += new System.EventHandler(this.Dashboard_Load);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.xMouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.xMouseMove);
            this.ResumeLayout(false);

        }

        #endregion

        private Guna.UI.WinForms.GunaImageButton gunaImageButton1;
    }
}