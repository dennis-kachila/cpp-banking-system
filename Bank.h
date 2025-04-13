/**
 * @file Bank.h
 * @brief Defines the Bank class for managing accounts and transactions
 * 
 * Demonstrates:
 * - STL containers (vector)
 * - Object composition
 * - Account management
 */

#pragma once
#include "Account.h"
#include "Transaction.h"
#include <vector>
#include <memory>

class Bank {
private:
    std::vector<std::shared_ptr<Account>> accounts;
    std::vector<Transaction> transactions;
    std::string bankName;

public:
    /**
     * @brief Constructor to initialize a Bank
     * @param name Name of the bank
     */
    explicit Bank(std::string name);

    // Account management
    void addAccount(std::shared_ptr<Account> account);
    std::shared_ptr<Account> findAccount(const std::string& accountNumber) const;
    void listAllAccounts() const;

    // Transaction processing
    void processDeposit(const std::string& accountNumber, double amount);
    void processWithdrawal(const std::string& accountNumber, double amount);
    void processTransfer(const std::string& fromAccount, 
                        const std::string& toAccount, 
                        double amount);

    // Transaction history
    void showTransactionHistory() const;
    void showAccountTransactions(const std::string& accountNumber) const;
};
