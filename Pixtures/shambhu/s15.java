//slip 15 Q1
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
public class s15 {
public static void main(String[] args) {
if (args.length != 2) {
System.out.println("Usage: java FileCopy <sourceFileName> <destinationFileName>");
return;
}
String sourceFileName = args[0];
String destinationFileName = args[1];
try {
copyFileContents(sourceFileName, destinationFileName);
System.out.println("File contents copied successfully from " + sourceFileName + " to " + destinationFileName);
} 
catch (IOException e) {
System.out.println("Error copying file contents: " + e.getMessage());
}
}
private static void copyFileContents(String sourceFileName, String destinationFileName) throws IOException {
try (BufferedReader reader = new BufferedReader(new FileReader(sourceFileName));
BufferedWriter writer = new BufferedWriter(new FileWriter(destinationFileName))) {
String line;
while ((line = reader.readLine()) != null) {
writer.write(line);
writer.newLine(); 
}
}
}
}
