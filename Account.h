//
// Created by medhk on 10/12/24.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <fstream>
#include <string>

// Base class for accounts
class Account {
protected:
    int accountID;
    std::string owner;
    std::string cardNumber;
    double balance;
    [[nodiscard]] int getID() const;
public:
    Account(int id, std::string  ownerName,std::string cardNumber, double initialBalance);
    ~Account();
    // show function
    void showAccount() const;
    // Deposit function
    void deposit(double amount);
    // Withdraw function
    void withdraw(double amount);
    // Transfer function
    void transfer(Account &toAccount, double amount);
    // save account to file
    void save(std::ofstream &outFile) const;
    // Load account from file
    static Account* load(std::ifstream &inFile);
    // get account ID
    [[nodiscard]] int getAccountID() const;
};

// Derived class for savings accounts with interest rates
class SavingsAccount : public Account {
    double interestRate;
public:
    SavingsAccount(int id, const std::string &ownerName,const std::string &cardNumber, double initialBalance, double rate);
    // Apply interest to balance
    void applyInterest();
    // show account
    void showSavingsAccount() const;
    // Override save to include interest rate
    void save(std::ofstream &outFile) const;
};



#endif //ACCOUNT_H
