#include <iostream>
#include <string>
#include <limits>
#include <random>

using namespace std;

/* Draws a line of specified length using a given character. */
void drawLine(int n, char c) {
    // for (int i = 0; i < n; i++)
    //     cout << c;
    // cout << endl;
    cout << string(n, c) << endl;
}

/* Displays the rules of the game to the player. */
void displayRules() {
    system("cls");
    cout << "\n\n";
    drawLine(80, '-');
    cout << "\nRule 1 -> Choose any number from 1 to 10.";
    cout << "\nRule 2 -> If you win you will get 10 times the money you bet.";
    cout << "\nRule 3 -> If you bet on wrong number you will lose your betting amount.";
    cout << "\n\n";
    drawLine(80, '-');

}

/* Prompts the user for input and validates it within a specified range. */
int getValidInput(int min, int max, const string& prompt) {
    int input;
    while (true) {
        cout << prompt;
        if (cin >> input && input >= min && input <= max) {
            return input;
        }
        cout << "Invalid input. Please enter your input between " << min << " and " << max << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    string player_name;
    int amount, betting_amount, guess, dice;
    char choice;

    // srand(time(0));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> rn(1, 10);

    drawLine(60, '_');
    cout << "\n\n\n\t\tCASINO GAME\t\t\n\n\n\n";
    drawLine(60, '_');

    cout << "\n\nEnter name:";
    getline(cin, player_name);

    amount = getValidInput(1, numeric_limits<int>::max(), "\n\nEnter deposit amount to play game: $");

    do {
        system("cls");
        displayRules();
        cout << "\n\nYour current balance is: $" << amount << endl;

        betting_amount = getValidInput(1, amount, player_name + ", please enter money to bet: $");

        // dice = rand() % 10 + 1;

        dice = rn(gen);
        // cout << "\nThe winning number is: " << dice << endl; // For testing purposes

        guess = getValidInput(1, 10, "Guess your number between 1 to 10: ");

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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (choice == 'y' || choice == 'Y');

    cout <<"\n\n\n";
    drawLine(70, '=');
    cout << "\n\nThanks for playing game. Your balance amount is $" << amount << "\n\n\n";
    drawLine(70, '=');

    return 0;
}