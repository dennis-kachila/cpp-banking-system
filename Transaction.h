/**
 * @file Transaction.h
 * @brief Defines the Transaction class for banking operations
 * 
 * Demonstrates:
 * - Enum class for transaction types
 * - Timestamp handling
 * - Class composition
 */

#pragma once
#include <string>
#include <ctime>

enum class TransactionType {
    DEPOSIT,
    WITHDRAWAL,
    TRANSFER
};

class Transaction {
private:
    std::string transactionId;
    TransactionType type;
    double amount;
    time_t timestamp;
    std::string description;

public:
    /**
     * @brief Constructor to initialize a Transaction
     * @param id Unique transaction ID
     * @param t Type of transaction
     * @param amt Transaction amount
     * @param desc Transaction description
     */
    Transaction(std::string id, TransactionType t, 
               double amt, std::string desc = "");

    // Accessor methods
    std::string getId() const;
    TransactionType getType() const;
    double getAmount() const;
    std::string getTimestamp() const;
    std::string getDescription() const;

    /**
     * @brief Displays transaction details
     * Demonstrates:
     * - Time formatting
     * - Enum to string conversion
     */
    void display() const;
};
