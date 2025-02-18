#include <fstream>
#include <iostream>
#include <unistd.h>
#include <conio.h>

using namespace std;

// Class to display the menu
class Menu {
public:
    void displayMenu();
};

// Function to display the food menu
void Menu::displayMenu() {
    cout << "\n\n\n\t\t\t\t\t ===============WELCOME TO FOOD ORDERING APP ================" << endl;
    cout << "\n\n\n\t\t\t\t\t =====================START YOUR ORDER=================" << endl;
    cout << "\n\n\n\t===============================\t\t\t============================\t\t\t\t=======================================" << endl;
    cout << "\t[1] Veggie Supreme (Rs.480)\t\t\t[2] Exotica Pizza(Rs.440)\t\t\t\t[3] Chicken Sizzler (Rs.580)\n"
         << "\t[4] Chrispy Chicken (Rs.520)\t\t\t[5] Spaghetti (Rs.350)\t\t\t\t\t[6] Country Feast (Rs.400)\n"
         << "\t[7] Tetrazzini (Rs.420)\t\t\t\t[8] Double Cheese (Rs.540)\t\t\t\t[9] Makizushi (Rs.548)\n"
         << "\t[10] Ham Burger (Rs.390)\t\t\t[11] Margherita Pizza(Rs.525)\t\t\t\t[12] Fish 'n' Chips (Rs.425)\n"
         << "\t[13] Fajitas (Rs.335)\t\t\t\t[14] Tempura (Rs.324)\t\t\t\t\t[15] Hot Dog (Rs.360)\n"
         << "\t===========================\t\t\t==============================\t\t\t\t===========================\n\n\n\t\t\t\t\t\t\t\t[16] EXIT" << endl;
}

