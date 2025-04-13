/**
 * @file main.cpp
 * @brief Main application for banking system
 * 
 * Demonstrates:
 * - Object creation and usage
 * - System testing
 * - Menu-driven interface
 */

#include "Bank.h"
#include "Account.h"
#include <iostream>
#include <memory>

void displayMenu() {
    std::cout << "\n=== OneTrue Banking System Menu ===\n"
              << "1. Create Account\n"
              << "2. Deposit\n"
              << "3. Withdraw\n"
              << "4. Transfer\n"
              << "5. View All Accounts\n"
              << "6. View Transaction History\n"
              << "7. View Account Transactions\n"
              << "8. Exit\n"
              << "Enter choice: ";
}

int main() {
    Bank bank("C++ Bank");
    int choice;
    std::string accountNumber, accountHolder, targetAccount;
    double amount;
    std::string accountType;

    // Test data - demonstrates system functionality
    auto testAccount1 = std::make_shared<Account>("ACC1001", "John Doe", 1000.0);
    auto testAccount2 = std::make_shared<Account>("ACC1002", "Jane Smith", 500.0, "Checking");
    bank.addAccount(testAccount1);
    bank.addAccount(testAccount2);
    bank.processDeposit("ACC1001", 200.0);
    bank.processWithdrawal("ACC1002", 100.0);
    bank.processTransfer("ACC1001", "ACC1002", 300.0);

    while(true) {
        displayMenu();
        std::cin >> choice;

        switch(choice) {
            case 1: // Create Account
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter account holder name: ";
                std::cin.ignore();
                std::getline(std::cin, accountHolder);
                std::cout << "Enter initial balance: ";
                std::cin >> amount;
                std::cout << "Enter account type (Savings/Checking): ";
                std::cin >> accountType;
                bank.addAccount(std::make_shared<Account>(accountNumber, accountHolder, amount, accountType));
                break;

            case 2: // Deposit
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                bank.processDeposit(accountNumber, amount);
                break;

            case 3: // Withdraw
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                bank.processWithdrawal(accountNumber, amount);
                break;

            case 4: // Transfer
                std::cout << "Enter source account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter target account number: ";
                std::cin >> targetAccount;
                std::cout << "Enter amount to transfer: ";
                std::cin >> amount;
                bank.processTransfer(accountNumber, targetAccount, amount);
                break;

            case 5: // View All Accounts
                bank.listAllAccounts();
                break;

            case 6: // View Transaction History
                bank.showTransactionHistory();
                break;

            case 7: // View Account Transactions
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                bank.showAccountTransactions(accountNumber);
                break;

            case 8: // Exit
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
