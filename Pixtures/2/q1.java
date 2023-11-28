public class q1 {
    public static void main(String[] args) {
        if (args.length != 4) {
            System.out.println("Usage: java BMICalculator <FirstName> <LastName> <WeightInKgs> <HeightInMeters>");
            return;
        }

        // Parse command line arguments
        String firstName = args[0];
        String lastName = args[1];
        double weightInKgs = Double.parseDouble(args[2]);
        double heightInMeters = Double.parseDouble(args[3]);

        // Calculate BMI
        double bmi = calculateBMI(weightInKgs, heightInMeters);

        // Display results
        System.out.println("Name: " + firstName + " " + lastName);
        System.out.println("Weight: " + weightInKgs + " kg");
        System.out.println("Height: " + heightInMeters + " meters");
        System.out.println("BMI: " + bmi);
    }

    // Function to calculate BMI
    private static double calculateBMI(double weightInKgs, double heightInMeters) {
        if (heightInMeters <= 0) {
            System.out.println("Error: Height should be greater than zero.");
            return -1; // Returning -1 as an error indicator
        }

        return weightInKgs / (heightInMeters * heightInMeters);
    }
}





/*public class q1{
public void BMI(String Full_Name,double height,
double weight ){
//height in metres and weight in kgs!
String [] arr = Full_Name.split(" ",3);
System.out.println("first name is: "+arr[0]);
System.out.println("the last name is: "+arr[2]);
double BMI = weight/(height * height);
System.out.println("The Body Mass Index is:
"+BMI);
}
public static void main(String[] args) {
XXX_clg_slip_2 b = new XXX_clg_slip_2();
b.BMI("Natawarlaal Prabhashankar
Udhaiwala",1.67,67);
}
}
*/
