using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Window;

namespace Minecraft_Draw_UI
{
    public partial class Form1 : Form
    {
        int HudX;
        int HudY;
        int HudWidth;
        int HudHeight;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        void CreateNewHud()
        {

        }

        private void button5_Click(object sender, EventArgs e)
        {
            HudX = Int16.Parse(textBox1.Text);
            HudY = Int16.Parse(textBox2.Text);

            panel1.Location = new Point(HudX, HudY);
        }

        private void domainUpDown1_SelectedItemChanged(object sender, EventArgs e)
        {
            HudX += 1;
            panel1.Location = new Point(HudX, HudY);
        }
    }
}
