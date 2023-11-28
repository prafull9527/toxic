//s7q1
import java.util.Scanner;
public class account {
Scanner sc = new Scanner(System.in);
String name = "";
int account_no;
String a ="";
int deposit;
int with;
int balance;
public void get_details() {
System.out.println("enter the cutomer name:");
name = sc.nextLine();
System.out.println("enter the account number:");
account_no = sc.nextInt();
System.out.println("enter the type of account:");
a=sc.next();
System.out.println("enter the deposit money:");
deposit = sc.nextInt();
System.out.println("enter the Withdraw money:");
with = sc.nextInt();
balance = deposit - with;
}
public void show_details() {
System.out.println("____________________________");
System.out.println("customer name ->" + name);
System.out.println("account number -> " + account_no);
System.out.println("account type -> "+ a);
System.out.println("deposit money -> "+deposit);
System.out.println("withdraw money -> "+with);
System.out.println("Available Balance -> " + balance);
}
public static void main(String[] args) {
account obj = new account();
obj.get_details();
obj.show_details();
}
}




//Q2
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;
public class main9 {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
System.out.print("Enter the path of the text file: ");
String filePath = scanner.nextLine();
try {
String fileContents = readFileContents(filePath);
System.out.println("\nOriginal Contents:");
System.out.println(fileContents);
System.out.println("\nReversed Contents with Changed Case:");
displayReversedAndChangedCase(fileContents);
} catch (IOException e) {
System.out.println("An error occurred while reading the file: " + e.getMessage());
} finally {
scanner.close();
}
}
private static String readFileContents(String filePath) throws IOException {
StringBuilder content = new StringBuilder();
try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
String line;
while ((line = reader.readLine()) != null) {
content.append(line).append("\n");
}
}
return content.toString();
}
private static void displayReversedAndChangedCase(String content) {
StringBuilder reversedContent = new StringBuilder(content).reverse();
StringBuilder changedCaseContent = new StringBuilder();
for (char c : reversedContent.toString().toCharArray()) {
if (Character.isUpperCase(c)) {
changedCaseContent.append(Character.toLowerCase(c));
} else if (Character.isLowerCase(c)) {
changedCaseContent.append(Character.toUpperCase(c));
} else {
changedCaseContent.append(c);
}
}
System.out.println(changedCaseContent.toString());
}
}
