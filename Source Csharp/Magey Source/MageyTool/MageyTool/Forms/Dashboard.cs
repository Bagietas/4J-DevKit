using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MageyTool
{
    public partial class Dashboard : Form
    {
        MageyTool.Class.Functions FUNCS = new MageyTool.Class.Functions();

        public static Point newpoint = new Point();
        public static int x;
        public static int y;
        public Dashboard()
        {
            InitializeComponent();
        }

        private void Dashboard_Load(object sender, EventArgs e)
        {
            FUNCS.SetDiscordRPC("1003367229842272296", "In the Dashboard", "DownCraft Platinum Edition", "idk");
        }

        private void xMouseDown(object sender, MouseEventArgs e)
        {
            x = Control.MousePosition.X - base.Location.X;
            y = Control.MousePosition.Y - base.Location.Y;
        }

        private void xMouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                newpoint = Control.MousePosition;
                newpoint.X -= x;
                newpoint.Y -= y;
                base.Location = newpoint;
            }
        }

        private void gunaImageButton1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
