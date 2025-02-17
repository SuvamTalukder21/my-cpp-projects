#include "Transaction.h"

#include <iostream>
#include <random>

using namespace std;

Transaction::Transaction(unsigned int transactionID, int accountNumber, double amount, const string& type, const string& date)
	: transactionID(transactionID), accountNumber(accountNumber), amount(amount), transactionType(type), date(date) {}

unsigned int Transaction::getTransactionID() const {
	return transactionID;
}

double Transaction::getAmount() const {
	return amount;
}

string Transaction::getTransactionType() const {
	return transactionType;
}

string Transaction::getDate() const {
	return date;
}

void Transaction::displayTransactionDetails() const {
	cout << "Transaction ID: " << transactionID << endl;
	cout << "Account Number: " << accountNumber << endl;
	cout << "Amount: $" << fabs(amount) << endl;
	cout << "Type: " << transactionType << endl;
	cout << "Date: " << date << endl;
}
