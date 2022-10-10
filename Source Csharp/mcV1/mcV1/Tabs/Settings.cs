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
using System.Threading.Tasks;
using System.Windows.Forms;

namespace mcV1.Tabs
{
    public partial class Settings : Form
    {
		private string GameBLES = "https://downcraft.xyz/downcraft/SPRX/src/Minecraft.rar";
		public static string GamePath = Application.StartupPath + "/files required/Minecraft BLES01976.rar";

		public Settings()
        {
            InitializeComponent();
		}
		private void updateTool()
		{
			using (WebClient webClient = new WebClient())
			{
				webClient.DownloadFileCompleted += Completed;
				webClient.DownloadProgressChanged += ProgressChanged;

				try
				{
					webClient.DownloadFileAsync(new Uri(GameBLES), GamePath);
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
			progressBar1.Value = e.ProgressPercentage;
			label1.Text = string.Format("{0} MB's / {1} MB's", ((double)e.BytesReceived / 1024.0 / 1024.0).ToString("0.00"), ((double)e.TotalBytesToReceive / 1024.0 / 1024.0).ToString("0.00"));
		}

		private void Completed(object sender, AsyncCompletedEventArgs e)
		{
			if (e.Cancelled)
			{
				MessageBox.Show("Download has been canceled.");
			}
			else
			{
				progressBar1.Maximum = progressBar1.Value;
				label1.Text = "Download Complete";

				MessageBox.Show("For install Minecraft BLES01976, you need extract Minecraft BLES01976.rar\n\nTake the folder 'Minecraft PlayStation3 Edition [BLES01976]' and add this folder on your PS3 \n'dev_hdd0/GAMES/Minecraft PlayStation3 Edition [BLES01976]'\n\nWhen it's done mount your game with WebMAN and make the update 1.84\nNow you got Minecraft BLES01976 installed on your console.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Information);
			}
		}


		private void guna2Button5_Click(object sender, EventArgs e)
        {
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
			updateTool();

			progressBar1.Visible = true;
			label1.Visible = true;
		}
    }
}
