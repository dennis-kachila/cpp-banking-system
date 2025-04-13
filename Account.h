/**
 * @file Account.h
 * @brief Defines the Account class for banking operations
 * 
 * This file demonstrates:
 * - Class declaration
 * - Access specifiers (public/private)
 * - Member variables
 * - Member functions
 * - Constructor
 */

#pragma once
#include <string>

class Account {
private:
    std::string accountNumber;  ///< Unique account identifier
    std::string accountHolder;  ///< Name of account holder
    double balance;             ///< Current account balance
    std::string accountType;    ///< Type of account (Savings/Checking)

public:
    /**
     * @brief Constructor to initialize an Account
     * @param number Unique account number
     * @param holder Name of account holder
     * @param initialBalance Starting balance
     * @param type Account type (default: "Savings")
     * 
     * Demonstrates:
     * - Constructor with parameters
     * - Default parameter values
     * - Member initialization
     */
    Account(std::string number, std::string holder, 
            double initialBalance, std::string type = "Savings");

    // Accessor methods
    std::string getAccountNumber() const;  ///< Returns account number
    std::string getAccountHolder() const;  ///< Returns account holder name
    double getBalance() const;             ///< Returns current balance
    std::string getAccountType() const;    ///< Returns account type

    // Transaction methods
    void deposit(double amount);  ///< Adds funds to account
    bool withdraw(double amount); ///< Removes funds from account
    void display() const;         ///< Shows account details
};
