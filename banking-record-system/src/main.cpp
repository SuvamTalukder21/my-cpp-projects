// Main program entry point
#include <iostream>
#include "BankManager.h"

using namespace std;

void displayMainMenu() {
	cout << "\n========= Main Menu =========\n"
		<< "1. Create/Open Account" << endl
		<< "2. View Account" << endl
		<< "3. Delete/Close Account" << endl
		<< "4. Exit" << endl
		<< "Enter your choice: ";
}

void displayAccountMenu(int accountNumber) {
	cout << "\n==== Account Menu for Account " << accountNumber << " ====\n"
		<< "1. Deposit/Withdraw Money" << endl
		<< "2. View Balance" << endl
		<< "3. View Transaction History" << endl
		<< "4. Back to Main Menu" << endl
		<< "Enter your choice: ";
}

int main() {
	BankManager system;
    system.loadAccountsFromFile();
	bool exitProgram = true;

    while (exitProgram) {
        displayMainMenu();
        int mainChoice;
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: {  // Create Account
                string ownerName;
                double initialBalance;
                cout << "Enter account owner's name: ";
                cin.ignore(); // clear newline from previous input
                getline(cin, ownerName);
                cout << "Enter initial balance: ";
                cin >> initialBalance;
                system.createAccount(ownerName, initialBalance);
                break;
            }
            case 2: {  // Open Account
                int accountNumber;
                cout << "Enter account number to open: ";
                cin >> accountNumber;
                BankAccount* account = system.findAccount(accountNumber);
                if (!account) {
                    cout << "Account not found!" << endl;
                    break;
                }

                // Account menu phase
                bool backToMain = true;
                while (backToMain) {
                    displayAccountMenu(accountNumber);
                    int accountChoice;
                    cin >> accountChoice;

                    switch (accountChoice) {
                        case 1: {  // Deposit
                            system.handleTransaction(accountNumber);
                            break;
                        }
                        case 2: {  // View Balance
                            cout << "Current balance: $" << account->getBalance() << endl;
                            break;
                        }
                        case 3: {  // View Transaction History
                            // We assume displayAccountDetails prints both account info and its transaction history.
                            system.displayTransactionHistory(accountNumber);
                            break;
                        }
                        case 4: {  // Back to Main Menu
                            backToMain = false;
                            break;
                        }
                        default:
                            cout << "Invalid option. Please try again." << endl;
                            break;
                    }
                }
                break;
            }
            case 3: {  // Delete Account
                int accountNumber;
                string ownerName;
                cout << "Enter account number to delete: ";
                cin >> accountNumber;
                system.deleteAccount(accountNumber);
                break;
            }
            case 4: {  // Exit
                exitProgram = false;
                break;
            }
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }

    system.saveAccountsToFile();
    cout << "Exiting program. Goodbye!" << endl;
    return 0;
}
