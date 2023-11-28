// User-defined exception class for COVID-19 positive patients
class CovidPositiveException extends Exception {
    public CovidPositiveException(String message) {
        super(message);
    }
}

// Class representing a patient
class Patient {
    private String patientName;
    private int patientAge;
    private double oxygenLevel;
    private int hrctReport;

    // Parameterized constructor
    public Patient(String patientName, int patientAge, double oxygenLevel, int hrctReport) {
        this.patientName = patientName;
        this.patientAge = patientAge;
        this.oxygenLevel = oxygenLevel;
        this.hrctReport = hrctReport;
    }

    // Method to check if the patient is COVID-19 positive
    public void checkCovidStatus() throws CovidPositiveException {
        if (oxygenLevel < 95 && hrctReport > 10) {
            throw new CovidPositiveException("Patient is Covid Positive(+) and Need to be Hospitalized");
        } else {
            displayPatientInfo();
        }
    }

    // Method to display patient information
    private void displayPatientInfo() {
        System.out.println("Patient Information:");
        System.out.println("Name: " + patientName);
        System.out.println("Age: " + patientAge);
        System.out.println("Oxygen Level: " + oxygenLevel + "%");
        System.out.println("HRCT Report: " + hrctReport);
    }
}

public class q2 {
    public static void main(String[] args) {
        try {
            // Create a Patient object
            Patient patient = new Patient("prafull chavan", 30, 94.5, 8);

            // Check COVID-19 status and display information
            patient.checkCovidStatus();
        } catch (CovidPositiveException e) {
            System.out.println("Exception: " + e.getMessage());
        }
    }
}

