using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Management;
using System.Net;
using System.Security.Permissions;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using Flagsec;

namespace mcV1.Classes
{
    internal class Functions
    {
        #region "Variables"

        WebClient web = new WebClient();

        public static string[] saveTxt = { "192.168.1.1", "Licence Key" };
        public static bool Logged;
        public static string LicenceKey;
        public static string SaveSettings = Application.StartupPath + "\\settings.txt";
        public static string CCAPI_setup = Application.StartupPath + "/files required/CCAPI-setupV2.60.exe";
        public static string webMAN_PKG = Application.StartupPath + "/files required/webMAN_MOD_1.47.42_Installer.pkg";
        public static string UpdaterFile = Application.StartupPath + "/UpdaterMC.exe";

        public static Thread CheckProcessLogin = new Thread(new ThreadStart(CheckBadProcess));
        public static Thread CheckProcessMain = new Thread(new ThreadStart(CheckBadProcess));

        #endregion

        #region "Create Settings TxT"
        public void saveInfoClose()
        {
            try
            {
                saveTxt = new string[] { Offsets.ps3IP, LicenceKey };
                File.WriteAllLines(SaveSettings, saveTxt);
            }
            catch
            {
                MessageBox.Show("Error has ocurred when saving settings.", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        #endregion
        #region "Login Func"
        public static string para3()
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

        public void Login()
        {
            try
            {
                string key = web.DownloadString("https://miisaakii.000webhostapp.com/Misakiki57/key.php");
                string HWID = web.DownloadString("https://miisaakii.000webhostapp.com/Misakiki57/HWID.php");

                string[] lines = HWID.Split(new string[] { Environment.NewLine, "\n", "\"r" }, StringSplitOptions.None);

                if (LicenceKey == key)
                {
                    if (lines.Contains(para3()))
                    {
                        Logged = true;
                        Form1 main = new Form1();
                        main.Show();
                        Form frm = Application.OpenForms["Login"];
                        frm.Hide();
                    }
                    else
                    {
                        MessageBox.Show("Your not allowed to use DownCraft.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                }
                else
                {
                    MessageBox.Show("Wrong licence key.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Oops unknow error :(", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        public void GetLicenceKey()
        {
            try
            {
                string key = web.DownloadString("https://miisaakii.000webhostapp.com/Misakiki57/key.php");
                string HWID = web.DownloadString("https://miisaakii.000webhostapp.com/Misakiki57/HWID.php");
                string[] lines = HWID.Split(new string[] { Environment.NewLine, "\n", "\"r" }, StringSplitOptions.None);

                if (lines.Contains(para3()))
                {
                    MessageBox.Show("Your licence key is: " + key, "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    MessageBox.Show("You are not registered, buy the access for get your licence key.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Oops unknow error :(", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        #endregion
        #region "Check bad program"

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
                        Application.Exit();
                        Functions.CheckProcessLogin.Abort();
                        Functions.CheckProcessMain.Abort();
                    }
                }
                catch
                {

                }
            }
        }

        #endregion
        #region "Webhook func"
        public void SendWebook(string link, string name, string picture, string message)
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

        #endregion
        #region "FTP func"
        public void FTP_UPLOAD(string URL, string username, string password, string pathConsole, string filePC)
        {
            using (var client = new WebClient())
            {
                client.Credentials = new NetworkCredential(username, password);
                client.UploadFile(URL + pathConsole, WebRequestMethods.Ftp.UploadFile, filePC);
            }
        }

        public void FTP_DOWNLOAD(string URL, string username, string password, string pathConsole, string filePC)
        {
            using (var client = new WebClient())
            {
                client.Credentials = new NetworkCredential(username, password);
                client.DownloadFile(URL + pathConsole, filePC);
            }
        }

        internal bool FTP_DELETE(string uriString, bool ssl = false, bool binary = false, string ftpUsername = "def", string ftpPassword = "default")
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
    }
}