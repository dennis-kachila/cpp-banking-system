/**
 * @file Bank.cpp
 * @brief Implements the Bank class
 * 
 * Demonstrates:
 * - STL vector usage
 * - Shared pointers
 * - Exception handling
 */

#include "Bank.h"
#include <iostream>
#include <algorithm>

Bank::Bank(std::string name) : bankName(std::move(name)) {}

void Bank::addAccount(std::shared_ptr<Account> account) {
    accounts.push_back(account);
    transactions.emplace_back(
        "ACCT-" + std::to_string(transactions.size() + 1),
        TransactionType::DEPOSIT,
        account->getBalance(),
        "Account creation"
    );
}

std::shared_ptr<Account> Bank::findAccount(const std::string& accountNumber) const {
    auto it = std::find_if(accounts.begin(), accounts.end(),
        [&accountNumber](const std::shared_ptr<Account>& acc) {
            return acc->getAccountNumber() == accountNumber;
        });
    return (it != accounts.end()) ? *it : nullptr;
}

void Bank::listAllAccounts() const {
    std::cout << "\n=== Accounts in " << bankName << " ===\n";
    for (const auto& account : accounts) {
        account->display();
        std::cout << "----------------\n";
    }
}

void Bank::processDeposit(const std::string& accountNumber, double amount) {
    auto account = findAccount(accountNumber);
    if (account) {
        account->deposit(amount);
        transactions.emplace_back(
            "DEP-" + std::to_string(transactions.size() + 1),
            TransactionType::DEPOSIT,
            amount,
            "Deposit to " + accountNumber
        );
    } else {
        std::cerr << "Error: Account not found\n";
    }
}

void Bank::processWithdrawal(const std::string& accountNumber, double amount) {
    auto account = findAccount(accountNumber);
    if (account && account->withdraw(amount)) {
        transactions.emplace_back(
            "WTH-" + std::to_string(transactions.size() + 1),
            TransactionType::WITHDRAWAL,
            amount,
            "Withdrawal from " + accountNumber
        );
    }
}

void Bank::processTransfer(const std::string& fromAccount, 
                         const std::string& toAccount, 
                         double amount) {
    auto src = findAccount(fromAccount);
    auto dest = findAccount(toAccount);
    
    if (src && dest && src->withdraw(amount)) {
        dest->deposit(amount);
        transactions.emplace_back(
            "TRN-" + std::to_string(transactions.size() + 1),
            TransactionType::TRANSFER,
            amount,
            "Transfer from " + fromAccount + " to " + toAccount
        );
    }
}

void Bank::showTransactionHistory() const {
    std::cout << "\n=== Transaction History ===\n";
    for (const auto& transaction : transactions) {
        transaction.display();
        std::cout << "----------------\n";
    }
}

void Bank::showAccountTransactions(const std::string& accountNumber) const {
    std::cout << "\n=== Transactions for Account " << accountNumber << " ===\n";
    for (const auto& transaction : transactions) {
        if (transaction.getDescription().find(accountNumber) != std::string::npos) {
            transaction.display();
            std::cout << "----------------\n";
        }
    }
