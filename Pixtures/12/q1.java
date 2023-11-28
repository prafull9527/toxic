class College {
    private int cno;
    private String cname;
    private String caddr;

    // Parameterized constructor for College class
    public College(int cno, String cname, String caddr) {
        this.cno = cno;
        this.cname = cname;
        this.caddr = caddr;
    }

    // Method to display College details
    public void displayCollegeDetails() {
        System.out.println("College Number: " + cno);
        System.out.println("College Name: " + cname);
        System.out.println("College Address: " + caddr);
    }
}

class Department extends College {
    private int dno;
    private String dname;

    // Parameterized constructor for Department class
    public Department(int cno, String cname, String caddr, int dno, String dname) {
        super(cno, cname, caddr);
        this.dno = dno;
        this.dname = dname;
    }

    // Method to display Department details along with College details
    public void displayDepartmentDetails() {
        // Call the displayCollegeDetails method from the parent class
        displayCollegeDetails();

        System.out.println("Department Number: " + dno);
        System.out.println("Department Name: " + dname);
    }
}

public class q2 {
    public static void main(String[] args) {
        // Creating an object of the Department class
        Department department = new Department(1, "ABC College", "123 Main Street", 101, "Computer Science");

        // Displaying College and Department details
        System.out.println("College and Department Details:");
        department.displayDepartmentDetails();
    }
}

