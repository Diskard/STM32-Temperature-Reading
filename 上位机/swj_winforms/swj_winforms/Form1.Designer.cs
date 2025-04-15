namespace swj_winforms
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea3 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend3 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series3 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.label2 = new System.Windows.Forms.Label();
            this.comboBox2 = new System.Windows.Forms.ComboBox();
            this.button3 = new System.Windows.Forms.Button();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.button4 = new System.Windows.Forms.Button();
            this.LED_Open = new System.Windows.Forms.RadioButton();
            this.LED_Close = new System.Windows.Forms.RadioButton();
            this.button5 = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.PlayB = new System.Windows.Forms.Button();
            this.BeepOFF = new System.Windows.Forms.RadioButton();
            this.BeepON = new System.Windows.Forms.RadioButton();
            this.PlayA = new System.Windows.Forms.Button();
            this.AlarmOn = new System.Windows.Forms.RadioButton();
            this.AlarmOff = new System.Windows.Forms.RadioButton();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.Is_LED_Off = new System.Windows.Forms.RadioButton();
            this.Is_LED_Breath = new System.Windows.Forms.RadioButton();
            this.Is_LED_Wink = new System.Windows.Forms.RadioButton();
            this.LED_Mode = new System.Windows.Forms.GroupBox();
            this.Is_Beep_On = new System.Windows.Forms.RadioButton();
            this.Is_Beep_Off = new System.Windows.Forms.RadioButton();
            this.Beep_Mode = new System.Windows.Forms.GroupBox();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.LED_Mode.SuspendLayout();
            this.Beep_Mode.SuspendLayout();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(1204, 263);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(184, 132);
            this.textBox1.TabIndex = 0;
            this.textBox1.Visible = false;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("宋体", 10F);
            this.button1.Location = new System.Drawing.Point(27, 37);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(280, 44);
            this.button1.TabIndex = 1;
            this.button1.Text = "扫描串口";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(113, 114);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(194, 26);
            this.comboBox1.TabIndex = 2;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("宋体", 12F);
            this.label1.Location = new System.Drawing.Point(33, 116);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(58, 24);
            this.label1.TabIndex = 3;
            this.label1.Text = "端口";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("宋体", 10F);
            this.button2.Location = new System.Drawing.Point(27, 232);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(280, 44);
            this.button2.TabIndex = 4;
            this.button2.Text = "打开串口";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // serialPort1
            // 
            this.serialPort1.PortName = "COM7";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("宋体", 12F);
            this.label2.Location = new System.Drawing.Point(25, 172);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 24);
            this.label2.TabIndex = 6;
            this.label2.Text = "波特率";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // comboBox2
            // 
            this.comboBox2.FormattingEnabled = true;
            this.comboBox2.Items.AddRange(new object[] {
            "115200",
            "9600",
            "4800"});
            this.comboBox2.Location = new System.Drawing.Point(113, 172);
            this.comboBox2.Name = "comboBox2";
            this.comboBox2.Size = new System.Drawing.Size(194, 26);
            this.comboBox2.TabIndex = 5;
            this.comboBox2.SelectedIndexChanged += new System.EventHandler(this.comboBox2_SelectedIndexChanged);
            // 
            // button3
            // 
            this.button3.Font = new System.Drawing.Font("宋体", 10F);
            this.button3.Location = new System.Drawing.Point(27, 300);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(280, 44);
            this.button3.TabIndex = 7;
            this.button3.Text = "清空接受区";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // chart1
            // 
            chartArea3.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea3);
            legend3.Name = "Legend1";
            this.chart1.Legends.Add(legend3);
            this.chart1.Location = new System.Drawing.Point(347, 37);
            this.chart1.Name = "chart1";
            series3.ChartArea = "ChartArea1";
            series3.Legend = "Legend1";
            series3.Name = "Series1";
            this.chart1.Series.Add(series3);
            this.chart1.Size = new System.Drawing.Size(1041, 416);
            this.chart1.TabIndex = 8;
            this.chart1.Text = "chart1";
            this.chart1.Click += new System.EventHandler(this.chart1_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(27, 370);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(280, 366);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 9;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // button4
            // 
            this.button4.Font = new System.Drawing.Font("宋体", 11F);
            this.button4.Location = new System.Drawing.Point(188, 40);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(155, 61);
            this.button4.TabIndex = 10;
            this.button4.Text = "呼吸灯";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // LED_Open
            // 
            this.LED_Open.AutoSize = true;
            this.LED_Open.Checked = true;
            this.LED_Open.Font = new System.Drawing.Font("宋体", 11F);
            this.LED_Open.Location = new System.Drawing.Point(25, 57);
            this.LED_Open.Name = "LED_Open";
            this.LED_Open.Size = new System.Drawing.Size(57, 26);
            this.LED_Open.TabIndex = 12;
            this.LED_Open.TabStop = true;
            this.LED_Open.Text = "开";
            this.LED_Open.UseVisualStyleBackColor = true;
            this.LED_Open.CheckedChanged += new System.EventHandler(this.LED_Open_CheckedChanged);
            // 
            // LED_Close
            // 
            this.LED_Close.AutoSize = true;
            this.LED_Close.Font = new System.Drawing.Font("宋体", 11F);
            this.LED_Close.Location = new System.Drawing.Point(106, 57);
            this.LED_Close.Name = "LED_Close";
            this.LED_Close.Size = new System.Drawing.Size(57, 26);
            this.LED_Close.TabIndex = 13;
            this.LED_Close.Text = "关";
            this.LED_Close.UseVisualStyleBackColor = true;
            this.LED_Close.CheckedChanged += new System.EventHandler(this.LED_Close_CheckedChanged);
            // 
            // button5
            // 
            this.button5.Font = new System.Drawing.Font("宋体", 11F);
            this.button5.Location = new System.Drawing.Point(364, 40);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(155, 61);
            this.button5.TabIndex = 14;
            this.button5.Text = "闪烁";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.BackColor = System.Drawing.SystemColors.Control;
            this.groupBox1.Controls.Add(this.button5);
            this.groupBox1.Controls.Add(this.LED_Close);
            this.groupBox1.Controls.Add(this.LED_Open);
            this.groupBox1.Controls.Add(this.button4);
            this.groupBox1.Font = new System.Drawing.Font("宋体", 11F);
            this.groupBox1.Location = new System.Drawing.Point(347, 470);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(534, 116);
            this.groupBox1.TabIndex = 20;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "LED 控制";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // groupBox2
            // 
            this.groupBox2.BackColor = System.Drawing.SystemColors.Control;
            this.groupBox2.Controls.Add(this.PlayB);
            this.groupBox2.Controls.Add(this.BeepOFF);
            this.groupBox2.Controls.Add(this.BeepON);
            this.groupBox2.Controls.Add(this.PlayA);
            this.groupBox2.Font = new System.Drawing.Font("宋体", 11F);
            this.groupBox2.Location = new System.Drawing.Point(347, 620);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(534, 116);
            this.groupBox2.TabIndex = 21;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "蜂鸣器 控制";
            // 
            // PlayB
            // 
            this.PlayB.Font = new System.Drawing.Font("宋体", 11F);
            this.PlayB.Location = new System.Drawing.Point(364, 40);
            this.PlayB.Name = "PlayB";
            this.PlayB.Size = new System.Drawing.Size(155, 61);
            this.PlayB.TabIndex = 14;
            this.PlayB.Text = "SongB";
            this.PlayB.UseVisualStyleBackColor = true;
            this.PlayB.Click += new System.EventHandler(this.PlayB_Click);
            // 
            // BeepOFF
            // 
            this.BeepOFF.AutoSize = true;
            this.BeepOFF.Font = new System.Drawing.Font("宋体", 11F);
            this.BeepOFF.Location = new System.Drawing.Point(106, 57);
            this.BeepOFF.Name = "BeepOFF";
            this.BeepOFF.Size = new System.Drawing.Size(57, 26);
            this.BeepOFF.TabIndex = 13;
            this.BeepOFF.Text = "关";
            this.BeepOFF.UseVisualStyleBackColor = true;
            this.BeepOFF.CheckedChanged += new System.EventHandler(this.BeepOFF_CheckedChanged);
            // 
            // BeepON
            // 
            this.BeepON.AutoSize = true;
            this.BeepON.Checked = true;
            this.BeepON.Font = new System.Drawing.Font("宋体", 11F);
            this.BeepON.Location = new System.Drawing.Point(25, 57);
            this.BeepON.Name = "BeepON";
            this.BeepON.Size = new System.Drawing.Size(57, 26);
            this.BeepON.TabIndex = 12;
            this.BeepON.TabStop = true;
            this.BeepON.Text = "开";
            this.BeepON.UseVisualStyleBackColor = true;
            this.BeepON.CheckedChanged += new System.EventHandler(this.BeepON_CheckedChanged);
            // 
            // PlayA
            // 
            this.PlayA.Font = new System.Drawing.Font("宋体", 11F);
            this.PlayA.Location = new System.Drawing.Point(188, 40);
            this.PlayA.Name = "PlayA";
            this.PlayA.Size = new System.Drawing.Size(155, 61);
            this.PlayA.TabIndex = 10;
            this.PlayA.Text = "SongA";
            this.PlayA.UseVisualStyleBackColor = true;
            this.PlayA.Click += new System.EventHandler(this.PlayA_Click);
            // 
            // AlarmOn
            // 
            this.AlarmOn.AutoSize = true;
            this.AlarmOn.Checked = true;
            this.AlarmOn.Font = new System.Drawing.Font("宋体", 11F);
            this.AlarmOn.Location = new System.Drawing.Point(70, 40);
            this.AlarmOn.Name = "AlarmOn";
            this.AlarmOn.Size = new System.Drawing.Size(123, 26);
            this.AlarmOn.TabIndex = 22;
            this.AlarmOn.TabStop = true;
            this.AlarmOn.Text = "开启报警";
            this.AlarmOn.UseVisualStyleBackColor = true;
            this.AlarmOn.CheckedChanged += new System.EventHandler(this.Alarm_On_CheckedChanged);
            // 
            // AlarmOff
            // 
            this.AlarmOff.AutoSize = true;
            this.AlarmOff.Font = new System.Drawing.Font("宋体", 11F);
            this.AlarmOff.Location = new System.Drawing.Point(268, 40);
            this.AlarmOff.Name = "AlarmOff";
            this.AlarmOff.Size = new System.Drawing.Size(123, 26);
            this.AlarmOff.TabIndex = 23;
            this.AlarmOff.Text = "关闭报警";
            this.AlarmOff.UseVisualStyleBackColor = true;
            this.AlarmOff.CheckedChanged += new System.EventHandler(this.AlarmOff_CheckedChanged);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.AlarmOff);
            this.groupBox3.Controls.Add(this.AlarmOn);
            this.groupBox3.Font = new System.Drawing.Font("宋体", 11F);
            this.groupBox3.Location = new System.Drawing.Point(905, 470);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(463, 83);
            this.groupBox3.TabIndex = 24;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "报警控制";
            this.groupBox3.Enter += new System.EventHandler(this.groupBox3_Enter);
            // 
            // Is_LED_Off
            // 
            this.Is_LED_Off.AutoSize = true;
            this.Is_LED_Off.Font = new System.Drawing.Font("宋体", 11F);
            this.Is_LED_Off.Location = new System.Drawing.Point(70, 32);
            this.Is_LED_Off.Name = "Is_LED_Off";
            this.Is_LED_Off.Size = new System.Drawing.Size(57, 26);
            this.Is_LED_Off.TabIndex = 25;
            this.Is_LED_Off.Text = "灭";
            this.Is_LED_Off.UseVisualStyleBackColor = true;
            this.Is_LED_Off.CheckedChanged += new System.EventHandler(this.Is_LED_Off_CheckedChanged);
            // 
            // Is_LED_Breath
            // 
            this.Is_LED_Breath.AutoSize = true;
            this.Is_LED_Breath.Checked = true;
            this.Is_LED_Breath.Font = new System.Drawing.Font("宋体", 11F);
            this.Is_LED_Breath.Location = new System.Drawing.Point(165, 32);
            this.Is_LED_Breath.Name = "Is_LED_Breath";
            this.Is_LED_Breath.Size = new System.Drawing.Size(101, 26);
            this.Is_LED_Breath.TabIndex = 26;
            this.Is_LED_Breath.TabStop = true;
            this.Is_LED_Breath.Text = "呼吸灯";
            this.Is_LED_Breath.UseVisualStyleBackColor = true;
            this.Is_LED_Breath.CheckedChanged += new System.EventHandler(this.Is_LED_Breath_CheckedChanged);
            // 
            // Is_LED_Wink
            // 
            this.Is_LED_Wink.AutoSize = true;
            this.Is_LED_Wink.Font = new System.Drawing.Font("宋体", 11F);
            this.Is_LED_Wink.Location = new System.Drawing.Point(299, 32);
            this.Is_LED_Wink.Name = "Is_LED_Wink";
            this.Is_LED_Wink.Size = new System.Drawing.Size(79, 26);
            this.Is_LED_Wink.TabIndex = 27;
            this.Is_LED_Wink.Text = "闪烁";
            this.Is_LED_Wink.UseVisualStyleBackColor = true;
            this.Is_LED_Wink.CheckedChanged += new System.EventHandler(this.Is_LED_Wink_CheckedChanged);
            // 
            // LED_Mode
            // 
            this.LED_Mode.Controls.Add(this.Is_LED_Wink);
            this.LED_Mode.Controls.Add(this.Is_LED_Breath);
            this.LED_Mode.Controls.Add(this.Is_LED_Off);
            this.LED_Mode.Font = new System.Drawing.Font("宋体", 11F);
            this.LED_Mode.Location = new System.Drawing.Point(905, 567);
            this.LED_Mode.Name = "LED_Mode";
            this.LED_Mode.Size = new System.Drawing.Size(462, 79);
            this.LED_Mode.TabIndex = 28;
            this.LED_Mode.TabStop = false;
            this.LED_Mode.Text = "LED状态";
            // 
            // Is_Beep_On
            // 
            this.Is_Beep_On.AutoSize = true;
            this.Is_Beep_On.Checked = true;
            this.Is_Beep_On.Font = new System.Drawing.Font("宋体", 11F);
            this.Is_Beep_On.Location = new System.Drawing.Point(298, 32);
            this.Is_Beep_On.Name = "Is_Beep_On";
            this.Is_Beep_On.Size = new System.Drawing.Size(123, 26);
            this.Is_Beep_On.TabIndex = 26;
            this.Is_Beep_On.TabStop = true;
            this.Is_Beep_On.Text = "允许发声";
            this.Is_Beep_On.UseVisualStyleBackColor = true;
            // 
            // Is_Beep_Off
            // 
            this.Is_Beep_Off.AutoSize = true;
            this.Is_Beep_Off.Font = new System.Drawing.Font("宋体", 11F);
            this.Is_Beep_Off.Location = new System.Drawing.Point(69, 32);
            this.Is_Beep_Off.Name = "Is_Beep_Off";
            this.Is_Beep_Off.Size = new System.Drawing.Size(123, 26);
            this.Is_Beep_Off.TabIndex = 25;
            this.Is_Beep_Off.Text = "禁止发声";
            this.Is_Beep_Off.UseVisualStyleBackColor = true;
            // 
            // Beep_Mode
            // 
            this.Beep_Mode.Controls.Add(this.Is_Beep_On);
            this.Beep_Mode.Controls.Add(this.Is_Beep_Off);
            this.Beep_Mode.Font = new System.Drawing.Font("宋体", 11F);
            this.Beep_Mode.Location = new System.Drawing.Point(906, 658);
            this.Beep_Mode.Name = "Beep_Mode";
            this.Beep_Mode.Size = new System.Drawing.Size(462, 79);
            this.Beep_Mode.TabIndex = 29;
            this.Beep_Mode.TabStop = false;
            this.Beep_Mode.Text = "Beep状态";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1432, 766);
            this.Controls.Add(this.Beep_Mode);
            this.Controls.Add(this.LED_Mode);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.comboBox2);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.chart1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "上位机—ByHzy";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.LED_Mode.ResumeLayout(false);
            this.LED_Mode.PerformLayout();
            this.Beep_Mode.ResumeLayout(false);
            this.Beep_Mode.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button2;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox comboBox2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.RadioButton LED_Open;
        private System.Windows.Forms.RadioButton LED_Close;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button PlayB;
        private System.Windows.Forms.RadioButton BeepOFF;
        private System.Windows.Forms.RadioButton BeepON;
        private System.Windows.Forms.Button PlayA;
        private System.Windows.Forms.RadioButton AlarmOff;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.RadioButton AlarmOn;
        private System.Windows.Forms.RadioButton Is_LED_Off;
        private System.Windows.Forms.RadioButton Is_LED_Breath;
        private System.Windows.Forms.RadioButton Is_LED_Wink;
        private System.Windows.Forms.GroupBox LED_Mode;
        private System.Windows.Forms.RadioButton Is_Beep_On;
        private System.Windows.Forms.RadioButton Is_Beep_Off;
        private System.Windows.Forms.GroupBox Beep_Mode;
    }
}

