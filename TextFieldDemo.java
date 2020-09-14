// Demonstrate text field.
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="TextFieldDemo" width=380 height=150>
</applet>
*/
public class TextFieldDemo extends Applet
implements ActionListener
{
		Label l_name,l_pass;
		TextField tf_name, tf_pass;
		public void init() 
		{
			 l_name = new Label("Name: ", Label.LEFT);
			 l_pass = new Label("Password: ", Label.RIGHT);
			
			tf_name = new TextField(12);
			tf_pass = new TextField(8);
			tf_pass.setEchoChar('?');
			

			add(l_name);
			add(tf_name);
			add(l_pass);
			add(tf_pass);
			
			// register to receive action events
			tf_name.addActionListener(this);
			tf_pass.addActionListener(this);
			
			
		}
		// User pressed Enter.
		public void actionPerformed(ActionEvent ae) 
		{
			repaint();
		}
		
		public void paint(Graphics g) 
		{
			g.drawString("Name: " + tf_name.getText(), 6, 60);
			g.drawString("Selected text in name: "+ tf_name.getSelectedText(), 6, 80);
			g.drawString("Password: " + tf_pass.getText(), 6, 100);
		}
}
