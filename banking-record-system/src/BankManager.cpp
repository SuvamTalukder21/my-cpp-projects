#include "BankManager.h"

#include <iostream>
#include <string>

using namespace std;

int BankManager::s_accountNumber = 1000; // Initialize static variable for account numbers

/* Create a new bank account with an initial balance */
void BankManager::createAccount(const string& ownerName, double initialBalance) {
	s_accountNumber++; // Generate a unique account number

	// Insert a new account into the accounts map using piecewise construction. This avoids unnecessary copies by constructing the key and value in place
	accounts.emplace(piecewise_construct, forward_as_tuple(s_accountNumber), forward_as_tuple(s_accountNumber, ownerName, initialBalance));

	cout << "Account created successfully. Account number: " << s_accountNumber << endl;
}

/* Find and return a pointer to the account with the given account number */
BankAccount* BankManager::findAccount(int accountNumber) {
	auto it = accounts.find(accountNumber);
	return (it != accounts.end()) ? &it->second : nullptr;
}

/* Ask user to Deposit or Withdraw money into the account with the given account number */
void BankManager::handleTransaction(int accountNumber) {
	unsigned int transactionID = rd(); // Generate a unique transaction ID
	BankAccount* account = findAccount(accountNumber);

	if (account) {
		double amount;
		string choice;
		cout << "Do you want to deposit (D) or withdraw (W) money? ";
		cin >> choice;

		transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

		if (choice == "w" || choice == "withdraw") {
			cout << "Enter the amount to withdraw: ";
			cin >> amount;

			account->withdraw(transactionID, amount);

		} else if (choice == "d" || choice == "deposit") {
			cout << "Enter the amount to deposit: ";
			cin >> amount;

			account->deposit(transactionID, amount);

		} else {
			cout << "Invalid choice." << endl;
		}
	} else {
		cout << "Account not found." << endl;
	}
}

/* Display detailed information for a specific account */
void BankManager::displayAccountInfo(int accountNumber) {
	BankAccount* account = findAccount(accountNumber);

	if (account) {
		account->displayAccountDetails();
	} else {
		cout << "Account not found." << endl;
	}
}

/* Display all transactions that have occurred in the system */
void BankManager::displayAllTransactions() const {
	cout << "Listing all transactions:" << endl;
	for (const auto& transaction : transactions) {
		transaction.displayTransactionDetails();
		cout << endl;
	}
}

/* Delete the account with the given account number */
void BankManager::deleteAccount(int accountNumber) {
	if (accounts.erase(accountNumber)) {
		cout << "Account " << accountNumber << " deleted successfully." << endl;
	} else {
		cout << "Error: Account " << accountNumber << " not found." << endl;
	}
}

void BankManager::displayTransactionHistory(int accountNumber) const {
	auto it = accounts.find(accountNumber);
	if (it != accounts.end()) {
		const BankAccount& account = it->second;
		cout << "\nTransaction History for Account #" << accountNumber << endl;
		cout << "-------------------------------------" << endl;

		const auto& transactions = account.getTransactionHistory();
		if (transactions.empty()) {
			cout << "No transactions found." << endl;
			return;
		}

		for (const auto& transaction : transactions) {
			transaction.displayTransactionDetails();
			cout << "-----------------------------" << endl;
		}
	} else {
		cout << "Account not found!" << endl;
	}
}

/* Load account and transaction data from a file */
void BankManager::loadAccountsFromFile() {
	accounts = fileHandler.readAccountsFromFile(DEFAULT_DATA_FILE);
	// Update s_accountNumber to avoid duplicates
	if (!accounts.empty()) {
		for (const auto& account : accounts) {
			s_accountNumber = max(s_accountNumber, account.first);
		}
	}
}

/* Save account and transaction data to a file */
void BankManager::saveAccountsToFile() {
	fileHandler.writeAccountsToFile(DEFAULT_DATA_FILE, accounts);
}
