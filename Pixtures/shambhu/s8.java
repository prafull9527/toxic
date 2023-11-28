//slip 8 Q1
import java.util.Scanner;
class Sphere {
private double radius;
public Sphere(double radius) {
this.radius = radius;
}
public double calculateSurfaceArea() {
return 4 * Math.PI * Math.pow(radius, 2);
}
public double calculateVolume() {
return (4.0 / 3) * Math.PI * Math.pow(radius, 3);
}
}
public class q1{
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter the radius of the sphere: ");
double radius = scanner.nextDouble();
Sphere mySphere = new Sphere(radius);
double surfaceArea = mySphere.calculateSurfaceArea();
double volume = mySphere.calculateVolume();
System.out.println("\nSphere Calculations:");
System.out.println("Surface Area: " + surfaceArea);
System.out.println("Volume: " + volume);
scanner.close();
}
}





//q2 
import java.awt.*;
import java.awt.event.*;


Label l1 , l2;
TextField t1 , t2;
int x,y;
Panel p;

{
setLayout(new FlowLayout());

p = new Panel();
p.setLayout(new GridLayout(2,2,5,5));

t1 = new TextField(10);
t1.setEditable(false);

t2 = new TextField(10);
t2.setEditable(false);

l1 = new Label("Co-ordinate of Mouse Clicked");
l2 = new Label("Co-ordinate of Mouse Motion");

p.add(l1);
p.add(t1);
p.add(l2);
p.add(t2);
add(p);

addMouseListener(new Moving());
addMouseMotionListener(new Click());

setSize(500,500);
setVisible(true);

}

class Moving extends MouseAdapter{
public void mouseClicked(MouseEvent me){
x = me.getX();
y = me.getY();
t1.setText(" X -> " + x + " Y -> " + y);
}
}

class Click extends MouseMotionAdapter{
public void mouseMoved(MouseEvent mm){
x = mm.getX();
y = mm.getY();
t2.setText(" X -> " + x + " Y -> " + y);
}
}

    