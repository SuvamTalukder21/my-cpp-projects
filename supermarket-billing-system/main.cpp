#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;

// Global variables for cursor positioning and menu control
int cursor_y = 7, report_row = 0, item_found_flag = 0;
COORD cursor_position = {0, 0};

// Function to set the cursor position in the console
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Structure to hold date information
struct Date {
	int month, day, year;
};

// File streams for reading and writing item data
ofstream fout;
ifstream fin;

// Class to represent an item in the supermarket
class Item {
	int item_number;
	char item_name[25];
	Date manufacturing_date;

public:
	// Function to add item details
	void add() {
		cout << "\n\n\tItem No: ";
		cin >> item_number;
		cout << "\n\n\tName of the item: ";
		cin >> item_name;
		cout << "\n\n\tManufacturing Date(dd-mm-yy): ";
		cin >> manufacturing_date.day >> manufacturing_date.month >> manufacturing_date.year;
	}

	// Function to display item details
	void show() {
		cout << "\n\tItem No: " << item_number;
		cout << "\n\n\tName of the item: " << item_name;
		cout << "\n\n\tDate: " << manufacturing_date.day << "/" << manufacturing_date.month << "/" << manufacturing_date.year;
	}

	// Function to report item details in a formatted way
	void report() {
		gotoxy(3, cursor_y);
		cout << item_number;
		gotoxy(13, cursor_y);
		puts(item_name);
	}

	// Function to return the item number
	int getItemNumber() {
		return(item_number);
	}
};

// Class to represent item amount details, inheriting from Item
class Amount: public Item {
	float price, quantity, tax, grossAmount, discount, netAmount;

public:
	void add();  // Function to add amount details
	void show();  // Function to display amount details
	void report();  // Function to report amount details
	void calculate();  // Function to calculate net amount
	void pay();  // Function to display payment details

	// Function to return net amount
	float getNetAmount() {
		return(netAmount);
	}
} amt;

// Function to add amount details
void Amount::add() {
	Item::add();   // Call the base class add function
	cout << "\n\n\tPrice: ";
	cin >> price;
	cout << "\n\n\tQuantity: ";
	cin >> quantity;
	cout << "\n\n\tTax percent: ";
	cin >> tax;
	cout << "\n\n\tDiscount percent: ";
	cin >> discount;
	calculate();  // Calculate net amount
	fout.write((char*)&amt, sizeof(amt));  // Write to file
	fout.close();
}

// Function to calculate net amount
void Amount::calculate() {
	grossAmount = price + (price * (tax / 100));
	netAmount = quantity * (grossAmount - (grossAmount * (discount / 100)));
}

// Function to display amount details
void Amount::show() {
	fin.open("itemstore.dat", ios::binary);
	fin.read((char*)&amt, sizeof(amt));
	Item::show();  // Call the base class show function
	cout << "\n\n\tNet Amount: " << netAmount;
	fin.close();
}

// Function to report amount details
void Amount::report() {
    Item::report();  // Call the base class report function
    gotoxy(23, cursor_y);
    cout << price;
    gotoxy(33, cursor_y);
    cout << quantity;
    gotoxy(44, cursor_y);
    cout << tax;
    gotoxy(52, cursor_y);
    cout << discount;
    gotoxy(64, cursor_y);
    cout << netAmount;
    cursor_y++;

    // Check if cursorY exceeds limit to pause and clear screen
    if (cursor_y == 50) {
        gotoxy(25, 50);
        cout << "PRESS ANY KEY TO CONTINUE...";
        getch();
        cursor_y = 7;
        system("cls");
        gotoxy(30, 3);
        cout << " ITEM DETAILS ";
        gotoxy(3, 5);
        cout << "NUMBER";
        gotoxy(13, 5);
        cout << "NAME";
        gotoxy(23, 5);
        cout << "PRICE";
        gotoxy(33, 5);
        cout << "QUANTITY";
        gotoxy(44, 5);
        cout << "TAX";
        gotoxy(52, 5);
        cout << "DEDUCTION";
        gotoxy(64, 5);
        cout << "NET AMOUNT";
    }
}

