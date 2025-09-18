#include <stdio.h>

void check_balance(double balance);
double deposit(double balance);
double withdraw(double balance);

int main() {
    double balance = 5000.00; 
    int choice;

    printf("SB Microfinance Bank\n");
    printf("Welcome Our Esteemed Costumer\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_balance(balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                printf("Thank you for banking with us. Goodbye and Hope to see you again!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// Function to check balance
void check_balance(double balance) {
    printf("Your current balance is: $%.2f\n", balance);
}

// Function for making deposits
double deposit(double balance) {
    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount. Please enter a positive value.\n");
    } else {
        balance += amount;
        printf("Successfully deposited $%.2f. New balance: $%.2f\n", amount, balance);
    }
    return balance;
}

// Function for making withdrawals
double withdraw(double balance) {
    double amount;
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("Invalid withdrawal amount. Please enter a positive value.\n");
    } else if (amount > balance) {
        printf("Insufficient funds! Your balance is $%.2f\n", balance);
    } else {
        balance -= amount;
        printf("Successfully withdrew $%.2f. New balance: $%.2f\n", amount, balance);
    }
    return balance;
}