// Class to handle the ordering process
class Order : public Menu {
protected:
    int quantity, item_choice, veggie_supreme, exotica, sizzler, crispy, spaghetti, feast, tetrazzini, h, makizushi, burger, margherita, chips, fajitas, tempura, hot_dog;
    int total_amount = 0;  // Total amount for the order
    string continue_order_response, update_order_response;

public:
    void processOrder() {
        ofstream order_file;
        order_file.open("order.txt");  // Open file to save the order
        if (!order_file) {
            cout << "File not found" << endl;
            exit(-1);
        }
        a:
            b:
                c:
                    cout << "\n\n\tENTER YOUR ORDER (one at a time): ";
                    cin >> item_choice;

                    cout << "\n\n\tDO YOU WANT TO UPDATE YOUR ORDER (Y/N): ";
                    cin >> update_order_response;

                    if(update_order_response == "Y" || update_order_response == "y") {
                        goto b;  // Go back to the start of the loop to update the order
                    } else if(update_order_response == "N" || update_order_response == "n") {
                        // Process the order based on the item chosen
                        switch (item_choice) {
                            case 1:
                                cout << "\n\n\tHOW MANY PIZZA DO YOU WANT: ";
                                cin >> quantity;

                                veggie_supreme = 480;
                                total_amount = total_amount + (veggie_supreme * quantity);  // Update total amount
                                order_file << "YOU ORDER Veggie Supreme: 480" << endl;
                                order_file << "NUMBER OF PIZZA IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Veggie Supreme " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 2:
                                cout << "\n\n\tHOW MANY PIZZA DO YOU WANT: ";
                                cin >> quantity;

                                exotica = 440;
                                total_amount = total_amount + (exotica * quantity);  // Update total amount
                                order_file << "YOU ORDER Exotica Pizza: 440" << endl;
                                order_file << "NUMBER OF PIZZA IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Exotica Pizza " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 3:
                                cout << "\n\n\tHOW MANY Chicken Sizzler DO YOU WANT: ";
                                cin >> quantity;

                                sizzler = 580;
                                total_amount = total_amount + (sizzler * quantity);  // Update total amount
                                order_file << "YOU ORDER Chicken Sizzler: 580" << endl;
                                order_file << "NUMBER OF Chicken Sizzler IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Chicken Sizzler " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 4:
                                cout << "\n\n\tHOW MANY Chrispy Chicken DO YOU WANT: ";
                                cin >> quantity;

                                crispy = 520;
                                total_amount = total_amount + (crispy * quantity);  // Update total amount
                                order_file << "YOU ORDER Chrispy Chicken: 520" << endl;
                                order_file << "NUMBER OF Chrispy Chicken IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Chrispy Chicken " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 5:
                                cout << "\n\n\tHOW MANY Spaghetti DO YOU WANT: ";
                                cin >> quantity;

                                spaghetti = 350;
                                total_amount = total_amount + (spaghetti * quantity);  // Update total amount
                                order_file << "YOU ORDER Spaghetti: 350" << endl;
                                order_file << "NUMBER OF Spaghetti IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Spaghetti " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 6:
                                cout << "\n\n\tHOW MANY Country Feast DO YOU WANT: ";
                                cin >> quantity;

                                feast = 400;
                                total_amount = total_amount + (feast * quantity);  // Update total amount
                                order_file << "YOU ORDER Country Feast: 400" << endl;
                                order_file << "NUMBER OF Country Feast IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Country Feast " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 7:
                                cout << "\n\n\tHOW MANY Tetrazzini DO YOU WANT: ";
                                cin >> quantity;

                                tetrazzini = 420;
                                total_amount = total_amount + (tetrazzini * quantity);  // Update total amount
                                order_file << "YOU ORDER Tetrazzini: 420" << endl;
                                order_file << "NUMBER OF Tetrazzini IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Tetrazzini " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 9:
                                cout << "\n\n\tHOW MANY Makizushi DO YOU WANT: ";
                                cin >> quantity;

                                makizushi = 548;
                                total_amount = total_amount + (makizushi * quantity);  // Update total amount
                                order_file << "YOU ORDER Makizushi: 548" << endl;
                                order_file << "NUMBER OF Makizushi IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Makizushi " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 10:
                                cout << "\n\n\tHOW MANY Ham Burger DO YOU WANT: ";
                                cin >> quantity;

                                burger = 390;
                                total_amount = total_amount + (burger * quantity);  // Update total amount
                                order_file << "YOU ORDER Ham Burger: 390" << endl;
                                order_file << "NUMBER OF Ham Burger IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Ham Burger " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 11:
                                cout << "\n\n\tHOW MANY Margherita Pizza DO YOU WANT: ";
                                cin >> quantity;

                                margherita = 525;
                                total_amount = total_amount + (margherita * quantity);  // Update total amount
                                order_file << "YOU ORDER Margherita Pizza: 525" << endl;
                                order_file << "NUMBER OF Margherita Pizza IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Margherita Pizza " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 12:
                                cout << "\n\n\tHOW MANY Fish 'n' Chips DO YOU WANT: ";
                                cin >> quantity;

                                chips = 425;
                                total_amount = total_amount + (chips * quantity);  // Update total amount
                                order_file << "YOU ORDER Fish 'n' Chips: 425" << endl;
                                order_file << "NUMBER OF Fish 'n' Chips IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Fish 'n' Chips " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 13:
                                cout << "\n\n\tHOW MANY Fajitas DO YOU WANT: ";
                                cin >> quantity;

                                fajitas = 335;
                                total_amount = total_amount + (fajitas * quantity);  // Update total amount
                                order_file << "YOU ORDER Fajitas: 335" << endl;
                                order_file << "NUMBER OF Fajitas IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Fajitas " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 14:
                                cout << "\n\n\tHOW MANY Tempura DO YOU WANT: ";
                                cin >> quantity;

                                tempura = 324;
                                total_amount = total_amount + (tempura * quantity);  // Update total amount
                                order_file << "YOU ORDER Tempura: 324" << endl;
                                order_file << "NUMBER OF Tempura IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Tempura " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 15:
                                cout << "\n\n\tHOW MANY Hot Dog DO YOU WANT: ";
                                cin >> quantity;

                                hot_dog = 360;
                                total_amount = total_amount + (hot_dog * quantity);  // Update total amount
                                order_file << "YOU ORDER Hot Dog: 360" << endl;
                                order_file << "NUMBER OF Hot Dog IS: " << quantity << endl;
                                order_file << "\n\n\tYOU ORDERED Hot Dog " << endl << "\tYOUR ORDER IS SUCCESSFULLY SAVED" << endl;
                                break;

                            case 16:
                                exit(0);  // Exit the loop if the user does not want to order more
                                break;

                            default:
                                cout << "\n\n\t\t\t\t\t YOU ENTERED WORONG ORDER KEY!!!" << endl;
                            goto c;
                            break;
                        }
                        cout << "\n\n\tDO YOU WANT TO ORDER MORE (Y/N): ";
                        cin >> continue_order_response;
                        if (continue_order_response == "yes" || continue_order_response == "Yes") {
                            goto a;
                        } else {
                            cout << "\n\n\t\t\t\t\tTHANK YOU FOR YOUR ORDER :) GENERATING BILL" << endl;  // Exit the loop if the user does not want to order more
                        }
                        // for (int a = 0; a < 0; a++) {
                        //     sleep(500);
                        //     cout << "...";
                        // }
                    } else {
                        cout << "\n\n\tINVALID INPUT" << endl;
                        goto c;
                    }

        // Display the final bill
        cout << "\n\t\t\t\t\t\t========================================================="<<endl;
        cout << "\n\t\t\t\t\t\t|                FOOD ORDERING SYSTEM                    |"<<endl;
        cout << "\n\t\t\t\t\t\t========================================================="<<endl;

        cout << endl;
        cout << endl;

        cout << "\t\t\t\t\t\t Bill No: CP51               Order: NB1353" << endl;
        cout << endl;
        cout << endl;
        cout << "\t\t\t\t\t\t Cashier: Harry" << endl;
        cout << endl;
        cout << "\n\t\t\t\t\t\t YOUR TOTAL BILL IS Rs." << total_amount << endl;
        order_file << "\t\t\t\t\t\t\t";
        order_file << "\t\t\t\t\t\t\tTOTAL BILL IS Rs." << total_amount;
        cout << "\n\t\t\t\t\t\t\t\t==================================================" << endl;

        order_file.close();  // Close the order file
    }

