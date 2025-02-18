#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

#define MAX_ROOMS 100 // Maximum number of rooms

// Class to store customer details
class Customer {
public:
    char name[100];          // Customer's name
    char address[100];       // Customer's address
    char phone[12];          // Customer's phone number
    char from_date[20];      // Check-in date
    char to_date[20];        // Check-out date
    float payment_advance;    // Advance payment made by the customer
    int booking_id;          // Unique booking ID
};

// Class to represent a Room
class Room {
public:
    char type;               // Room type (e.g., Single, Double)
    char comfort_type;       // Comfort type (e.g., Standard, Luxury)
    char ac;                 // AC type (A for AC, N for Non-AC)
    int room_number;         // Unique room number
    int rent;                // Daily rent for the room
    int status;              // Room status (0 for available, 1 for booked)

    class Customer customer;       // Customer details associated with the room

	// Method to add a room
	class Room addRoom(int roomNumber);
	// Method to search for a room
	void searchRoom(int roomNumber);
	// Method to delete a room
	void deleteRoom(int roomNumber);
	// Method to display room details
	void displayRoom(const Room &room);
};

// Global variables
int room_count = 0; // Counter for the number of rooms
Room rooms[MAX_ROOMS]; // Array to store rooms

// Method to add a room
Room Room::addRoom(int roomNumber) {
    Room newRoom; // Create a new room object
    newRoom.room_number = roomNumber; // Set the room number

    // Get room details from the user
    cout << "\nType AC/Non-AC (A/N): ";
    cin >> newRoom.ac;
    cout << "\nType Room (S- Single, D- Double): ";
    cin >> newRoom.type;
    cout << "\nType Comfort (S/N): ";
    cin >> newRoom.comfort_type;
    cout << "\nDaily Rent: ";
    cin >> newRoom.rent;
    newRoom.status = 0; // Set status to available

    cout << "\nRoom Added Successfully!";
    getch(); // Wait for user input
    return newRoom; // Return the new room object
}

// Method to search for a room
void Room::searchRoom(int roomNumber) {
	int i;
	int found = 0; // Flag to check if room is found
	for (i = 0; i < room_count; i++) {
		if (rooms[i].room_number == roomNumber) {
			found = 1;  // Room found
			break;
		}
	}
	if (found == 1) {
		cout << "Room Details" << endl;
		if (rooms[i].status == 1) {
			cout << "\nRoom is Reserved" << endl;
		} else {
			cout << "\nRoom is available" << endl;
		}
		displayRoom(rooms[i]);  // Display room details
		getch();
	} else {
		cout << "\nRoom not found" << endl;
	}
	getch();  // Wait for user input
}


// Method to display room details
void Room::displayRoom(const Room &room) {
	cout << "Room Number: " << room.room_number << endl;
	cout << "Type AC/Non-AC (A/N) : " << room.ac << endl;
	cout << "Type Room (S- Single, D- Double) : " << room.type << endl;
	cout << "Type Comfort (S/N) : " << room.comfort_type << endl;
	cout << "Rent: " << room.rent << endl;
}

// Method to delete a room
void Room::deleteRoom(int roomNumber) {
    int i;
    int found = 0; // Flag to check if room is found
    for (i = 0; i < room_count; i++) {
        if (rooms[i].room_number == roomNumber) {
            found = 1; // Room found
            break;
        }
    }
    if (found) {
        rooms[i].status = 0; // Set status to available
        cout << "Room is deleted successfully" << endl;
    } else {
        cout << "Room not found" << endl;
    }
    getch(); // Wait for user input
}

// Class to manage hotel operations
class HotelManagement : protected Room {
public:
    void checkIn(); // Method to check in a customer
    void getAvailableRooms(); // Method to get available rooms
    void searchCustomer(const char* customerName); // Method to search for a customer
    void checkOut(int roomNumber); // Method to check out a customer
    void guestSummaryReport(); // Method to generate a guest summary report
};

