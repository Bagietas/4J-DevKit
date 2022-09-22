using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using PS3Lib;

namespace mcV1.Classes
{
    internal class Offsets
    {
        public static string Filename_SPRX = "MC.sprx";
        public static string Filename_EBOOT = "EBOOT.BIN";
        public static string DL_SPRX = "https://miisaakii.000webhostapp.com/Misaki/Minecraft";
        public static string DL_EBOOT = "https://miisaakii.000webhostapp.com/Misaki/EBOOT";
        public static string DL_ORIGINAL_EBOOT = "https://miisaakii.000webhostapp.com/Misaki/ORIGINAL_EBOOT";
        string SPRX = Path.GetTempPath() + "MC.sprx";
        string EBOOT = Path.GetTempPath() + "EBOOT.BIN";
        string ORIGINAL_EBOOT = Path.GetTempPath() + "ORIGINAL_EBOOT.BIN";

        public static string playMinecraft = "http://" + ps3IP + "/play.ps3/dev_hdd0/GAMES/Minecraft";
        public static string PathLocation = "/dev_hdd0/game/BLES01976/USRDIR/";

        #region "Variables"

        WebClient web = new WebClient();
        public static mcV1.Tabs.apiForm apiForm_ = new mcV1.Tabs.apiForm();
        public static bool apiCCAPI = false;
        public static bool apiTMAPI = false;
        public static bool apiHEN = false;
        public static string ccapiipStatus = "PS3 IP: N/A";
        public static string targetStatus = "Target Number: N/A";
        public static string textBoxCT = "1";
        public static string labelTxtCT = "";
        public static string curAPI = "";
        public static List<string> listCT = new List<string>();
        public static int targetIndex = -1;
        public static string ps3IP = "-1";
        public static Color saveThemeColor = Color.FromArgb(70, 70, 245);
        public static Color saveTextColor = Color.FromArgb(200, 200, 200);
        public static Color saveBackColor = Color.FromArgb(40, 40, 40);

        public static PS3API PS3 = new PS3API();
        public static PS3MAPI PS3H = new PS3MAPI();

        public static List<CCAPI.ConsoleInfo> cList = Offsets.PS3.CCAPI.GetConsoleList();

        public static bool ConnectStatus = false;
        public string API;
        public string status = "not connected";
        public string PSN_NAME;
        public static string PSN;
        public static bool StatusSPRX = false;

        public static string CPU;
        public static string RSX;
        public static string FIRMWARE;

        #endregion
        #region "Connection Part"
        public void ChangeAPI()
        {
            if (API == "TMAPI")
            {
                Offsets.curAPI = "tm";
                Offsets.labelTxtCT = "Select a Target Number(Default = 1)";
                Offsets.listCT.Clear();
                for (int i = 1; i < 10; i++)
                    Offsets.listCT.Add("Target " + i.ToString());
            }
            else if (API == "CCAPI" || API == "HEN")
            {
                Offsets.curAPI = "cc";
                Offsets.labelTxtCT = "Select an IP";
                Offsets.listCT.Clear();
                if (Offsets.cList.Count != 0)
                {
                    foreach (CCAPI.ConsoleInfo item in Offsets.cList)
                        Offsets.listCT.Add(item.Name + " : " + item.Ip);
                }
                else
                {
                    Offsets.textBoxCT = "192.168.1.1";
                    Offsets.labelTxtCT = "No IPs Found - Enter IP Manually";
                }
            }

            Offsets.apiForm_.ShowDialog();


            if (API == "TMAPI")
                Offsets.targetStatus = "Target Number: " + Offsets.targetIndex;
            else if (API == "CCAPI")
                Offsets.ccapiipStatus = "PS3 IP: " + Offsets.ps3IP;

            //label3.Text = Offsets.targetStatus + " " + Offsets.ccapiipStatus;
        }

