using Colorful;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;
using Console = Colorful.Console;

namespace injectSPRX
{
    internal class Program
    {
        #region "Variables"

        WebClient web = new WebClient();
        public static void ConsoleEmpty() { Console.Write("\n"); }
        public static async Task Pause() { await Task.Delay(1000); }

        public static string filename = null;
        public static string ps3IP = null;
        public static string injectPath = null;
        public static string FileForInject = null;

        public static bool ps3IP_found = false;

        #endregion
        #region "Get Infos"
        public static void getInfos()
        {
            try
            {
                string text = AppDomain.CurrentDomain.BaseDirectory + "\\settings.txt";

                if (File.Exists(text))
                {
                    string[] array = File.ReadAllLines(text);
                    if (array[0].EndsWith("useLoader=true"))
                    {
                        ps3IP = array[1];
                        filename = array[2];
                        FileForInject = array[3];
                        injectPath = array[4];
                    }
                }
            }
            catch(Exception ex)
            {

            }
          
        }

        #endregion
        #region "inject SPRX"
        public async static void inject()
        {
            var PATH = AppDomain.CurrentDomain.BaseDirectory + "\\" + filename + "";
            using (var client = new WebClient())
            {
                client.Credentials = new NetworkCredential("", "");
                client.UploadFile("ftp://" + ps3IP + injectPath + FileForInject, WebRequestMethods.Ftp.UploadFile, PATH);
                client.DownloadString("http://" + ps3IP + "/xmb.ps3$reloadgame");
            }
        }

        internal static async void InjectSPRX()
        {
            getInfos();
            Console.Title = "SPRX Injector by Misaki";
            Console.WriteAscii("   " + "SPRX Injector", Color.DarkMagenta);
            ConsoleEmpty();
            Console.Write("[!] Welcome to SPRX Injector, made by Misaki.", Color.White);
            ConsoleEmpty();
            ConsoleEmpty();
            Console.Write("[!] This app has been created for inject any SPRX after build on VS.", Color.Green);
            ConsoleEmpty();
            ConsoleEmpty();
            Console.Write("[+] Checking file to inject...", Color.White);
            ConsoleEmpty();
            Console.Write("[+] File found: ", Color.White);
            Console.Write(filename, Color.Green);
            ConsoleEmpty();
            Console.Write("[+] Starting connection to PS3: ", Color.White);
            Console.Write(ps3IP, Color.Green);
            ConsoleEmpty();
            Console.Write("[+] Connected to PS3, starting injecting to: ", Color.White);
            Console.Write(injectPath, Color.Green);
            inject();
            ConsoleEmpty();
            Console.Write("[+] Injecting done, the game will restart", Color.White);
            ConsoleEmpty();
            Console.Write("[+] The app will auto close in 10 seconds...", Color.White);

            await Task.Delay(10000);
            Environment.Exit(0);
        }

        #endregion
        #region "Main"
        static void Main(string[] args)
        {
            InjectSPRX();
            Console.ReadLine();
        }
        #endregion
    }
}
