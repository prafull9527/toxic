import java.util.Arrays;
import java.util.Scanner;

public class q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of cities (n): ");
        int n = scanner.nextInt();

        // Create an array to store the names of cities
        String[] cities = new String[n];

        // Input names of cities from the user
        for (int i = 0; i < n; i++) {
            System.out.print("Enter the name of city " + (i + 1) + ": ");
            cities[i] = scanner.next();
        }

        // Sort the array of cities in ascending order
        Arrays.sort(cities);

        // Display the sorted list of cities
        System.out.println("\nCities in ascending order:");
        for (String city : cities) {
            System.out.println(city);
        }

        scanner.close();
    }
}

