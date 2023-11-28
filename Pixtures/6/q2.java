import java.util.Scanner;

// Abstract class Order
abstract class Order {
    protected int id;
    protected String description;

    // Abstract method to be implemented by subclasses
    protected abstract void accept();

    // Abstract method to be implemented by subclasses
    protected abstract void display();
}

// Subclass PurchaseOrder extending Order
class PurchaseOrder extends Order {
    private String customerName;

    // Implementation of the abstract method accept for PurchaseOrder
    @Override
    protected void accept() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Purchase Order ID: ");
        id = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        System.out.print("Enter Purchase Order Description: ");
        description = scanner.nextLine();
        System.out.print("Enter Customer Name: ");
        customerName = scanner.nextLine();
    }

    // Implementation of the abstract method display for PurchaseOrder
    @Override
    protected void display() {
        System.out.println("\nPurchase Order Details:");
        System.out.println("ID: " + id);
        System.out.println("Description: " + description);
        System.out.println("Customer Name: " + customerName);
    }
}

// Subclass SalesOrder extending Order
class SalesOrder extends Order {
    private String vendorName;

    // Implementation of the abstract method accept for SalesOrder
    @Override
    protected void accept() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Sales Order ID: ");
        id = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character
        System.out.print("Enter Sales Order Description: ");
        description = scanner.nextLine();
        System.out.print("Enter Vendor Name: ");
        vendorName = scanner.nextLine();
    }

    // Implementation of the abstract method display for SalesOrder
    @Override
    protected void display() {
        System.out.println("\nSales Order Details:");
        System.out.println("ID: " + id);
        System.out.println("Description: " + description);
        System.out.println("Vendor Name: " + vendorName);
    }
}

public class q2 {
    public static void main(String[] args) {
        // Create three objects each of PurchaseOrder and SalesOrder
        Order[] orders = new Order[6];

        for (int i = 0; i < 3; i++) {
            orders[i] = new PurchaseOrder();
            orders[i].accept();
        }

        for (int i = 3; i < 6; i++) {
            orders[i] = new SalesOrder();
            orders[i].accept();
        }

        // Display details for each order
        System.out.println("\nDetails for each order:");
        for (Order order : orders) {
            order.display();
        }
    }
}

