import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class q1 {
    public static void main(String[] args) {
        // Check if a file name is provided as a command-line argument
        if (args.length != 1) {
            System.out.println("Usage: java FileWordLineCount <filename>");
            return;
        }

        // Get the file name from the command-line argument
        String fileName = args[0];

        // Create a Path object from the file name
        Path filePath = Paths.get(fileName);

        // Check if the file exists
        if (Files.exists(filePath) && Files.isRegularFile(filePath)) {
            try {
                // Read all lines from the file
                List<String> lines = Files.readAllLines(filePath);

                // Count the number of words and lines
                int wordCount = 0;
                int lineCount = lines.size();

                for (String line : lines) {
                    String[] words = line.split("\\s+"); // Split the line into words
                    wordCount += words.length;
                }

                // Display the results
                System.out.println("Number of words in the file: " + wordCount);
                System.out.println("Number of lines in the file: " + lineCount);
            } catch (IOException e) {
                System.out.println("Error reading the file: " + e.getMessage());
            }
        } else {
            System.out.println("File does not exist or is not a regular file.");
        }
    }
}

