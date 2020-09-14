// Demonstrate text field.
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
/*
<applet code="TextFieldDemo2" width=500 height=500>
</applet>
*/
public class TextFieldDemo2 extends Applet
implements TextListener
{
		
		TextField tf1;
		TextArea ta1;
		public void init() 
		{ 	 
			tf1 = new TextField(12);
			ta1 = new TextArea("",12,20,TextArea.SCROLLBARS_BOTH);
			
			add(tf1);
			add(ta1);
			
			tf1.addTextListener(this);
		}
		public void textValueChanged(TextEvent te) 
		{
			ta1.append("TextEvent  : "+tf1.getText() + "\n");
		}
}
