#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


using namespace std;


int main() {
    srand(time(0)); // Seed for random number generation


    int choice;
    bool quit = false;


    while (!quit) {
        cout << "Welcome to the Loop Showcase Program!" << endl;
        cout << "Main Menu:" << endl;
        cout << "1. Counting Game" << endl;
        cout << "2. Word Reversal" << endl;
        cout << "3. Random Message" << endl;
        cout << "4. Guessing Game" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {
        case 1: {
            int n;
            cout << "Enter a number: ";
            cin >> n;
            cout << "Counting from 1 to " << n << ":" << endl;
            for (int i = 1; i <= n; ++i) {
                cout << i << endl;
            }
            break;
        }
        case 2: {
            string word;
            cout << "Enter a word: ";
            cin >> word;
            cout << "Word reversal:" << endl;
            int length = word.length();
            while (length >= 0) {
                cout << word.substr(length, 1) << endl;
                length--;
            }
            break;
        }
        case 3: {
            int randomNum = rand() % 5 + 1;
            cout << "Printing a random message " << randomNum << " times:" << endl;
            for (int i = 0; i < randomNum; ++i) {
                cout << "Hello, World!" << endl;
            }
            break;
        }
        case 4: {
            int target = rand() % 10 + 1;
            int guess;
            bool guessed = false;
            cout << "Welcome to the Guessing Game!" << endl;
            while (!guessed) {
                cout << "Guess a number between 1 and 10: ";
                cin >> guess;
                if (guess == target) {
                    cout << "Congratulations! You guessed the correct number." << endl;
                    guessed = true;
                }
                else if (guess < target) {
                    cout << "Too low! Try again." << endl;
                }
                else {
                    cout << "Too high! Try again." << endl;
                }
            }
            break;
        }
        case 5: {
            quit = true;
            break;
        }
        default: {
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
        }
    }


    cout << "Thank you for using the Loop Showcase Program! Goodbye." << endl;


    return 0;
}