// Function to display payment details
void Amount::pay() {
	show();  // Show item details
	cout << "\n\n\n\t\t**********************************************";
	cout << "\n\t\t                   DETAILS                        ";
	cout << "\n\n\n\t\t**********************************************";
	cout << "\n\n\t\tPRICE                       : " << price;
	cout << "\n\n\t\tQUANTITY                    : " << quantity;
	cout << "\n\n\t\tTAX PERCENTAGE              : " << tax;
	cout << "\n\n\t\tDISCOUNT PERCENTAGE         : " << discount;
	cout << "\n\n\t\tNET AMOUNT                  : $" << netAmount;
	cout << "\n\n\n\t\t**********************************************";
}

int main() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout << setprecision(2);
	fstream tempFile("temp.dat", ios::binary | ios::out);

	// Main menu loop
	menu:
		system("cls");
		gotoxy(25, 2);
		cout << "Super Market Billing";
		gotoxy(25, 3);
		cout << "===========================\n\n";
		cout << "\n\t\t1. Bill Report\n\n";
		cout << "\n\t\t2. Add/Remove/Edit Item\n\n";
		cout << "\n\t\t3. Show Item Details\n\n";
		cout << "\n\t\t4. Exit\n\n";
		cout << "\t\tPlease Enter Required Option: ";

		int choice, ff;
		float grand_total;
		cin >> choice;

	switch (choice) {
		case 1: // Bill Report
			ss:
				system("cls");
				gotoxy(25, 2);
				cout << "Bill Details";
				gotoxy(25, 3);
				cout << "================\n\n";
				cout << "\n\t\t1. All Items\n\n";
				cout << "\n\t\t2. Back to Main Menu\n\n";
				cout << "\t\tPlease Enter Required Option: ";

				int report_choice;
				cin >> report_choice;
				if (report_choice == 1) {
					system("cls");
					gotoxy(30, 3);
					cout << " BILL DETAILS ";
					gotoxy(3, 5);
					cout << "ITEM NO";
					gotoxy(13, 5);
					cout << "NAME";
					gotoxy(23, 5);
					cout << "PRICE";
					gotoxy(33, 5);
					cout << "QUANTITY";
					gotoxy(44, 5);
					cout << "TAX %";
					gotoxy(52, 5);
					cout << "DISCOUNT %";
					gotoxy(64, 5);
					cout << "NET AMOUNT";

					fin.open("itemstore.dat", ios::binary);
					if (!fin) {
						cout << "\n\nFile Not Found...";
						goto menu;
					}

					fin.seekg(0);
					grand_total = 0;
					while (!fin.eof()) {
						fin.read((char*)&amt, sizeof(amt));
						if (!fin.eof()) {
							amt.report();
							grand_total += amt.getNetAmount();
							ff = 0;
						}
						if (ff != 0) grand_total = 0;
					}
					gotoxy(17, cursor_y);
					cout << "\n\n\n\n\t\t\tGrand Total = " << grand_total;
					getch();
					fin.close();
				}
				if (report_choice == 2) {
					goto menu;  // Go back to main menu
				}
				goto ss;

		case 2:  // Add/Remove/Edit Item
			db:
				system("cls");
				gotoxy(25, 2);
				cout << "Bill Editor";
				gotoxy(25, 3);
				cout << "==================\n\n";
				cout << "\n\t\t1. Add Item Details\n\n";
				cout << "\t\t2. Edit Item Details\n\n";
				cout << "\t\t3. Delete Item Details\n\n";
				cout << "\t\t4. Back to Main Menu\n\n";
				cout << "\t\tPlease Enter Required Option: ";

				int editor_choice;
				cin >> editor_choice;

				switch (editor_choice) {
					case 1:  // Add Item
						fout.open("itemstore.dat", ios::binary | ios::app);
						amt.add();
						cout << "\n\tItem Added Successfully!";
						getch();
						goto db;

					case 2:  // Edit Item
						int item_number;
						item_found_flag = 0;
						cout << "\n\n\tEnter Item Number to be Edited: ";
						cin >> item_number;
						fin.open("itemstore.dat", ios::binary);
						fout.open("itemstore.dat", ios::binary | ios::app);
						if (!fin) {
							cout << "\n\nFile Not Found...";
							goto menu;
						}
						fin.seekg(0);
						report_row = 0;
						while (!fin.eof()) {
							fin.read((char*)&amt, sizeof(amt));
							if (!fin.eof()) {
								int x = amt.Item::getItemNumber();
								if (x == item_number) {
									item_found_flag = 1;
									fout.seekp(report_row * sizeof(amt));
									system("cls");
									cout << "\n\t\tCurrent Details are\n";
									amt.show();
									cout << "\n\n\t\tEnter New Details\n";
									amt.add();
									cout << "\n\t\tItem Details Edited";
								}
							}
							report_row++;
						}
						if (item_found_flag == 0) {
							cout << "\n\t\tItem number does not exist... Please Retry!";
							getch();
							goto db;
						}
						fin.close();
						getch();
						goto db;
					case 3:  // Delete Item
						item_found_flag = 0;
						system("cls");
						cout << "\n\n\tEnter Item Number to be Deleted: ";
						cin >> item_number;
						fin.open("itemstore.dat", ios::binary);
						if (!fin) {
							cout << "File Not Found...";
							goto menu;
						}
						fin.seekg(0);
						while (fin.read((char*)&amt, sizeof(amt))) {
							int x = amt.Item::getItemNumber();
							if (x != item_number)
								tempFile.write((char*)&amt, sizeof(amt));
							else
								item_found_flag = 1;
						}
						fin.close();
						tempFile.close();
						fout.open("itemstore.dat", ios::trunc | ios::binary);
						fout.seekp(0);
						tempFile.open("temp.dat", ios::binary | ios::in);
						if (!tempFile) {
							cout << "Error in file";
							goto db;
						}
						while (tempFile.read((char*)&amt, sizeof(amt)))
							fout.write((char*)&amt, sizeof(amt));

						tempFile.close();
						fout.close();
						if (item_found_flag == 1)
							cout << "\n\t\tItem Successfully Deleted";
						else if (item_found_flag == 0)
							cout << "\n\t\tItem does not Exist! Please Retry";
						getch();
						goto db;

					case 4: // Back to Main Menu
						goto menu;

					default:
						cout << "\n\n\t\tWrong Choice!!!! Retry";
						getch();
						goto db;
				}
		case 3:  // Show Item Details
			system("cls");
			item_found_flag = 0;
			int item_number;
			cout << "\n\n\t\tEnter Item Number: ";
			cin >> item_number;
			fin.open("itemstore.dat", ios::binary);
			if (!fin) {
				cout << "\n\nFile Not Found...\nProgram is Terminated!";
				goto menu;
			}
			fin.seekg(0);
			while (fin.read((char*)&amt, sizeof(amt))) {
				int x = amt.Item::getItemNumber();
				if (x == item_number) {
					amt.pay();
					item_found_flag = 1;
					break;
				}
			}
			if (item_found_flag == 0)
				cout << "\n\t\tItem does not exist!...Please Retry!";
			getch();
			goto menu;

		case 4:  // Exit Program
			system("cls");
			gotoxy(20, 20);
			cout << "ARE YOU SURE, YOU WANT TO EXIT (Y/N)?";
			char exit_choice;
			cin >> exit_choice;
			if ((exit_choice == 'y') || (exit_choice == 'Y')) {
				gotoxy(12, 20);
				system("cls");
				cout << "************* THANK YOU *************";
				getch();
				exit(0);
			}
			else if ((exit_choice == 'n') || (exit_choice == 'N'))
				goto menu;

		default:
			cout << "\n\n\t\tWrong Choice.....Please Retry!";
			getch();
			goto menu;
	}
	return 0;
}
