/**
 * @file Transaction.cpp
 * @brief Implements the Transaction class
 * 
 * Demonstrates:
 * - Time handling with ctime
 * - Enum to string conversion
 * - String formatting
 */

#include "Transaction.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

// Constructor implementation
Transaction::Transaction(std::string id, TransactionType t, 
                       double amt, std::string desc)
    : transactionId(id), type(t), amount(amt), 
      description(desc) {
    timestamp = time(nullptr); // Set to current time
}

// Accessor implementations
std::string Transaction::getId() const {
    return transactionId;
}

TransactionType Transaction::getType() const {
    return type;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getTimestamp() const {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&timestamp));
    return std::string(buffer);
}

std::string Transaction::getDescription() const {
    return description;
}

void Transaction::display() const {
    std::string typeStr;
    switch(type) {
        case TransactionType::DEPOSIT: typeStr = "DEPOSIT"; break;
        case TransactionType::WITHDRAWAL: typeStr = "WITHDRAWAL"; break;
        case TransactionType::TRANSFER: typeStr = "TRANSFER"; break;
    }

    std::cout << "Transaction ID: " << transactionId << "\n"
              << "Type: " << typeStr << "\n"
              << "Amount: $" << std::fixed << std::setprecision(2) << amount << "\n"
              << "Timestamp: " << getTimestamp() << "\n"
              << "Description: " << description << "\n";
}
