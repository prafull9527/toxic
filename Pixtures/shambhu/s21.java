//slip 21 Q1
import javax.swing.*;
import java.awt.*;
class InvalidDateException extends Exception {
public InvalidDateException(String message) {
super(message);
}
}
class MyDate {
private int day;
private int month;
private int year;
public MyDate(int day, int month, int year) throws InvalidDateException {
if (!isValidDate(day, month, year)) {
throw new InvalidDateException("Invalid date: " + day + "/" + month + "/" + year);
}
this.day = day;
this.month = month;
this.year = year;
}
private boolean isValidDate(int day, int month, int year) {
if (month < 1 || month > 12) {
return false;
}
int[] daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
if (day < 1 || day > daysInMonth[month]) {
return false;
}
if (month == 2 && isLeapYear(year) && day == 29) {
return true;
}
return !(month == 2 && day == 29);
}
private boolean isLeapYear(int year) {
return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
public void displayDate() {
System.out.println("Date: " + day + "/" + month + "/" + year);
}
}
public class MyDateDemo {
public static void main(String[] args) {
try {
MyDate validDate = new MyDate(15, 8, 2023);
validDate.displayDate();
} catch (InvalidDateException e) {
System.out.println("Exception: " + e.getMessage());
}
}
}





// Q2
import javax.swing.*;
import java.awt.*;
class Employee {
private static int objectCount = 0;
private int id;
private String name;
private String deptName;
private double salary;
public Employee() {
this.id = 0;
this.name = "Default";
this.deptName = "DefaultDept";
this.salary = 0.0;
objectCount++;
displayEmployee();
displayObjectCount();
}
public Employee(int id, String name, String deptName, double salary) {
this.id = id;
this.name = name;
this.deptName = deptName;
this.salary = salary;
objectCount++;
displayEmployee();
displayObjectCount();
}
public static void displayObjectCount() {
System.out.println("Object count: " + objectCount);
System.out.println("-----------------------------");
}
public void displayEmployee() {
System.out.println("Employee Details:");
System.out.println("ID: " + id);
System.out.println("Name: " + name);
System.out.println("Department: " + deptName);
System.out.println("Salary: $" + salary);
}
}
public class EmployeeDemo {
public static void main(String[] args) {
Employee defaultEmployee = new Employee();
Employee emp1 = new Employee(1, "John Doe", "IT", 50000.0);
Employee emp2 = new Employee(2, "Jane Smith", "HR", 60000.0);
Employee.displayObjectCount();
}
}
