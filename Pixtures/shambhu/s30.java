//slip no 30 q1
import java.util.*;
class Person {
String PersonName;
long AadharNumber;
String PanNumber;
Person(String Name , long AadharNo , String panNo){
this.PersonName = Name;
this.AadharNumber = AadharNo;
this.PanNumber = panNo;
}
public void display(){
System.out.println("Person Name " + PersonName);
System.out.println("Aadhar Number " + AadharNumber);
System.out.println("Pan card Number " + PanNumber);
}
public String toString(){
return "Person Name "+PersonName +
"Aadhar Number " + AadharNumber +
"PanCard Number " + PanNumber;
}
}
public static void main(String[] args) {
Person[] person  = new Person[5];
Scanner sc = new Scanner(System.in);
System.out.println("Complete the following Details \n");
for (int i = 0; i < 5; i++){
System.out.println("Enter the Person Name ");
String name = sc.next();
System.out.println("Enter the Person Aadhar card Number");
long Aadhar = sc.nextLong();
System.out.println("Enter the Person Pan Card Number");
String pan = sc.next();
person[i] = new Person(name , Aadhar , pan);
}
sc.close();
for(Person p : person){
System.out.println(p.toString());
}
}


//q2
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
class UI extends JFrame implements ActionListener {
JPanel panel;
JTextField Number1, Number2;
JLabel l1, l2;
JButton divideBtn;
UI() {
setSize(1100, 800);
setTitle("Divide Performing");
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
panel = new JPanel();
l1 = new JLabel("Number 1 ");
l1.setBounds(0, 0, 100, 30);
l1.setBorder(BorderFactory.createLineBorder(Color.black, 3));
panel.add(l1);
add(panel);
setLayout(null);
setVisible(true);
}
@Override
public void actionPerformed(ActionEvent e) {
}
}
public static void main(String[] args) {
new UI();
}
