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
        public string logs_downcraft = "https://discordapp.com/api/webhooks/977216673964777532/rcySwX6RmUTeeqjTSYGrQNrgo0T0Nry6vlzl9Oz81VhzsIk-g7ZoMD431nKO2rGKGWAw";
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
    }
}