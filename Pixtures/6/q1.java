import java.util.Scanner;

class Employee {
    private int empId;
    private String empName;
    private String empDesignation;
    private double empSalary;

    // Parameterized constructor
    public Employee(int empId, String empName, String empDesignation, double empSalary) {
        this.empId = empId;
        this.empName = empName;
        this.empDesignation = empDesignation;
        this.empSalary = empSalary;
    }

    // Override toString() method
    @Override
    public String toString() {
        return "Employee Information:\n" +
                "Empid: " + empId +
                "\nEmpname: " + empName +
                "\nEmpdesignation: " + empDesignation +
                "\nEmpsal: " + empSalary;
    }
}

public class q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input employee details
        System.out.print("Enter Empid: ");
        int empId = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        System.out.print("Enter Empname: ");
        String empName = scanner.nextLine();
        System.out.print("Enter Empdesignation: ");
        String empDesignation = scanner.nextLine();
        System.out.print("Enter Empsal: ");
        double empSalary = scanner.nextDouble();

        // Create an Employee object
        Employee employee = new Employee(empId, empName, empDesignation, empSalary);

        // Display employee information using toString()
        System.out.println(employee.toString());

        scanner.close();
    }
}

