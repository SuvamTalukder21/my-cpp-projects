# Banking Record System

The Banking Record System is a simple, menu-driven console application written in C++ that allows users to manage bank accounts and record transactions. The system persists data using JSON files via the [nlohmann/json](https://github.com/nlohmann/json) library. Users can create, view, update, and delete accounts, as well as deposit or withdraw funds. This project demonstrates the use of modern C++ features, file I/O, and object-oriented design.

## Table of Contents

- [Features](#features)
- [Project Structure](#project-structure)
- [Prerequisites](#prerequisites)
- [Build Instructions](#build-instructions)
- [Usage](#usage)
- [File Descriptions](#file-descriptions)
- [Rooms for Improvement](#rooms-for-improvement)
- [License](#license)

## Features

- **Account Management:**  
  Create, open, view, and delete bank accounts.

- **Transaction Handling:**  
  Record deposits and withdrawals. Withdrawals are stored as negative numbers, but are displayed as positive amounts when viewed.

- **Data Persistence:**  
  Save and load account data (including transaction history) using JSON. Data is stored in an external file (`data/accounts.json`).

- **Menu-Based User Interface:**  
  A two-phase menu system allows users to first select high-level account operations and then perform account-specific actions.

## Project Structure

```bash
BankingSystem/
│
├── src/                     # Source code files (.cpp)
│   ├── main.cpp             # Main program entry point (menu UI)
│   ├── BankAccount.cpp      # Implementation of BankAccount class
│   ├── Transaction.cpp      # Implementation of Transaction class
│   ├── BankManager.cpp      # Implementation of BankManager class
│   └── FileHandler.cpp      # Implementation of FileHandler class (JSON file I/O & validation)
│
├── include/                 # Header files (.h)
│   ├── BankAccount.h        # BankAccount class declaration
│   ├── Transaction.h        # Transaction class declaration
│   ├── BankManager.h        # BankManager class declaration
│   └── FileHandler.h        # FileHandler class declaration
│
├── data/                    # Data files for persistence
│   └── accounts.json        # JSON file storing account and transaction data
│
├── CMakeLists.txt           # CMake configuration file
└── README.md                # Project documentation (this file)
```

## Prerequisites

- **C++ Compiler:** A C++ compiler that supports C++11 or later.
- **CMake:** Version 3.10 or newer.
- **nlohmann/json:** Managed automatically via CMake's FetchContent.
- **CLion (or any IDE of your choice):** For building and running the project.

## Build Instructions

1. **Clone the repository:**

   ```bash
    # Clone the repository without checking out files
    git clone --no-checkout https://github.com/SuvamTalukder21/my-cpp-projects.git

    # Change into the repository directory
    cd my-cpp-projects
    
    # Enable sparse checkout
    git sparse-checkout init --cone
    
    # Specify the folder to clone
    git sparse-checkout set banking-record-system
    
    # Checkout the files from the main branch
    git checkout main
   
    # Change into the project directory
    cd banking-record-system
   ```

2. **Create a build directory and run CMake:**

   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

3. **Data Directory:**  
   The `CMakeLists.txt` file creates the `data` directory automatically (using `file(MAKE_DIRECTORY ${DATA_DIR})`) after loading it (if not automatically creates try to load CMake file manually). If not creates any folder ensure that `data` folder exists relative to your project root.

## Usage

When the program runs, you will be presented with a main menu with options to create/open accounts, view accounts, delete/close accounts, or exit. For example:

- **Main Menu:**
    - **1. Create/Open Account:**  
      Prompts for the account owner's name and an initial balance to create a new account.
    - **2. View Account:**  
      Opens an existing account by account number, then enters an account-specific menu where you can deposit/withdraw funds, view the current balance, or see transaction history.
    - **3. Delete/Close Account:**  
      Deletes the specified account.
    - **4. Exit:**  
      Saves all account data to the JSON file (`data/accounts.json`) and exits the program.

- **Account Menu:**
    - **1. Deposit/Withdraw Money:**  
      Prompts for an amount to deposit or withdraw.
    - **2. View Balance:**  
      Displays the current balance.
    - **3. View Transaction History:**  
      Lists all transactions associated with the account.
    - **4. Back to Main Menu:**  
      Returns to the main menu.

## File Descriptions

- **main.cpp:**  
  Contains the menu-based user interface and serves as the entry point of the application.

- **BankAccount.h/cpp:**  
  Implements the BankAccount class that encapsulates account details (account number, owner name, balance) and transaction history.

- **Transaction.h/cpp:**  
  Implements the Transaction class for individual transactions, including deposits and withdrawals.

- **BankManager.h/cpp:**  
  Acts as the main interface for managing bank accounts. Provides methods for creating, finding, deleting accounts, handling transactions, and saving/loading data.

- **FileHandler.h/cpp:**  
  Contains functions for reading from and writing to a JSON file. It also includes simple validation functions for account numbers and transaction amounts.

- **CMakeLists.txt:**  
  Configures the build system using CMake, downloads the nlohmann/json package, sets up compiler flags, and creates the data directory.

## Rooms for Improvement

While the current system provides a solid foundation, there are several areas where improvements could be made:

1. **Code Improvement:**
    - Use `std::map` header instead of `std::unordered_map` header according to account number in `BankManager.cpp` file because `std::map` is an ordered container while `std::unordered_map` is an unordered container. Since you are storing the account numbers in a sorted order, it would be better to use `std::map` to maintain the order of the accounts.
    - Change the order of data using code in `FileHandler.cpp` file which is stored in `accounts.json` (where the desired output will be first _account number_ followed by _account holder name_, _amount_, _transactions_ and under _transactions_ first would be _transactionID_, followed by _amount_, _type_, _transaction date_).
    - You can change the `CMakeLists.txt` file to use the `C++17` standard instead of `C++11`. Also by replacing `CMAKE_SOURCE_DIR` with `CMAKE_BINARY_DIR` since `cmake-build-debug` is an executable folder where all the data are stored.
    - My suggestion would be to add admin functionality to the system. The admin should be able to view all the accounts, search for an account by account number, and view the transaction history of any account. This would make the system more versatile and useful.

2. **Code Modularization and Testing:**
    - Increase unit testing coverage for all classes (e.g., BankAccount, Transaction, BankManager, and FileHandler).
    - Refactor code to reduce dependencies and improve maintainability (e.g., use dependency injection for FileHandler).

3. **Error Handling and Robustness:**
    - Improve error handling in file operations, such as more informative error messages or retry logic when file I/O fails.
    - Validate user input more robustly to prevent invalid entries (e.g., non-numeric values for amounts).

4. **Extensibility:**
    - Integrate additional features such as funds transfer between accounts, account interest calculations, and account statement generation.
    - Consider switching to an embedded database (e.g., SQLite) for more efficient data management if the dataset grows larger.

5. **User Interface Enhancements:**
    - Develop a graphical user interface (GUI) for a more user-friendly experience.
    - Provide clearer prompts and feedback messages.

6. **Concurrency and Multi-User Support:**
    - Add support for concurrent access if the application is expanded to support multiple users simultaneously.
    - Implement locking or use a database instead of a flat JSON file for data persistence if needed.

7. **Security:**
    - Implement data encryption for sensitive information.
    - Add proper authentication if the system is expanded for real-world usage.

## License

This project is licensed under the MIT License. See the [LICENSE](https://opensource.org/license/mit) file for details.
