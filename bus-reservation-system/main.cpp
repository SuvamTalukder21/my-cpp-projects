// BUS RESERVATION SYSTEM

#include <iostream>
#include <cstring>
using namespace std;

static int busCount = 0; // Counter for the number of buses

class BusReservationSystem {
    char bus_number[5]; // Bus number
    char driver_name[10]; // Driver's name
    char arrival_time[5]; // Arrival time
    char departure_time[5]; // Departure time
    char from_location[10]; // Departure location
    char to_location[10]; // Destination location
    char seat[8][4][10]; // 2D array to hold seat reservations

public:
    void installBus(); // Function to install a new bus
    void allotSeat(); // Function to allot a seat to a passenger
    void initializeSeats(); // Function to initialize seats as empty
    void showBusDetails(); // Function to show bus details
    void showAvailableBuses(); // Function to show available buses
    void displaySeatPosition(int busIndex); // Function to display seat positions
};

BusReservationSystem buses[10]; // Array to hold multiple bus reservation systems

// Function to print a line of characters
void printLine(char ch) {
    for (int i = 80; i > 0; i--)
        cout << ch;
}

// Function to install a new bus
void BusReservationSystem::installBus() {
    cout << "Enter bus number: ";
    cin >> buses[busCount].bus_number;
    cout << "Enter driver's name: ";
    cin >> buses[busCount].driver_name;
    cout << "Enter arrival time: ";
    cin >> buses[busCount].arrival_time;
    cout << "Enter departure time: ";
    cin >> buses[busCount].departure_time;
    cout << "Enter from location: ";
    cin >> buses[busCount].from_location;
    cout << "Enter to location: ";
    cin >> buses[busCount].to_location;
    buses[busCount].initializeSeats();  // Initialize seats for the new bus
    busCount++;  // Increment bus count
}

// Function to allot a seat to a passenger
void BusReservationSystem::allotSeat() {
    int seat_number;
    char bus_number_input[5];
    top:
        cout << "Bus no: ";
        cin >> bus_number_input;

        // Find the bus index based on bus number
        int bus_index;
        for(bus_index = 0; bus_index <= busCount; bus_index++)
        {
            if(strcmp(buses[bus_index].bus_number, bus_number_input) == 0)
                break; // Exit the loop if bus number is found
        }

    // Loop to get valid bus number
    while(bus_index <= busCount)
    {
        cout << "\nSeat Number: ";
        cin >> seat_number;

        // Check if seat number is valid
        if (seat_number > 32) {
            cout<<"\nThere are only 32 seats available in this bus.";
        } else {
            // Check if the seat is empty
            if (strcmp(buses[bus_index].seat[seat_number / 4][(seat_number % 4) - 1], "Empty") == 0) {
                cout<<"Enter passenger's name: ";
                cin>>buses[bus_index].seat[seat_number / 4][(seat_number % 4) - 1];
                break;  // Exit the seat allotment loop
            }

            cout<<"The seat no. is already reserved. \n";
        }
    }

    if(bus_index > busCount) {
        cout<<"Enter correct bus number \n";
        goto top;
    }

}

// Function to initialize all seats as empty
void BusReservationSystem::initializeSeats() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            strcpy(buses[busCount].seat[i][j], "Empty");
        }
    }
}

// Function to show bus details
void BusReservationSystem::showBusDetails() {
    char bus_number_input[5];
    cout << "Enter bus number: ";
    cin >> bus_number_input;

    // Find the bus index based on bus number
    int bus_index;
    for(bus_index = 0; bus_index <= busCount; bus_index++)
    {
        if(strcmp(buses[bus_index].bus_number, bus_number_input) == 0)
            break;
    }

    // If bus is found, display bus details
    while(bus_index <= busCount)
    {
        printLine('*');
        cout << "Bus number: " << buses[bus_index].bus_number << endl;
        cout << "Driver's name: " << buses[bus_index].driver_name << endl;
        cout << "Arrival time: " << buses[bus_index].arrival_time << endl;
        cout << "Departure time: " << buses[bus_index].departure_time << endl;
        cout << "From: " << buses[bus_index].from_location << endl;
        cout << "To: " << buses[bus_index].to_location << endl;
        printLine('*');
        buses[0].displaySeatPosition(bus_index);  // Display seat positions
        int a = 1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 4; j++) {
                a++;
                if (strcmp(buses[bus_index].seat[i][j], "Empty") != 0)
                    cout << "\nThe seat no " << (a - 1) << " is reserved for " << buses[bus_index].seat[i][j] << ".";
            }
        }
        break;
    }

    if(bus_index > busCount)
        cout<<"Enter correct bus number... \n";
}

// Function to display seat positions
void BusReservationSystem::displaySeatPosition(int busIndex) {
    int s = 0, p = 0;
    for (int i = 0; i < 8; i++) {
        cout << "\n";
        for (int j = 0; j < 4; j++) {
            s++;
            if (strcmp(buses[busIndex].seat[i][j], "Empty") == 0) {
                // cout << "The seat no " << s << " is empty.";
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << buses[busIndex].seat[i][j];
                busCount++;
            }
            else {
                // cout << "The seat no " << s << " is reserved for " << buses[busIndex].seat[i][j] << ".";
                // p++;
                cout.width(5);
                cout.fill(' ');
                cout << s << ".";
                cout.width(10);
                cout.fill(' ');
                cout << buses[busIndex].seat[i][j];
                busCount++;
            }
        }
    }

    cout << "\n\nThere are " << s << " seats in the bus, out of which " << p << " seats are reserved and " << s - p << " seats are available.";
}

// Function to show available buses
void BusReservationSystem::showAvailableBuses() {
    for (int n = 0; n < busCount; n++) {
        printLine('*');
        cout << "Bus number: " << buses[n].bus_number << endl;
        cout << "Driver's name: " << buses[n].driver_name << endl;
        cout << "Arrival time: " << buses[n].arrival_time << endl;
        cout << "Departure time: " << buses[n].departure_time << endl;
        cout << "From: " << buses[n].from_location << endl;
        cout << "To: " << buses[n].to_location << endl;
        printLine('*');
        printLine('_');
    }
}

int main()
{
    int choice;
    while (true) {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t1.Install\n\t\t\t"
             << "2.Reservation\n\t\t\t"
             << "3.Show\n\t\t\t"
             << "4.Buses Available. \n\t\t\t"
             << "5.Exit";
        cout << "\n\t\t\tEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                buses[busCount].installBus();
                break;
            case 2:
                buses[0].allotSeat();
                break;
            case 3:
                buses[0].showBusDetails();
                break;
            case 4:
                buses[0].showAvailableBuses();
                break;
            case 5:
                exit(0);  // Exit the program
            default:
                cout << "Invalid option. Please try again."; // Handle invalid input
            break;
        }
    }
    return 0;  // Return success
}