// Method to generate a guest summary report
void HotelManagement::guestSummaryReport() {
    if (room_count == 0) {
        cout << "\nNo Guest in Hotel" << endl;
        getch();
        return;
    }
    for (int i = 0; i < room_count; i++) {
        if (rooms[i].status == 1) { // If room is booked
            cout << "\nCustomer Name: " << rooms[i].customer.name << endl;
            cout << "Room Number: " << rooms[i].room_number << endl;
            cout << "Address (only city): " << rooms[i].customer.address << endl;
            cout << "Phone: " << rooms[i].customer.phone << endl;
            cout << "\n---------------------------------------" << endl;
        }
    }
    getch(); // Wait for user input
}

// Method to check in a customer
void HotelManagement::checkIn() {
	int i;
	int roomNumber;
	cout << "Enter Room number : ";
	cin >> roomNumber;

	int found = 0; // Flag to check if room is found
	for (i = 0; i < room_count; i++) {
		if (rooms[i].room_number == roomNumber) {
			found = 1;  // Room found
			break;
		}
	}
	if (found == 1) {
		if (rooms[i].status == 1) {
			cout << "\nRoom is already Booked" << endl;
			getch();
			return;
		}
		// Get customer details
		cout << "Enter booking id: ";
		cin >> rooms[i].customer.booking_id;
		cout << "Enter Customer Name (First Name): ";
		cin >> rooms[i].customer.name;
		cout << "Address (only city): ";
		cin >> rooms[i].customer.address;
		cout << "Phone: ";
		cin >> rooms[i].customer.phone;
		cout << "From Date: ";
		cin >> rooms[i].customer.from_date;
		cout << "To Date: ";
		cin >> rooms[i].customer.to_date;
		cout << "Payment Advance: ";
		cin >> rooms[i].customer.payment_advance;

		rooms[i].status = 1;  // Set room status to booked
		cout << "Customer Checked-in Successfully" << endl;
	} else {
		cout << "Room not found" << endl;
	}
	getch();  // Wait for user input
}

// Method to get available rooms
void HotelManagement::getAvailableRooms() {
	int found = 0;  // Flag to check if any room is available
	for (int i = 0; i < room_count; i++) {
		if (rooms[i].status == 0) {  // If room is available
			displayRoom(rooms[i]);  // Display room details
			found = 1;  // Set found flag
		}
	}
	if (found == 0) {
		cout << "All rooms are reserved" << endl;
	}
	getch();  // Wait for user input
}

// Method to search for a customer
void HotelManagement::searchCustomer(const char* customerName) {
	int found = 0;
	for (int i = 0; i < room_count; i++) {
		if (rooms[i].status == 1 && stricmp(rooms[i].customer.name, customerName) == 0) {
			cout << "Customer Name: " << rooms[i].customer.name << endl;
			cout << "Room Number: " << rooms[i].room_number << endl;
			// cout << "Address (only city): " << rooms[i].cust.address << endl;
			// cout << "Phone: " << rooms[i].cust.phone << endl;
			cout << "\n Press enter for next record" << endl;
			found = 1;  // Set found flag
			getch(); // Wait for user input
			// break;
		}
	}
	if (found == 0) {
		cout << "Person not found" << endl;
	}
	getch(); // Wait for user input
}

// Method to check out a customer
void HotelManagement::checkOut(int roomNumber) {
	int i;
	int found = 0;  // Flag to check if room is found
	float billAmount = 0;  // Total bill amount
	for (i = 0; i < room_count; i++) {
		if (rooms[i].status == 1 && rooms[i].room_number == roomNumber) {
			found = 1;  // Room found
			break;
		}
	}
	if (found == 1) {
		int days;
		cout << "\nEnter number of days: ";
		cin >> days;
		billAmount = rooms[i].rent * days;  // Calculate total bill

		// Display checkout details
		cout << "################# Checkout Details #################" << endl;
		cout << "Customer Name: " << rooms[i].customer.name << endl;
		cout << "Room Number: " << rooms[i].room_number << endl;
		cout << "Address (only city): " << rooms[i].customer.address << endl;
		cout << "Phone: " << rooms[i].customer.phone << endl;
		cout << "Total Amount: " << billAmount << "$" << endl;
		cout << "Advance Paid: " << rooms[i].customer.payment_advance << "$" << endl;
		cout << "Total Payable: " << billAmount - rooms[i].customer.payment_advance << "$ only" << endl;

		rooms[i].status = 0;  // Set room status to available
	}
	getch();  // Wait for user input
}

