#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

// Function to set the cursor position in the console
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Class to represent a student
class Student {
	int roll_number;  // Student's roll number
	char name[50];  // Student's name
	int physics_marks, chemistry_marks, math_marks, english_marks, cs_marks;  // Marks in different subjects
	float percentage; // Percentage of marks
	char grade;  // Grade based on percentage

	// Private method to calculate percentage and grade
	void calculate() {
		percentage = (physics_marks + chemistry_marks + math_marks + english_marks + cs_marks) / 5.0;
		if (percentage >= 60)
			grade = 'A';
		else if (percentage >= 50)
			grade = 'B';
		else if (percentage >= 33)
			grade = 'C';
		else
			grade = 'F';
	}

	public:
		// Method to get student data from user
		void getData() {
			cout << "\nEnter the roll number of student: ";
			cin >> roll_number;
			cout << "\nEnter the name of student: ";
			cin >> name;
			cout << "\nEnter the marks of physics out of 100: ";
			cin >> physics_marks;
			cout << "\nEnter the marks of chemistry out of 100: ";
			cin >> chemistry_marks;
			cout << "\nEnter the marks of mathematics out of 100: ";
			cin >> math_marks;
			cout << "\nEnter the marks of english out of 100: ";
			cin >> english_marks;
			cout << "\nEnter the marks of computer science out of 100: ";
			cin >> cs_marks;
			calculate();  // Calculate percentage and grade
		}

		// Method to display student data
		void showData() {
			cout << "\nRoll number of student: " << roll_number;
			cout << "\nName of student: " << name;
			cout << "\nMarks in physics: " << physics_marks;
			cout << "\nMarks in chemistry: " << chemistry_marks;
			cout << "\nMarks in mathematics: " << math_marks;
			cout << "\nMarks in english: " << english_marks;
			cout << "\nMarks in computer science: " << cs_marks;
			cout << "\nPercentage of student is: " << setprecision(2) << percentage;
			cout << "\nGrade of student is: " << grade;
		}

    // Method to display student data in tabular format
    void showTabular() {
        cout << roll_number << setw(12) << " " << name << setw(10) << " "
             << physics_marks << setw(3) << " " << chemistry_marks << setw(3) << " "
             << math_marks << setw(3) << " " << english_marks << setw(3) << " "
             << cs_marks << setw(3) << " " << setprecision(3) << percentage << setw(6) << " "
             << grade << endl;
    }

		int getRollNumber() {
			return roll_number;
		}
};

// Global file stream and student object
fstream file_stream;
Student student;

// Function to write student data to file
void writeStudent() {
	file_stream.open("student.dat", ios::out | ios::app);
	student.getData();
	file_stream.write(reinterpret_cast<char *>(&student), sizeof(Student));
	file_stream.close();
	cout << "\n\nStudent record has been created.";
	getch();
}

// Function to display all student records
void displayAllStudents() {
	cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	file_stream.open("student.dat", ios::in);
	while (file_stream.read(reinterpret_cast<char *>(&student), sizeof(Student))) {
		student.showData();
		cout << "\n\n====================================\n";
		getch();
	}
	file_stream.close();
	getch();
}

// Function to display a specific student's record based on roll number
void displayStudentByRollNumber(int roll_number) {
	int found = 0;
	file_stream.open("student.dat", ios::in);
	while (file_stream.read(reinterpret_cast<char *>(&student), sizeof(Student))) {
		if (student.getRollNumber() == roll_number) {
			student.showData();
			found = 1;
		}
	}
	file_stream.close();
	if (found == 0)
		cout << "\n\nRecord not exist.";
	getch();
}

// Function to modify a student's record
void modifyStudent() {
	int roll_number, found = 0;
	system("cls");
	cout << "\n\n\tTo Modify ";
	cout << "\n\n\tPlease Enter the roll number of student: ";
	cin >> roll_number;
	file_stream.open("student.dat", ios::in | ios::out);
	while (file_stream.read(reinterpret_cast<char *>(&student), sizeof(Student)) && found == 0) {
		if (student.getRollNumber() == roll_number) {
			student.showData();
			cout << "\nPlease Enter the new details of student: " << endl;
			student.getData();
			int pos = -1 * static_cast<int>(sizeof(student));
			file_stream.seekp(pos, ios::cur);
			file_stream.write(reinterpret_cast<char *>(&student), sizeof(Student));
			cout << "\n\n\t Record Updated.";
			found = 1;
		}
	}
	file_stream.close();
	if (found == 0)
		cout << "\n\n Record Not Found.";
	getch();
}

