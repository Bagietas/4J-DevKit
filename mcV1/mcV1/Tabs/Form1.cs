using mcV1.Classes;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace mcV1
{
    public partial class Form1 : Form
    {
        public static Thread Process = new Thread(new ThreadStart(Functions.CheckBadProcess));

        public static Point newpoint = new Point();
        public static int x;
        public static int y;
        
        mcV1.Classes.Offsets OFFSETS = new mcV1.Classes.Offsets();

        public Form1()
        {
            InitializeComponent();
        }

        #region "System Move Title Panel"
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
        #endregion

        private void Form1_Load(object sender, EventArgs e)
        {
            this.gunaGradient2Panel1.MouseDown += this.xMouseDown;
            this.gunaGradient2Panel1.MouseMove += this.xMouseMove;
            this.gunaGradient2Panel1.MouseDown += this.xMouseDown;
            this.gunaGradient2Panel1.MouseMove += this.xMouseMove;

            Process.Start();
        }

        private void guna2Button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void guna2Button2_Click(object sender, EventArgs e)
        {
            OFFSETS.ChangeAPI();
            OFFSETS.doConnect();

            if (mcV1.Classes.Offsets.ConnectStatus == true)
            {
                //guna2Button1.ForeColor = Color.FromArgb(FUNCS.RED, FUNCS.GREEN, FUNCS.BLUE);
            }
        }
    }
}
