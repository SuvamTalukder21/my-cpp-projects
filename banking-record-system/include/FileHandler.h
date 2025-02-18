#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "BankAccount.h"

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>

using namespace std;

using json = nlohmann::json;

class FileHandler {
public:
	// Function to read accounts from a JSON file
	static unordered_map<int, BankAccount> readAccountsFromFile(const string& filename);

	// Function to write accounts to a JSON file
	static void writeAccountsToFile(const string& filename, const unordered_map<int, BankAccount>& accounts);

	// Validation functions
	static bool validateAccountNumber(int accountNumber);
	static bool validateTransactionAmount(double amount);
	static bool validateWidthdrawalAmount(double amount, double balance);
};

#endif //FILEHANDLER_H
