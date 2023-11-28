import java.util.ArrayList;
import java.util.List;

class Customer {
    private int custNo;
    private String custName;
    private String contactNumber;
    private String custAddr;

    // Constructor
    public Customer(int custNo, String custName, String contactNumber, String custAddr) {
        this.custNo = custNo;
        this.custName = custName;
        this.contactNumber = contactNumber;
        this.custAddr = custAddr;
    }

    // Method to search for customer by contact number
    public static Customer searchCustomerByContactNumber(List<Customer> customerList, String contactNumber) {
        for (Customer customer : customerList) {
            if (customer.getContactNumber().equals(contactNumber)) {
                return customer;
            }
        }
        return null; // Return null if no customer is found with the given contact number
    }

    // Getter method for contact number
    public String getContactNumber() {
        return contactNumber;
    }

    // Display customer details
    public void displayCustomerDetails() {
        System.out.println("Customer Details:");
        System.out.println("Customer Number: " + custNo);
        System.out.println("Customer Name: " + custName);
        System.out.println("Contact Number: " + contactNumber);
        System.out.println("Customer Address: " + custAddr);
        System.out.println("-----------------------");
    }
}

public class q1 {
    public static void main(String[] args) {
        // Create a list of customers
        List<Customer> customerList = new ArrayList<>();
        customerList.add(new Customer(1, "John Doe", "1234567890", "123 Main St"));
        customerList.add(new Customer(2, "Alice Smith", "9876543210", "456 Oak St"));
        customerList.add(new Customer(3, "Bob Johnson", "5556667777", "789 Pine St"));

        // Search for a customer by contact number
        String searchContactNumber = "9876543210";
        Customer foundCustomer = Customer.searchCustomerByContactNumber(customerList, searchContactNumber);

        // Display customer details if found
        if (foundCustomer != null) {
            foundCustomer.displayCustomerDetails();
        } else {
            System.out.println("No customer found with contact number: " + searchContactNumber);
        }
    }
}

