 
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to generate a random number within a specified range
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to play the number guessing game
void playGame(int minRange, int maxRange, int maxTries) {
    int targetNumber = generateRandomNumber(minRange, maxRange);
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I'm thinking of a number between " << minRange << " and " << maxRange << ".\n";
    cout << "You have " << maxTries << " attempts to guess the number.\n";

    while (attempts < maxTries) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < targetNumber) {
            cout << "Too low! Try again. (Attempts left: " << maxTries - attempts << ")\n";
        } else if (guess > targetNumber) {
            cout << "Too high! Try again. (Attempts left: " << maxTries - attempts << ")\n";
        } else {
cout << "Congratulations! You guessed the number (" << targetNumber << ") in " << attempts << " attempts.\n";
            return;
        }
    }

    cout << "Sorry, you've run out of attempts. The correct number was " << targetNumber << ".\n";
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int minRange = 1;
    int maxRange = 100;
    int maxTries = 7;
    int choice;

    do {
        cout << "Number Guessing Game Menu:\n";
        cout << "1. Easy (1-50, 5 attempts)\n";
        cout << "2. Medium (1-100, 7 attempts)\n";
        cout << "3. Hard (1-200, 10 attempts)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                maxRange = 50;
                maxTries = 5;
                playGame(minRange, maxRange, maxTries);
                break;
            case 2:
                maxRange = 100;
                maxTries = 7;
  playGame(minRange, maxRange, maxTries);
                break;
            case 3:
                maxRange = 200;
                maxTries = 10;
                playGame(minRange, maxRange, maxTries);
                break;
            case 4:
                cout << "Thank you for playing the Number Guessing Game!\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
