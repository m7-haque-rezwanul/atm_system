// atm.h

#ifndef ATM_H
#define ATM_H

#include <stdio.h>

#define MAX_TRANSACTIONS 100

// Struct to store user information
typedef struct {
    int account_number;
    int pin;
    float balance;
    char transaction_history[MAX_TRANSACTIONS][50];
    int transaction_count;
} Account;

// Function prototypes
void load_account(Account *acc, int account_number);
void save_account(Account *acc);
int authenticate(Account *acc);
void display_balance(Account *acc);
void withdraw_cash(Account *acc);
void deposit_cash(Account *acc);
void display_transaction_history(Account *acc);
void change_pin(Account *acc);

#endif
