/**
 * @file Account.cpp
 * @brief Implements the Account class
 * 
 * Demonstrates:
 * - Class method implementations
 * - Input validation
 * - Basic error handling
 */

#include "Account.h"
#include <iostream>
#include <iomanip>

// Constructor implementation
Account::Account(std::string number, std::string holder, 
                double initialBalance, std::string type)
    : accountNumber(number), accountHolder(holder),
      balance(initialBalance), accountType(type) {
    // Input validation
    if(initialBalance < 0) {
        std::cerr << "Warning: Account created with negative balance\n";
    }
}

// Accessor implementations
std::string Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getAccountHolder() const {
    return accountHolder;
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getAccountType() const {
    return accountType;
}

// Transaction methods
void Account::deposit(double amount) {
    if(amount > 0) {
        balance += amount;
    } else {
        std::cerr << "Error: Deposit amount must be positive\n";
    }
}

bool Account::withdraw(double amount) {
    if(amount > 0 && balance >= amount) {
        balance -= amount;
        return true;
    }
    std::cerr << "Error: Insufficient funds or invalid amount\n";
    return false;
}

void Account::display() const {
    std::cout << "Account Number: " << accountNumber << "\n"
              << "Account Holder: " << accountHolder << "\n"
              << "Account Type: " << accountType << "\n"
              << "Balance: $" << std::fixed << std::setprecision(2) 
              << balance << "\n";
}
