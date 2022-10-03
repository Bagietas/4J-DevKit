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
    public partial class Connect : Form
    {
        mcV1.Classes.Offsets OFFSETS = new mcV1.Classes.Offsets();
        mcV1.Classes.Functions FUNCTIONS = new mcV1.Classes.Functions();
        public Connect()
        {
            InitializeComponent();
        }

        private void Connect_Load(object sender, EventArgs e)
        {
            label1.Text = mcV1.Classes.Offsets.PSN_NAME;
            label5.Text = mcV1.Classes.Offsets.CPU;
            label3.Text = mcV1.Classes.Offsets.RSX;
            label8.Text = mcV1.Classes.Offsets.FIRMWARE;
            label10.Text = mcV1.Classes.Offsets.API;
        }

        private void guna2Button2_Click(object sender, EventArgs e)
        {
            if (guna2RadioButton1.Checked)
                mcV1.Classes.Offsets.API = "CCAPI";
            else if (guna2RadioButton2.Checked)
                mcV1.Classes.Offsets.API = "TMAPI";
            else if (guna2RadioButton3.Checked)
                mcV1.Classes.Offsets.API = "HEN";

            OFFSETS.ChangeAPI();
            OFFSETS.doConnect();

            label1.Text = mcV1.Classes.Offsets.PSN_NAME;
            label5.Text = mcV1.Classes.Offsets.CPU;
            label3.Text = mcV1.Classes.Offsets.RSX;
            label8.Text = mcV1.Classes.Offsets.FIRMWARE;
            label10.Text = mcV1.Classes.Offsets.API;
        }

        private void guna2GroupBox1_Click(object sender, EventArgs e)
        {

        }

        private void guna2Button3_Click(object sender, EventArgs e)
        {

        }
    }
}
