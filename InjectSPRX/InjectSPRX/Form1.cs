﻿using System;
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
using ftp;

namespace InjectSPRX
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        internal async void InjectSPRX()
        {
            string text = Application.StartupPath + "\\settings.txt";

            if (File.Exists(text))
            {
                string[] array = File.ReadAllLines(text);
                if (array[0].EndsWith("useLoader=true"))
                {
                    string ConsoleIP = array[1];
                    string FileName = array[2];
                    string PathLocation = array[3];
                    var PATH = Application.StartupPath + "\\" + FileName + "";
                    {
                        if (File.Exists(PATH) is true)
                        {
                            label2.Text = "File Found " + FileName;
                            await Task.Delay(2000);
                            using (var client = new WebClient())
                            {
                                label3.Text = "Starting connection to " + ConsoleIP;
                                await Task.Delay(2000);
                                client.Credentials = new NetworkCredential("", "");
                                client.UploadFile("ftp://" + ConsoleIP + PathLocation + FileName, WebRequestMethods.Ftp.UploadFile, PATH);
                                label4.Text = "Successfuly inject SPRX to " + PathLocation;
                                await Task.Delay(2000);
                                label5.Text = "Reload the game and exiting app";
                                var reload = new WebClient();
                                reload.DownloadString("http://" + ConsoleIP + "/xmb.ps3$reloadgame");
                                await Task.Delay(4000);
                                Application.Exit();
                            }
                        }
                        else
                        {
                            MessageBox.Show("Oops i cannot find the SPRX file.");
                        }
                    }
                }
            }
            else
            {
                MessageBox.Show("Missing settings file.");
            }
        }

        private async void Form1_Load(object sender, EventArgs e)
        {
            await Task.Delay(200);
            InjectSPRX();
        }
    }
}
