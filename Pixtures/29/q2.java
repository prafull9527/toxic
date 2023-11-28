import java.util.ArrayList;
import java.util.Scanner;

class Vehicle {
    protected String company;
    protected double price;

    public Vehicle(String company, double price) {
        this.company = company;
        this.price = price;
    }

    public void displayInfo() {
        System.out.println("Company: " + company);
        System.out.println("Price: $" + price);
    }
}

class LightMotorVehicle extends Vehicle {
    private double mileage;

    public LightMotorVehicle(String company, double price, double mileage) {
        super(company, price);
        this.mileage = mileage;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Mileage: " + mileage + " km/l");
    }
}

class HeavyMotorVehicle extends Vehicle {
    private double capacityInTons;

    public HeavyMotorVehicle(String company, double price, double capacityInTons) {
        super(company, price);
        this.capacityInTons = capacityInTons;
    }

    @Override
    public void displayInfo() {
        super.displayInfo();
        System.out.println("Capacity: " + capacityInTons + " tons");
    }
}

public class q2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Vehicle> vehicles = new ArrayList<>();

        System.out.print("Enter the number of vehicles (n): ");
        int n = scanner.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.println("\nEnter details for Vehicle " + (i + 1) + ":");
            System.out.print("Enter the type of vehicle (Light/Heavy): ");
            String vehicleType = scanner.next();

            System.out.print("Enter the company: ");
            String company = scanner.next();

            System.out.print("Enter the price: ");
            double price = scanner.nextDouble();

            if (vehicleType.equalsIgnoreCase("Light")) {
                System.out.print("Enter the mileage: ");
                double mileage = scanner.nextDouble();
                vehicles.add(new LightMotorVehicle(company, price, mileage));
            } else if (vehicleType.equalsIgnoreCase("Heavy")) {
                System.out.print("Enter the capacity in tons: ");
                double capacityInTons = scanner.nextDouble();
                vehicles.add(new HeavyMotorVehicle(company, price, capacityInTons));
            } else {
                System.out.println("Invalid vehicle type. Please enter Light or Heavy.");
                i--; // Decrement i to re-enter details for the current vehicle
            }
        }

        // Display information for all vehicles
        System.out.println("\nVehicle Information:");
        for (Vehicle vehicle : vehicles) {
            System.out.println("\n-----------------------");
            vehicle.displayInfo();
        }
    }
}

