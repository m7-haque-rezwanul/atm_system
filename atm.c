// atm.c

#include "atm.h"
#include <stdlib.h>
#include <string.h>

// Function to load account data from a file
void load_account(Account *acc, int account_number) {
    char filename[20];
    sprintf(filename, "%d.dat", account_number);
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Account not found.\n");
        exit(1);
    }

    fread(acc, sizeof(Account), 1, file);
    fclose(file);
}

// Function to save account data to a file
void save_account(Account *acc) {
    char filename[20];
    sprintf(filename, "%d.dat", acc->account_number);
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Error saving account data.\n");
        exit(1);
    }

    fwrite(acc, sizeof(Account), 1, file);
    fclose(file);
}

// Authentication function
int authenticate(Account *acc) {
    int pin_attempt;
    printf("Enter PIN: ");
    scanf("%d", &pin_attempt);

    return pin_attempt == acc->pin;
}

// Balance inquiry
void display_balance(Account *acc) {
    printf("Your current balance is: $%.2f\n", acc->balance);
}

// Cash withdrawal
void withdraw_cash(Account *acc) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > acc->balance) {
        printf("Insufficient balance.\n");
    } else {
        acc->balance -= amount;
        sprintf(acc->transaction_history[acc->transaction_count++], "Withdrawn: $%.2f", amount);
        printf("Please take your cash.\n");
    }
}

// Cash deposit
void deposit_cash(Account *acc) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    acc->balance += amount;
    sprintf(acc->transaction_history[acc->transaction_count++], "Deposited: $%.2f", amount);
    printf("Amount successfully deposited.\n");
}

// Transaction history display
void display_transaction_history(Account *acc) {
    printf("Transaction History:\n");
    for (int i = 0; i < acc->transaction_count; i++) {
        printf("%s\n", acc->transaction_history[i]);
    }
}

// Change PIN function
void change_pin(Account *acc) {
    int old_pin, new_pin;
    printf("Enter old PIN: ");
    scanf("%d", &old_pin);

    if (old_pin == acc->pin) {
        printf("Enter new PIN: ");
        scanf("%d", &new_pin);
        acc->pin = new_pin;
        printf("PIN successfully changed.\n");
    } else {
        printf("Incorrect PIN.\n");
    }
}
