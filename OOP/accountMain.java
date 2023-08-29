class Account {
    private int accountNumber;
    protected double balance;

    public Account(int accountNumber, double balance) {
        this.accountNumber = accountNumber;
        this.balance = balance;
    }

    public void deposit(double amount) {
        this.balance += amount;
    }

    public void withdraw(double amount) {
        if (this.balance < amount) {
            throw new IllegalArgumentException("Insufficient balance");
        }
        this.balance -= amount;
    }

    public void displayBalance() {
        System.out.println("Account number: " + this.accountNumber);
        System.out.println("Account balance: " + this.balance);
    }
}

class SavingsAccount extends Account {
    private double interest;

    public SavingsAccount(int accountNumber, double balance, double interest) {
        super(accountNumber, balance);
        this.interest = interest;
    }

    public void calculateInterest() {
        this.balance += this.balance * this.interest;
    }

    public void displayAll() {
        super.displayBalance();
        System.out.println("Interest: " + this.interest);
    }
}

class CurrentAccount extends Account {
    private double overdraftLimit;

    public CurrentAccount(int accountNumber, double balance, double overdraftLimit) {
        super(accountNumber, balance);
        this.overdraftLimit = overdraftLimit;
    }

    @Override
    public void withdraw(double amount) {
        if (this.balance - amount < -this.overdraftLimit) {
            throw new IllegalArgumentException("Overdraft limit exceeded");
        }
        super.withdraw(amount);
    }

    public void displayAll() {
        super.displayBalance();
        System.out.println("Overdraft limit: " + this.overdraftLimit);
    }
}

public class accountMain {
    public static void main(String[] args) {
        SavingsAccount savingsAccount = new SavingsAccount(123456789, 1000, 1);
        savingsAccount.deposit(1000);
        savingsAccount.calculateInterest();
        savingsAccount.displayAll();

        CurrentAccount currentAccount = new CurrentAccount(987654321, 5000, 1000);
        currentAccount.withdraw(2000);
        currentAccount.displayAll();
    }
}
