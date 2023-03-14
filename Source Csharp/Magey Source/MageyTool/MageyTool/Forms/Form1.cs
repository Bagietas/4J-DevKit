using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using KeyAuth;

namespace MageyTool
{
    public partial class Form1 : Form
    {
        static string name = "downcraft";
        static string ownerid = "mBt9tTP1SG";
        static string seceret = "97bf0f3fd4022db9f0cd98aef3b770e51d89853a06caabdc55e8a07e649aa5ba";
        static string version = "1.0";
        public static api KeyAuthApp = new api(name,ownerid, seceret,version);

        public static Point newpoint = new Point();
        public static int x;
        public static int y;

        MageyTool.Class.Functions FUNCS = new MageyTool.Class.Functions();

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

        public Form1()
        {
            InitializeComponent();
            KeyAuthApp.init();
        }

        private void gunaButton1_Click(object sender, EventArgs e)
        {
            KeyAuthApp.login(username.Text, password.Text);
            if (KeyAuthApp.response.success)
            {
                Dashboard main = new Dashboard();
                main.Show();
                this.Hide();
            }
            else
            {
                MessageBox.Show("Oops, wrong username or password.");
            }
        }

        private void gunaButton2_Click(object sender, EventArgs e)
        {
            KeyAuthApp.register(username.Text, password.Text, key.Text);
            if (KeyAuthApp.response.success)
            {
                Dashboard main = new Dashboard();
                main.Show();
                this.Hide();
            }
        }

        private void gunaImageButton1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.gunaImageButton2.MouseDown += this.xMouseDown; //For Move Form
            this.gunaImageButton2.MouseMove += this.xMouseMove; //For Move Form
            this.gunaImageButton2.MouseDown += this.xMouseDown; //For Move Form
            this.gunaImageButton2.MouseMove += this.xMouseMove; //For Move Form

            FUNCS.SetDiscordRPC("1003367229842272296", "Waiting to login...", "DownCraft Platinum Edition", "idk");
        }
    }
}
