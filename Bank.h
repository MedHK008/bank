//
// Created by medhk on 10/12/24.
//

#ifndef BANK_H
#define BANK_H

#include <vector>
#include <fstream>
#include <string>
#include "Account.h"



// Class to manage the bank system
class Bank {
    std::vector<Account*> accounts;

public:
    ~Bank();

    // Add account to the bank
    void addAccount(Account* account);

    // Find account by ID
    Account* findAccount(int accountID);

    // Save all accounts to a file
    void saveAllAccounts(const std::string &filename) const;

    // Load all accounts from a file
    void loadAllAccounts(const std::string &filename);
};




#endif //BANK_H
