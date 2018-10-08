import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;

public class OperationPanel extends JPanel {
private CalcFrame current_calc_state;

	private final String opers[] = {"+", "-", "x", "/", "=", "CLR"};

	public OperationPanel (CalcFrame c) {
		setLayout(new GridLayout(2, 3, 10, 10));
		
		current_calc_state = c;
		
		for (int i = 0; i < opers.length; i++) {
			
			final String op = opers[i];
			JButton OpButton = new JButton (op);
			
			OpButton.addActionListener (new ActionListener () {
				
				@Override
				public void actionPerformed (ActionEvent e) {
					if (op == "=") {
						current_calc_state.evaluateExpression();						
					}
					else if (op == "CLR"){
						current_calc_state.writeDisplay ("");
					}
					else {
						current_calc_state.writeDisplay (current_calc_state.readDisplay() + op);
					}
				}
			});
			
			add (OpButton);
		}
		
		setVisible(true);
	}
}
