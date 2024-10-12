#include "Account.h"
#include "Bank.h"

using namespace std;
// Example usage of the system
int main() {
    Bank bank;

    // Add accounts
    auto* acc1 = new Account(1, "John Doe","235641897511168894615073", 1000.0);
    auto* acc2 = new SavingsAccount(2, "Jane Smith","345486455217843541684561", 2000.0, 0.05);


    acc1->showAccount();
    acc2->showAccount();

    bank.addAccount(acc1);
    bank.addAccount(acc2);

    // Perform transactions
    acc1->deposit(500);
    acc1->showAccount();
    acc2->withdraw(300);
    acc2->showAccount();
    acc1->transfer(*acc2, 200);
    acc1->showAccount();
    acc2->showAccount();

    // Save accounts to file
    bank.saveAllAccounts("accounts.txt");

    return 0;
}
