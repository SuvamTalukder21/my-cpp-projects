#include <iostream>

using namespace std;

void drawLine(int n, char c) {
    for (int i = 0; i < n; i++)
        cout << c;
    cout << endl;
}

void rules() {
    system("cls");
    cout << "\n\n";
    drawLine(80, '-');
    cout << "\nRule 1 -> Choose any number from 1 to 10.";
    cout << "\nRule 2 -> If you win you will get 10 times the money you bet.";
    cout << "\nRule 3 -> If you bet on wrong number you will lose your betting amount.";
    cout << "\n\n";
    drawLine(80, '-');

}

int main() {
    string player_name;
    int amount, betting_amount, guess;
    char choice;

    srand(time(0));

    drawLine(60, '_');
    cout << "\n\n\n\t\tCASINO GAME\t\t\n\n\n\n";
    drawLine(60, '_');

    cout << "\n\nEnter name:";
    getline(cin, player_name);

    cout << "\n\nEnter deposit amount to play game: $";
    cin >> amount;

    do {
        system("cls");
        rules();
        cout << "\n\nYour current balance is: $" << amount << endl;

        do {
            cout << player_name << ", please enter money to bet: $";
            cin >> betting_amount;
            if (betting_amount > amount) {
                cout << "Your betting more than your current balance\n";
                cout << "\nRe-Enter data\n";
            }
        } while (betting_amount > amount);

        int dice = rand() % 10 + 1;
        // cout << "\nThe winning number is: " << dice << endl; // For testing purposes

        do {
            cout << "Guess your number between 1 to 10:";
            cin >> guess;
            if (guess <= 0 || guess > 10) {
                cout << "Please check the number!! It should be between 1 to 10...\n";
                cout << "\nRe-Enter data\n";
            }
        } while (guess <= 0 || guess > 10);

        if (dice == guess) {
            cout << "\n\nGood Luck!!! You won $" << betting_amount * 10;
            amount += betting_amount * 10;
        } else {
            cout << "\n\nBad Luck!!! You lost $" << betting_amount << endl;
            amount -= betting_amount;
        }

        cout << "\nThe winning number was: " << dice << endl;
        cout << endl << player_name << ", you have $" << amount << endl;

        if (amount == 0) {
            cout << "You've no money to play.";
            break;
        }

        cout << "\n\n---> Do you want to play again (y/n)?";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout <<"\n\n\n";
    drawLine(70, '=');
    cout << "\n\nThanks for playing game. Your balance amount is $" << amount << "\n\n\n";
    drawLine(70, '=');
    return 0;
}