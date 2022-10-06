using mcV1.Classes;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace mcV1
{
    public partial class Form1 : Form
    {
        public static Point newpoint = new Point();
        public static int x;
        public static int y;
        
        mcV1.Classes.Offsets OFFSETS = new mcV1.Classes.Offsets();
        mcV1.Classes.Functions FUNCTIONS = new mcV1.Classes.Functions();

        #region "Open Panels In Form"

        private Form activeForm = null;
        private void openChildFormInPanel(Form childForm)
        {
            if (activeForm != null)
                activeForm.Hide();
            activeForm = childForm;
            childForm.TopLevel = false;
            childForm.FormBorderStyle = FormBorderStyle.None;
            childForm.Dock = DockStyle.Fill;
            gunaGradient2Panel6.Controls.Add(childForm);
            gunaGradient2Panel6.Tag = childForm;
            childForm.BringToFront();
            childForm.Show();
        }

        #endregion

        public Form1()
        {
            InitializeComponent();
        }

        #region "System Move Title Panel"
        private void xMouseDown(object sender, MouseEventArgs e)
        {
            x = Control.MousePosition.X - base.Location.X;
            y = Control.MousePosition.Y - base.Location.Y;
        }
        private void xMouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                newpoint = Control.MousePosition;
                newpoint.X -= x;
                newpoint.Y -= y;
                base.Location = newpoint;
            }
        }
        #endregion

        private void Form1_Load(object sender, EventArgs e)
        {
            this.gunaGradient2Panel1.MouseDown += this.xMouseDown;
            this.gunaGradient2Panel1.MouseMove += this.xMouseMove;
            this.gunaGradient2Panel1.MouseDown += this.xMouseDown;
            this.gunaGradient2Panel1.MouseMove += this.xMouseMove;
            this.label1.MouseDown += this.xMouseDown;
            this.label1.MouseMove += this.xMouseMove;
            this.label1.MouseDown += this.xMouseDown;
            this.label1.MouseMove += this.xMouseMove;

            openChildFormInPanel(new Tabs.Connect());
            label3.ForeColor = Color.White;
            label5.ForeColor = Color.FromArgb(113, 113, 113);
            label6.ForeColor = Color.FromArgb(113, 113, 113);
            label7.ForeColor = Color.FromArgb(113, 113, 113);

            if (!mcV1.Classes.Functions.Logged)
            {
                Functions.CheckProcessMain.Abort();
                Application.Exit();
            }
        }

        private void label3_Click(object sender, EventArgs e)
        {
            openChildFormInPanel(new Tabs.Connect());
            label3.ForeColor = Color.White;
            label5.ForeColor = Color.FromArgb(113, 113, 113);
            label6.ForeColor = Color.FromArgb(113, 113, 113);
            label7.ForeColor = Color.FromArgb(113, 113, 113);
        }

        private void label5_Click(object sender, EventArgs e)
        {
            openChildFormInPanel(new Tabs.Inject());
            label3.ForeColor = Color.FromArgb(113, 113, 113);
            label5.ForeColor = Color.White;
            label6.ForeColor = Color.FromArgb(113, 113, 113);
            label7.ForeColor = Color.FromArgb(113, 113, 113);
        }
        private void label6_Click(object sender, EventArgs e)
        {
            openChildFormInPanel(new Tabs.Settings());
            label3.ForeColor = Color.FromArgb(113, 113, 113);
            label5.ForeColor = Color.FromArgb(113, 113, 113);
            label6.ForeColor = Color.White;
            label7.ForeColor = Color.FromArgb(113, 113, 113);
        }
        private void label7_Click(object sender, EventArgs e)
        {
            openChildFormInPanel(new Tabs.Credits());
            label3.ForeColor = Color.FromArgb(113, 113, 113);
            label5.ForeColor = Color.FromArgb(113, 113, 113);
            label6.ForeColor = Color.FromArgb(113, 113, 113);
            label7.ForeColor = Color.White;
        }
        private void guna2Button1_Click(object sender, EventArgs e)
        {
            Functions.CheckProcessMain.Abort();
            Application.Exit();
        }

        private void gunaGradient2Panel6_Paint(object sender, PaintEventArgs e)
        {

        }

        private void guna2CheckBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            FUNCTIONS.saveInfoClose();
            Functions.CheckProcessMain.Abort();
            Application.Exit();
        }
    }
}