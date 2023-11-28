import java.util.Scanner;

class Sphere {
    private double radius;

    // Constructor
    public Sphere(double radius) {
        this.radius = radius;
    }

    // Method to calculate the surface area of the sphere
    public double calculateSurfaceArea() {
        return 4 * Math.PI * Math.pow(radius, 2);
    }

    // Method to calculate the volume of the sphere
    public double calculateVolume() {
        return (4.0 / 3.0) * Math.PI * Math.pow(radius, 3);
    }
}

public class q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the radius of the sphere: ");
        double radius = scanner.nextDouble();

        // Create Sphere object
        Sphere mySphere = new Sphere(radius);

        // Calculate and display surface area and volume
        double surfaceArea = mySphere.calculateSurfaceArea();
        double volume = mySphere.calculateVolume();

        System.out.println("Surface Area of the Sphere: " + surfaceArea);
        System.out.println("Volume of the Sphere: " + volume);

        scanner.close();
    }
}

