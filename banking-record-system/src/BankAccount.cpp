#include "BankAccount.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <sstream>

using namespace std;

// Generalized function to get current date/time as string (I just tried something new)
string getCurrentDate(const string& format) {
	auto now = chrono::system_clock::now(); // Get current time point
	auto time_t = chrono::system_clock::to_time_t(now); // Convert to time_t
	auto local_time = localtime(&time_t); // Convert to local time
    
	ostringstream oss; // Create a string stream for formatting
	oss << put_time(local_time, format.c_str()); // Format the time according to the format string
	return oss.str(); // Return the string representation of the current time in the specified format
}

BankAccount::BankAccount(int accountNumber, string ownerName, double initialBalance)
	:  accountNumber(accountNumber), accountHolderName(move(ownerName)), balance(initialBalance), transactionHistory() {}

int BankAccount::getAccountNumber() const {
	return accountNumber;
}

string BankAccount::getAccountHolderName() const {
	return accountHolderName;
}

void BankAccount::deposit(unsigned int transactionID, double amount) {
	balance += amount;
	addTransaction(transactionID, amount, "Deposit", getCurrentDate("%d/%m/%Y"));
	cout << "Deposit successful. New balance: $" << getBalance() << endl;
}

void BankAccount::withdraw(unsigned int transactionID, double amount) {
	if (amount > 0 && amount <= balance) {
		balance -= amount;
		addTransaction(transactionID, -amount, "Withdraw", getCurrentDate("%d/%m/%Y"));
		cout << "Withdrawal successful. New balance: $" << getBalance() << endl;
	} else {
		cout << "Invalid withdrawal amount. Insufficient funds." << endl;
	}
}

double BankAccount::getBalance() const {
	return balance;
}

void BankAccount::displayAccountDetails() const {
	cout << "Account Holder: " << accountHolderName << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Balance: $" << balance << endl;
}

void BankAccount::addTransaction(unsigned int transactionID, double amount, const string& type, const string& date) {
	if (existingTransactionIDs.find(transactionID) == existingTransactionIDs.end()) {
		transactionHistory.emplace_back(transactionID, accountNumber, amount, type, date);
		existingTransactionIDs.insert(transactionID);
	} else {
		// cout << "Transaction ID already exists." << endl;
		throw runtime_error("Transaction ID already exists.");
	}
}

const vector<Transaction>& BankAccount::getTransactionHistory() const {
	return transactionHistory;
}
