#include <iostream>
#include <stdexcept> // Required for exception handling


using namespace std;


int main() {
    const float pi = 3.14159;
    float userInput;


    while (true) {
        //used while(true) for an infinite loop. Alternative solutions include do-while(true) and for(;;)
        cout << "Enter a number to divide pi by (enter '420' to exit): ";
        if (!(cin >> userInput)) {
            // Input validation: check if input is a float
            cout << "Error: Please enter a valid number.\n";
            cin.clear();
            // Clear error flag. Resets error state of input stream to let operations proceed normally by discarding invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            //discards invalid input  
            continue;
            // Skip to next iteration
        }
        if (userInput == 0) {
            // Handling division by zero
            cout << "Error: Cannot divide by zero.\n";
            continue; // Skip to next iteration
        }
        if (userInput == 420) {
            // Throwing an uncaught exception for '420'
            throw runtime_error("Naughty Number Error: You entered 420!");
            //throw signals exceptional conditions that occur, runtime_error indicates that when the error occured (during runtime)
        }
        try {
            // Division operation wrapped in a try-catch block
            float result = pi / userInput;
            cout << "Result of pi / " << userInput << " = " << result << endl;
        }
        catch (const exception& e) {
            // Catching and handling division-related exceptions
            cout << "Error: " << e.what() << endl;
            //try-catch allows the function to handle exepctions that might occur during the code execution
            //the try block can catch and handle execptions during the division process
            // provides clear error feedback, handle errors, and execute without the program crashing
            // (const excepton& e) ensures that the caight exception object is passed by the reference (&) to avoid copying of the exception object.
            // const: exception cannot be modified within the catch block (helps with clarity and safety)
            // Alternative: (exception* e) I learned about pointers from the CodeLabs. This can provide the possibility of a null pointer, requiring additional checks before dereferencing the pointer

            //e.what() helps make the process of diagnosing errors easier, but can be removed and would still function
        }
    }


    return 0;
    // while I am aware that I am able to do a 'while' loop, 'if-else' loops, and/or 'switch,' for future preface, I wanted to give myself the chance to try new methods to expand my knowledge of how to deal with errors that can occur within outputs and inputs to achieve the specific criteria assigned to avoid as little errors as possible