// Function to manage room operations
void manageRooms() {
    Room room; // Room object
    int option, roomNumber;
    bool isRoomExists;

    do {
        system("cls");
        cout << "### Manage Rooms ###" << endl;
        cout << "1. Add Room" << endl;
        cout << "2. Search Room" << endl;
        cout << "3. Delete Room" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter Option: ";
        cin >> option;

        switch (option) {
            case 1: // Add Room
                cout << "Enter Room Number: ";
                cin >> roomNumber;

                // Check if room number already exists
                isRoomExists = false;
                for (int i = 0; i < room_count; i++) {
                    if (rooms[i].room_number == roomNumber) {
                        isRoomExists = true; // Room number exists
                        break;
                    }
                }
                if (isRoomExists) {
                    cout << "\nRoom number is present. Please enter a unique number." << endl;
                	isRoomExists = false;
                    getch(); // Wait for user input
                } else {
                    rooms[room_count] = room.addRoom(roomNumber); // Add new room
                    room_count++; // Increment room count
                }
                break;

            case 2: // Search Room
                cout << "Enter Room Number: ";
                cin >> roomNumber;
                room.searchRoom(roomNumber); // Search for the room
                break;

            case 3: // Delete Room
                cout << "Enter Room Number: ";
                cin >> roomNumber;
                room.deleteRoom(roomNumber); // Delete the room
                break;

            case 4: // Back to Main Menu
                break;

            default:
                cout << "Invalid Option" << endl;
                getch(); // Wait for user input
                break;
        }
    } while (option != 4); // Loop until user chooses to go back
}

// Main function
int main() {
    HotelManagement hotelManager; // Hotel management object
    int option;
    char customerName[100]; // Customer name for searching

    do {
        system("cls");
        cout << "### Hotel Management System ###" << endl;
        cout << "1. Manage/Add Rooms" << endl;
        cout << "2. Check-In Room" << endl;
        cout << "3. Available Rooms" << endl;
        cout << "4. Search Customer" << endl;
        cout << "5. Check-Out Room" << endl;
        cout << "6. Guest Summary Report" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter Option: ";
        cin >> option;

        switch (option) {
            case 1: // Manage/Add Rooms
                manageRooms();
                break;

            case 2: // Check-In Room
                if (room_count == 0) {
                    cout << "Rooms data is not available. Please add rooms first." << endl;
                    getch(); // Wait for user input
                	break;
                } else {
                    hotelManager.checkIn(); // Check in a customer
                }
                break;

            case 3: // Available Rooms
                if (room_count == 0) {
                    cout << "Rooms data is not available. Please add rooms first." << endl;
                    getch(); // Wait for user input
                	break;
                } else {
                    hotelManager.getAvailableRooms(); // Get available rooms
                }
                break;

            case 4: // Search Customer
                if (room_count == 0) {
                    cout << "Rooms data is not available. Please add rooms first." << endl;
                    getch(); // Wait for user input
                	break;
                } else {
                    cout << "Enter Customer Name: ";
                    cin >> customerName;
                    hotelManager.searchCustomer(customerName); // Search for a customer
                }
                break;

            case 5: // Check-Out Room
                if (room_count == 0) {
                    cout << "Rooms data is not available. Please add rooms first." << endl;
                    getch(); // Wait for user input
                } else {
                    int roomNumber;
                    cout << "Enter Room Number: ";
                    cin >> roomNumber;
                    hotelManager.checkOut(roomNumber); // Check out a customer
                }
                break;

            case 6: // Guest Summary Report
                hotelManager.guestSummaryReport(); // Generate guest summary report
                break;

            case 7: // Exit
                cout << "\nTHANK YOU FOR USING THIS SOFTWARE" << endl;
                break;

            default:
                cout << "\nPlease enter a correct option" << endl;
                getch(); // Wait for user input
                break;
        }
    } while (option != 7); // Loop until user chooses to exit

    getch(); // Wait for user input before closing
    return 0; // End of program
}
