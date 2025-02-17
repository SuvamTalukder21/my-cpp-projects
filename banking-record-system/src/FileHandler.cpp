#include "FileHandler.h"

#include <fstream>
#include <unordered_map>

using namespace std;

/* Function to read accounts from a JSON file */
unordered_map<int, BankAccount> FileHandler::readAccountsFromFile(const string& filename) {
	unordered_map<int, BankAccount> accounts;
	ifstream file(filename);
	json accountsJson;

	if (file.is_open()) {
		file >> accountsJson;
		file.close();
	}

	for (const auto& accountJson : accountsJson) {
		int accountNumber = accountJson["accountNumber"];
		string ownerName = accountJson["accountHolderName"];
		double balance = accountJson["balance"];

		BankAccount account(accountNumber, ownerName, balance);

		// Load transactions
		for (const auto& txJson : accountJson["transactions"]) {
			unsigned int txID = txJson["transactionID"];
			double amount = txJson["amount"];
			string type = txJson["type"];
			string date = txJson["date"];

			// Add transaction and track its ID
			account.addTransaction(txID, amount, type, date);
		}

		// Insert the account into the map using piecewise construction to avoid unnecessary copies
		accounts.emplace(piecewise_construct, forward_as_tuple(accountNumber), forward_as_tuple(move(account)));
	}

	return accounts;
}

/* Function to write accounts to a JSON file */
void FileHandler::writeAccountsToFile(const string& filename, const unordered_map<int, BankAccount>& accounts) {
	ofstream file(filename);

	if (!file.is_open()) {
		throw runtime_error("Could not open file for writing. Failed to open file: " + filename);
	}

	json accountsJson = json::array();

	for (const auto& accountPair : accounts) {
		const BankAccount& account = accountPair.second;

		json accountJson = {
			{"accountNumber", account.getAccountNumber()},
			{"accountHolderName", account.getAccountHolderName()},
			{"balance", account.getBalance()},
		};

		// Convert transaction history to JSON
		json transactionsJson = json::array();
		for (const auto& transaction : account.getTransactionHistory()) {
			json transactionJson;
			transactionJson["transactionID"] = transaction.getTransactionID();
			transactionJson["amount"] = transaction.getAmount();
			transactionJson["type"] = transaction.getTransactionType();
			transactionJson["date"] = transaction.getDate();
			transactionsJson.push_back(transactionJson);
		}
		accountJson["transactions"] = transactionsJson;

		// Add the account JSON to the accounts JSON array
		accountsJson.push_back(accountJson);
	}

	if (file.is_open()) {
		file << accountsJson.dump(4);
		file.close();
	}
}

// Validation functions
bool FileHandler::validateAccountNumber(int accountNumber) {
	return accountNumber >= 1000 && accountNumber <= 9999;
}

bool FileHandler::validateTransactionAmount(double amount) {
	return amount > 0;
}

bool FileHandler::validateWidthdrawalAmount(double amount, double balance) {
	return amount > 0 && amount <= balance;
}
