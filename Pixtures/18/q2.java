import java.util.Arrays;
import java.util.Scanner;

class CricketPlayer {
    String name;
    int noOfInnings;
    int noOfTimesNotOut;
    int totalRuns;
    double batAvg;

    // Parameterized constructor
    public CricketPlayer(String name, int noOfInnings, int noOfTimesNotOut, int totalRuns) {
        this.name = name;
        this.noOfInnings = noOfInnings;
        this.noOfTimesNotOut = noOfTimesNotOut;
        this.totalRuns = totalRuns;
        this.batAvg = avg(totalRuns, noOfInnings - noOfTimesNotOut);
    }

    // Static method to calculate batting average
    public static double avg(int totalRuns, int totalOuts) {
        if (totalOuts == 0) {
            return 0.0;
        }
        return (double) totalRuns / totalOuts;
    }

    // Static method to sort CricketPlayer array based on average
    public static void sort(CricketPlayer[] players) {
        Arrays.sort(players, (a, b) -> Double.compare(b.batAvg, a.batAvg));
    }

    // Method to display player details
    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Number of Innings: " + noOfInnings);
        System.out.println("Number of Times Not Out: " + noOfTimesNotOut);
        System.out.println("Total Runs: " + totalRuns);
        System.out.println("Batting Average: " + batAvg);
        System.out.println();
    }
}

public class q2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of players: ");
        int n = scanner.nextInt();

        // Create an array of CricketPlayer objects
        CricketPlayer[] players = new CricketPlayer[n];

        // Input details for each player
        for (int i = 0; i < n; i++) {
            System.out.println("Enter details for Player " + (i + 1) + ":");
            System.out.print("Name: ");
            String name = scanner.next();
            System.out.print("Number of Innings: ");
            int innings = scanner.nextInt();
            System.out.print("Number of Times Not Out: ");
            int notOuts = scanner.nextInt();
            System.out.print("Total Runs: ");
            int runs = scanner.nextInt();

            // Create a CricketPlayer object and add it to the array
            players[i] = new CricketPlayer(name, innings, notOuts, runs);
        }

        // Sort the array based on batting average
        CricketPlayer.sort(players);

        // Display player details in sorted order
        System.out.println("\nPlayer details in sorted order:");
        for (CricketPlayer player : players) {
            player.displayDetails();
        }

        scanner.close();
    }
}

