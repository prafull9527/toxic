public class Clock {
    private int hours;
    private int minutes;
    private int seconds;
    private boolean isAM;

    // Default constructor
    public Clock() {
        this.hours = 0;
        this.minutes = 0;
        this.seconds = 0;
        this.isAM = true;
    }

    // Parameterized constructor with input validation
    public Clock(int hours, int minutes, int seconds, boolean isAM) {
        setClock(hours, minutes, seconds, isAM);
    }

    // Method to set the time with input validation
    public void setClock(int hours, int minutes, int seconds, boolean isAM) {
        if (isValidTime(hours, minutes, seconds)) {
            this.hours = hours;
            this.minutes = minutes;
            this.seconds = seconds;
            this.isAM = isAM;
        } else {
            System.out.println("Invalid time input. Please provide valid hours, minutes, and seconds.");
        }
    }

    // Method to check the validity of the time
    private boolean isValidTime(int hours, int minutes, int seconds) {
        return (hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60) && (seconds >= 0 && seconds < 60);
    }

    // Method to display the time in AM/PM format
    public void displayTime() {
        System.out.printf("Time: %02d:%02d:%02d %s%n", hours, minutes, seconds, isAM ? "AM" : "PM");
    }

    public static void main(String[] args) {
        // Example usage of the Clock class
        Clock myClock = new Clock(12, 30, 45, true);
        myClock.displayTime();

        // Trying to set an invalid time
        myClock.setClock(25, 70, 80, false);
        myClock.displayTime(); // This should display the original time, not the invalid input
    }
}

