#include "Account.h"
#include "Bank.h"
#include <iostream>

using namespace std;

void displayMenu() {
    cout << "1. Deposit" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Transfer" << endl;
    cout << "4. Show Account" << endl;
    cout << "5. Save Accounts" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Bank bank;
    bank.loadAllAccounts("./accounts.txt");
    int choice = 0;
    int accountId;
    double amount;
    int targetAccountId;
    while (true) {
        cout << "Enter your account ID: ";
        cin >> accountId;
        Account* account = bank.findAccount(accountId);
        if (account == nullptr) {
            cout << "Account not found!" << endl;
            continue;
        }
        while(choice != 6) {
            displayMenu();
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    account->deposit(amount);
                break;
                case 2:
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    account->withdraw(amount);
                    break;
                case 3:
                    cout << "Enter target account ID: ";
                    cin >> targetAccountId;
                    cout << "Enter amount to transfer: ";
                    cin >> amount;
                    if (Account* targetAccount = bank.findAccount(targetAccountId); targetAccount != nullptr) {
                        account->transfer(*targetAccount, amount);
                    } else {
                        cout << "Target account not found!" << endl;
                    }
                    break;
                case 4:
                    account->showAccount();
                break;
                case 5:
                    bank.saveAllAccounts("accounts.txt");
                break;
                case 6:
                    return 0;
                default:
                    cout << "Invalid choice!" << endl;
            }
        }
        cout << "Do you want to continue?(1 for y/0 fo n):";
        cin >> choice;
        if (choice == 1) return 0;
    }
}