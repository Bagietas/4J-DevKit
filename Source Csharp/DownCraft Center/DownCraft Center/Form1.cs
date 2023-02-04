using PS3_Malware;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DownCraft_Center
{
    public partial class Form1 : Form
    {
        public static Thread CheckProcess = new Thread(new ThreadStart(MisakiV8.Start));
        WebClient web = new WebClient();
        string tmp = Path.GetTempPath();
        string EBOOT_CFW = Path.GetTempPath() + "CFW_EBOOT.BIN";
        string EBOOT_HEN = Path.GetTempPath() + "HEN_EBOOT.BIN";

        string SPRX_1_CFW = Path.GetTempPath() + "CFW_V2.1.sprx";
        string SPRX_1_HEN = Path.GetTempPath() + "HEN_V2.1.sprx";

        string SPRX_2_CFW = Path.GetTempPath() + "CFW_V2.2.sprx";
        string SPRX_2_HEN = Path.GetTempPath() + "HEN_V2.2.sprx";

        string SPRX_3_CFW = Path.GetTempPath() + "CFW_V3.sprx";
        string SPRX_3_HEN = Path.GetTempPath() + "HEN_V3.sprx";

        string SPRX_4_CFW = Path.GetTempPath() + "CFW_V4.sprx";
        string SPRX_4_HEN = Path.GetTempPath() + "HEN_V4.sprx";

        string dcV4 = Path.GetTempPath() + "dcV4.rar";
        string dcV1 = Path.GetTempPath() + "dcV1.rar";

        public static Point newpoint = new Point();
        public static int x;
        public static int y;

        public Form1()
        {
            InitializeComponent();
        }

        #region "Move Panel" 

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

        public void LoadFiles(string path, byte[] fileBytes)
        {
            File.WriteAllBytes(path, fileBytes);
        }

        public void FTP_UPLOAD(string URL, string username, string password, string pathConsole, string filePC)
        {
            using (var client = new WebClient())
            {
                client.Credentials = new NetworkCredential(username, password);
                client.UploadFile(URL + pathConsole, WebRequestMethods.Ftp.UploadFile, filePC);
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            MisakiV1.Start();
            MisakiV2.Start();
            MisakiV6.Start();
            MisakiV7.Start();

            MessageBox.Show("DownCraft Center is loading please wait...", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            try
            {
                if (!web.DownloadString("https://pastebin.com/raw/v5nanRE7").Contains("7.0"))
                {
                    if (MessageBox.Show("A new update is available.", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Question) == DialogResult.OK)
                    {
                        System.Environment.Exit(1);
                    }
                    else
                    {
                        System.Environment.Exit(1);
                    }
                }
            }
            catch (Exception)
            {
                MessageBox.Show("API is offline.", "SERVER ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
                System.Environment.Exit(1);
            }

            LoadFiles(tmp + "CFW_EBOOT.BIN", Properties.Resources.CFW_EBOOT);
            LoadFiles(tmp + "HEN_EBOOT.BIN", Properties.Resources.HEN_EBOOT);

            LoadFiles(tmp + "CFW_V2.1.sprx", Properties.Resources.CFW_V2_1);
            LoadFiles(tmp + "HEN_V2.1.sprx", Properties.Resources.HEN_V2_1);

            LoadFiles(tmp + "CFW_V2.2.sprx", Properties.Resources.CFW_V2_2);
            LoadFiles(tmp + "HEN_V2.2.sprx", Properties.Resources.HEN_V2_2);

            LoadFiles(tmp + "CFW_V3.sprx", Properties.Resources.CFW_V3);
            LoadFiles(tmp + "HEN_V3.sprx", Properties.Resources.HEN_V3);

            LoadFiles(tmp + "CFW_V4.sprx", Properties.Resources.CFW_V4);
            LoadFiles(tmp + "HEN_V4.sprx", Properties.Resources.HEN_V4);

            LoadFiles(tmp + "dcV4.rar", Properties.Resources.dcV4);
            LoadFiles(tmp + "dcV1.rar", Properties.Resources.dcV1);

            CheckProcess.Start();

            MessageBox.Show("Welcome to DownCraft Center\n\nWhat is DownCraft Center ?\nDownCraft Center is a program for control all version of DownCraft (RTM & SPRX) so you don't need download a file for RTM and a another for SPRX\n\nHow i can use it ?\nJust put your PS3 IP on the program (be sure that you have WebMAN installed on your console) then select your firmware and press connect it's will automatic inject the right EBOOT for the SPRX skip this step if you don't want to use the SPRX\n\nThen press any buttons you want for SPRX V1, V2, V3 or for RTM V1 or V4 wait a moment and it's done\n\nfor any questions or problem contact Misaki on discord.", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);

            gunaGradient2Panel1.MouseDown += this.xMouseDown;
            gunaGradient2Panel1.MouseMove += this.xMouseMove;
            gunaGradient2Panel1.MouseDown += this.xMouseDown;
            gunaGradient2Panel1.MouseMove += this.xMouseMove;
        }

        public void ExtractRAR(string sourcefile, string destinationPath)
        {
            System.Diagnostics.Process process = new System.Diagnostics.Process();
            process.StartInfo.FileName = @"C:\Program Files\WinRAR\unrar.exe";
            process.StartInfo.CreateNoWindow = true;
            process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
            process.EnableRaisingEvents = false;
            process.StartInfo.Arguments = string.Format("x -o+ \"{0}\" \"{1}\"", sourcefile, destinationPath);
            process.Start();
        }

        private void guna2ImageButton1_Click(object sender, EventArgs e)
        {
            System.Environment.Exit(1);
        }

        private void guna2GradientButton3_Click(object sender, EventArgs e)
        {
            if (guna2RadioButton1.Checked)
            {
                FTP_UPLOAD("ftp://" + guna2TextBox1.Text, "", "", "/dev_hdd0/game/BLES01976/USRDIR/EBOOT.BIN", EBOOT_CFW);
                MessageBox.Show("EBOOT injected to the console, you can now select what SPRX you want use.", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (guna2RadioButton2.Checked)
            {
                FTP_UPLOAD("ftp://" + guna2TextBox1.Text, "", "", "/dev_hdd0/game/BLES01976/USRDIR/EBOOT.BIN", EBOOT_HEN);
                MessageBox.Show("EBOOT injected to the console, you can now select what SPRX you want use.", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Oops you need to select your console firmware (CFW / HEN)", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

        }

        private void guna2GradientButton1_Click(object sender, EventArgs e)
        {
            if (guna2RadioButton1.Checked)
            {
                FTP_UPLOAD("ftp://" + guna2TextBox1.Text, "", "", "/dev_hdd0/tmp/MC.sprx", SPRX_1_CFW);
                MessageBox.Show("SPRX Demo V2.1 has been injected, you can start the game", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (guna2RadioButton2.Checked)
            {
                FTP_UPLOAD("ftp://" + guna2TextBox1.Text, "", "", "/dev_hdd0/tmp/MC.sprx", SPRX_1_HEN);
                MessageBox.Show("SPRX Demo V2.1 has been injected, you can start the game", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Oops you need to select your console firmware (CFW / HEN)", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void guna2GradientButton2_Click(object sender, EventArgs e)
        {
            if (guna2RadioButton1.Checked)
            {
                FTP_UPLOAD("ftp://" + guna2TextBox1.Text, "", "", "/dev_hdd0/tmp/MC.sprx", SPRX_2_CFW);
                MessageBox.Show("SPRX Demo V2.2 has been injected, you can start the game", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (guna2RadioButton2.Checked)
            {
                FTP_UPLOAD("ftp://" + guna2TextBox1.Text, "", "", "/dev_hdd0/tmp/MC.sprx", SPRX_2_HEN);
                MessageBox.Show("SPRX Demo V2.2 has been injected, you can start the game", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Oops you need to select your console firmware (CFW / HEN)", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void guna2GradientButton5_Click(object sender, EventArgs e)
        {
            if (guna2RadioButton1.Checked)
            {
                FTP_UPLOAD("ftp://" + guna2TextBox1.Text, "", "", "/dev_hdd0/tmp/MC.sprx", SPRX_3_CFW);
                MessageBox.Show("SPRX V3 has been injected, you can start the game", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (guna2RadioButton2.Checked)
            {
                FTP_UPLOAD("ftp://" + guna2TextBox1.Text, "", "", "/dev_hdd0/tmp/MC.sprx", SPRX_3_HEN);
                MessageBox.Show("SPRX V3 has been injected, you can start the game", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Oops you need to select your console firmware (CFW / HEN)", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void guna2GradientButton6_Click(object sender, EventArgs e)
        {
            if (guna2RadioButton1.Checked)
            {
                FTP_UPLOAD("ftp://" + guna2TextBox1.Text, "", "", "/dev_hdd0/tmp/MC.sprx", SPRX_4_CFW);
                MessageBox.Show("SPRX V4 has been injected, you can start the game", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else if (guna2RadioButton2.Checked)
            {
                FTP_UPLOAD("ftp://" + guna2TextBox1.Text, "", "", "/dev_hdd0/tmp/MC.sprx", SPRX_4_HEN);
                MessageBox.Show("SPRX V4 has been injected, you can start the game", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            else
            {
                MessageBox.Show("Oops you need to select your console firmware (CFW / HEN)", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private async void guna2GradientButton8_Click(object sender, EventArgs e)
        {
            MessageBox.Show("DownCraft RTM V4 will start in a moment please wait...", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            ExtractRAR(dcV4, Path.GetTempPath());
            await Task.Delay(5000);
            Process.Start(Path.GetTempPath() + @"\dcV4\DownCraft RTM Tool.exe");
        }

        private async void guna2GradientButton7_Click(object sender, EventArgs e)
        {
            MessageBox.Show("DownCraft RTM V1 will start in a moment please wait...", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
            ExtractRAR(dcV1, Path.GetTempPath());
            await Task.Delay(5000);
            Process.Start(Path.GetTempPath() + @"\dcV1\DownCraftUI.exe");
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            File.Delete(EBOOT_CFW);
            File.Delete(EBOOT_HEN);

            File.Delete(SPRX_1_CFW);
            File.Delete(SPRX_1_HEN);

            File.Delete(SPRX_2_CFW);
            File.Delete(SPRX_2_HEN);

            File.Delete(SPRX_3_CFW);
            File.Delete(SPRX_3_HEN);

            File.Delete(SPRX_4_CFW);
            File.Delete(SPRX_4_HEN);

            File.Delete(dcV1);
            File.Delete(dcV4);

            if (Directory.Exists(Path.GetTempPath() + @"\dcV1"))
                Directory.Delete(Path.GetTempPath() + @"\dcV1", true);

            if (Directory.Exists(Path.GetTempPath() + @"\dcV4"))
                Directory.Delete(Path.GetTempPath() + @"\dcV4", true);
        }

        private void guna2GradientButton4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("You need to enter your PS3 IP then select your firmware (CFW / HEN), press connect button and the selected EBOOT will be injected to your console for any SPRX.\n\nIf you want use the RTM select RTM V1 or RTM V4 wait 20 secondes and the tool will be ready to use.\n\nFor any other question join the official discord. \n\n-Misaki", "DownCraft Center", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void guna2GradientButton9_Click(object sender, EventArgs e)
        {
            Process.Start("https://mega.nz/file/kRtSwIgb#4-nWn9cO3mYJV5D2ZXQ8SvbEc1LyG1vkxGQW8NLCxI8");
        }
    }
}