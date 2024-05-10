#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;


// Function prototypes
void countingGame();
void wordReversal();
void randomMessage();
void guessingGame();


int main() {
    srand(time(0)); // Seed for random number generation


    int choice;
    do {
        cout << "Main Menu:" << endl;
        cout << "1. Counting Game" << endl;
        cout << "2. Word Reversal" << endl;
        cout << "3. Random Message" << endl;
        cout << "4. Guessing Game" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
        case 1:
            countingGame();
            break;
        case 2:
            wordReversal();
            break;
        case 3:
            randomMessage();
            break;
        case 4:
            guessingGame();
            break;
        case 5:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);


    return 0;
}


void countingGame() {
    int count;
    cout << "Enter a number: ";
    cin >> count;


    if (count <= 0) { //error handling for invalid input
        cout << "Invalid input. Please enter a positive number." << endl;
        return;
    }


    cout << "Counting from 1 to " << count << ":" << endl;
    for (int i = 1; i <= count; ++i) {
        cout << i << " ";
    }
    cout << endl;
}


void wordReversal() {
    string word;
    cout << "Enter a word: ";
    cin >> word;


    int length = word.length();
    for (int i = length - 1; i >= 0; --i) {
        cout << word[i];
    }
    cout << endl;
}


void randomMessage() {
    int numMessages = rand() % 10 + 1; // Random number of messages (1 to 10)
    for (int i = 0; i < numMessages; ++i) {
        cout << "This is a random message." << endl;
    }
}


void guessingGame() {
    int randomNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 0;
    cout << "Guess the number between 1 and 100." << endl;


    // do while loop is used to ensure that the game conditions are met 
    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;


        if (guess < randomNumber)
            cout << "Too low. Try again." << endl;
        else if (guess > randomNumber)
            cout << "Too high. Try again." << endl;
        else
            cout << "Congratulations! You guessed the number " << randomNumber << " in " << attempts << " attempts." << endl;
    } while (guess != randomNumber);
}