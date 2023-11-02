#include <stdio.h>
#include <string.h>


struct Customer {
    char name[30];
    int accountNumber;
    float balance;
};

// Function to print the names of customers with a balance greater than Rs. 50000
void printCustomersWithBalanceAbove50000(struct Customer customers[], int n) {
    printf("Customers with balance above Rs. 50000:\n");
    for (int i = 0; i < n; i++) {
        if (customers[i].balance > 50000.0) {
            printf("%s\n", customers[i].name);
        }
    }
}

// Function to add Rs. 1000 to the balance of customers with balance more than Rs. 10000
void add1000ToBalance(struct Customer customers[], int n) {
    printf("Incremented balances for customers with balance above Rs. 10000:\n");
    for (int i = 0; i < n; i++) {
        if (customers[i].balance > 10000.0) {
            customers[i].balance += 1000.0;
            printf("%s: Rs. %.2f\n", customers[i].name, customers[i].balance);
        }
    }
}

// Function to withdraw a specified amount from a customer's account
void withdrawAmount(struct Customer customers[], int n, int accountNumber, float amount) {
    for (int i = 0; i < n; i++) {
        if (customers[i].accountNumber == accountNumber) {
            if (customers[i].balance >= amount) {
                customers[i].balance -= amount;
                printf("Rs. %.2f withdrawn from %s's account (Account Number: %d)\n",
                       amount, customers[i].name, customers[i].accountNumber);
            } else {
                printf("Insufficient balance to withdraw Rs. %.2f from %s's account (Account Number: %d)\n",
                       amount, customers[i].name, customers[i].accountNumber);
            }
            return;
        }
    }
    printf("Customer with Account Number %d not found.\n", accountNumber);
}

int main() {
    struct Customer customers[15];
    int n = 15;

    // Initialize customer data
    for (int i = 0; i < n; i++) {
        printf("Enter name for customer %d: ", i + 1);
        scanf("%s", customers[i].name);

        printf("Enter account number for customer %d: ", i + 1);
        scanf("%d", &customers[i].accountNumber);

        printf("Enter balance for customer %d: ", i + 1);
        scanf("%f", &customers[i].balance);
    }


    printCustomersWithBalanceAbove50000(customers, n);


    add1000ToBalance(customers, n);


    int accountToWithdraw;
    float amountToWithdraw;
    printf("Enter Account Number to withdraw from: ");
    scanf("%d", &accountToWithdraw);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amountToWithdraw);
    withdrawAmount(customers, n, accountToWithdraw, amountToWithdraw);

    return 0;
}
