// main.c

#include "atm.h"
#include <stdio.h>

int main() {
    Account acc;
    int account_number;

    printf("Welcome to the ATM\n");
    printf("Enter account number: ");
    scanf("%d", &account_number);

    load_account(&acc, account_number);

    if (authenticate(&acc)) {
        int choice;
        do {
            printf("\nATM Menu:\n");
            printf("1. Check Balance\n2. Withdraw Cash\n3. Deposit Cash\n4. View Transactions\n5. Change PIN\n6. Exit\n");
            printf("Choose an option: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    display_balance(&acc);
                    break;
                case 2:
                    withdraw_cash(&acc);
                    break;
                case 3:
                    deposit_cash(&acc);
                    break;
                case 4:
                    display_transaction_history(&acc);
                    break;
                case 5:
                    change_pin(&acc);
                    break;
                case 6:
                    save_account(&acc);
                    printf("Thank you for using our ATM.\n");
                    break;
                default:
                    printf("Invalid choice. Try again.\n");
            }
        } while (choice != 6);
    } else {
        printf("Authentication failed.\n");
    }

    return 0;
}
