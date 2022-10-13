using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace RPCS3_Memory_Writer
{
    public partial class Form1 : Form
    {
        #region "Variables"

        string TMP = Path.GetTempPath() + "PS3";
        const string MAKE = "make.exe";
        public static string MINECRAFT = "EBOOT.ELF";

        #endregion
        #region "Functions"

        BinaryWriter bn;
        SaveFileDialog sv;

        void ExecCmd(string file, string arg)
        {
            Process pro = new Process();
            pro.StartInfo.FileName = file;
            pro.StartInfo.WorkingDirectory = TMP;
            pro.StartInfo.Arguments = arg;
            pro.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
            pro.StartInfo.CreateNoWindow = true;
            pro.StartInfo.UseShellExecute = false;
            pro.Start();
            pro.WaitForExit();
        }

        void PatchOffset(uint Offset, byte[] value)
        {
            bn.Seek((int)Offset, SeekOrigin.Begin);
            bn.Write(value);
            bn.Flush();
            Application.DoEvents();
        }

        void LoadFiles(string path, byte[] fileBytes)
        {
            File.WriteAllBytes(path, fileBytes);
        }
        public static byte[] StringToByteArray(String hex)
        {
            int NumberChars = hex.Length;
            byte[] bytes = new byte[NumberChars / 2];
            for (int i = 0; i < NumberChars; i += 2)
                bytes[i / 2] = Convert.ToByte(hex.Substring(i, 2), 16);
            return bytes;
        }

        #endregion

        public Form1()
        {
            InitializeComponent();
        }

        #region "Form Load / Close"

        private void Form1_Load(object sender, EventArgs e)
        {
            if (!Directory.Exists(TMP))
            {
                Directory.CreateDirectory(TMP);
            }

            if (!File.Exists(TMP + MAKE))
            {
                LoadFiles(TMP + MAKE, Properties.Resources.make);
            }
            if (!File.Exists(TMP + MINECRAFT))
            {
                LoadFiles(TMP + MINECRAFT, Properties.Resources.EBOOT);
            }
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Directory.Delete(TMP, true);
        }

        #endregion
        #region "Button"
        void BuildEBOOT()
        {
            bn.Close();

            String UserName = Environment.UserName;
            sv = new SaveFileDialog();
            sv.InitialDirectory = @"C:\Users\" + UserName + @"\Desktop";
            sv.FileName = "EBOOT";
            sv.Filter = "EBOOT.BIN|*.BIN";

            if (sv.ShowDialog() == DialogResult.OK)
            {
                ExecCmd(TMP + MAKE, TMP + MINECRAFT + " " + sv.FileName);
            }

            File.Delete(TMP + MINECRAFT);
            LoadFiles(TMP + MINECRAFT, Properties.Resources.EBOOT);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            uint address = Convert.ToUInt32(textBox1.Text, 16);
            byte[] byteArray = StringToByteArray(textBox2.Text);

            try
            {
                bn = new BinaryWriter(File.Open(TMP + MINECRAFT, FileMode.Open, FileAccess.Write));
                PatchOffset(address, new byte[] { byteArray[0], byteArray[1], byteArray[2], byteArray[3] });
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.ToString());
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            BuildEBOOT();
        }

        #endregion
    }
}
