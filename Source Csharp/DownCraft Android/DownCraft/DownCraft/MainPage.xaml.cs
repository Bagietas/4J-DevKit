using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;
using PS3ManagerAPI;
using System.IO;
using WebHook;

namespace DownCraft
{
    public partial class MainPage : ContentPage
    {
        public string IP = "192.168.1.1";
        public uint[] ProcessID;
        public string PSN_NAME = "//";

        public bool Connected = false;

        WebClient Request = new WebClient();
        Webz1 WebHook1 = new Webz1();
        PS3MAPI PS3 = new PS3MAPI();

        public MainPage()
        {
            InitializeComponent();
        }

        #region "Functions & Utility"

        public void SendLogsConnect(string URL, string username, string avatar, string message)
        {
            WebHook1.SendMessage(URL, username, avatar, message);
        }

        public void MessageBox(string title, string message, string button)
        {
            Application.Current.MainPage.DisplayAlert(title, message, button);
        }

        #endregion

        private void Button_Clicked(object sender, EventArgs e)
        {
            if (!Connected)
            {
                Connected = true;
                IP = PS3IP.Text;
                PS3.ConnectTarget(IP);
                PSN_NAME = PS3.Process.Memory.ReadString(ProcessID[0], 0x3000AD34, 16);

                if (PSN_NAME == "")
                {
                    PSN_NAME = PS3.Process.Memory.ReadString(ProcessID[0], 0x3000ABA4, 16);
                }

                PS3.PS3.Notify("Welcome to DownCraft Android!");
                SendLogsConnect("", "DownCraft Logs", "https://i.imgur.com/CnDRlA9.jpg", "```User: " + PSN_NAME + " is now connected to DownCraft Android.```");
                BtnConnect.Text = "Connected";
                MessageBox("DownCraft", "Connected to PS3!", "OK");
            }
            else
            {

            }
        }

