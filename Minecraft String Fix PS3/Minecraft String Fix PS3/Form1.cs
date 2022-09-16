using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Minecraft_String_Fix_PS3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        public string fixString(string fixStr)
        {
            int length = fixStr.Length;
            int startIndex = 1;
            int num3 = 0;
            while (true)
            {
                if (num3 >= length)
                {
                    fixStr = fixStr.Replace(".", "");
                    return (fixStr + "");
                }
                fixStr = fixStr.Insert(startIndex, ".");
                startIndex += 2;
                num3++;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = fixString(textBox1.Text);
        }
    }
}
