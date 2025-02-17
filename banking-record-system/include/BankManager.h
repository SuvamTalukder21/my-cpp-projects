// BankSystem class declaration
#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include "BankAccount.h"
#include "Transaction.h"
#include "FileHandler.h"

#include <random>

using namespace std;

// This class manages multiple bank accounts and transactions, acting as the main interface for the banking system
class BankManager {
private:
	random_device rd; // Random device for generating unique transaction IDs
	const string DEFAULT_DATA_FILE = "../data/accounts.json"; // Default data file for storing account information
	static int s_accountNumber; // Static variable to generate unique account numbers

	unordered_map<int, BankAccount> accounts; // A collection of all bank accounts
	vector<Transaction> transactions; // A collection of all transactions
	FileHandler fileHandler; // File handler object for reading/writing data

public:
	void createAccount(const string& ownerName, double initialBalance); // Create a new bank account with an initial balance
	BankAccount* findAccount(int accountNumber); // Find and return a pointer to the account with the given account number (returns nullptr if not found)
	void handleTransaction(int accountNumber); // Deposit money into the account with the given account number
	void displayAccountInfo(int accountNumber); // Display detailed information for a specific account
	void displayAllTransactions() const; // Display all transactions that have occurred in the system
	void deleteAccount(int accountNumber); // Delete the account with the given account number
	void displayTransactionHistory(int accountNumber) const; // Display the transaction history for a specific account
	void loadAccountsFromFile(); // Load account and transaction data from a file
	void saveAccountsToFile(); // Save account and transaction data to a file
};

#endif //BANKMANAGER_H
