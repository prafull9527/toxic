//slip 12 Q1
class College {
protected int cno;
protected String cname;
protected String caddr;
public College(int cno, String cname, String caddr) {
this.cno = cno;
this.cname = cname;
this.caddr = caddr;
}
public void displayCollegeDetails() {
System.out.println("College Details:");
System.out.println("College Number: " + cno);
System.out.println("College Name: " + cname);
System.out.println("College Address: " + caddr);
}
}
class Department extends College {
private int dno;
private String dname;
public Department(int cno, String cname, String caddr, int dno, String dname) {
super(cno, cname, caddr);
this.dno = dno;
this.dname = dname;
}
public void displayDepartmentDetails() {
super.displayCollegeDetails();
System.out.println("Department Details:");
System.out.println("Department Number: " + dno);
System.out.println("Department Name: " + dname);
}
}
public class CollegeDepartmentDemo {
public static void main(String[] args) {
Department myDepartment = new Department(1, "XYZ College", "123 Main Street", 101, "Computer Science");
myDepartment.displayDepartmentDetails();
}
}




// Q2
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class SimpleCalculator extends JFrame {
private JTextField resultTextField;
public SimpleCalculator() {
setTitle("Simple Calculator");
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
setLayout(new BorderLayout());
resultTextField = new JTextField();
resultTextField.setEditable(false);
add(resultTextField, BorderLayout.NORTH);
JPanel buttonPanel = new JPanel();
buttonPanel.setLayout(new GridLayout(4, 4, 5, 5));
String[] buttonLabels = {
"7", "8", "9", "/",
"4", "5", "6", "*",
"1", "2", "3", "-",
"0", ".", "=", "+"
};
for (String label : buttonLabels) {
JButton button = new JButton(label);
button.addActionListener(new ButtonClickListener());
buttonPanel.add(button);
}
add(buttonPanel, BorderLayout.CENTER);
pack();
setLocationRelativeTo(null); 
setVisible(true);
}
