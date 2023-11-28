slip 20 Q1
import javax.swing.*;
import java.awt.*;
public class BorderLayoutExample extends JFrame {
public BorderLayoutExample() {
setTitle("BorderLayout Example");
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
setSize(300, 200);
JButton btnNorth = new JButton("North");
JButton btnSouth = new JButton("South");
JButton btnEast = new JButton("East");
JButton btnWest = new JButton("West");
JButton btnCenter = new JButton("Center");
setLayout(new BorderLayout());
add(btnNorth, BorderLayout.NORTH);
add(btnSouth, BorderLayout.SOUTH);
add(btnEast, BorderLayout.EAST);
add(btnWest, BorderLayout.WEST);
add(btnCenter, BorderLayout.CENTER);
}
public static void main(String[] args) {
SwingUtilities.invokeLater() -> {
BorderLayoutExample example = new BorderLayoutExample();
example.setVisible(true);
};
}
}





//q2
import java_Slips.Operation.Arithmatic;
import java_Slips.Operation.Maximum;

public static void main(String[] args) 
{
Arithmatic arth = new Arithmatic();
Maximum maximums = new Maximum();

float a = arth.addition(5,5);
float b = arth.subtraction(5,5);
System.out.println(a);
System.out.println(b);

int x = maximums.max(5,5);
System.out.println(x);
}

