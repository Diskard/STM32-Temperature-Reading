using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Windows.Forms.DataVisualization.Charting;
using System.Threading;
using System.Reflection.Emit;
using System.Collections;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;


namespace swj_winforms
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;
            serialPort1.DataReceived += new SerialDataReceivedEventHandler(port_DataReceived);
            serialPort1.Encoding = Encoding.GetEncoding("GB2312");
            System.Windows.Forms.Control.CheckForIllegalCrossThreadCalls = false;
            chart1.Series.Add("line1");//折线图创建图线
            chart1.Series["line1"].Color = Color.Green;
            this.chart1.ChartAreas[0].AxisY.Minimum = 30;
            this.chart1.ChartAreas[0].AxisY.Maximum = 40;
            this.chart1.ChartAreas[0].AxisX.Minimum = 0;
            this.chart1.ChartAreas[0].AxisX.Maximum = 90;
            chart1.Series["line1"].ChartType = SeriesChartType.Line;

        }
        //------------图表绘制------------------//
        void chart_display()
        {
            Draw();
        }
        delegate void my_delegate();//创建一个代理,图表刷新需要在主线程，所以需要加委托
        Queue<double> Q1 = new Queue<double>();
        public void Draw()
        {
            if (!chart1.InvokeRequired)
            {
                this.chart1.Series["line1"].Points.Clear();
                for (int i = 0; i < FFF_chart.Length; i++)
                {
                    chart1.Series["line1"].Points.AddXY(i, FFF_chart[i]);
                }
            }
            else
            {
                my_delegate delegate_FFF = new my_delegate(Draw);
                Invoke(delegate_FFF, new object[] { });//执行唤醒操作
            }
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            SearchAnAddSerialToComboBox(serialPort1, comboBox1);
        }
        private void SearchAnAddSerialToComboBox(SerialPort MyPort, ComboBox MyBox)//搜索串口函数
        { //将可用的串口号添加到ComboBox
            string[] NmberOfport = new string[20];//最多容纳20个，太多会卡，影响效率
            string MidString1;//中间数组，用于缓存
            MyBox.Items.Clear();//清空combobox的内容
            for (int i = 1; i < 20; i++)
            {
                try //核心是靠try和catch 完成遍历
                {
                    MidString1 = "COM" + i.ToString();  //把串口名字赋给MidString1
                    MyPort.PortName = MidString1;       //把MidString1赋给 MyPort.PortName 
                    MyPort.Open();                      //如果失败，后面代码不执行？？
                    NmberOfport[i - 1] = MidString1;    //依次把MidString1的字符赋给NmberOfport
                    MyBox.Items.Add(MidString1);        //打开成功，添加到下列列表
                    MyPort.Close();                     //关闭
                    MyBox.Text = NmberOfport[i - 1];    //显示最后扫描成功那个串口
                }
                catch { };
            }
        }
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (button2.Text == "打开串口")//为0时，表示关闭，此时可以进行打开操作
            {
                try
                {
                    serialPort1.PortName = comboBox1.Text;//获取端口号
                    serialPort1.BaudRate = Convert.ToInt32(comboBox2.Text);//设置波特率
                    serialPort1.Open();//打开串口
                    button2.Text = " 关闭串口";
                }
                catch
                {
                    MessageBox.Show("串口打开错误");
                }
            }
            else  //为1时，表示开启，此时可以进行关闭操作
            {
                try
                {
                    serialPort1.Close();//关闭串口
                    button2.Text = "打开串口";//置位为0，表示状态为关闭
                }
                catch { }
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            //ComponentResourceManager resources = new ComponentResourceManager(typeof(Form1));
            //this.pictureBox1.Image = ((Image)(resources.GetObject("Image")));
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            FFF_chart = new double[90];
        }

        //-----------------数据接收部分--------------------//
        byte[] buf; ////缓冲数组
        public double[] FFF_chart;
        public double Std_Temperature = 37.0;
        bool flag = false;
        string str;
        private void port_DataReceived(object sender, SerialDataReceivedEventArgs e)//接收函数  SerialDataReceivedEventArgs写错，导致错误，谨记
        {
            Thread chart_display_th = new Thread(new ThreadStart(chart_display));////////数值显示线程
            chart_display_th.Start();
            try
            {
                buf = new byte[serialPort1.BytesToRead];//定义缓冲数组
                serialPort1.Read(buf, 0, buf.Length);

                if (buf.Length >= 3 && buf[0] == 'T' && buf[1] == 'E' && buf[2] == 'M')// && buf[29] == 122 && buf[30] == 122 && buf[31] == 122
                {
                    for (int count_i = 0; count_i < 89; count_i++)
                    { FFF_chart[count_i] = FFF_chart[count_i + 1]; }
                    FFF_chart[89] = (buf[3] - 48)*10 + (buf[4] - 48) + (buf[6] - 48)*0.1 + (buf[7] - 48) * 0.01;
                    if (FFF_chart[89] > Std_Temperature)
                    {
                        chart1.Series["line1"].Color = Color.Red;
                        if (flag == false)
                        {
                            MessageBox.Show("温度过高", "警告Warning");
                            flag = true;
                        }
                    }
                    else if (FFF_chart[89] <= Std_Temperature)
                    {
                        chart1.Series["line1"].Color = Color.Green;
                    }
                    else if (FFF_chart[89] <= Std_Temperature - 2) flag = false;


                    if (buf[9] == '1') Is_LED_Wink.Checked = true;
                    else if(buf[8] == '0') Is_LED_Wink.Checked = false;

                    if (buf[11] == '1') Is_LED_Breath.Checked = true;
                    else if(buf[9] == '0') Is_LED_Breath.Checked = false;

                    Is_LED_Off.Checked = LED_Close.Checked;

                    Is_Beep_Off.Checked = BeepOFF.Checked;
                    Is_Beep_On.Checked = BeepON.Checked;

                    /*str = System.Text.Encoding.Default.GetString(buf);
                    textBox1.AppendText(str);
                    textBox1.AppendText("\r\n");*/
                }

            }
            catch { }
        }

        private void LED_Open_CheckedChanged(object sender, EventArgs e)
        {
            if (LED_Open.Checked)
            {
                byte[] buffer = new byte[6];
                buffer[0] = (byte)'L'; buffer[1] = (byte)'E'; buffer[2] = (byte)'D';
                buffer[3] = (byte)'1';
                buffer[4] = 0x0D; buffer[5] = 0x0A;
                try
                {
                    serialPort1.Write(buffer, 0, 6);
                }
                catch
                {
                    if (!serialPort1.IsOpen)
                        MessageBox.Show("端口错误", "错误");
                }
            }
            /*
             LED开，此时向单片机发送"LED1"
             */
        }

        private void LED_Close_CheckedChanged(object sender, EventArgs e)
        {
            /*
             LED关，此时向单片机发送"LED0"
             */
            if (LED_Close.Checked)
            {
                byte[] buffer = new byte[6];
                buffer[0] = 76; buffer[1] = 69; buffer[2] = 68;
                buffer[3] = 48;
                buffer[4] = 0x0D; buffer[5] = 0x0A;
                try
                {
                    serialPort1.Write(buffer, 0, 6);
                    //serialPort1.Close();

                }
                catch
                {
                    if (serialPort1.IsOpen)
                        MessageBox.Show("端口错误", "错误");
                    if (!serialPort1.IsOpen)
                        MessageBox.Show("端口未开", "错误");
                }
            }

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void PlayA_Click(object sender, EventArgs e)
        {
            //"BEP2"
            byte[] buffer = new byte[6];
            buffer[0] = (byte)'B'; buffer[1] = (byte)'E'; buffer[2] = (byte)'P';
            buffer[3] = (byte)'2';
            buffer[4] = 0x0D; buffer[5] = 0x0A;
            try
            {
                serialPort1.Write(buffer, 0, 6);
            }
            catch
            {
                if (!serialPort1.IsOpen)
                    MessageBox.Show("端口错误", "错误");
            }
        }

        private void PlayB_Click(object sender, EventArgs e)
        {
            //"BEP3"
            byte[] buffer = new byte[6];
            buffer[0] = (byte)'B'; buffer[1] = (byte)'E'; buffer[2] = (byte)'P';
            buffer[3] = (byte)'3';
            buffer[4] = 0x0D; buffer[5] = 0x0A;
            try
            {
                serialPort1.Write(buffer, 0, 6);
            }
            catch
            {
                if (!serialPort1.IsOpen)
                    MessageBox.Show("端口错误", "错误");
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            /*
             LED呼吸灯，此时向单片机发送"LED2"
             */
            byte[] buffer = new byte[6];
            buffer[0] = (byte)'L'; buffer[1] = (byte)'E'; buffer[2] = (byte)'D';
            buffer[3] = (byte)'2';
            buffer[4] = 0x0D; buffer[5] = 0x0A;
            try
            {
                serialPort1.Write(buffer, 0, 6);
            }
            catch
            {
                if (!serialPort1.IsOpen)
                    MessageBox.Show("端口错误", "错误");
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            /*
             LED闪烁，此时向单片机发送"LED3"
             */
            byte[] buffer = new byte[6];
            buffer[0] = (byte)'L'; buffer[1] = (byte)'E'; buffer[2] = (byte)'D';
            buffer[3] = (byte)'3';
            buffer[4] = 0x0D; buffer[5] = 0x0A;
            try
            {
                serialPort1.Write(buffer, 0, 6);
            }
            catch
            {
                if (!serialPort1.IsOpen)
                    MessageBox.Show("端口错误", "错误");
            }
        }

        private void BeepON_CheckedChanged(object sender, EventArgs e)
        {
            if(BeepON.Checked)
            {
                byte[] buffer = new byte[6];
                buffer[0] = (byte)'B'; buffer[1] = (byte)'E'; buffer[2] = (byte)'P';
                buffer[3] = (byte)'1';
                buffer[4] = 0x0D; buffer[5] = 0x0A;
                try
                {
                    serialPort1.Write(buffer, 0, 6);
                }
                catch
                {
                    if (!serialPort1.IsOpen)
                        MessageBox.Show("端口错误", "错误");
                }
            }
            //蜂鸣器开，发送"BEP1"
        }

        private void BeepOFF_CheckedChanged(object sender, EventArgs e)
        {
            if(BeepOFF.Checked)
            {
                //蜂鸣器关，发送"BEP0"
                byte[] buffer = new byte[6];
                buffer[0] = (byte)'B'; buffer[1] = (byte)'E'; buffer[2] = (byte)'P';
                buffer[3] = (byte)'0';
                buffer[4] = 0x0D; buffer[5] = 0x0A;
                try
                {
                    serialPort1.Write(buffer, 0, buffer.Length);
                }
                catch
                {
                    if (!serialPort1.IsOpen)
                        MessageBox.Show("端口错误", "错误");
                }
            }

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button6_Click(object sender, EventArgs e)
        {

        }

        private void groupBox3_Enter(object sender, EventArgs e)
        {

        }

        private void Alarm_On_CheckedChanged(object sender, EventArgs e)
        {
            if (AlarmOn.Checked)
            {
                //警报开，发送"ALM1"
                byte[] buffer = new byte[6];
                buffer[0] = (byte)'A'; buffer[1] = (byte)'L'; buffer[2] = (byte)'M';
                buffer[3] = (byte)'1';
                buffer[4] = 0x0D; buffer[5] = 0x0A;
                try
                {
                    serialPort1.Write(buffer, 0, buffer.Length);
                    LED_Open.Checked = true;
                    BeepON.Checked = true;
                }
                catch
                {
                    if (!serialPort1.IsOpen)
                        MessageBox.Show("端口错误", "错误");
                }
            }
        }

        private void AlarmOff_CheckedChanged(object sender, EventArgs e)
        {
            if (AlarmOff.Checked)
            {
                //警报开，发送"ALM1"
                byte[] buffer = new byte[6];
                buffer[0] = (byte)'A'; buffer[1] = (byte)'L'; buffer[2] = (byte)'M';
                buffer[3] = (byte)'0';
                buffer[4] = 0x0D; buffer[5] = 0x0A;
                try
                {
                    serialPort1.Write(buffer, 0, buffer.Length);
                }
                catch
                {
                    if (!serialPort1.IsOpen)
                        MessageBox.Show("端口错误", "错误");
                }
            }
        }

        private void progressBar1_Click(object sender, EventArgs e)
        {

        }

        private void Is_LED_Breath_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void Is_LED_Off_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void Is_LED_Wink_CheckedChanged(object sender, EventArgs e)
        {

        }

        //-----------串口数据接收------------//
        /*private void port_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                string recive_data;
                recive_data = serialPort1.ReadExisting();
                textBox1.AppendText(recive_data);
                textBox1.AppendText("\r\n");
            }
            catch { }
        }*/
    }
}
