#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Class to manage account queries
class AccountQuery
{
    char account_number[20]; // To store account number
    char first_name[10];     // To store first name
    char last_name[10];      // To store last name
    float total_balance;     // To store total balance

public:
    void readData();        // Function to read account data from user
    void showData();        // Function to display account data
    void writeRecord();     // Function to write a new record to file
    void readRecords();      // Function to read all records from file
    void searchRecord();     // Function to search for a specific record
    void editRecord();       // Function to edit an existing record
    void deleteRecord();     // Function to delete a specific record
};

// Function to read account data from user
void AccountQuery::readData()
{
    cout << "\nEnter Account Number: ";
    cin >> account_number;
    cout << "\nEnter First Name: ";
    cin >> first_name;
    cout << "\nEnter Last Name: ";
    cin >> last_name;
    cout << "\nEnter balance: ";
    cin >> total_balance;
    cout << endl;
}

// Function to display account data
void AccountQuery::showData()
{
    cout << "Account Number: " << account_number<< endl;
    cout << "First Name: " << first_name << endl;
    cout << "Last Name: " << last_name << endl;
    cout << "Current balance: " << total_balance << endl;
    cout << "-----------------------------" << endl;
}

// Function to write a new record to the file
void AccountQuery::writeRecord()
{
    ofstream outfile;
    outfile.open("record.bank", ios::binary | ios::app); // Open file in append mode
    readData(); // Read data from user
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this)); // Write data to file
    outfile.close(); // Close the file
}

// Function to read all records from the file
void AccountQuery::readRecords()
{
    ifstream infile;
    infile.open("record.bank", ios::binary); // Open file in binary mode
    if (!infile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    cout << "\n***Data from file****" << endl;
    while (!infile.eof())
    {
        if (infile.read(reinterpret_cast<char*>(this), sizeof(*this)))
        {
            showData(); // Display each record
        }
    }
    infile.close(); // Close the file
}

// Function to search for a specific record
void AccountQuery::searchRecord()
{
    int recordNumber;
    ifstream infile;
    infile.open("record.bank", ios::binary); // Open file in binary mode
    if (!infile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    infile.seekg(0, ios::end); // Move to the end of the file
    int recordCount = infile.tellg() / sizeof(*this); // Calculate number of records
    cout << "\nThere are " << recordCount << " records in the file";
    cout << "\nEnter record number to search: ";
    cin >> recordNumber;
    infile.seekg((recordNumber - 1) * sizeof(*this)); // Move to the specific record
    infile.read(reinterpret_cast<char*>(this), sizeof(*this)); // Read the record
    showData(); // Display the record
}

// Function to edit an existing record
void AccountQuery::editRecord()
{
    int recordNumber;
    fstream iofile;
    iofile.open("record.bank", ios::in | ios::binary); // Open file in read mode
    if (!iofile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    iofile.seekg(0, ios::end); // Move to the end of the file
    int recordCount = iofile.tellg() / sizeof(*this); // Calculate number of records
    cout << "\nThere are " << recordCount << " records in the file";
    cout << "\nEnter Record Number to edit: ";
    cin >> recordNumber;
    iofile.seekg((recordNumber - 1) * sizeof(*this)); // Move to the specific record
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this)); // Read the record
    cout << "Record " << recordNumber << " has the following data" << endl;
    showData(); // Display the record
    iofile.close(); // Close the file

    // Reopen the file in read/write mode to update the record
    iofile.open("record.bank", ios::out | ios::in | ios::binary);
    iofile.seekp((recordNumber - 1) * sizeof(*this)); // Move to the specific record
    cout << "\nEnter data to modify " << endl;
    readData(); // Read new data from user
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this)); // Write updated data to file
}

// Function to delete a specific record
void AccountQuery::deleteRecord()
{
    int recordNumber;
    ifstream infile;
    infile.open("record.bank", ios::binary); // Open file in binary mode
    if (!infile)
    {
        cout << "Error in Opening! File Not Found!!" << endl;
        return;
    }
    infile.seekg(0, ios::end); // Move to the end of the file
    int recordCount = infile.tellg() / sizeof(*this); // Calculate number of records
    cout << "\nThere are " << recordCount << " records in the file";
    cout << "\nEnter Record Number to delete: ";
    cin >> recordNumber;

    fstream tmpfile;
    tmpfile.open("tmpfile.bank", ios::out | ios::binary); // Create a temporary file
    infile.seekg(0); // Move to the beginning of the original file
    for (int i = 0; i < recordCount; i++)
    {
        infile.read(reinterpret_cast<char*>(this), sizeof(*this)); // Read each record
        if (i == (recordNumber - 1)) // Skip the record to be deleted
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this)); // Write to temporary file
    }
    infile.close(); // Close the original file
    tmpfile.close(); // Close the temporary file
    remove("record.bank"); // Remove the original file
    rename("tmpfile.bank", "record.bank"); // Rename temporary file to original file name
}

// Main function to run the account information system
int main()
{
    AccountQuery account; // Create an instance of AccountQuery
    int choice; // Variable to store user choice
    cout << "***Account Information System***" << endl;
    while (true)
    {
        // Display menu options
        cout << "Select one option below ";
        cout << "\n\t1-->Add record to file";
        cout << "\n\t2-->Show records from file";
        cout << "\n\t3-->Search record from file";
        cout << "\n\t4-->Update record";
        cout << "\n\t5-->Delete record";
        cout << "\n\t6-->Quit";
        cout << "\nEnter your choice: ";
        cin >> choice; // Get user choice
        switch (choice)
        {
        case 1:
            account.writeRecord(); break;
        case 2:
            account.readRecords();
            break;
        case 3:
            account.searchRecord();
            break;
        case 4:
            account.editRecord();
            break;
        case 5:
            account.deleteRecord();
            break;
        case 6:
            exit(0); // Exit the program
            break;
        default:
            cout << "\nEnter correct choice"; // Handle invalid choice
            exit(0);
        }
    }
    
    system("pause"); // Pause the system before exiting
    return 0; // Return success
}
