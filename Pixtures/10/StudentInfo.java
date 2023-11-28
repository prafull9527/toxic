// Package declaration
package student;

import java.util.Scanner;

// Class in the student package to display student information
public class StudentInfo {
    private int rollNo;
    private String studentClass;
    private double percentage;

    // Parameterized constructor
    public StudentInfo(int rollNo, String studentClass, double percentage) {
        this.rollNo = rollNo;
        this.studentClass = studentClass;
        this.percentage = percentage;
    }

    // Method to display student information
    public void displayStudentInfo() {
        System.out.println("Roll Number: " + rollNo);
        System.out.println("Class: " + studentClass);
        System.out.println("Percentage: " + percentage + "%");
    }
}

// Another class in the student package to calculate student percentage
class StudentPer {
    // Method to find the percentage of the student
    public static double calculatePercentage(int[] marks) {
        int totalMarks = 0;
        for (int mark : marks) {
            totalMarks += mark;
        }

        return (double) totalMarks / marks.length;
    }
}

// Main class outside the student package
public class StudentTest {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Accepting student details from the user
        System.out.print("Enter Roll Number: ");
        int rollNo = scanner.nextInt();

        System.out.print("Enter Class: ");
        String studentClass = scanner.next();

        int[] marks = new int[6];
        System.out.println("Enter Marks for 6 Subjects:");
        for (int i = 0; i < 6; i++) {
            System.out.print("Subject " + (i + 1) + ": ");
            marks[i] = scanner.nextInt();
        }

        // Creating an object of StudentPer to calculate percentage
        double percentage = StudentPer.calculatePercentage(marks);

        // Creating an object of StudentInfo to display student information
        StudentInfo studentInfo = new StudentInfo(rollNo, studentClass, percentage);

        // Displaying student information
        System.out.println("\nStudent Information:");
        studentInfo.displayStudentInfo();

        scanner.close();
    }
}

