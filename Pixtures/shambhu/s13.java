//slip 13 Q1
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class FileWordLineCounter {
public static void main(String[] args) {
if (args.length != 1) {
System.out.println("Usage: java FileWordLineCounter <filename>");
return;
}
String fileName = args[0];
try {
int wordCount = countWords(fileName);
int lineCount = countLines(fileName);
System.out.println("Number of words in the file: " + wordCount);
System.out.println("Number of lines in the file: " + lineCount);
} catch (IOException e) {
System.out.println("Error reading the file: " + e.getMessage());
}
}
private static int countWords(String fileName) throws IOException {
int wordCount = 0;
try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
String line;
while ((line = reader.readLine()) != null) {
String[] words = line.split("\\s+"); 
wordCount += words.length;
}
}
return wordCount;
}
private static int countLines(String fileName) throws IOException {
int lineCount = 0;
try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
while (reader.readLine() != null) {
lineCount++;
}
}
return lineCount
}
}




//q2
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
public class DateTimeFormatter {
public static void main(String[] args) {
Date currentDate = new Date();
displayFormattedDate("dd/MM/yyyy", currentDate);
displayFormattedDate("MM-dd-yyyy", currentDate);
displayFormattedDate("EEEE MMMM dd yyyy", currentDate);
displayFormattedDateTime("EEE MMM dd HH:mm:ss z yyyy", currentDate);
displayFormattedDateTime("dd/MM/yy HH:mm:ss a Z", currentDate);
}
private static void displayFormattedDate(String pattern, Date date) {
SimpleDateFormat dateFormat = new SimpleDateFormat("Current date is : " + pattern);
System.out.println(dateFormat.format(date));
}
private static void displayFormattedDateTime(String pattern, Date date) {
SimpleDateFormat dateTimeFormat = new SimpleDateFormat("Current date and time is : " + pattern, Locale.US);
System.out.println(dateTimeFormat.format(date));
}
}