//s1 q1
import java.util.Scanner;
public void ShowArray(int [] arr,int length){
System.out.println("The array you entered is as below: ");
for(int i=0;i<arr.length;i++){
System.out.print(" "+arr[i]);
}
}
public String PrimeNumbers(int [] arr, int length){
int num=0;
String primeno ="";
System.out.println("\nHere these no.s from your array are prime numbers: ");
for(int i=1; i<arr.length; i++)
{
int counter=0;
for (num=i ; num >=1 ; num--)
{
if(i%num == 0)
{
counter= counter + 1;
}
}
if( counter ==2){
primeno = primeno + i +" ";
}
}
return primeno;
}
public class s1 {
public static void main(String[] args)
 {
int [] arr = {1,2,3,4,5,6,7,8,9,10};
int size=arr.length;
Q1 q = new Q1();
q.ShowArray(arr,size);
System.out.println(q.PrimeNumbers(arr,size));
}
}



/*

// q2
import java.util.Scanner;
abstract class Staff
{
protected int id;
protected String name;
public Staff(int id , String name)
{
this.id = id;
this.name = name;
}
public abstract void display();
}
class OfficeStaff extends Staff
{
private String department;
public OfficeStaff(int id ,String name , String department)
{
super(id , name);
this.department = department;
}
public void display()
{
System.out.println("ID is -> " + id);
System.out.println("Name is -> " + name);
System.out.println("Department is -> " + department);
}
}
public static void main(String[] args) 
{
Scanner sc = new Scanner(System.in);
System.out.println("How many details You will added");
int n = sc.nextInt();
OfficeStaff[] osa = new OfficeStaff[n];
for(int i = 0 ; i < n; i++){
System.out.println("Enter ID ");
int id = sc.nextInt();
sc.nextLine();
System.out.println("Enter Name ");
String name = sc.next();
sc.nextLine();
System.out.println("Enter Department ");
String department = sc.next();
sc.nextLine();
osa[i] = new OfficeStaff(id , name , department);
}
sc.close();
for (OfficeStaff OF : osa) {
OF.display();
}
}*/
