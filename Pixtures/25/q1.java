import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Student {
    private int rollNo;
    private String name;
    private String className;
    private double percentage;

    // Constructor
    public Student(int rollNo, String name, String className, double percentage) {
        this.rollNo = rollNo;
        this.name = name;
        this.className = className;
        this.percentage = percentage;
    }

    // Display student information
    public void displayStudentInfo() {
        System.out.println("Student Information:");
        System.out.println("Roll Number: " + rollNo);
        System.out.println("Name: " + name);
        System.out.println("Class: " + className);
        System.out.println("Percentage: " + percentage + "%");
    }

    // Read student information from the console
    public static Student readStudentInfoFromConsole() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter Student Information:");

        System.out.print("Roll Number: ");
        int rollNo = Integer.parseInt(reader.readLine());

        System.out.print("Name: ");
        String name = reader.readLine();

        System.out.print("Class: ");
        String className = reader.readLine();

        System.out.print("Percentage: ");
        double percentage = Double.parseDouble(reader.readLine());

        return new Student(rollNo, name, className, percentage);
    }
}

public class q1 {
    public static void main(String[] args) {
        try {
            // Read student information from the console
            Student student = Student.readStudentInfoFromConsole();

            // Display student information
            student.displayStudentInfo();
        } catch (IOException e) {
            System.out.println("An error occurred while reading input: " + e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println("Invalid input. Please enter valid numeric values for Roll Number and Percentage.");
        }
    }
}

