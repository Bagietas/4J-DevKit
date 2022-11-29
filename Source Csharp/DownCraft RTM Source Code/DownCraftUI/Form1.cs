using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using DownCraftUI.Classes;

namespace DownCraftUI
{
    public partial class Form1 : Form
    {
        bool OpenedPanel;
        public static Point newpoint = new Point();
        public static int x;
        public static int y;
        Functions FUNCS = new Functions();
        Offsets OFFSETS = new Offsets();
        public static Thread Process = new Thread(new ThreadStart(Functions.CheckBadProcess));

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

        #region "Open Panels In Form"

        private Form activeForm = null;
        private void openChildFormInPanel(Form childForm)
        {
            if (activeForm != null)
                activeForm.Close();
            activeForm = childForm;
            childForm.TopLevel = false;
            childForm.FormBorderStyle = FormBorderStyle.None;
            childForm.Dock = DockStyle.Fill;
            guna2GradientPanel2.Controls.Add(childForm);
            guna2GradientPanel2.Tag = childForm;
            childForm.BringToFront();
            childForm.Show();
        }

        #endregion

        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                WebClient webClientUpdate = new WebClient();

                if (!webClientUpdate.DownloadString("https://pastebin.com/raw/v5nanRE7").Contains("3.0"))
                {
                    if (MessageBox.Show("DownCraft have a new update available.\n\nplease re-download the new update on the official website DownCraft.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Question) == DialogResult.OK)
                    {
                        Process.Start("");
                        Application.Exit();
                    }
                    else
                    {
                        Application.Exit();
                    }
                }
            }
            catch (Exception)
            {
                MessageBox.Show("API is offline", "SERVER ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Application.Exit();
            }      

            Process.Start();

            this.guna2GradientPanel1.MouseDown += this.xMouseDown;
            this.guna2GradientPanel1.MouseMove += this.xMouseMove;
            this.guna2GradientPanel1.MouseDown += this.xMouseDown;
            this.guna2GradientPanel1.MouseMove += this.xMouseMove;
            this.guna2ImageButton1.MouseDown += this.xMouseDown;
            this.guna2ImageButton1.MouseMove += this.xMouseMove;
            this.guna2ImageButton1.MouseDown += this.xMouseDown;
            this.guna2ImageButton1.MouseMove += this.xMouseMove;
            this.guna2ImageButton2.MouseDown += this.xMouseDown;
            this.guna2ImageButton2.MouseMove += this.xMouseMove;
            this.guna2ImageButton2.MouseDown += this.xMouseDown;
            this.guna2ImageButton2.MouseMove += this.xMouseMove;
            this.guna2ImageButton3.MouseDown += this.xMouseDown;
            this.guna2ImageButton3.MouseMove += this.xMouseMove;
            this.guna2ImageButton3.MouseDown += this.xMouseDown;
            this.guna2ImageButton3.MouseMove += this.xMouseMove;

            openChildFormInPanel(new Tabs.Main());
            FUNCS.SetDiscordRPC("1004653026486792262", "Waiting to connect", "Made by Misakiii", OFFSETS.status);
        }

        private void guna2ImageButton1_Click(object sender, EventArgs e)
        {
            if (!OpenedPanel)
            {
                openChildFormInPanel(new Tabs.Settings());
                OpenedPanel = true;
                FUNCS.SetDiscordRPC("1004653026486792262", "Navigate In Settings", "Made by Misakiii", OFFSETS.status);
            }
            else
            {
                openChildFormInPanel(new Tabs.Main());
                OpenedPanel = false;

                if (Offsets.ConnectStatus == true)
                {
                    FUNCS.SetDiscordRPC("1004653026486792262", "Navigate In Main Menu", "Made by Misakiii", OFFSETS.status);
                }
                else
                {
                    FUNCS.SetDiscordRPC("1004653026486792262", "Waiting to connect", "Made by Misakiii", OFFSETS.status);
                }
            }
        }

        private void guna2ImageButton2_Click(object sender, EventArgs e)
        {
            Process.Start("https://discord.gg/wPJ2n5gG9r");
        }

        private void guna2GradientPanel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void Form1_Move(object sender, EventArgs e)
        {
            Functions.x = this.Location.X + this.Size.Width - 1;
            Functions.y = this.Location.Y;
        }
    }
}
