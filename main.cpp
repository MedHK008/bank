#include "Account.h"
#include "Bank.h"
#include <iostream>

using namespace std;

void displayMenu(const string& name)
{
    cout << endl << "************************\t\t\t" << name << "\t\t\t*******************************" << endl;
    cout << "*                        \t" << "Enter your choice: "<< "                         "<<endl;
    cout << "*************************\t" << "1. Deposit         "<< "*************************"<< endl;
    cout << "*************************\t" << "2. Withdraw        "<< "*************************"<< endl;
    cout << "*************************\t" << "3. Transfer        "<< "*************************"<< endl;
    cout << "*************************\t" << "4. Show Account    "<< "*************************"<< endl;
    cout << "*************************\t" << "5. Save Accounts   "<< "*************************"<< endl;
    cout << "*************************\t" << "6. Delete Account  "<< "*************************"<< endl;
    cout << "*************************\t" << "7. Exit            "<< "*************************"<< endl;
    cout << "**********************************************************************************" << endl;
}

int main()
{
    Bank bank("CDM");
    bank.loadAllAccounts("accounts.txt");
    int choice = 0;
    int accountId;
    double amount;
    int targetAccountId;
    while (true) {
        cout << "Enter your account ID (type 0 o create a new account) :" << endl;
        cin >> accountId;
        if(accountId == 0) {
            string ownerName;
            string cardNumber;
            double initialBalance = 0;
            cout << "Enter your name: ";
            cin >> ownerName;
            cout << "Enter your card number: ";
            cin >> cardNumber;
            cout << "Enter your initial balance: ";
            cin >> initialBalance;
            auto* account = new Account(bank.calculateNumberOfAccounts(),ownerName,cardNumber,initialBalance);
            bank.addAccount(account);
            accountId = account->getAccountID();
        }
        Account* account = bank.findAccount(accountId);
        if (account == nullptr) {
            cout << "Account not found!" << endl;
            continue;
        }
        while(choice != 7) {
            displayMenu(bank.name);
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
                    bank.removeAccountFromFile(account);
                    break;
                case 7:
                    break;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
            }
        }
        cout << "Do you want to continue?(1 for y/0 fo n):";
        cin >> choice;
        if (choice == 1) {
            return 0;
        }
    }
}