    void showOrder() {
        displayMenu();  // Show the menu
        processOrder();  // Process the order
    }
};

// Class to handle user login and access control
class UserAccess : public Menu, public Order {
public:
    void login() {
        long int userID;
        d:
            cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t---------------------";
            cout << "\n\t\t\t\t\t\t\tEnter Login Id = " << endl;
            cin >> userID;
            cout<<"\t\t\t\t\t\t\t---------------------";

            if (userID != 1234) {
                cout << "\nDon't try to be smart.....Enter correct id" << endl;
                goto d;
            } else {
                z:
                    string password = "pass";
                    string entered_password = "";
                    char c;
                    cout << "\n\n\n\n\t\t\t\t\tPassword = ";
                    p:
                        c = getch();  // Get character input without displaying it
                        cout << "*";  // Display asterisk for each character
                        if (c != 13) {
                            entered_password += c;  // Append character to password
                            goto p;
                        }

                    if (entered_password == password) {
                        cout << "\n\n\t\t\t\t\t Access Granted. Welcome to our system." << endl;
                        system("pause");
                        system("cls");
                        showOrder();  // Show the order menu
                    }
                    else {
                        cout << "\n Access Denied. Wrong Password. Try again." << endl;
                        goto z;  // Go back to the start of the loop to enter the password again
                    }
            }
    }
};

// Main function to run the application
int main() {
    UserAccess user_access; // Create an instance of UserAccess
    user_access.login(); // Start the login process
    getch(); // Wait for user input before closing
    return 0;
}
