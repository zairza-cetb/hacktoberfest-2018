import java.awt.Color;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

public class CalcFrame extends JFrame {

	private JButton resultArea;
	
	public CalcFrame() {
		setSize(300, 400);
		setDefaultCloseOperation (EXIT_ON_CLOSE);
		setLayout (new GridLayout(3, 1));
		
		resultArea = new JButton ("");
		resultArea.setEnabled(false);
		resultArea.setBackground(Color.WHITE);
		
		add (resultArea);
		resultArea.setBorder(new EmptyBorder(10, 10, 10, 10));
		
		JPanel numPanel = new NumberPanel(this);
		numPanel.setBorder(new EmptyBorder(10, 10, 10, 10));
		add (numPanel);
		
		JPanel opPanel = new OperationPanel(this);
		opPanel.setBorder(new EmptyBorder(10, 10, 10, 10));
		add (opPanel);
		
		setVisible(true);
	}
	
	public void writeDisplay (String expression) {
		resultArea.setText(expression);
	}
	
	public String readDisplay () {
		return resultArea.getText();
	}
	
	public void evaluateExpression () {
		String expression = readDisplay();
		double result = 0;
		char operator = expression.charAt(1);
		int operand1 = expression.charAt(0) - '0', operand2 = expression.charAt(2) - '0';
		if (operator == '+') {
			result = operand1 + operand2;
		}
		else if (operator == '-') {
			result = operand1 - operand2;
		}
		else if (operator == 'x') {
			result = operand1 * operand2;
		}
		else if (operator == '/') {
			result = operand1 / operand2;
		}
		
		writeDisplay(Double.toString(result));
	}
	
	//public static void main(String[] args) {
	//	JFrame calcFrame = new CalcFrame();
	//}
}
