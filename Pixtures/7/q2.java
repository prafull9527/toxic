import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class q2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the path of the text file: ");
        String filePath = scanner.nextLine();

        try {
            // Read the contents of the file
            String fileContents = readFile(filePath);

            // Display the original contents
            System.out.println("Original Contents:");
            System.out.println(fileContents);

            // Display the contents in reverse order and change case
            String reversedAndChangedCase = reverseAndChangeCase(fileContents);
            System.out.println("\nReversed and Changed Case Contents:");
            System.out.println(reversedAndChangedCase);
        } catch (IOException e) {
            System.out.println("Error reading the file: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }

    private static String readFile(String filePath) throws IOException {
        StringBuilder content = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                content.append(line).append("\n");
            }
        }
        return content.toString();
    }

    private static String reverseAndChangeCase(String original) {
        StringBuilder reversedAndChangedCase = new StringBuilder();
        for (int i = original.length() - 1; i >= 0; i--) {
            char currentChar = original.charAt(i);
            if (Character.isUpperCase(currentChar)) {
                reversedAndChangedCase.append(Character.toLowerCase(currentChar));
            } else if (Character.isLowerCase(currentChar)) {
                reversedAndChangedCase.append(Character.toUpperCase(currentChar));
            } else {
                reversedAndChangedCase.append(currentChar);
            }
        }
        return reversedAndChangedCase.toString();
    }
}

