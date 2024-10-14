//
// Created by medhk on 10/12/24.
//

#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "Account.h"



// Class to manage the bank system
class Bank {
    std::vector<Account*> accounts;
    std::vector<SavingsAccount*> savingsAccounts;
    int numberOfAccounts{};
public:
    std::string name;
    explicit Bank(std::string name);
    ~Bank();
    int calculateNumberOfAccounts();
    void addAccount(Account* account);
    void removeAccount(Account* account);
    void removeAccountFromFile(Account* account);
    Account* findAccount(int accountID);
    void saveAllAccounts(const std::string &filename) const;
    void loadAllAccounts(const std::string &filename);
};

#endif //BANK_H
