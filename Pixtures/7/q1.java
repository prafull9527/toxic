import java.util.Scanner;

class Bank {
    private String accountHolderName;
    private double balance;

    // Constructor
    public Bank(String accountHolderName, double initialBalance) {
        this.accountHolderName = accountHolderName;
        this.balance = initialBalance;
    }

    // Method to deposit money into the account
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
System.out.println("Deposit successful. $" + amount + " deposited.");
}
else 
{
System.out.println("Invalid deposit amount. Please enter a positive value.");
        }
    }

    // Method to withdraw money from the account
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            System.out.println("Withdrawal successful. $" + amount + " withdrawn.");
        } else {
            System.out.println("Invalid withdrawal amount or insufficient funds.");
        }
    }

    // Method to check the balance
    public void checkBalance() {
        System.out.println("Account Holder: " + accountHolderName);
        System.out.println("Current Balance: $" + balance);
    }
}

public class q1 {
    public static void main(String[] args) {
        // Example usage of the Bank class
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter account holder name: ");
        String accountHolderName = scanner.nextLine();

        System.out.print("Enter initial balance: $");
        double initialBalance = scanner.nextDouble();

        // Create Bank object
        Bank myAccount = new Bank(accountHolderName, initialBalance);

        // Perform operations
        myAccount.checkBalance();

        System.out.print("Enter deposit amount: $");
        double depositAmount = scanner.nextDouble();
        myAccount.deposit(depositAmount);

        System.out.print("Enter withdrawal amount: $");
        double withdrawalAmount = scanner.nextDouble();
        myAccount.withdraw(withdrawalAmount);

        myAccount.checkBalance();

        scanner.close();
    }
}

