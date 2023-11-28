import java.util.Scanner;

class Person {
    private String personName;
    private String aadharNo;
    private String panNo;

    // Parameterized constructor
    public Person(String personName, String aadharNo, String panNo) {
        this.personName = personName;
        this.aadharNo = aadharNo;
        this.panNo = panNo;
    }

    // Display person information
    public void displayPersonInfo() {
        System.out.println("Person Information:");
        System.out.println("Name: " + this.personName);
        System.out.println("Aadhar Number: " + this.aadharNo);
        System.out.println("PAN Number: " + this.panNo);
        System.out.println("-----------------------");
    }
}

public class q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Person[] persons = new Person[5];

        System.out.println("Enter information for 5 persons:");

        for (int i = 0; i < 5; i++) {
            System.out.println("\nEnter details for Person " + (i + 1) + ":");
            System.out.print("Enter Person Name: ");
            String name = scanner.nextLine();

            System.out.print("Enter Aadhar Number: ");
            String aadhar = scanner.nextLine();

            System.out.print("Enter PAN Number: ");
            String pan = scanner.nextLine();

            persons[i] = new Person(name, aadhar, pan);
        }

        // Display information for all persons
        System.out.println("\nPersons Information:");
        for (Person person : persons) {
            System.out.println("\n-----------------------");
            person.displayPersonInfo();
        }
    }
}

