#include <iostream>
#include <cstring>
using namespace std;

static int empty_seat_count = 0;  // Counter for the number of buses

class BusReservationSystem {
    char bus_number[5];  // Bus number
    char driver_name[10];  // Driver's name
    char arrival_time[5];  // Arrival time
    char departure_time[5];  // Departure time
    char from_location[10];  // Departure location
    char to_location[10];  // Destination location
    char seat[8][4][10];  // 2D array to hold seat reservations

public:
    void installBus();  // Function to install a new bus
    void allotSeat();  // Function to allot a seat to a passenger
    void initializeSeats();  // Function to initialize seats as empty
    void showBusDetails();  // Function to show bus details
    void showAvailableBuses();  // Function to show available buses
    void displaySeatPosition(int bus_index);  // Function to display seat positions
};

BusReservationSystem buses[10];  // Array to hold multiple bus reservation systems

// Function to print a line of characters
void printLine(char ch)
{
    for (int i = 80; i > 0; i--)
        cout << ch;
}

// Function to install a new bus
void BusReservationSystem::installBus()
{
    cout << "Enter bus no: ";
    cin >> buses[empty_seat_count].bus_number;
    cout << "\nEnter Driver's name: ";
    cin >> buses[empty_seat_count].driver_name;
    cout << "\nArrival time: ";
    cin >> buses[empty_seat_count].arrival_time;
    cout << "\nDeparture: ";
    cin >> buses[empty_seat_count].departure_time;
    cout << "\nFrom: \t\t\t";
    cin >> buses[empty_seat_count].from_location;
    cout << "\nTo: \t\t\t";
    cin >> buses[empty_seat_count].to_location;
    buses[empty_seat_count].initializeSeats();  // Initialize seats for the new bus
    empty_seat_count++;  // Increment bus count
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
        for(bus_index=0; bus_index<=empty_seat_count; bus_index++) {
            if(strcmp(buses[bus_index].bus_number, bus_number_input)==0)
                break;
        }

    // If bus is found
    while(bus_index<=empty_seat_count) {
        cout << "\nSeat Number: ";
        cin >> seat_number;

        // Check if seat number is valid
        if(seat_number > 32) {
            cout << "\nThere are only 32 seats available in this bus.";
        } else {
            // Check if the seat is empty
            if(strcmp(buses[bus_index].seat[seat_number / 4][(seat_number % 4) - 1], "Empty") == 0) {
                cout << "Enter passenger's name: ";
                cin >> buses[bus_index].seat[seat_number / 4][(seat_number % 4) - 1];
                break;  // Exit the bus selection loop
            }

            cout << "The seat no. is already reserved. \n";
        }
    }

    if (bus_index > empty_seat_count) {
        cout<<"Enter correct bus number \n";
        goto top;
    }
}


// Function to initialize all seats as empty
void BusReservationSystem::initializeSeats()
{
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 4; j++) {
            strcpy(buses[empty_seat_count].seat[i][j], "Empty");
        }
    }
}

// Function to show bus details
void BusReservationSystem::showBusDetails()
{
    int bus_index;
    char bus_number_input[5];
    cout << "Enter bus no: ";
    cin >> bus_number_input;

    // Find the bus index based on bus number
    for(bus_index = 0; bus_index <= empty_seat_count; bus_index++) {
        if(strcmp(buses[bus_index].bus_number, bus_number_input) == 0)
            break;
    }

    // If bus is found
    while(bus_index <= empty_seat_count) {
        printLine('*');
        cout << "Bus no: \t" << buses[bus_index].bus_number
        << "\nDriver: \t" << buses[bus_index].driver_name
        << "\t\tArrival time: \t" << buses[bus_index].arrival_time
        << "\nDeparture time: "<< buses[bus_index].departure_time
        << "\nFrom: \t\t" << buses[bus_index].from_location
        << "\t\tTo: \t\t" << buses[bus_index].to_location << "\n";
        printLine('*');
        buses[0].displaySeatPosition(bus_index);  // Display seat positions
        int a = 1;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 4; j++) {
                a++;
                if(strcmp(buses[bus_index].seat[i][j], "Empty")!=0)
                    cout << "\nThe seat no "<< a-1 << " is reserved for " << buses[bus_index].seat[i][j] << ".";
            }
        }
        break;
    }

    if(bus_index>empty_seat_count)
        cout<<"Enter correct bus no: ";
}

// Function to display seat positions
void BusReservationSystem::displaySeatPosition(int bus_index)
{
    int seat_count = 0; empty_seat_count=0;
    for(int i = 0; i < 8; i++) {
        cout<<"\n";
        for(int j = 0; j < 4; j++) {
           seat_count++;
           if(strcmp(buses[bus_index].seat[i][j],"Empty")==0) {
               cout.width(5);
               cout.fill(' ');
               cout<<seat_count<<".";
               cout.width(10);
               cout.fill(' ');
               cout<<buses[1].seat[i][j];
               empty_seat_count++;
           } else {
                cout.width(5);
               cout.fill(' ');
               cout<<seat_count<<".";
               cout.width(10);
               cout.fill(' ');
               cout<<buses[bus_index].seat[i][j];

            }
        }
    }

    cout<<"\n\nThere are " << empty_seat_count << " seats empty in Bus No: " << buses[bus_index].bus_number;
}

// Function to show available buses
void BusReservationSystem::showAvailableBuses()
{
    for(int busIndex = 0; busIndex<empty_seat_count;busIndex++)
    {
        printLine('*');
        cout << "Bus number: \t" << buses[busIndex].bus_number
             << "\nDriver: \t" << buses[busIndex].driver_name
             << "\t\tArrival time: \t" << buses[busIndex].arrival_time
             << "\tDeparture Time: " << buses[busIndex].departure_time
             << "\nFrom: \t\t" << buses[busIndex].from_location
             << "\t\tTo: \t\t" << buses[busIndex].to_location << "\n";
        printLine('*');
        printLine('_');
    }
}

int main()
{
    system("cls");  // Clear the console screen
    int choice;
    while(true)
    {
        cout << "\n\n\n\n\n";
        cout << "\t\t\t1.Install\n\t\t\t"
             << "2.Reservation\n\t\t\t"
             << "3.Show\n\t\t\t"
             << "4.Buses Available. \n\t\t\t"
             <<"5.Exit";

        cout<<"\n\t\t\tEnter your choice:->  ";
        cin>>choice;
        switch(choice) {
            case 1:
                buses[empty_seat_count].installBus();  // Install a new bus
                break;
            case 2:
                buses[empty_seat_count].allotSeat();  // Reserve a seat
                break;
            case 3:
                buses[0].showBusDetails();  // Show details of a specific bus
                break;
            case 4:
                buses[0].showAvailableBuses();  // Show all available buses
                break;
            case 5:
                exit(0);  // Exit the program
            default:
                cout<<"Invalid option. Enter correct choice.";  // Invalid choice
        }
    }
    return 0;  // Exit with success
}
