class Account {
    String custName;
    int accNo;

    // Default constructor
    public Account() {
        this.custName = "";
        this.accNo = 0;
    }

    // Parameterized constructor
    public Account(String custName, int accNo) {
        this.custName = custName;
        this.accNo = accNo;
    }

    public void displayCustomerDetails() {
        System.out.println("Customer Name: " + custName);
        System.out.println("Account Number: " + accNo);
    }
}

class SavingAccount extends Account {
    double savingBal;
    double minBal;

    // Default constructor
    public SavingAccount() {
        super(); // Call the default constructor of the base class (Account)
        this.savingBal = 0.0;
        this.minBal = 0.0;
    }

    // Parameterized constructor
    public SavingAccount(String custName, int accNo, double savingBal, double minBal) {
        super(custName, accNo); // Call the parameterized constructor of the base class (Account)
        this.savingBal = savingBal;
        this.minBal = minBal;
    }
}

class AccountDetail extends SavingAccount {
    double depositAmt;
    double withdrawalAmt;

    // Default constructor
    public AccountDetail() {
        super(); // Call the default constructor of the base class (SavingAccount)
        this.depositAmt = 0.0;
        this.withdrawalAmt = 0.0;
    }

    // Parameterized constructor
    public AccountDetail(String custName, int accNo, double savingBal, double minBal, double depositAmt, double withdrawalAmt) {
        super(custName, accNo, savingBal, minBal); // Call the parameterized constructor of the base class (SavingAccount)
        this.depositAmt = depositAmt;
        this.withdrawalAmt = withdrawalAmt;
    }

    // Method to display customer details
    public void displayCustomerDetails() {
        super.displayCustomerDetails(); // Call the displayCustomerDetails method of the base class (Account)
        System.out.println("Saving Balance: " + savingBal);
        System.out.println("Minimum Balance: " + minBal);
        System.out.println("Deposit Amount: " + depositAmt);
        System.out.println("Withdrawal Amount: " + withdrawalAmt);
    }
}

public class q2 {
    public static void main(String[] args) {
        // Create an object of AccountDetail
        AccountDetail account1 = new AccountDetail("John Doe", 123456, 1000.0, 500.0, 200.0, 50.0);

        // Display customer details
        account1.displayCustomerDetails();
    }
}

