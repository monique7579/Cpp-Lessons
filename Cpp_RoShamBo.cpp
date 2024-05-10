#include <iostream>
#include <cstdlib> //for rand() and srand()
#include <ctime> //for time()


using namespace std;


int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));


    // Get user's choice
    cout << "Enter your choice (Rock, Paper, Scissors, Lizard, Spock): ";
    string userChoice;
    cin >> userChoice;


    // Convert user's choice to lowercase for case-insensitive comparison to allow the user can input both “rock” and “Rock” without there being any errors
    for (char& c : userChoice) {
        c = tolower(c);
    }


    // Randomly generate computer's choice
    string choices[] = { "rock", "paper", "scissors", "lizard", "spock" };
    int computerChoiceIndex = rand() % 5;
    // generates random index between 0-4 (because the remainder will get a value within that range) and used it to select a choice from the array of choices
    string computerChoice = choices[computerChoiceIndex];
    // computer's choice is stored into computerChoice


    // Output computer's choice
    cout << "Computer chose: " << computerChoice << endl;


    // Implement conditionals to decide and print the winner
    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    }
    else if (
        (userChoice == "rock" && (computerChoice == "scissors" || computerChoice == "lizard")) ||
        (userChoice == "paper" && (computerChoice == "rock" || computerChoice == "spock")) ||
        (userChoice == "scissors" && (computerChoice == "paper" || computerChoice == "lizard")) ||
        (userChoice == "lizard" && (computerChoice == "spock" || computerChoice == "paper")) ||
        (userChoice == "spock" && (computerChoice == "scissors" || computerChoice == "rock"))
        ) {
        cout << "You win!" << endl;
    }
    else {
        cout << "Computer wins!" << endl;
    }


    return 0;
}
