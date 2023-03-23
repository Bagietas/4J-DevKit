#region "Library"
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
#endregion

namespace injectSPRX
{
    /*
     build normalement
    décompile en PRX
    rename le fichier en debug_nomdfichier
    resign en HEN
    décompile en PRX
    */

    internal class Program
    {
        #region "Variables"

        public static string debug_folder = AppDomain.CurrentDomain.BaseDirectory + "\\debug";

        WebClient web = new WebClient();
        public static void ConsoleEmpty() { Console.Write("\n"); }
        public static async Task Pause() { await Task.Delay(1000); }

        public static string filename = null;
        public static string ps3IP = null;
        public static string injectPath = null;
        public static string FileForInject = null;
        public static string debug_sprx = null;

        public static bool ps3IP_found = false;

        #endregion
        #region "Get Infos"
        public static void getInfos()
        {
            try
            {
                if (!Directory.Exists(debug_folder)) 
                {
                    Directory.CreateDirectory(debug_folder);
                }

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
                        debug_sprx = array[5];
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
            try
            {
                var PATH = AppDomain.CurrentDomain.BaseDirectory + "\\" + filename + "";
                using (var client = new WebClient())
                {
                    client.Credentials = new NetworkCredential("", "");
                    client.UploadFile("ftp://" + ps3IP + injectPath + FileForInject, WebRequestMethods.Ftp.UploadFile, PATH);
                    client.DownloadString("http://" + ps3IP + "/xmb.ps3$reloadgame");
                }

                Console.Write("[+] Injecting done, the game will restart", Color.White);
            }
            catch(Exception ex) 
            {
                Console.Write("[+] Oops failed to inject to PS3, the application will close...", Color.Red);
                await Task.Delay(5000);
                Environment.Exit(0);
            }
        }

        public async static void debug_output()
        {
            if (debug_sprx == "true") 
            {
                Console.Write("[+] SPRX is now debug, you can find it in the folder debug", Color.White);
                ConsoleEmpty();
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
            ConsoleEmpty();
            inject();
            ConsoleEmpty();
            debug_output();
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
