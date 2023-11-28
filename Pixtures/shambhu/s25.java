//slip25_q1
import java.io.*;
public static void main(String[] args) throws IOException{
int rollNo;
String name;
String Class;
System.out.println("Enter Student Roll number");
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
rollNo = Integer.parseInt(br.readLine());
System.out.println("Enter Student Name");
name = br.readLine();
System.out.println("Enter Class of the students");
Class = br.readLine();
System.out.println("Here Student data...");
System.out.println("\n\n");
System.out.println("student roll Number : " + rollNo);
System.out.println("student Name : " + name);
System.out.println("student Class : " + Class);
br.close();
}

