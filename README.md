# Console-Based Banking System in C++

A console-based banking system implemented in C++ that demonstrates object-oriented programming principles

## Features

- Account management (create, view)
- Transaction processing (deposit, withdrawal, transfer)
- Transaction history tracking
- Simple console-based user interface

## Classes

- `Account`: Represents bank accounts with number, holder name, type, and balance
- `Transaction`: Records financial transactions with timestamps and descriptions  
- `Bank`: Main system class that manages accounts and transactions

## How to Compile and Run

1. Ensure you have g++ installed (version 13 or later recommended)
2. Compile the program:
   ```bash
   g++ -std=c++17 -o bank_app main.cpp Account.cpp Transaction.cpp Bank.cpp
   ```
3. Run the executable:
   ```bash
   ./bank_app
   ```

## Usage Examples

### Creating an Account
```
1. Create Account
Enter account number: 1001  
Enter account holder name: John Doe
Enter initial balance: 1000
Enter account type (Savings/Checking): Savings
```

### Making a Deposit
```
2. Deposit
Enter account number: 1001
Enter amount to deposit: 500
```

### Viewing Transactions
```
6. View Transaction History
```

## File Structure

- `Account.h`/`.cpp`: Account class implementation
- `Transaction.h`/`.cpp`: Transaction class implementation  
- `Bank.h`/`.cpp`: Main banking system logic
- `main.cpp`: Program entry point and user interface

## Requirements

- C++17 compatible compiler
- Linux/macOS environment recommended
