import java.awt.*;
import java.awt.event.*;
import javax.swing.JOptionPane;
public class awt1 extends Frame implements ActionListener {
Button submit, clear;
Label username, password, status;
public int attempt = 1;
TextField Enteruser, Enterpass, msg;
public awt1() {
Panel pane = new Panel();
username = new Label("Enter UserName", Label.CENTER);
password = new Label("Enter Password", Label.RIGHT);
Enteruser = new TextField(10);
Enterpass = new TextField(10);
submit = new Button("Submit");
clear = new Button("Clear");
msg = new TextField(20);
msg.setEditable(false);
status = new Label("Status");
pane.add(username);
pane.add(Enteruser);
pane.add(password);
pane.add(Enterpass);
pane.add(submit);
pane.add(clear);
pane.add(status);
pane.add(msg);
pane.setSize(1800, 1200);
pane.setVisible(true);
add(pane);
setTitle("Login page making");
setSize(500, 500);
setVisible(true);
submit.addActionListener(this);
clear.addActionListener(this);
addWindowListener new WindowAdapter() {
public void windowClosing(WindowEvent e) {
dispose(); 
}
};
}
@Override
public void actionPerformed(ActionEvent e) {
Button btn = (Button) (e.getSource());
String user = Enteruser.getText();
String password = Enterpass.getText();
if ((btn.getLabel()).equals("Clear")) {
Enteruser.setText("");
Enterpass.setText("");
}
if (attempt < 3) {
if (btn.getLabel().equals("Submit")) {
try {
if (user.equals("admin") && password.equals("1234")) {
msg.setText("Login");
} else {
msg.setText("Invalid");
JOptionPane.showMessageDialog(null,
"You have 3 attempts and you loose " + attempt + " attempt");
}

} catch (Exception e1) {
JOptionPane.showMessageDialog(null, "Your doing some mistake");
}
}
attempt++;
}
else {
System.exit(0);
}
}
public static void main(String[] args) {
new awt1();
}
}
