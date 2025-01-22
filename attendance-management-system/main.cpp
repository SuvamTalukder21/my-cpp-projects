#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Function declarations
int displayAdminMenu();
int displayStudentMenu();
int studentLogin();
int validateCredentials(string username, string password);
int listAllStudentsByRollNo();
int removeAllStudents();
int removeStudentByRollNo();
int checkRegisteredStudents();
int checkStudentPresenceCount();
int listStudentsWithAttendanceCount();
int registerStudent();
int adminLogin();
int markAttendance(string username);
int countAttendance(string username);
int delay();

// Function to create a delay
int delay() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 20000; j++) {
            for (int k = 0; k < 20000; k++) {
                // do nothing
            }
        }
    }
    cout << "Exiting in 3 seconds..." << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 20000; j++) {
            for (int k = 0; k < 20000; k++) {
                // do nothing
            }
        }
    }
    return 0;
}

// Function to display the admin menu and handle admin actions
int displayAdminMenu() {
	int go_back = 0;
	while (go_back == 0) {
		system("cls");
		cout << "1. Register a student" << endl;
		cout << "2. Delete all registered students name" << endl;
		cout << "3. Delete student by roll number" << endl;
		cout << "4. Check list of registered  students" << endl;
		cout << "5. Check presence count of a student by roll number" << endl;
		cout << "6. Get list of students with their attendance count" << endl;
		cout << "7. Go back" << endl;
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				registerStudent();
				break;
			case 2:
				removeAllStudents();
				break;
			case 3:
				removeStudentByRollNo();
				break;
			case 4:
				checkRegisteredStudents();
				break;
			case 5:
				checkStudentPresenceCount();
				break;
			case 6:
				listStudentsWithAttendanceCount();
				break;
			case 7:
				go_back = 1;
				break;
			default:
				cout << "Invalid choice!" << endl;
				getchar();
		}
		if (go_back == 1) {
			break;
		}
	}
	return 0;
}

// Function to handle student login
int studentLogin() {
    system("cls");
    cout << "\n------------Student Login------------" << endl;
    displayStudentMenu();
    delay();
    return 0;
}

// Function to handle admin login
int adminLogin() {
    system("cls");
    cout << "\n------------Admin Login------------" << endl;
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (username == "admin" && password == "admin") {
        displayAdminMenu();
        getchar();
        delay();
    } else {
        cout << "\n Error! Invalid credentials...";
        cout << "\n Press any key for main menu";
        getchar();
        getchar();
    }
    delay();
    return 0;
}

// Function to validate user credentials
int validateCredentials(string username, string password) {
	ifstream read;
	read.open("db.dat");
	if (read) {
		int record_found = 0;
		string line;
		string temp = username + password + ".dat";
		cout << "\nFile name is: " << temp;
		while (getline(read, line)) {
			if (line == temp) {
				record_found = 1;
				break;
			}
		}
		if (record_found == 0)
			return 0;
		else
			return 1;
	} else {
		return 0;
	}
	// return record_found == 0 ? 0 : 1;
}

// int get_all_students_by_name() {
// 	cout << "\n list of all students by their name\n";
// 	cout << "Press any key to continue...";
// 	getchar();
// 	getchar();
// 	return 0;
// }

// Function to list all students by their roll number
int listAllStudentsByRollNo() {
	cout << "\n list of all students by their roll number\n";
	cout << "Press any key to continue...";
	getchar();
	getchar();
	return 0;
}

