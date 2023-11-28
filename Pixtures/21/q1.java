class InvalidDateException extends Exception {
    public InvalidDateException(String message) {
        super(message);
    }
}

class MyDate {
    private int day;
    private int month;
    private int year;

    public MyDate(int day, int month, int year) throws InvalidDateException {
        if (isValidDate(day, month, year)) {
            this.day = day;
            this.month = month;
            this.year = year;
        } else {
            throw new InvalidDateException("Invalid date entered.");
        }
    }

    public void displayDate() {
        System.out.println("Date: " + day + "/" + month + "/" + year);
    }

    private boolean isValidDate(int day, int month, int year) {
        if (month < 1 || month > 12 || day < 1) {
            return false;
        }

        int maxDaysInMonth;
        if (month == 2) {
            // Check for leap year
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                maxDaysInMonth = 29;
            } else {
                maxDaysInMonth = 28;
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            maxDaysInMonth = 30;
        } else {
            maxDaysInMonth = 31;
        }

        return day <= maxDaysInMonth;
    }
}

public class q1 {
    public static void main(String[] args) {
        try {
            // Create MyDate objects with valid and invalid dates
            MyDate validDate = new MyDate(15, 7, 2022);
            MyDate invalidDate = new MyDate(32, 13, 2023); // This should throw an InvalidDateException

            // Display valid date
            validDate.displayDate();
        } catch (InvalidDateException e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}

