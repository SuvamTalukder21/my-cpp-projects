#include <iostream>
#include <cstring>
#include <cstdio>
// #include <cstdlib>
// #include <iomanip>
// #include <conio.h>

using namespace std;

// Structure to hold student information
struct Student {
    char first_name[50];
    char last_name[50];
    char course[100];
    int section;
};

int main() {
	FILE *file_pointer, *temp_file_pointer;
	char another_record, user_choice;

	// Create a student object
	Student student_record;
	char xfirst_name[50], search_last_name[50];
	long int record_size;

	// Open the file for reading and writing in binary mode
	file_pointer = fopen("users.txt", "rb+");

	// If the file does not exist, create it
	if (file_pointer == NULL) {
		file_pointer = fopen("users.txt", "wb+");

		if (file_pointer == NULL) {
			puts("Cannot open file");
			return 0;
		}
	}
	record_size = sizeof(student_record);

    // Main loop for the menu
    while (true) {
        system("cls"); // Clear the console

		cout << "\t\t====== STUDENT DATABASE MANAGEMENT SYSTEM ======";
		cout << "\n\n";
		cout << "\n\n";
		cout << "\n \t\t\t 1. Add    Records";
		cout << "\n \t\t\t 2. List   Records";
		cout << "\n \t\t\t 3. Modify Records";
		cout << "\n \t\t\t 4. Delete Records";
		cout << "\n \t\t\t 5. Exit   Program";
		cout << "\n\n";
		cout << "\t\t\t Select Your Choice :=> ";
		fflush(stdin);
		user_choice = getchar();

		switch (user_choice) {
			case '1':  // Add Records
				fseek(file_pointer, 0, SEEK_END);  // Move to the end of the file
				another_record = 'Y';
				while (another_record == 'Y' || another_record == 'y') {
					system("cls");
					cout << "Enter the first name: ";
					cin >> student_record.first_name;
					cout << "Enter the last name: ";
					cin >> student_record.last_name;
					cout << "Enter the course: ";
					cin >> student_record.course;
					cout << "Enter the section: ";
					cin >> student_record.section;

					// Write the student record to the file
					fwrite(&student_record, record_size, 1, file_pointer);
					cout << "\n Add another record (Y/N) ";
					fflush(stdin);
					another_record = getchar();
				}
				break;

			case '2':  // List Records
				system("cls");
				rewind(file_pointer);  // Move to the beginning of the file
				cout << "=== View the Records in the Database ===";
				cout << "\n";
				while (fread(&student_record, record_size, 1, file_pointer) == 1) {
					cout << "\n" << "Name: " << student_record.first_name << " " << student_record.last_name;
					cout << "\n" << "Course: " << student_record.course;
					cout << "\n" << "Section: " << student_record.section << "\n";
				}
				cout << "\n\n";
				system("pause");
				break;

			case '3':  // Modify Records
				system("cls");
				another_record = 'Y';
				while (another_record == 'Y' || another_record == 'y') {
					cout << "Enter the last name of the student to modify: ";
					cin >> search_last_name;

					rewind(file_pointer);  // Move to the beginning of the file
					while (fread(&student_record, record_size, 1, file_pointer) == 1) {
						if (strcmp(student_record.last_name, search_last_name) == 0) {
							cout << "Enter new first name: ";
							cin >> student_record.first_name;
							cout << "Enter new last name: ";
							cin >> student_record.last_name;
							cout << "Enter new course: ";
							cin >> student_record.course;
							cout << "Enter new section: ";
							cin >> student_record.section;
							fseek(file_pointer, -record_size, SEEK_CUR);  // Move back to the current record position
							fwrite(&student_record, record_size, 1, file_pointer);  // Update the record
							break;
						}
					}
					cout << "\n Modify another record (Y/N) ";
					fflush(stdin);
					another_record = getchar();
				}
				break;
			case '4':  // Delete Records
				system("cls");
				another_record = 'Y';
				while (another_record == 'Y' || another_record == 'y') {
					cout << "\n Enter the last name of the student to delete: ";
					cin >> search_last_name;

                    // Create a temporary file to store records that are not deleted
                    temp_file_pointer = fopen("temp.dat", "wb");

					rewind(file_pointer);  // Move to the beginning of the file
					while (fread(&student_record, record_size, 1, file_pointer) == 1) {
						if (strcmp(student_record.last_name, search_last_name) != 0) {
							fwrite(&student_record, record_size, 1, temp_file_pointer);  // Write to temp file
						}
					}
					fclose(file_pointer);
					fclose(temp_file_pointer);
					remove("users.txt"); // Delete the original file
					rename("temp.dat", "users.txt"); // Rename temp file to original file name

                    // Reopen the original file
                    file_pointer = fopen("users.txt", "rb+");

					cout << "\n Delete another record (Y/N) ";
					fflush(stdin);
					another_record = getchar();
				}
				break;
			case '5':  // Exit Program
				fclose(file_pointer);
				cout << "\n\n";
				cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE";
				cout << "\n\n";
				exit(0);
		}
	}

	return 0;
}