// Function to remove all students
int removeAllStudents() {
    cout << "\n Delete all registered students\n";
    cout << "Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

// Function to remove a student by roll number
int removeStudentByRollNo() {
    cout << "\n Delete student by roll number\n";
    cout << "Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

// Function to check presence count of a student by roll number
int checkStudentPresenceCount() {
    cout << "\n Check presence count of any student by roll number\n";
    cout << "Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

int check_all_presence_count_rollno() {
	cout << "\n Check presence count of all student by roll number\n";
	cout << "Press any key to continue...";
	getchar();
	getchar();
	return 0;
}

// Function to display the student menu and handle student actions
int displayStudentMenu() {
	cout << "------------Student View------------" << endl;
	string username, password;
	cout << "Enter username: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	int res = validateCredentials(username, password);
	if (res == 0) {
		cout << "\n Error! Invalid credentials...";
		cout << "\n Press any key for main menu";
		getchar();
		getchar();
	}
	int go_back = 0;
	while (1) {
		system("cls");
		cout << "1. Mark my attendance for today" << endl;
		cout << "2. Count my attendance" << endl;
		cout << "3. Go back" << endl;
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				markAttendance(username);
				break;
			case 2:
				countAttendance(username);
				break;
			case 3:
				go_back = 1;
				break;
			default:
				cout << "\nInvalid choice! Enter again..." << endl;
				getchar();
		}
		if (go_back == 1) {
			break;
		}
	}
	return 0;
}

// Function to mark attendance for the student
int markAttendance(string username) {
    cout << "\n Mark my attendance for today\n";
    cout << "Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

// Function to count attendance for the student
int countAttendance(string username) {
    cout << "\n Count my attendance for today\n";
    cout << "Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

// Function to check the list of all registered students
int checkRegisteredStudents() {
    cout << "\n Check list of registered students\n";
    cout << "Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

// Function to list students with their attendance count
int listStudentsWithAttendanceCount() {
    cout << "\n Check list of students registered by username";
    ifstream read;
    read.open("db.dat");

    if (read) {
        string line;
        while (getline(read, line)) {
            char name[100];
            strcpy(name, line.c_str());
            char onlyname[100];
            strncpy(onlyname, name, (strlen(name) - 4));
            cout << "\n" << onlyname;
        }
        read.close();
    } else {
        cout << "\n Error! File not found...";
    }

    cout << "Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

// Function to register a new student
int registerStudent() {
	cout << "\n-----------------Form to Register Student-----------------";
	string name, roll_no, username, password, address, father, mother;
	cout << "\nEnter name: ";
	cin >> name;
	cout << "\nEnter username: ";
	cin >> username;
	cout << "\nEnter password: ";
	cin >> password;
	cout << "\nEnter roll number: ";
	cin >> roll_no;
	getchar();  // Clear the newline character from the input buffer
	char add[100];
	cout << "\nEnter address: ";
	cin.getline(add, 100);
	cout << "\nEnter father's name: ";
	cin >> father;
	cout << "\nEnter mother's name: ";
	cin >> mother;

	// Check if the username is already registered
	ifstream read;
	read.open("db.dat");
	if (read) {
		int record_found = 0;
		string line;
		while (getline(read, line)) {
			// if (line == username + password + ".dat") {
			if (line == username + ".dat") {
				record_found = 1;
				break;
			}
		}
		if (record_found == 1) {
			cout << "\n Username already registered. Please choose another username.";
			getchar();
			getchar();
			delay();
			read.close();
			return 0;
		}
	}
	read.close();

	// Register the new student
	ofstream out;
	out.open("db.dat", ios::app);
	// out << username + password + ".dat" << endl;
	out << username + ".dat" << endl;
	out.close();

    ofstream out1;
    string temp = username + ".dat";
    out1.open(temp.c_str());
    out1 << name << endl;
    out1 << username << endl;
    out1 << password << endl;
    out1 << roll_no << endl;
    out1 << add << endl;
    out1 << father << endl;
    out1 << mother << endl;
    out1.close();

    cout << "\n Student registered successfully!";
    cout << "\n Press any key to continue...";
    getchar();
    getchar();
    return 0;
}

// Main function to run the program
int main(int argc, char **argv) {
    while (1) {
        system("cls");
        cout << "------------Student Attendance Management System------------" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "1. Student Login" << endl;
        cout << "2. Admin Login" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                studentLogin();
                break;

            case 2:
                adminLogin();
                break;

            case 3:
                while (1) {
                    system("cls");
                    cout << "Are you sure you want to exit? (Y/N)" << endl;
                    char ex;
                    cin >> ex;
                    if (ex == 'Y' || ex == 'y') {
                        exit(0);
                    } else if (ex == 'N' || ex == 'n') {
                        break;
                    } else {
                        cout << "Invalid choice!" << endl;
                        getchar();
                    }
                }
                break;

            default:
                cout << "Invalid choice!" << endl;
                getchar();
        }
    }

    return 0;
}
