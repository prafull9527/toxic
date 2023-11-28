// Marker Interface
interface Displayable {}

// Product class implementing the marker interface
class Product implements Displayable {
    private int productId;
    private String productName;
    private double productCost;
    private int productQuantity;
    private static int objectCount = 0;

    // Default constructor
    public Product() {
        objectCount++;
    }

    // Parameterized constructor
    public Product(int productId, String productName, double productCost, int productQuantity) {
        this.productId = productId;
        this.productName = productName;
        this.productCost = productCost;
        this.productQuantity = productQuantity;
        objectCount++;
    }

    // Method to display the contents of the product
    public void displayProduct() {
        System.out.println("Product ID: " + productId);
        System.out.println("Product Name: " + productName);
        System.out.println("Product Cost: $" + productCost);
        System.out.println("Product Quantity: " + productQuantity);
        System.out.println("----------------------------");
    }

    // Method to display the object count
    public static void displayObjectCount() {
        System.out.println("Total Product Objects: " + objectCount);
    }
}

public class q2 {
    public static void main(String[] args) {
        // Creating objects of the Product class
        Product product1 = new Product(101, "Laptop", 1200.50, 5);
        Product product2 = new Product(102, "Mobile Phone", 500.75, 10);
        Product product3 = new Product();

        // Displaying the contents of each object
        System.out.println("Product 1 Details:");
        product1.displayProduct();

        System.out.println("Product 2 Details:");
        product2.displayProduct();

        System.out.println("Product 3 Details:");
        product3.displayProduct();

        // Displaying the object count
        Product.displayObjectCount();
    }
}

