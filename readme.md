# Bank System

This project is a simple bank system implemented in C++.

## Project Structure

## Files

- **Account.cpp**: Implementation of the `Account` class.
- **Account.h**: Header file for the `Account` class.
- **Bank.cpp**: Implementation of the `Bank` class.
- **Bank.h**: Header file for the `Bank` class.
- **main.cpp**: Entry point of the application.
- **CMakeLists.txt**: CMake configuration file for building the project.
- **readme.md**: This README file.

## Classes

### Account

The `Account` class represents a bank account. It is defined in [Account.h](src/Account.h) and implemented in [Account.cpp](src/Account.cpp).

#### Methods
- **`void deposit(const double amount)`**: Deposits a specified amount into the account. Throws an exception if the amount is non-positive.
- **`void withdraw(const double amount)`**: Withdraws a specified amount from the account. Throws an exception if the amount is non-positive or if the balance is insufficient.
- **`void transfer(Account &toAccount, const double amount)`**: Transfers a specified amount from the current account to another account. Throws an exception if the amount is non-positive or if the balance is insufficient.
- **`void applyInterest()`**: Applies interest to the balance of a savings account.

### Bank

The `Bank` class manages multiple accounts. It is defined in [Bank.h](src/Bank.h) and implemented in [Bank.cpp](src/Bank.cpp).

#### methods
- **`int calculateNumberOfAccounts()`**: Calculates and returns the total number of accounts managed by the bank.
- **`void addAccount(const Account &account)`**: Adds a new account to the bank.
- **`void removeAccount(const int accountID)`**: Removes an account from the bank by its ID.
- **`Account* getAccount(const int accountID)`**: Retrieves an account by its ID. Returns a pointer to the account or `nullptr` if not found.
- **`void transfer(const int fromAccountID, const int toAccountID, const double amount)`**: Transfers a specified amount from one account to another by their IDs. Throws an exception if the amount is non-positive or if the balance is insufficient.

## Building the Project

cmake version : 3.28

c++ compiler needed

To build the project, Follow these steps:

1. **Generate build files**:
    ```sh
    cmake -S . -B build
    ```

2. **Build the project**:
    ```sh
    cmake --build build
    ```

## Running the Project

After building the project, you can run the executable:

```sh
./build/bank