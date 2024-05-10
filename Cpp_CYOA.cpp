#include <iostream>
#include <string>
#include <vector>


using namespace std;


// Forward declaration of Decision class
class Decision;


// State Machine Class
class StateMachine {
private:
    vector<string> inventory;
    bool hasKey = false;
    bool hasMap = false;
    bool hasTreasure = false;


public:
    // Function to add item to inventory
    void addItem(const string& item) {
        inventory.push_back(item);
    }


    // Functions to manipulate flags
    void acquireKey() {
        hasKey = true;
    }


    void acquireMap() {
        hasMap = true;
    }


    void acquireTreasure() {
        hasTreasure = true;
    }


    // Function to check if player has a certain item
    bool hasItem(const string& item) const {
        for (const string& i : inventory) {
            if (i == item) {
                return true;
            }
        }
        return false;
    }


    // Function to check if player has key
    bool hasTheKey() const {
        return hasKey;
    }


    // Function to check if player has map
    bool hasTheMap() const {
        return hasMap;
    }


    // Function to check if player has treasure
    bool hasTheTreasure() const {
        return hasTreasure;
    }
};


// Decision Class
class Decision {
private:
    string description;
    vector<Decision*> options;


public:
    // Constructor
    Decision(const string& desc) : description(desc) {}


    // Function to add an option
    void addOption(Decision* option) {
        options.push_back(option);
    }


    // Function to display description and options
    void display() const {
        cout << description << endl;
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i]->description << endl;
        }
    }


    // Function to handle player choice
    Decision* chooseOption() const {
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice >= 1 && choice <= static_cast<int>(options.size())) {
            return options[choice - 1];
        }
        else {
            cout << "Invalid choice. Please choose again." << endl;
            return chooseOption();
        }
    }
};


int main() {
    // Initialize state machine
    StateMachine gameState;


    // Create decision instances
    Decision start("You find yourself at the entrance of a dark cave. What do you do?");
    Decision explore("You explore deeper into the cave. Suddenly, you see two paths diverging. Which one do you take?");
    Decision pathLeft("You choose the left path and find a locked door. Do you have a key?");
    Decision pathRight("You choose the right path and find a chest. Do you open it?");
    Decision endLockedDoor("The door opens, and you find a hidden treasure inside. Congratulations! You win!");
    Decision endChest("You open the chest and find it empty. You lose!");


    // Link decisions together
    start.addOption(&explore);
    explore.addOption(&pathLeft);
    explore.addOption(&pathRight);
    pathLeft.addOption(&endLockedDoor);
    pathRight.addOption(&endChest);


    // Game loop
    Decision* currentDecision = &start;
    while (currentDecision != nullptr) {
        currentDecision->display();
        currentDecision = currentDecision->chooseOption();
    }


    return 0;
}