        protected void God_Mode_Clicked(object sender, EventArgs e)
        {
            if (God_Mode.IsChecked)
            {
                PS3.PS3.Notify("God Mode: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x004B2021, new byte[] { 0x80 });
            }
            else
            {
                PS3.PS3.Notify("God Mode: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x004B2021, new byte[] { 0x20 });
            }
        }

        protected void Instant_Damage_Clicked(object sender, EventArgs e)
        {
            if (Instant_Damage.IsChecked)
            {
                PS3.PS3.Notify("Instant Damage: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x003A3FF0, new byte[] { 0x40, 0x80 });
            }
            else
            {
                PS3.PS3.Notify("Instant Damage: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x003A3FF0, new byte[] { 0x3F, 0x00 });
            }
        }
        protected void KnockBack_Clicked(object sender, EventArgs e)
        {
            if (KnockBack.IsChecked)
            {
                PS3.PS3.Notify("Knockback: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x003A4018, new byte[] { 0x40, 0x80 });
            }
            else
            {
                PS3.PS3.Notify("Knockback: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x003A4018, new byte[] { 0x3E, 0xCC });
            }
        }

        protected void Infinite_Pickup_Clicked(object sender, EventArgs e)
        {
            if (Infinite_Pickup.IsChecked)
            {
                PS3.PS3.Notify("Infinite Pickup: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x00224B13, new byte[] { 0x00 });
            }
            else
            {
                PS3.PS3.Notify("Infinite Pickup: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x00224B13, new byte[] { 0x01 });
            }
        }

        protected void Fast_Bow_Clicked(object sender, EventArgs e)
        {
            if (Fast_Bow.IsChecked)
            {
                PS3.PS3.Notify("Fast Bow: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x000FB4C5, new byte[] { 0xE0, 0x18, 0x18 });
            }
            else
            {
                PS3.PS3.Notify("Fast Bow: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x000FB4C5, new byte[] { 0xE0, 0x08, 0x18 });
            }
        }
        protected void Super_Speed_Clicked(object sender, EventArgs e)
        {
            if (Super_Speed.IsChecked)
            {
                PS3.PS3.Notify("Super Speed: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x003ABD49, new byte[] { 0xFF, 0xFF, 0xFF });
            }
            else
            {
                PS3.PS3.Notify("Super Speed: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x003ABD49, new byte[] { 0x26, 0xAD, 0x89 });
            }
        }
        protected void Super_Jump_Clicked(object sender, EventArgs e)
        {
            if (Super_Jump.IsChecked)
            {
                PS3.PS3.Notify("Super Jump: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x003AA77C, new byte[] { 0x3F });
            }
            else
            {
                PS3.PS3.Notify("Super Jump: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x003AA77C, new byte[] { 0x3E });
            }
        }
        protected void Night_Vision_Clicked(object sender, EventArgs e)
        {
            if (Night_Vision.IsChecked)
            {
                PS3.PS3.Notify("Night Vision: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x00A9A6C8, new byte[] { 0x7F });
            }
            else
            {
                PS3.PS3.Notify("Night Vision: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x00A9A6C8, new byte[] { 0x3F });
            }
        }

        protected void No_Colission_Clicked(object sender, EventArgs e)
        {
            if (No_Colission.IsChecked)
            {
                PS3.PS3.Notify("No Colission: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x002271B0, new byte[] { 0x40 });
            }
            else
            {
                PS3.PS3.Notify("No Colission: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x002271B0, new byte[] { 0x41 });
            }
        }

        protected void Small_Velocity_Clicked(object sender, EventArgs e)
        {
            if (Small_Velocity.IsChecked)
            {

            }
            else
            {

            }
        }

        protected void Swim_Fly_Clicked(object sender, EventArgs e)
        {
            if (Swim_Fly.IsChecked)
            {
                PS3.PS3.Notify("Swim Fly: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x00390410, new byte[] { 0x3B, 0x40, 0x00, 0x10 });
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x003ABD44, new byte[] { 0x3D });
            }
            else
            {
                PS3.PS3.Notify("Swim Fly: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x00390410, new byte[] { 0x3B, 0x40, 0x00, 0x00 });
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x003ABD44, new byte[] { 0x3C });
            }
        }
        protected void Kill_Aura_Clicked(object sender, EventArgs e)
        {
            if (Kill_Aura.IsChecked)
            {
                PS3.PS3.Notify("Kill Aura: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x00233290, new byte[] { 0xFF });
            }
            else
            {
                PS3.PS3.Notify("Kill Aura: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x00233290, new byte[] { 0x00 });
            }
        }
        protected void Can_Fly_Clicked(object sender, EventArgs e)
        {
            if (Can_Fly.IsChecked)
            {
                PS3.PS3.Notify("Can Fly: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x00B02378, new byte[] { 0x40 });
            }
            else
            {
                PS3.PS3.Notify("Can Fly: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x00B02378, new byte[] { 0x41 });
            }
        }

        protected void Infinite_Craft_Clicked(object sender, EventArgs e)
        {
            if (Infinite_Craft.IsChecked)
            {
                PS3.PS3.Notify("Infinite Craft: ON");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x0098871F, new byte[] { 0x01 });
            }
            else
            {
                PS3.PS3.Notify("Infinite Craft: OFF");
                PS3.Process.Memory.SetMemory(ProcessID[0], 0x0098871F, new byte[] { 0x00 });
            }
        }

        protected void Special_Items_Clicked(object sender, EventArgs e)
        {
            if (Special_Items.IsChecked)
            {
                PS3.PS3.Notify("Check your inventory creative\nYou have now some special items !");
            }
            else
            {
               
            }
        }

        private void SetNameChanger_Clicked(object sender, EventArgs e)
        {
            byte[] bytes = Encoding.ASCII.GetBytes(NameChanger.Text + "");
            PS3.Process.Memory.SetMemory(ProcessID[0], 0x3000ABE4, bytes);
            PS3.Process.Memory.SetMemory(ProcessID[0], 0x3000ABA4, bytes);
            PS3.PS3.Notify("New name has been set, rejoin the world.");
        }
    }
}
