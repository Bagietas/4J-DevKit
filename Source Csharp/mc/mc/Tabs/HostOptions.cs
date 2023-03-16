using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace mc.Tabs
{
    public partial class HostOptions : Form
    {
        Offsets OFFSETS = new Offsets();
        public HostOptions()
        {
            InitializeComponent();
        }

        private void guna2ToggleSwitch1_CheckedChanged(object sender, EventArgs e)
        {
            if (guna2ToggleSwitch1.Checked)
            {
                OFFSETS.GOD_MODE(true);
            }
            else
            {
                OFFSETS.GOD_MODE(false);
            }
        }
    }
}
