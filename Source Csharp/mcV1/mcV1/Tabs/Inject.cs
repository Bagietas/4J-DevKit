using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace mcV1.Tabs
{
    public partial class Inject : Form
    {
        mcV1.Classes.Offsets OFFSETS = new mcV1.Classes.Offsets();
        mcV1.Classes.Functions FUNCTIONS = new mcV1.Classes.Functions();

        public Inject()
        {
            InitializeComponent();
        }

        private async void guna2Button5_Click(object sender, EventArgs e)
        {
            if (!mcV1.Classes.Offsets.Injected)
            {
                label1.ForeColor = Color.Salmon;
                label1.Text = "Injecting...";
                OFFSETS.INJECT_SPRX_IN_PS3();
                label1.Text = "Reloading the game...";
                await Task.Delay(30000);
                label1.ForeColor = Color.Orange;
                label1.Text = "Waiting for enable SPRX";
            }
            else
            {
                MessageBox.Show("You have already injected DownCraft SPRX, restart the application for reinject it.", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void guna2Button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("How to use it ?\n\n(NOTE: You need to have WebMAN Mod installed on your PS3 before inject the SPRX)\n\nStart your Minecraft (BLES01976 ONLY)\n\nWhen you are in Minecraft menu, connect the tool to your PS3 using (CCAPI, TMAPI, HEN).\n\nthen press 'Inject SPRX', wait 1-2 min (depends of your internet connection).\n\nWhen it's done, the game will restart when you are in the Minecraft menu again, join a random world and connect the tool to your console again.\n\nEnable 'Enable SPRX' and wait, the SPRX will be enabled in your game.\n\nMade By Misaki", "DownCraft", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void guna2CheckBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (guna2CheckBox1.Checked)
            {
                OFFSETS.ENABLE_SPRX();

                if (mcV1.Classes.Offsets.StatusSPRX == true)
                {
                    label1.ForeColor = Color.Green;
                    label1.Text = "SPRX Enabled";
                }
            }
        }

        private void Inject_Load(object sender, EventArgs e)
        {
            if (mcV1.Classes.Offsets.StatusSPRX == true)
            {
                label1.ForeColor = Color.Green;
                label1.Text = "SPRX Enabled";
            }
        }
    }
}
