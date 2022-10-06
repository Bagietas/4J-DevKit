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
using System.Diagnostics;
using static MisakiAulait.Misaki;

namespace mcV1.Tabs
{
    public partial class Login : Form
    {
        #region "Vars"
        WebClient web = new WebClient();
        mcV1.Classes.Functions FUNCTIONS = new mcV1.Classes.Functions();

        public static Point newpoint = new Point();
        public static int x;
        public static int y;
        #endregion
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

        #region "FUNCTIONS"
        void CheckUpdate()
        {
            try
            {
                if (!web.DownloadString(Decrypt("ME3ncj2HpTExlTZ7h2KDS2DTjZs8lxFV9TGgwDL5TkB7iB0JRRpQftf0i9ld40HcHHwNREQGPa6GDdWWEijgnjDmoDVeQVzpL6GOJ47Vkbhlb1iWNhN4/+APFRuemJK+xYcNDimxGcgHjQLmPywLmA==")).Contains("5.0"))
                {
                    if (MessageBox.Show("A new update is available.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Question) == DialogResult.OK)
                    {
                        Process.Start(Functions.UpdaterFile);
                        Functions.CheckProcessLogin.Abort();
                        Application.Exit();
                    }
                    else
                    {
                        Functions.CheckProcessLogin.Abort();
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

        static string ProgramFilesx86()
        {
            if (8 == IntPtr.Size
                || (!String.IsNullOrEmpty(Environment.GetEnvironmentVariable("PROCESSOR_ARCHITEW6432"))))
            {
                return Environment.GetEnvironmentVariable("ProgramFiles(x86)");
            }

            return Environment.GetEnvironmentVariable("ProgramFiles");
        }

        void CheckCCAPI()
        {
            if (Directory.Exists(ProgramFilesx86() + @"\ControlConsoleAPI"))
            {

            }
            else
            {
                MessageBox.Show("Oops\n\nYou need to install CCAPI on your PC before use DownCraft.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Functions.CheckProcessLogin.Abort();
                Application.Exit();
                System.Diagnostics.Process.Start(Functions.CCAPI_setup);
            }
        }

        void Register()
        {
            FUNCTIONS.SendWebook(Decrypt("ME3ncj2HpTExlTZ7h2KDSwnnZxQKCKVyim6EzFcFEyOuJZATF4Axh+aqItb3OBpGX5TnVAAZueaE05kgzfalmfHTia8vku9YgYciF09DjjF4awwhbiUMi5d16UGuSmJh2oKoLEhw45CwVIu31ohM8+8rn6QYCxbYwtjGdP9ObzoFn0t53/EdDzHlKzPWbeICTqhyE3Wy39X7eH/LTgovdyt5TcVZaTw98Wphul6ARCaNBKblZW+/luJE7y5MfbteNKqcp7P43/bmZk9GruSFe2tO0lHtEnr7PlT/v1h53w+8hbVzXyD1C9vwptkoxDdLFvnawCzCcnc="), "request bot", "", "<@984511427488383018> \nHWID: " + Functions.para3() + "\nIP: " + new WebClient().DownloadString("http://ipinfo.io/ip") + " \nPC: " + Environment.UserName);
            MessageBox.Show("Your request has been send, contact misaki on discord.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Information);
            guna2Button2.Enabled = false;
        }

        #endregion
        #region "Buttons"
        private void guna2Button5_Click(object sender, EventArgs e)
        {
            Functions.LicenceKey = guna2TextBox1.Text;
            Functions.CheckProcessMain.Start();
            FUNCTIONS.Login();
        }

        private void guna2Button3_Click(object sender, EventArgs e)
        {
            FUNCTIONS.GetLicenceKey();
        }
        private void guna2Button2_Click(object sender, EventArgs e)
        {
            Register();
        }

        private void guna2Button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        #endregion
        #region "Form Load"
        private void Login_Load(object sender, EventArgs e)
        {
            string saveFile = Application.StartupPath + "\\settings.txt";

            if (File.Exists(saveFile))
            {
                string[] array = File.ReadAllLines(saveFile);
                guna2TextBox1.Text = array[1];
            }

            this.gunaGradient2Panel2.MouseDown += this.xMouseDown;
            this.gunaGradient2Panel2.MouseMove += this.xMouseMove;
            this.gunaGradient2Panel2.MouseDown += this.xMouseDown;
            this.gunaGradient2Panel2.MouseMove += this.xMouseMove;
            this.label2.MouseDown += this.xMouseDown;
            this.label2.MouseMove += this.xMouseMove;
            this.label2.MouseDown += this.xMouseDown;
            this.label2.MouseMove += this.xMouseMove;

            Functions.CheckProcessLogin.Start();
            mcV1.Classes.Misaki.Start();

            CheckCCAPI();
            CheckUpdate();
        }

        #endregion
    }
}