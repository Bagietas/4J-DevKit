using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DiscordRpcDemo;

namespace MageyTool.Class
{
    internal class Functions
    {
        private DiscordRpc.EventHandlers handlers;
        private DiscordRpc.RichPresence presence;
        public void SetDiscordRPC(string ID, string details, string state, string LargeImageText)
        {
            this.handlers = default(DiscordRpc.EventHandlers);
            DiscordRpc.Initialize(ID, ref this.handlers, true, null);
            this.handlers = default(DiscordRpc.EventHandlers);
            DiscordRpc.Initialize(ID, ref this.handlers, true, null);
            this.presence.details = details;

            System.DateTime epoch = new System.DateTime(1970, 1, 1, 0, 0, 0, System.DateTimeKind.Utc);
            long cur_time = (long)(System.DateTime.UtcNow - epoch).TotalSeconds;

            presence.startTimestamp = cur_time;
            this.presence.state = state;
            this.presence.largeImageKey = "downcraftbymagey";
            this.presence.largeImageText = LargeImageText;
            DiscordRpc.UpdatePresence(ref this.presence);
        }
    }
}
