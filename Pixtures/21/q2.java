class Employee {
    private int id;
    private String name;
    private String deptName;
    private double salary;
    private static int objectCount = 0;

    // Default constructor
    public Employee() {
        this.id = 0;
        this.name = "Unknown";
        this.deptName = "Unknown";
        this.salary = 0.0;
        objectCount++;
    }

    // Parameterized constructor
    public Employee(int id, String name, String deptName, double salary) {
        this.id = id;
        this.name = name;
        this.deptName = deptName;
        this.salary = salary;
        objectCount++;
        displayObjectCount();
    }

    // Static method to get the object count
    public static int getObjectCount() {
        return objectCount;
    }

    // Display object count
    private void displayObjectCount() {
        System.out.println("Object count: " + objectCount);
    }

    // Display employee details
    public void displayEmployeeDetails() {
        System.out.println("Employee Details:");
        System.out.println("ID: " + id);
        System.out.println("Name: " + name);
        System.out.println("Department: " + deptName);
        System.out.println("Salary: " + salary);
        System.out.println("-----------------------");
    }
}

public class q2 {
    public static void main(String[] args) {
        // Create objects using parameterized constructor
        Employee emp1 = new Employee(1, "John Doe", "HR", 50000.0);
        Employee emp2 = new Employee(2, "Alice Smith", "IT", 60000.0);

        // Display object count and employee details
        System.out.println("Total Objects created: " + Employee.getObjectCount());
        emp1.displayEmployeeDetails();
        emp2.displayEmployeeDetails();
    }
}

