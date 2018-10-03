import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

public class LoginFrame extends JFrame implements ActionListener {
	private JTextField useridField;
	private JPasswordField passwordField;
	JFrame nextFrame;
	
	public LoginFrame() {
		setSize(300, 400);
		setDefaultCloseOperation (EXIT_ON_CLOSE);
		
		setLayout (new GridLayout(5, 1, 10, 10));
		
		JLabel useridLabel = new JLabel("User ID");
		useridLabel.setBorder(new EmptyBorder(10, 10, 10, 10));
		add (useridLabel);
		
		useridField = new JTextField();
		useridField.setEditable(true);
		useridField.setBorder(new EmptyBorder(10, 10, 10, 10));
		add(useridField);
		
		JLabel passwordLabel = new JLabel("Password");
		passwordLabel.setBorder(new EmptyBorder(10, 10, 10, 10));;
		add (passwordLabel);
		
		passwordField = new JPasswordField(20);
		passwordField.setEditable(true);
		passwordField.setBorder(new EmptyBorder(10, 10, 10, 10));
		add(passwordField);
		
		JButton loginButton = new JButton("Login");
		loginButton.addActionListener(this);
		loginButton.setBorder(new EmptyBorder(10, 10, 10, 10));
		add(loginButton);
		
		setVisible(true);
	}
	
	public void actionPerformed(ActionEvent e) {
		if (checkCredentials()) {
			nextFrame = new CalcFrame();
		}
	}
	
	private boolean checkCredentials() {
		final String userid = useridField.getText().trim();
		final String password = passwordField.getText().trim();
		return (userid.equals("Ganesh") && password.equals("Gaitonde"));
	}
	
	public static void main(String[] args) {
		JFrame loginFrame = new LoginFrame();
	}
}
