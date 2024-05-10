#include <iostream>
#include <vector>


using namespace std;


// Function to calculate Fibonacci sequence iteratively and store results in an array
void fibonacciIterative(int n, vector<int>& fibArray) {
    fibArray[0] = 0;
    fibArray[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }
}


// Function to calculate factorial recursively using pre-solved portions from an array
int factorial(int n, vector<int>& factArray) {
    if (n <= 1)
        return 1;
    if (factArray[n] != 0)
        return factArray[n];
    factArray[n] = n * factorial(n - 1, factArray);
    return factArray[n];
}


int main() {
    // Initialize array for storing Fibonacci and factorial results
    const int maxN = 10; // Maximum value for n
    vector<int> fibArray(maxN + 1, 0); // Initialize with 0s
    vector<int> factArray(maxN + 1, 0); // Initialize with 0s


    // Calculate Fibonacci sequence iteratively
    fibonacciIterative(maxN, fibArray);


    // Calculate factorial sequence using pre-solved portions
    for (int i = 0; i <= maxN; ++i) {
        factorial(i, factArray);
    }


    // Display Fibonacci sequence
    cout << "Fibonacci Sequence: ";
    for (int i = 0; i <= maxN; ++i) {
        cout << fibArray[i] << " ";
    }
    cout << endl;


    // Display Factorial sequence
    cout << "Factorial Sequence: ";
    for (int i = 0; i <= maxN; ++i) {
        cout << factArray[i] << " ";
    }
    cout << endl;


    return 0;
}
//fibonacciIterative function calculates the Fibonacci sequence iteratively and stores the results in the fibArray.
//factorial function calculates the factorial sequence recursively using pre - solved portions stored in the factArray.
//The main function initializes arrays for storing Fibonacci and factorial results.It then calculates both sequences and displays the results.
//Pointers are implicitly used for array manipulation, as vectors manage memory dynamically and efficiently.
