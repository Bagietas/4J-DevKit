using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace WebHook
{
    public class Webz1
    {
        private static NameValueCollection discordValues = new NameValueCollection();
        WebClient Web1 = new WebClient();
        public void SendMessage(string URL, string username, string avatar, string message)
        {
            discordValues.Add("username", username);
            discordValues.Add("avatar_url", avatar);
            discordValues.Add("content", message);

            Web1.UploadValues(URL, discordValues);
        }
    }

    public class Webz2
    {
        private static NameValueCollection discordValues = new NameValueCollection();
        WebClient Web2 = new WebClient();
        public void SendMessage(string URL, string username, string avatar, string message)
        {
            discordValues.Add("username", username);
            discordValues.Add("avatar_url", avatar);
            discordValues.Add("content", message);

            Web2.UploadValues(URL, discordValues);
        }
    }
}