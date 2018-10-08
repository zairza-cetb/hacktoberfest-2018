import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;

public class NumberPanel extends JPanel {
	private CalcFrame current_calc_state;
	
	public NumberPanel (CalcFrame c) {
		current_calc_state = c;
		
		setLayout(new GridLayout(3, 3, 10, 10));
		
		for (int i = 1; i < 10; i++) {
			
			final int num = i;
			JButton NumButton = new JButton (Integer.toString (num));
			
			NumButton.addActionListener (new ActionListener () {
				@Override
				public void actionPerformed (ActionEvent e) {
					current_calc_state.writeDisplay (current_calc_state.readDisplay() + Integer.toString(num));
				}
			});
			
			add (NumButton);
		}
		
		setVisible(true);
	}
}
