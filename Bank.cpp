//
// Created by medhk on 10/12/24.
//

#include "Bank.h"
#include <fstream>
#include <string>
#include "Account.h"
Bank::~Bank() {
    for (const auto acc : accounts) {
        delete acc;
    }
}

// Add account to the bank
void Bank::addAccount(Account* account) {
    accounts.push_back(account);
}

// Find account by ID
Account* Bank::findAccount(const int accountID) {
    for (const auto acc : accounts) {
        if (acc->getAccountID() == accountID) return acc;
    }
    return nullptr;
}

// Save all accounts to a file
void Bank::saveAllAccounts(const std::string &filename) const {
    std::ofstream outFile(filename);
    for (const auto acc : accounts) {
        acc->save(outFile);
    }
}

// Load all accounts from a file
void Bank::loadAllAccounts(const std::string &filename) {
    std::ifstream inFile(filename);
    while (!inFile.eof()) {
        if (Account* acc = Account::load(inFile); acc != nullptr) {
            accounts.push_back(acc);
        }
    }
}