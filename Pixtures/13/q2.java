import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class q2 {
    public static void main(String[] args) {
        // Get the current date and time
        LocalDateTime currentDateTime = LocalDateTime.now();

        // Format 1: dd/MM/yyyy
        String format1 = currentDateTime.format(DateTimeFormatter.ofPattern("dd/MM/yyyy"));
        System.out.println("Current date is: " + format1);

        // Format 2: MM-dd-yyyy
        String format2 = currentDateTime.format(DateTimeFormatter.ofPattern("MM-dd-yyyy"));
        System.out.println("Current date is: " + format2);

        // Format 3: EEEE MMMM dd yyyy
        String format3 = currentDateTime.format(DateTimeFormatter.ofPattern("EEEE MMMM dd yyyy"));
        System.out.println("Current date is: " + format3);

        // Format 4: EEEE MMMM dd HH:mm:ss z yyyy
        String format4 = currentDateTime.format(DateTimeFormatter.ofPattern("EEE MMM dd HH:mm:ss z yyyy"));
        System.out.println("Current date and time is: " + format4);

        // Format 5: dd/MM/yy HH:mm:ss a Z
        String format5 = currentDateTime.format(DateTimeFormatter.ofPattern("dd/MM/yy HH:mm:ss a Z"));
        System.out.println("Current date and time is: " + format5);
    }
}

