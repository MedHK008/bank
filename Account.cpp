//
// Created by medhk on 10/12/24.
//

#include "Account.h"

#include <iostream>
#include <utility>


int Account::getID() const {
    return accountID;
}

Account::Account(const int id, std::string  ownerName,std::string cardNumber, const double initialBalance)
        : accountID(id), owner(std::move(ownerName)),cardNumber(std::move(cardNumber)), balance(initialBalance) {

}

Account::~Account() = default;

void Account::showAccount() const {
    std::cout << "Owner Name: " << owner << std::endl;

    std::cout << "Balance: " << balance << std::endl;
}

void Account::deposit(const double amount) {
    if (amount <= 0) throw std::invalid_argument("Deposit amount must be positive.");
    balance += amount;
}

void Account::withdraw(const double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Withdraw amount must be positive.");
    if (balance < amount)
        throw std::runtime_error("Insufficient balance.");
    balance -= amount;
}

void Account::transfer(Account &toAccount, const double amount) {
    withdraw(amount);
    toAccount.deposit(amount);
}

void Account::save(std::ofstream &outFile) const {
    outFile << accountID << " " << owner << " " << cardNumber << " " << balance << std::endl;
}

Account* Account::load(std::ifstream &inFile) {
    int id;
    std::string owner;
    std::string cardNumber;
    double balance;
    inFile >> id >> owner >> cardNumber >> balance;
    return new Account(id, owner,cardNumber, balance);
}

int Account::getAccountID() const {
    return getID();
}

SavingsAccount::SavingsAccount(const int id, const std::string &ownerName, const std::string &cardNumber, const double initialBalance, const double rate)
        : Account(id, ownerName,cardNumber, initialBalance), interestRate(rate) {}

void SavingsAccount::applyInterest() {
    balance += balance * interestRate;
}

void SavingsAccount::showSavingsAccount() const {
    std::cout << accountID << " " << owner << " " << balance << " " << interestRate << std::endl;
}

void SavingsAccount::save(std::ofstream &outFile) const {
    outFile << accountID << " " << owner << " " << cardNumber << " " << balance << " " << interestRate << std::endl;
}