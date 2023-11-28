//slip 9 Q1
import java.util.Scanner;
public class Clock {
private int hours;
private int minutes;
private int seconds;
private String amPm;
public Clock() {
this.hours = 0;
this.minutes = 0;
this.seconds = 0;
this.amPm = "AM";
}
public Clock(int hours, int minutes, int seconds) {
if (isValidTime(hours, minutes, seconds)) {
this.hours = hours;
this.minutes = minutes;
this.seconds = seconds;
setAmPm();
} else {
System.out.println("Invalid time input. Defaulting to midnight (12:00:00 AM).");
this.hours = 0;
this.minutes = 0;
this.seconds = 0;
this.amPm = "AM";
}
}
private boolean isValidTime(int hours, int minutes, int seconds) {
return (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60);
}
private void setAmPm() {
amPm = (hours >= 12) ? "PM" : "AM";
if (hours > 12) {
hours -= 12;
} else if (hours == 0) {
hours = 12;
}
}
public void displayTime() {
System.out.println("Time: " + String.format("%02d", hours) + ":" +
String.format("%02d", minutes) + ":" +
String.format("%02d", seconds) + " " + amPm);
}
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter hours: ");
int hours = scanner.nextInt();
System.out.print("Enter minutes: ");
int minutes = scanner.nextInt();
System.out.print("Enter seconds: ");
int seconds = scanner.nextInt();
Clock myClock = new Clock(hours, minutes, seconds);
myClock.displayTime();
scanner.close();
}
}




//q2
import java.util.Scanner;
interface ProductMaker
class Product implements ProductMaker
{
int pid;
String pName;
int Cost;
int quantity;
int total;

Product()
{
pid = 0;
pName ="";
Cost = 0;
quantity = 0;
total=0;
}

Product(int id , String name , int cost , int quantities)
{
this.pid = id;
this.pName = name;
this.Cost = cost;
this.quantity = quantities;
}

public void Data()
{
System.out.println("-------------------------------------------------------------");
System.out.println("Your Data Here ");
System.out.println("id -> " + pid);
System.out.println("Name -> " + pName);
System.out.println("cost -> " + Cost);
System.out.println("quantity -> " + quantity);
total = (Cost * quantity);
System.out.println("Total Price are -> " + total);
System.out.println("-------------------------------------------------------------");

}
}
public static void main(String[] args) 
{
int count=0;
System.out.println("Enter the Size");
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
Product[] product = new Product[n];
for (int i = 0 ; i < n ; i++)
{
System.out.println("Enter Id of the Products");
int ID = sc.nextInt();
sc.nextLine();
System.out.println("Enter Name of the Products");
String NAME = sc.next();
sc.nextLine();
System.out.println("Enter Cost of the Products");
int COST = sc.nextInt();
sc.nextLine();
System.out.println("Enter quantities of the Products");
int QUANTITY = sc.nextInt();
sc.nextLine();
count++;
product[i] = new Product(ID , NAME, COST , QUANTITY);
}
sc.close();
for(Product p : product)
{
p.Data();
}
}
