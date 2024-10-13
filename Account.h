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
    void showAccount() const;
    void deposit(double amount);
    void withdraw(double amount);
    void transfer(Account &toAccount, double amount);
    void save(std::ofstream &outFile) const;
    static Account* load(std::ifstream &inFile);
    [[nodiscard]] int getAccountID() const;
};

class SavingsAccount : public Account {
    double interestRate;
public:
    SavingsAccount(int id, const std::string &ownerName,const std::string &cardNumber, double initialBalance, double rate);
    void applyInterest();
    void showSavingsAccount() const;
    void save(std::ofstream &outFile) const;
};



#endif //ACCOUNT_H
