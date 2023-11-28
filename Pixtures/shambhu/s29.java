//s29q1
import java.util.Scanner;
class Customers{
int CustomerNumber;
String CustomerName;
long ContactNumber;
String Address;
public Customers(int Number , String Name , long PhoneNumber , String address ){
this.CustomerNumber = Number;
this.CustomerName = Name;
this.ContactNumber = PhoneNumber;
this.Address = address;
}
public void Search(long CustomerPhoneNumber){
if(CustomerPhoneNumber == ContactNumber){
System.out.println("Customer ID " + this.CustomerNumber);
System.out.println("Customer Name " + this.CustomerName);
System.out.println("Customer Phone number " + this.ContactNumber);
System.out.println("Customer Address " + this.Address);
}
}
}
public static void main(String[] args) {
Scanner sc = new Scanner(System.in);
System.out.println("Enter the n for size ");
int n = sc.nextInt();
Customers[] c = new Customers[n];
for (int i = 0 ; i < n; i++){
System.out.println("Enter Customer ID");
int cid = sc.nextInt();
System.out.println("Enter Name of Customer");
String cName = sc.next();
System.out.println("Enter Phone Number of Customer");
long phone = sc.nextLong();
System.out.println("Enter Address");
String add = sc.next();
c[i] = new Customers(cid, cName , phone , add);
}
System.out.println("Enter Contact name for Search name");
long CustomerPhoneNumber = sc.nextLong();
for (Customers cd : c){
cd.Search(CustomerPhoneNumber);
}
}





//slip 29 Q2
import java.util.Scanner;
class Vehicle {
protected String company;
protected double price;
public Vehicle(String company, double price) {
this.company = company;
this.price = price;
}
public void displayInfo() {
System.out.println("Vehicle Information:");
System.out.println("Company: " + company);
System.out.println("Price: $" + price);
}
}
class LightMotorVehicle extends Vehicle {
private double mileage;
public LightMotorVehicle(String company, double price, double mileage) {
super(company, price);
this.mileage = mileage;
}
@Override
public void displayInfo() {
super.displayInfo();
System.out.println("Mileage: " + mileage + " km/l");
System.out.println("-----------------------------");
}
}
class HeavyMotorVehicle extends Vehicle {
private double capacity_in_tons;
public HeavyMotorVehicle(String company, double price, double capacity_in_tons) {
super(company, price);
this.capacity_in_tons = capacity_in_tons;
}
@Override
public void displayInfo() {
super.displayInfo();
System.out.println("Capacity in Tons: " + capacity_in_tons + " tons");
System.out.println("-----------------------------");
}
}
public class VehicleDemo {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter the number of vehicles (n): ");
int n = scanner.nextInt();
scanner.nextLine(); 
Vehicle[] vehicles = new Vehicle[n];
for (int i = 0; i < n; i++) {
System.out.println("Enter information for Vehicle #" + (i + 1));
System.out.print("Enter vehicle type (Light / Heavy): ");
String vehicleType = scanner.nextLine();
System.out.print("Enter company: ");
String company = scanner.nextLine();
System.out.print("Enter price: $");
double price = scanner.nextDouble();
scanner.nextLine(); 
if ("Light".equalsIgnoreCase(vehicleType)) {
System.out.print("Enter mileage: ");
double mileage = scanner.nextDouble();
scanner.nextLine(); 
vehicles[i] = new LightMotorVehicle(company, price, mileage);
} else if ("Heavy".equalsIgnoreCase(vehicleType)) {
System.out.print("Enter capacity in tons: ");
double capacity_in_tons = scanner.nextDouble();
scanner.nextLine(); 
vehicles[i] = new HeavyMotorVehicle(company, price, capacity_in_tons);
} else {
System.out.println("Invalid vehicle type. Please enter Light or Heavy.");
i--; 
}
}
System.out.println("\nVehicle Information for All Vehicles:");
for (Vehicle vehicle : vehicles) {
vehicle.displayInfo();
}
scanner.close();
}
}
