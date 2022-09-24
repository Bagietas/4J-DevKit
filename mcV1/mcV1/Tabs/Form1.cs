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
        public static Thread Process = new Thread(new ThreadStart(Functions.CheckBadProcess));

        public static Point newpoint = new Point();
        public static int x;
        public static int y;
        
        mcV1.Classes.Offsets OFFSETS = new mcV1.Classes.Offsets();
        mcV1.Classes.Functions FUNCTIONS = new mcV1.Classes.Functions();


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

            Process.Start();
        }

        private void guna2Button1_Click(object sender, EventArgs e)
        {
            Process.Abort();
            Application.Exit();
        }

        private void guna2Button2_Click(object sender, EventArgs e)
        {
            if (guna2RadioButton1.Checked)
                OFFSETS.API = "CCAPI";
            else if (guna2RadioButton2.Checked)
                OFFSETS.API = "TMAPI";
            else if (guna2RadioButton3.Checked)
                OFFSETS.API = "HEN";

            OFFSETS.ChangeAPI();
            OFFSETS.doConnect();

            if (mcV1.Classes.Offsets.ConnectStatus == true)
            {
                label2.Text = "Connected";
                label2.ForeColor = Color.Green;
            }
        }
   
        private void guna2Button3_Click(object sender, EventArgs e)
        {
            if (!mcV1.Classes.Offsets.ConnectStatus == true)
            {
                MessageBox.Show("Oops, you need to be connected to your PS3 before inject the SPRX.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                OFFSETS.INJECT_SPRX_IN_PS3();
                label2.Text = "Waiting for connect";
                label2.ForeColor = Color.Orange;
            }
        }

        private void guna2Button4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("How to use it ?\n\n(NOTE: You need to have WebMAN Mod installed on your PS3 before inject the SPRX)\n\nStart your Minecraft (BLES01976 ONLY)\n\nWhen you are in Minecraft menu, connect the tool to your PS3 using (CCAPI, TMAPI, HEN).\n\nthen press 'Inject SPRX', wait 1-2 min (depends of your internet connection).\n\nWhen it's done, the game will restart when you are in the Minecraft menu again, join a random world and connect the tool to your console again.\n\nEnable 'Enable SPRX' and wait, the SPRX will be enabled in your game.\n\nMade By Misaki", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private async void guna2CheckBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (Offsets.ConnectStatus == true)
            {
                label4.Text = "Initialization";
                OFFSETS.ENABLE_SPRX();

                if (Offsets.StatusSPRX)
                {
                    label4.Text = "Status: Active";
                    await Task.Delay(5000);
                    Process.Abort();
                    Application.Exit();
                }
                else
                {
                    label4.Text = "Status: Inactive";
                }
            }
            else
            {
                MessageBox.Show("Oops, you need to be connected to your PS3 before use the SPRX.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
