#include <fstream>
#include <iostream>

using namespace std;

// Function to book an appointment
int bookAppointment() {
    system("cls"); // Clear the console

    cout << "\n -------------- Book Your Appointment -------------- \n";
    cout << "\n -------------- Available Slots -------------- \n";

    ifstream appointment_file;  // File to read existing appointments
    appointment_file.open("appointment.dat");
    int hoursbook = 8;
    int appointment_status[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // Array to track booked hours
    int record_found = 0;  // Flag to check if any records are found

    // Read existing appointments from the file
    if (appointment_file) {
        string line;
        char key = 'A';
        int i = 9;
        while(getline(appointment_file, line))
        {
            char booked_hour = line[0];  // Get the booked hour (A, B, C, ...)
            int index = (booked_hour - 65);
            appointment_status[index] = 1;  // Mark the hour as booked
        }

        if(record_found != 1)
        {
            // Display appointment summary
            cout << "\n Appointment Summary by hours: ";
            char key = 'A';   // Start labeling hours from 'A'
            int hours = 9;
            for (int i = 0; i <= 12; i++) {
                if (i == 0) {
                    if (appointment_status[i] == 0) {
                        cout << "\n " << key << " -> 0" << hours << " - Available";
                    } else {
                        cout << "\n " << key << " -> 0" << hours << " - Booked";
                    }
                } else {
                    if (appointment_status[i] == 0) {
                        cout << "\n " << key << " -> " << hours << " - Available";
                    } else {
                        cout << "\n " << key << " -> " << hours << " - Booked";
                    }
                }
                hours++;  // Move to the next hour label
                key++;
            }
        }
        appointment_file.close();  // Close the file after reading
    }
    if (record_found == 0) {
        // Prompt user for their choice of appointment
        cout << "\n Appointment Available for following hours: ";
        char key = 'A';
        for (int i = 9; i <= 21; i++) {
            if (i == 9) {
                cout << "\n " << key << " -> 0" << i << " - Available";
            } else {
                cout << "\n " << key << " -> " << i << " - Available";
            }
            key++;
        }
    }
    char user_choice;
    // cout << "\n\n Do you want to book your appointment? (Y/N): ";
    cout << "\n\n Input your choice: ";
    cin >> user_choice;

    // Validate user input
    if (!((user_choice >= 'A' && user_choice <= 'Z') || (user_choice >= 'a' && user_choice <= 'z'))) {
        cout << "\n Invalid Input. Please try again.";
        cout << "\n Please select the correct value from the the A-Z.";
        cout << "\n Please enter any key to continue...";
        getchar(); // Wait for user input
        getchar();
        system("cls");
        bookAppointment();  // Restart the booking process
    }

    int index = (user_choice - 65);
    int isBooked = 1;
    if (appointment_status[index] == 0) {
        isBooked = 0;
    }

    if (isBooked == 1) {
        cout << "\n Appointment is already booked for this hour." << endl << "Please select another hour.";
        cout << "\n Please enter any key to continue...";
        getchar();
        getchar();
        system("cls");
        return bookAppointment();  // Restart the booking process
    }

    // Get user's name for the appointment
    string user_name;
    cout << "\n Please enter your first name: ";
    cin >> user_name;

    // Save the appointment to the file
    ofstream appointmentOutputFile;
    appointmentOutputFile.open("appointment.dat", ios::app);
    if (appointmentOutputFile) {
        appointmentOutputFile << user_choice << ":" << user_name.c_str() << "\n"; // Save the appointment
        appointmentOutputFile.close();
        cout << "\n Appointment booked for hour " << (user_choice - 65) + 9 << " successfully!!";
    } else {
        cout << "\n Error while saving booking.";
    }

    cout << "\n Please enter any key to continue...";
    getchar();
    getchar();
    return 0; // Return to main menu
}

// Function to view existing appointments
int viewExistingAppointments() {
    system("cls"); // Clear the console

    cout << "\n -------------- Appointment Summary -------------- \n";
    ifstream appointmentFile; // File to read existing appointments
    appointmentFile.open("appointment.dat");
    int appointmentStatus[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};  // Array to track booked hours
    int record_found = 0;  // Flag to check if any records are found

    // Read existing appointments from the file
    if (appointmentFile) {
        string line;
        while (getline(appointmentFile, line)) {
            char bookedHour = line[0];  // Get the booked hour (A, B, C, ...)
            int index = (bookedHour - 65);  // Convert character to index
            appointmentStatus[index] = 1;  // Mark the hour as booked
            record_found = 1;  // Set flag to true as we found a record
        }
        if (record_found == 1) {
            // Display appointment summary
            cout << "\n Appointment Summary by hours: ";
            char hourLabel = 'A';  // Start labeling hours from 'A'
            int hour = 9;  // Convert index to actual hour (9 AM + index)
            for (int i = 0; i <= 12; i++) {
                if (appointmentStatus[i] == 0) {
                    cout << "\n " << hourLabel << " -> " << hour << " - Available";
                } else {
                    cout << "\n " << hourLabel << " -> " << hour << " - Booked";
                }
                hour++;
                hourLabel++; // Move to the next hour label
            }
        }
        appointmentFile.close(); // Close the file after reading
    } else {
        char key = 'A';
        for (int i = 9; i <= 21; i++) {
            if (i == 9) {
                cout << "\n " << key << " -> 0" << i << " - Available";
            } else {
                cout << "\n " << key << " -> " << i << " - Available";
            }
            key++;
        }
    }

    cout << "\n Please enter any key to continue...";
    getchar();
    getchar();
    return 0; // Return to main menu
}

// Main function to run the appointment system
int main(int argc, char** argv) {
    while (1) {
        system("cls"); // Clear the console
        cout << "\tDoctor's Appointment System";
        cout << "\n ----------------------------------------- \n";
        cout << "\n 1. Book Appointment";
        cout << "\n 2. View Appointment";
        cout << "\n 3. Exit";
        int userChoice;
        cout << "\n\n Input your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                bookAppointment(); // Call function to book an appointment
                break;
            case 2:
                viewExistingAppointments(); // Call function to view existing appointments
                break;
            case 3:
                while (1) {
                    system("cls"); // Clear the console
                    cout << "\n Are you sure you want to exit? (Y/N): ";
                    char exitChoice;
                    cin >> exitChoice;
                    if (exitChoice == 'Y' || exitChoice == 'y') {
                        exit(0); // Exit the program
                    } else if (exitChoice == 'N' || exitChoice == 'n') {
                        break; // Go back to the main menu
                    } else {
                        cout << "\n Invalid choice. Please try again.";
                        getchar(); // Wait for user input
                    }
                }
                break;
            default:
                cout << "\n Invalid Input. Please try again.";
                getchar(); // Wait for user input
        }
    }

    return 0; // End of program
}
