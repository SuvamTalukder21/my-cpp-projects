// BankAccount class declaration
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include "Transaction.h"

#include <random>
#include <unordered_set>
#include <nlohmann/json.hpp>

using namespace std;

// This class represents an individual bank account, storing basic account information and handling deposit/withdrawal operations
class BankAccount {
private:
	int accountNumber; // A unique identifier for the account
	string accountHolderName; // Name of the account holder
	double balance; // Current balance in the account
	vector<Transaction> transactionHistory; // A list of transactions associated with the account
	unordered_set<unsigned int> existingTransactionIDs; // A set of existing transaction IDs for quick lookup
	using json = nlohmann::json;

public:
	BankAccount(int accountNumber, string ownerName, double initialBalance); // Constructor to initialize the account with basic information
	int getAccountNumber() const; // Get the account number
	string getAccountHolderName() const; // Get the account holder's name
	double getBalance() const; // Get the current balance
	void deposit(unsigned int transactionID, double amount); // Deposit money into the account
	void withdraw(unsigned int transactionID, double amount); // Withdraw money if funds are sufficient (returns true if successful, false if insufficient funds)
	void displayAccountDetails() const; // Display the account information (for debugging or admin purposes)
	void addTransaction(unsigned int transactionID, double amount, const string& type, const string& date); // Add a new transaction to the account history
	const vector<Transaction>& getTransactionHistory() const; // Get the transaction history
};

#endif //BANKACCOUNT_H
