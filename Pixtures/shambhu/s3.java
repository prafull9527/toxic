//s3 q1
import java.util.Scanner;
public class n {
public void SortCities(String [] arr){
int d=0;
while(d!=arr.length) {
for (int i = 0; i <= arr.length - 2; i++) {
for (int j = i + 1; j <= arr.length - 1; j++) {
if (arr[i].length() > arr[j].length()) {
String temp = " ";
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
}
d++;
}
for (String element:arr) {
System.out.println(" "+element);
}
}
public static void main(String[] args) {
java.util.Scanner sc = new java.util.Scanner(System.in);
java.util.Scanner scc = new java.util.Scanner(System.in);
System.out.println("Enter how many cities: ");
int a = sc.nextInt();
String [] city = new String[a];
for(int i=0; i<a; i++){
System.out.format("Enter the %d city name: ",(i+1));
city[i]=scc.nextLine();
}
s.SortCities(city);
}
}





//Q2
import java.util.Scanner;
class CovidPositiveException extends Exception {
public CovidPositiveException(String message) {
super(message);
}
}
class Patient {
String patientName;
int patientAge;
double patientOxyLevel;
int patientHRCTReport;
public Patient(String patientName, int patientAge, double patientOxyLevel, int patientHRCTReport) throws CovidPositiveException {
this.patientName = patientName;
this.patientAge = patientAge;
if (patientOxyLevel < 95.0) {
throw new CovidPositiveException("Patient is Covid Positive(+) and Needs to be Hospitalized. Oxygen level is less than 95%.");
}
if (patientHRCTReport > 10) {
throw new CovidPositiveException("Patient is Covid Positive(+) and Needs to be Hospitalized. HRCT scan report is greater than 10.");
}
this.patientOxyLevel = patientOxyLevel;
this.patientHRCTReport = patientHRCTReport;
}
public void displayPatientInfo() {
System.out.println("Patient Information:");
System.out.println("Name: " + patientName);
System.out.println("Age: " + patientAge);
System.out.println("Oxygen Level: " + patientOxyLevel + "%");
System.out.println("HRCT Report: " + patientHRCTReport);
}
}
public class main4 {
public static void main(String[] args) {
try {
Patient patient = new Patient("John Doe", 30, 92.5, 8);
patient.displayPatientInfo();
} catch (CovidPositiveException e) {
System.out.println("Exception: " + e.getMessage());
}
}
}
