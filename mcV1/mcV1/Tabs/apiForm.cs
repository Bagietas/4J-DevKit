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
    public partial class apiForm : Form
    {
        public apiForm()
        {
            InitializeComponent();
        }

        private void setColor()
        {
            BackColor = mcV1.Classes.Offsets.saveBackColor;
            button1.BackColor = mcV1.Classes.Offsets.saveBackColor;
            button1.ForeColor = mcV1.Classes.Offsets.saveTextColor;
            button1.FlatAppearance.BorderColor = mcV1.Classes.Offsets.saveThemeColor;

            button4.BackColor = mcV1.Classes.Offsets.saveBackColor;
            button4.ForeColor = mcV1.Classes.Offsets.saveTextColor;
            button4.FlatAppearance.BorderColor = mcV1.Classes.Offsets.saveThemeColor;

            listBox1.BackColor = mcV1.Classes.Offsets.saveBackColor;

            textBox1.BackColor = mcV1.Classes.Offsets.saveBackColor;
            textBox1.ForeColor = mcV1.Classes.Offsets.saveTextColor;

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (mcV1.Classes.Offsets.curAPI == "tm")
                textBox1.Text = Convert.ToString(listBox1.SelectedIndex + 1);
            else if (mcV1.Classes.Offsets.curAPI == "cc")
                textBox1.Text = mcV1.Classes.Offsets.cList[listBox1.SelectedIndex].Ip;
        }

        private void listBox1_DrawItem(object sender, DrawItemEventArgs e)
        {
            if (e.Index < 0) return;
            if ((e.State & DrawItemState.Selected) == DrawItemState.Selected)
                e = new DrawItemEventArgs(e.Graphics,
                                          e.Font,
                                          e.Bounds,
                                          e.Index,
                                          e.State ^ DrawItemState.Selected,
                                          mcV1.Classes.Offsets.saveTextColor,
                                          mcV1.Classes.Offsets.saveThemeColor);

            SolidBrush brush = new SolidBrush(mcV1.Classes.Offsets.saveTextColor);
            e.DrawBackground();
            e.Graphics.DrawString(listBox1.Items[e.Index].ToString(), e.Font, brush, e.Bounds, StringFormat.GenericDefault);
            e.DrawFocusRectangle();
        }

        private void apiForm_Load(object sender, EventArgs e)
        {
            setColor();
            if (mcV1.Classes.Offsets.curAPI == "tm")
                textBox1.Text = "" + mcV1.Classes.Offsets.targetIndex;
            else if (mcV1.Classes.Offsets.curAPI == "cc")
                textBox1.Text = mcV1.Classes.Offsets.ps3IP;
            listBox1.Items.Clear();
            listBox1.Items.AddRange(mcV1.Classes.Offsets.listCT.ToArray());
            label10.Text = mcV1.Classes.Offsets.labelTxtCT;

            if (listBox1.Items.Count != 0)
                listBox1.SelectedIndex = 0;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            mcV1.Classes.Offsets.apiForm_.DialogResult = DialogResult.Cancel;
            Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            try
            {
                if (mcV1.Classes.Offsets.curAPI == "tm")
                    mcV1.Classes.Offsets.targetIndex = Convert.ToInt32(textBox1.Text);
                else if (mcV1.Classes.Offsets.curAPI == "cc")
                    mcV1.Classes.Offsets.ps3IP = textBox1.Text;

                mcV1.Classes.Offsets.apiForm_.DialogResult = DialogResult.OK;
                Close();
            }
            catch
            {
                MessageBox.Show("Invalid Entry!", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
