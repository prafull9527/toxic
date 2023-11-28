import java.util.Scanner;

// Abstract class Staff
abstract class Staff {
    protected int id;
    protected String name;

    // Parameterized constructor
    protected Staff(int id, String name) {
        this.id = id;
        this.name = name;
    }

    // Abstract method to be implemented by subclasses
    protected abstract void displayDetails();
}

// Subclass OfficeStaff extending Staff
class OfficeStaff extends Staff {
    private String department;

    // Parameterized constructor for OfficeStaff
    public OfficeStaff(int id, String name, String department) {
        super(id, name);
        this.department = department;
    }

    // Implementation of the abstract method to display details
    @Override
    protected void displayDetails() {
        System.out.println("ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Department: " + department);
        System.out.println();
    }
}

public class q2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of OfficeStaff objects (n): ");
        int n = scanner.nextInt();

        // Create an array to store OfficeStaff objects
        OfficeStaff[] officeStaffArray = new OfficeStaff[n];

        // Input details for each OfficeStaff object
        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for OfficeStaff " + (i + 1) + ":");
            System.out.print("Enter ID: ");
            int id = scanner.nextInt();
            System.out.print("Enter Name: ");
            String name = scanner.next();
            System.out.print("Enter Department: ");
            String department = scanner.next();

            // Create an OfficeStaff object and add it to the array
            officeStaffArray[i] = new OfficeStaff(id, name, department);
        }

        // Display details for each OfficeStaff object
        System.out.println("\nDetails of OfficeStaff:");
        for (OfficeStaff officeStaff : officeStaffArray) {
            officeStaff.displayDetails();
        }

        scanner.close();
    }
}