// Function to delete a student's record
void deleteStudent() {
	int roll_number;
	system("cls");
	cout << "\n\n\n\tDelete Record";
	cout << "\n\nPlease Enter the roll number of student: ";
	cin >> roll_number;
	file_stream.open("student.dat", ios::in | ios::out);
	fstream temp_file;
	temp_file.open("Temp.dat", ios::out);
	file_stream.seekg(0, ios::beg);
	while (file_stream.read(reinterpret_cast<char *>(&student), sizeof(Student))) {
		if (student.getRollNumber() != roll_number) {
			temp_file.write(reinterpret_cast<char *>(&student), sizeof(Student));
		}
	}
	temp_file.close();
	file_stream.close();
	remove("student.dat");
	rename("Temp.dat", "student.dat");
	cout << "\n\n\tRecord Deleted.";
	getch();
}

// Function to display the class result
void displayClassResult() {
	system("cls");
	file_stream.open("student.dat", ios::in);
	if (!file_stream) {
		cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File";
		cout << "\n\n\n Program is closing....";
		getch();
		exit(0);
	}
	cout << "\n\n\t\tALL STUDENTS RESULT \n\n";
	cout << "====================================================\n";
	cout << "R.No. Name       P   C   M   E   CS   %age   Grade\n";
	cout << "====================================================\n";
	while (file_stream.read(reinterpret_cast<char *>(&student), sizeof(Student))) {
		student.showTabular();
	}
	file_stream.close();
	getch();
}

// Function to display results menu
void displayResultMenu() {
	int choice, roll_number;
	char continue_choice;
	system("cls");
	cout << "\n\n\nRESULT MENU";
	cout << "\n\n\n1. Class Result\n\n2. Student Report Card\n\n3. Back to Main Menu";
	cout << "\n\n\nEnter Choice (1/2)? ";
	cin >> choice;
	switch (choice) {
		case 1:
			displayClassResult();
			break;
		case 2:
			do {
				system("cls");
				cout << "\n\nEnter roll number of student: ";
				cin >> roll_number;
				displayStudentByRollNumber(roll_number);
				cout << "\n\nDo you want to see more result (y/n)? ";
				cin >> continue_choice;
			} while (continue_choice == 'y' || continue_choice == 'Y');
			break;
		case 3:
			break;
		default:
			cout << "\a";
	}
}

// Function to display introductory screen
void displayIntro() {
	system("cls");
	gotoxy(35, 11);
	cout << "STUDENT";
	gotoxy(33, 14);
	cout << "REPORT CARD";
	gotoxy(35, 17);

	getch();
}

// Function to display entry menu
void displayEntryMenu() {
	char choice;
	system("cls");
	cout << "\n\n\n\tENTRY MENU";
	cout << "\n\n\n\t1.CREATE STUDENT RECORD";
	cout << "\n\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
	cout << "\n\n\n\t3.SEARCH STUDENT RECORD ";
	cout << "\n\n\n\t4.MODIFY STUDENT RECORD";
	cout << "\n\n\n\t5.DELETE STUDENT RECORD";
	cout << "\n\n\n\t6.BACK TO MAIN MENU";
	cout << "\n\n\n\tPlease Enter Your Choice (1-6) ";
	choice = getche();
	switch (choice) {
		case '1':
			system("cls");
			writeStudent();
			break;
		case '2':
			displayAllStudents();
			break;
		case '3':
			int roll_number;
			system("cls");
			cout << "\n\n\n\tPlease Enter The roll number ";
			cin >> roll_number;
			displayStudentByRollNumber(roll_number);
			break;
		case '4':
			modifyStudent();
			break;
		case '5':
			deleteStudent();
			break;
		case '6':
			break;
		default:
			cout << "\a";
			displayEntryMenu();
	}
}

// Main function
int main() {
	char choice;
	displayIntro();
	do {
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\n\t1. RESULT MENU";
		cout << "\n\n\n\t2. ENTRY/EDIT MENU";
		cout << "\n\n\n\t3. EXIT";
		cout << "\n\n\n\tPlease Select Your Option (1-3) ";
		choice = getche();
		switch (choice) {
			case '1':
				displayResultMenu();
				break;
			case '2':
				displayEntryMenu();
				break;
			case '3':
				exit(0);
			default:
				cout << "\a";
		}
	} while (choice != '3');

    return 0;
}
