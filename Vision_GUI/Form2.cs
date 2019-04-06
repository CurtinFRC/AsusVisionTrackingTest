using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using AForge.Video;

namespace Vision_GUI
{
    public partial class Form2 : Form
    {
        MJPEGStream localhost;
        MJPEGStream curtinvision;
        public Form2()
        {
            InitializeComponent();
            localhost = new MJPEGStream("http://localhost:1181/stream.mjpg");
            localhost.NewFrame += localhost_NewFrame;

            curtinvision = new MJPEGStream("http://curtinvision.local:1181/stream.mjpeg");
            curtinvision.NewFrame += curtinvision_NewFrame;
        }

        void localhost_NewFrame(object sender, NewFrameEventArgs eventArgs)
        {
            Bitmap lcl = (Bitmap)eventArgs.Frame.Clone();
            pictureBox1.Image = lcl;
        }

        void curtinvision_NewFrame(object sender, NewFrameEventArgs eventArgs)
        {
            Bitmap bmp = (Bitmap)eventArgs.Frame.Clone();
            pictureBox1.Image = bmp;
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
       
        }

        private void button2_Click(object sender, EventArgs e)
        {
            localhost.Start();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            curtinvision.Start();
        }
    }
}
