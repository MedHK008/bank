//
// Created by medhk on 10/12/24.
//
#include "Bank.h"
#include <fstream>
#include <string>
#include <utility>
#include <algorithm>
#include "Account.h"

Bank::Bank(std::string name):name(std::move(name)) {}

Bank::~Bank() {
    for (const auto acc : accounts) {
        delete acc;
    }
}

int Bank::calculateNumberOfAccounts() {
    int numberOfAccounts = 0;
    for (const auto acc : accounts) {
        numberOfAccounts++;
    }
    this->numberOfAccounts = numberOfAccounts;
    return numberOfAccounts;
}

void Bank::addAccount(Account* account) {
    accounts.push_back(account);
    saveAllAccounts("./accounts.txt");
}

void Bank::removeAccount(Account *account) {
    const auto it = std::ranges::remove(accounts, account).begin();
    accounts.erase(it, accounts.end());
    delete account;
}

void Bank::removeAccountFromFile(Account *account) {
    removeAccount(account);
    saveAllAccounts("./accounts");
}

Account* Bank::findAccount(const int accountID) {
    for (const auto acc : accounts) {
        if (acc->getAccountID() == accountID) return acc;
    }
    return nullptr;
}

void Bank::saveAllAccounts(const std::string &filename) const {
    std::ofstream outFile(filename);
    for (const auto acc : accounts) {
        acc->save(outFile);
    }
}

void Bank::loadAllAccounts(const std::string &filename) {
    std::ifstream inFile(filename);
    while (!inFile.eof()) {
        if (Account* acc = Account::load(inFile); acc != nullptr) {
            accounts.push_back(acc);
        }
    }
}