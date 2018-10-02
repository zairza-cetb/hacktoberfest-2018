using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace Calculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            button1.FlatStyle = FlatStyle.Popup;
            ToggleButtonState(false);
        }

        private void SetText (string text)
        {
            if (text == "") richTextBox1.Text = "";
            else richTextBox1.Text += text;
        }

        private void ToggleButtonState(Boolean flag)
        {
            button2.Enabled = flag;
            button3.Enabled = flag;
            button4.Enabled = flag;
            button5.Enabled = flag;

            button6.Enabled = flag;
            button7.Enabled = flag;
            button8.Enabled = flag;
            button9.Enabled = flag;

            button10.Enabled = flag;
            button11.Enabled = flag;
            button12.Enabled = flag;
            button13.Enabled = flag;

            button14.Enabled = flag;
            button15.Enabled = flag;
            button16.Enabled = flag;
            button17.Enabled = flag;

            button18.Enabled = flag;
            button19.Enabled = flag;
        }

        private List<object> getCalculation(string calcString, char op)
        {
            int index = calcString.IndexOf(op);
            int i = 0;
            double answer = 0.0d;
            int startIndex = 0;
            int endIndex = 0;

            for (i = index - 1; i >= 0; i--)
            {
                if (calcString.ElementAt(i) == '+' || calcString.ElementAt(i) == '-' || calcString.ElementAt(i) == 'x' || calcString.ElementAt(i) == '/') break;
            }
            startIndex = i + 1;

            for (i = index + 1; i < calcString.Length; i++)
            {
                if (calcString.ElementAt(i) == '+' || calcString.ElementAt(i) == '-' || calcString.ElementAt(i) == 'x' || calcString.ElementAt(i) == '/') break;
            }
            endIndex = i - 1;

            double firstNumber = Convert.ToDouble(calcString.Substring(startIndex, (index - startIndex)));
            double secondNumber = Convert.ToDouble(calcString.Substring(index + 1, (endIndex - index)));

            if (op == '+') answer = firstNumber + secondNumber;
            else if (op == '-') answer = firstNumber - secondNumber;
            else if (op == 'x') answer = firstNumber * secondNumber;
            else if (op == '/') answer = firstNumber / secondNumber;

            calcString = calcString.Substring(0, startIndex) + Convert.ToString(answer) + calcString.Substring(endIndex + 1);
            List<object> returnAnswer = new List<object>();
            returnAnswer.Add(answer);
            returnAnswer.Add(calcString);

            return returnAnswer;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            button1.FlatStyle = FlatStyle.Flat;
            ToggleButtonState(true);
        }

        private void button16_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
            button1.FlatStyle = FlatStyle.Popup;
            ToggleButtonState(false);
        }

        private void button14_Click(object sender, EventArgs e)
        {
            SetText("0");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            SetText("7");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            SetText("8");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            SetText("9");
        }
        
        private void button6_Click(object sender, EventArgs e)
        {
            SetText("4");
        }

        private void button7_Click(object sender, EventArgs e)
        {
            SetText("5");
        }

        private void button8_Click(object sender, EventArgs e)
        {
            SetText("6");
        }

        private void button10_Click(object sender, EventArgs e)
        {
            SetText("1");
        }

        private void button11_Click(object sender, EventArgs e)
        {
            SetText("2");
        }

        private void button12_Click(object sender, EventArgs e)
        {
            SetText("3");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            SetText("/");
        }

        private void button13_Click(object sender, EventArgs e)
        {
            SetText("-");
        }

        private void button9_Click(object sender, EventArgs e)
        {
            SetText("x");
        }

        private void button15_Click(object sender, EventArgs e)
        {
            SetText("+");
        }

        private void button17_Click(object sender, EventArgs e)
        {
            SetText("");
        }

        private void button19_Click(object sender, EventArgs e)
        {
            SetText(".");
        }

        private void button18_Click(object sender, EventArgs e)
        {
            string calcString = richTextBox1.Text;
            double answer = 0.0d;

            while(calcString.Contains("/"))
            {
                List<object> interAnswer = getCalculation(calcString, '/');
                answer = Convert.ToDouble(interAnswer.ElementAt(0));
                calcString = Convert.ToString(interAnswer.ElementAt(1));
            }

            while (calcString.Contains("x"))
            {
                List<object> interAnswer = getCalculation(calcString, 'x');
                answer = Convert.ToDouble(interAnswer.ElementAt(0));
                calcString = Convert.ToString(interAnswer.ElementAt(1));
            }

            while (calcString.Contains("+"))
            {
                List<object> interAnswer = getCalculation(calcString, '+');
                answer = Convert.ToDouble(interAnswer.ElementAt(0));
                calcString = Convert.ToString(interAnswer.ElementAt(1));
            }

            while (calcString.Contains("-"))
            {
                if (calcString.ElementAt(0) == '-') break;

                List<object> interAnswer = getCalculation(calcString, '-');
                answer = Convert.ToDouble(interAnswer.ElementAt(0));
                calcString = Convert.ToString(interAnswer.ElementAt(1));
            }
            
            richTextBox1.Text = "";
            richTextBox1.Text = Convert.ToString(answer);
        }
    }
}
