using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Management;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using mcV1.Classes;
using System.Threading;

namespace mcV1.Tabs
{
    public partial class Login : Form
    {
        private string localFile = Application.StartupPath + "/UpdaterMC.exe";
        public static Thread Process = new Thread(new ThreadStart(Functions.CheckBadProcess));

        WebClient web = new WebClient();
        mcV1.Classes.Functions FUNCTIONS = new mcV1.Classes.Functions();

        public static Point newpoint = new Point();
        public static int x;
        public static int y;

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

        public Login()
        {
            InitializeComponent();
        }

        #region "HWID"
        private static string para3()
        {
            string str = "";
            ManagementObjectCollection.ManagementObjectEnumerator objA = new ManagementObjectSearcher("Select * From Win32_processor").Get().GetEnumerator();
            try
            {
                while (true)
                {
                    if (!objA.MoveNext())
                    {
                        break;
                    }
                    ManagementObject current = (ManagementObject)objA.Current;
                    str = current["ProcessorID"].ToString();
                }
            }
            finally
            {
                if (!ReferenceEquals(objA, null))
                {
                    objA.Dispose();
                }
            }
            ManagementObject obj3 = new ManagementObject("win32_logicaldisk.deviceid=\"c:\"");
            obj3.Get();
            return (str + obj3["VolumeSerialNumber"].ToString());
        }

        #endregion
        #region "LOGIN"

        public async void LOGIN()
        {
            await Task.Delay(1);
            guna2Button2.Text = "Waiting...";
            guna2Button2.Enabled = false;
            try
            {
                string key = web.DownloadString("https://miisaakii.000webhostapp.com/Misakiki57/key.php");
                string HWID = web.DownloadString("https://miisaakii.000webhostapp.com/Misakiki57/HWID.php");

                string[] lines = HWID.Split(new string[] { Environment.NewLine, "\n", "\"r" }, StringSplitOptions.None);

                if (guna2TextBox1.Text == key)
                {
                    if (lines.Contains(para3()))
                    {
                        Form1 open = new Form1();
                        open.Show();
                        Process.Abort();
                        this.Hide();
                    }
                    else
                    {
                        MessageBox.Show("Your not allowed to use DownCraft.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        guna2Button2.Text = "Login";
                        guna2Button2.Enabled = true;
                    }
                }
                else
                {
                    MessageBox.Show("Wrong licence key.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    guna2Button2.Text = "Login";
                    guna2Button2.Enabled = true;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Oops unknow error :(", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
                guna2Button2.Text = "Login";
                guna2Button2.Enabled = true;
            }
        }

        #endregion

        private void guna2Button2_Click(object sender, EventArgs e)
        {
            LOGIN();
        }

        private void guna2Button3_Click(object sender, EventArgs e)
        {
            FUNCTIONS.SendWebook("https://discord.com/api/webhooks/1022812833693585439/BWoY1K1jaAdV2AqqLMTX4hGWxxHEvUIYW4t8nEfgblUVRQYn5NiD7VrpMgEESVmUbof8", "request bot", "", "<@984511427488383018> \nHWID: " + para3() + "\nIP: " + new WebClient().DownloadString("http://ipinfo.io/ip") + " \nPC: " + Environment.UserName);
            MessageBox.Show("Your request has been send, contact misaki on discord.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Information);
            guna2Button3.Enabled = false;
        }

        private void guna2Button1_Click(object sender, EventArgs e)
        {
            Process.Abort();
            Application.Exit();
        }

        private void Login_Load(object sender, EventArgs e)
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
            mcV1.Classes.Misaki.Start();

            try
            {
                if (!web.DownloadString("https://miisaakii.000webhostapp.com/Misakiki57/API.php").Contains("1.0"))
                {
                    if (MessageBox.Show("A new update is available.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Question) == DialogResult.OK)
                    {
                        Process.Start(localFile);
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
                MessageBox.Show("API is offline.", "SERVER ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Application.Exit();
            }
        }
    }
}
