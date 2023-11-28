// SY package
package SY;

public class SYMarks {
    int ComputerTotal;
    int MathsTotal;
    int ElectronicsTotal;

    public SYMarks(int computerTotal, int mathsTotal, int electronicsTotal) {
        ComputerTotal = computerTotal;
        MathsTotal = mathsTotal;
        ElectronicsTotal = electronicsTotal;
    }
}

// TY package
package TY;

public class TYMarks {
    int Theory;
    int Practicals;

    public TYMarks(int theory, int practicals) {
        Theory = theory;
        Practicals = practicals;
    }
}

// Student package
import SY.SYMarks;
import TY.TYMarks;

class Student {
    int rollNumber;
    String name;
    SYMarks syMarks;
    TYMarks tyMarks;

    public Student(int rollNumber, String name, SYMarks syMarks, TYMarks tyMarks) {
        this.rollNumber = rollNumber;
        this.name = name;
        this.syMarks = syMarks;
        this.tyMarks = tyMarks;
    }

    public int calculateComputerTotal() {
        return syMarks.ComputerTotal + tyMarks.Theory;
    }

    public void displayResult() {
        int computerTotal = calculateComputerTotal();
        int mathsTotal = syMarks.MathsTotal;
        int electronicsTotal = syMarks.ElectronicsTotal;
        int practicals = tyMarks.Practicals;

        int totalMarks = computerTotal + mathsTotal + electronicsTotal + practicals;

        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Name: " + name);
        System.out.println("Computer Total: " + computerTotal);
        System.out.println("Maths Total: " + mathsTotal);
        System.out.println("Electronics Total: " + electronicsTotal);
        System.out.println("Practicals: " + practicals);
        System.out.println("Total Marks: " + totalMarks);

        // Calculate Grade
        if (totalMarks >= 70) {
            System.out.println("Grade: A");
        } else if (totalMarks >= 60) {
            System.out.println("Grade: B");
        } else if (totalMarks >= 50) {
            System.out.println("Grade: C");
        } else if (totalMarks >= 40) {
            System.out.println("Grade: Pass Class");
        } else {
            System.out.println("Grade: FAIL");
        }

        System.out.println("--------------------------------------");
    }
}

// Main class
public class q2 {
    public static void main(String[] args) {
        // Create 'n' objects of Student class
        Student student1 = new Student(1, "John", new SYMarks(80, 75, 85), new TYMarks(70, 80));
        Student student2 = new Student(2, "Alice", new SYMarks(65, 60, 70), new TYMarks(75, 85));

        // Display results
        student1.displayResult();
        student2.displayResult();
    }
}

