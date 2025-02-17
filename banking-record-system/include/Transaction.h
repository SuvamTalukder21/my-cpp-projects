// Transaction class declaration
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <nlohmann/json.hpp>

using namespace std;

// This class represents a single transaction in a bank account, storing transaction history details such as the amount, type, and date.
class Transaction {
private:
	unsigned int transactionID; // Unique ID for the transaction
	int accountNumber; // Account number associated with the transaction
	double amount; // Amount involved in the transaction (positive for deposits, negative for withdrawals)
	string transactionType; // Type of transaction (e.g., deposit, withdrawal)
	string date; // Date of the transaction

public:
	Transaction(unsigned int transactionID, int accountNumber, double amount, const string& type, const string& date); // Constructor to initialize a transaction.
	unsigned int getTransactionID() const; // Get the unique transaction ID
	double getAmount() const; // Get the transaction amount
	string getTransactionType() const; // Get the transaction type (e.g., deposit, withdrawal)
	string getDate() const; // Get the transaction date
	void displayTransactionDetails() const; // Display the details of the transaction (for logs or statements)
};

#endif //TRANSACTION_H