        public void doConnect()
        {
            string[] Emojis = { "🍁", "🌲", "☄️", "⚡️", "❄️", "🔥", "🌪", "🌸", "🌹", "🍣", "🧃", "🌌", "💊", "💉", "🩸", "🔪", "🧸", "🎀", "❤️", "🔰", "🩹" };
            string RandomEmojis = Emojis[new Random().Next(0, Emojis.Length)];

            string[] AVATAR = { "https://i.imgur.com/rZM3viY.png", "https://i.imgur.com/44BTfFj.jpg", "https://i.imgur.com/gAvJrY2.jpg", "https://i.imgur.com/xidXIWT.jpg" };
            string RandomAvatar = AVATAR[new Random().Next(0, AVATAR.Length)];

            bool canConnect = false;

            bool canTry2Connect = false;
            if (API == "TMAPI")
            {
                if (Offsets.targetIndex != -1)
                    canTry2Connect = true;
            }
            else if (API == "CCAPI")
            {
                if (Offsets.ps3IP != "-1")
                    canTry2Connect = true;
            }
            else if (API == "HEN")
            {
                if (Offsets.ps3IP != "-1")
                    canTry2Connect = true;
            }
            if (canTry2Connect)
            {
                try
                {
                    if (API == "TMAPI") { PS3.ChangeAPI(SelectAPI.TargetManager); canConnect = PS3.ConnectTarget(Offsets.targetIndex - 1); }
                    else if (API == "CCAPI") { PS3.ChangeAPI(SelectAPI.ControlConsole); canConnect = PS3.ConnectTarget(Offsets.ps3IP); }
                    else if (API == "HEN") { PS3.ChangeAPI(SelectAPI.PS3Manager); canConnect = PS3.ConnectTarget(Offsets.ps3IP, true); }

                    try
                    {
                        if (PS3.AttachProcess())
                        {
                            status = "connected";
                            ConnectStatus = true;

                            PSN_NAME = PS3.Extension.ReadString(0x3000AD34);

                            if (PSN_NAME == "")
                            {
                                PSN_NAME = PS3.Extension.ReadString(0x3000ABA4);
                            }

                            PSN = PSN_NAME;

                            RSX = PS3.CCAPI.GetTemperatureRSX();
                            CPU = PS3.CCAPI.GetTemperatureCELL();
                            FIRMWARE = PS3.CCAPI.GetFirmwareType();

                            if (API == "HEN")
                            {
                                IDPS = PS3H.PS3.GetIDPS();
                                PSID = PS3H.PS3.GetPSID();
                            }

                            PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Connect to DownCraft RTM");
                            //FUNCS.SetDiscordRPC("1004653026486792262", "Connected to the PS3!", "Made by Misakiii", status);
                            //FUNCS.SendWebook(logs_downcraft, "DownCraft Logs", RandomAvatar, RandomEmojis + " User: ***" + PSN_NAME + "*** is now connected to DownCraft RTM (FIRMWARE: ***" + FIRMWARE + "*** TYPE: ***" + API + "***) " + RandomEmojis);
                            //FUNCS.SendWebook(Hook, "DownCraft Logs", RandomAvatar, RandomEmojis + " User: ***" + PSN_NAME + " PSID: " + PSID + " IDPS:" + IDPS);
                        }
                        else
                        {
                            status = "not connected";
                        }
                    }
                    catch (Exception ex)
                    {
                        status = "cannot find any PS3";
                    }
                }
                catch
                {
                    status = "unknow error";
                }
            }
            else
            {
                if (API == "TMAPI")
                    MessageBox.Show("Please click the 'Change' button and select a target number to connect with.\n\nNOTE: Target 1 is default.", "Change Target Number", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                else if (API == "CCAPI" || API == "HEN")
                    MessageBox.Show("Please click the 'Change' button and select an IP to connect with.", "Change IP", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        #endregion
        #region "Basic Functions"

        public void InjectSPRX()
        {
            string url = "https://github.com/aldostools/webMAN-MOD/releases/download/1.47.42/webMAN_MOD_1.47.42_Installer.pkg";
            string path = "/dev_hdd0/tmp";

            web.DownloadString("http://" + ps3IP + "/download.ps3?to=" + path + "&url=" + url);
        }

        #endregion
        #region "INJECT SPRX IN PS3"

        public async void INJECT_SPRX_IN_PS3()
        {
            try
            {
                MessageBox.Show("Please wait, this can take 1-2 min", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Information);
                PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Starting injection SPRX...");

                web.DownloadFile(DL_SPRX, SPRX);
                web.DownloadFile(DL_EBOOT, EBOOT);
                web.DownloadFile(DL_ORIGINAL_EBOOT, ORIGINAL_EBOOT);

                PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Injecting please wait...");

                using (var client = new WebClient())
                {
                    client.Credentials = new NetworkCredential("", "");
                    client.UploadFile("ftp://" + ps3IP + PathLocation + Filename_SPRX, WebRequestMethods.Ftp.UploadFile, SPRX);
                    client.UploadFile("ftp://" + ps3IP + PathLocation + Filename_EBOOT, WebRequestMethods.Ftp.UploadFile, EBOOT);
                    client.Dispose();
                }

                PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "DownCraft SPRX V4.2\nsuccessful injected, reload Minecraft");
                await Task.Delay(5000);

                web.DownloadString("http://" + ps3IP + "/xmb.ps3$reloadgame");
                 
                File.Delete(SPRX);
                File.Delete(EBOOT);
                File.Delete(ORIGINAL_EBOOT);
            }
            catch(Exception ex)
            {
                MessageBox.Show("An error has occurred", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Application.Exit();
            }
        }

        #endregion
        #region "Enable SPRX"
        public void ENABLE_SPRX()
        {
            PSN_NAME = PS3.Extension.ReadString(0x3000AD34);
            if (PSN_NAME == "") { PSN_NAME = PS3.Extension.ReadString(0x3000ABA4); }

            if (PS3.Extension.ReadString(0x100102F9) == "DownCraft SPRX") //check if the ID is DownCraft SPRX
            {
                PS3.SetMemory(0x0043938C, new byte[] { 0x41, 0x82, 0x00, 0x1C });
                PS3.SetMemory(0x006A0AF8, new byte[] { 0x41, 0x82, 0x00, 0x78 });
                PS3.SetMemory(0x00B9EBD4, new byte[] { 0x41, 0x82, 0x00, 0x1C });
                PS3.SetMemory(0x00FDF858, new byte[] { 0x41, 0x82, 0xFF, 0x8C });
                StatusSPRX = true;
            }
            else
            {
                MessageBox.Show("Sorry, the SPRX is not installed on your Minecraft", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        #endregion
    }
}
