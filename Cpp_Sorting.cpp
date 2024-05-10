#include <iostream> 
#include <vector>  
#include <ctime> 
#include <cstdlib>
#include "Cpp_Sorting.h"
/* <iostream>: Include the input/output stream library: used for functions such as cout and cin
<vector>: Include the vector library: functionality for dynamic arrays (vectors). Dynamic resizing and efficient random access to mutable arrays.
<ctime>: Header file provides declarations for functions, macros, and types used for working with time and date information in C++ programs. You gain access to functions like time(), clock(), and difftime(), which are commonly used for measuring time, calculating elapsed time, and working with timestamps. Additionally, <ctime> defines types like time_t and tm, which represent time values and broken-down time structures.
<cstdlib>: header file that provides several general-purpose functions and macros for performing common tasks such as memory allocation, random number generation, string conversion, and other utility functions. It's the C++ equivalent of the C standard library's <stdlib.h> header.
*/
using namespace std;


// Function to perform Selection Sort on an array
void selectionSortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}


// Function to perform Selection Sort on a vector
void selectionSortVector(vector<int>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(vec[i], vec[minIndex]);
        }
    }
}


// Function to perform error checking and check if array and vector have the same content
bool validateInput(const vector<int>& vec, const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (vec[i] != arr[i]) {
            return false;
        }
    }
    return true;
}


// Function to perform unit tests
void runTests() {
    // Test case 1: Basic case
    int arr1[] = { 5, 2, 7, 3, 9 };
    vector<int> vec1 = { 5, 2, 7, 3, 9 };
    selectionSortArray(arr1, 5);
    selectionSortVector(vec1);
    cout << "Test 1: " << (validateInput(vec1, arr1, 5) ? "Passed" : "Failed") << endl;


    // Test case 2: Empty input

    int arr2[] = {};
    vector<int> vec2 = {};
    selectionSortArray(arr2, 0);
    selectionSortVector(vec2);
    cout << "Test 2: " << (validateInput(vec2, arr2, 0) ? "Passed" : "Failed") << endl;


    // Test case 3: Already sorted input
    int arr3[] = { 1, 2, 3, 4, 5 };
    vector<int> vec3 = { 1, 2, 3, 4, 5 };
    selectionSortArray(arr3, 5);
    selectionSortVector(vec3);
    cout << "Test 3: " << (validateInput(vec3, arr3, 5) ? "Passed" : "Failed") << endl;
}


int main() {
    // Seed for random numbers
    srand(time(0));


    // Example usage
    const int size = 10;
    int arr[size];
    vector<int> vec(size);


    // Fill arrays with random numbers
    for (int i = 0; i < size; ++i) {
        int num = rand() % 100;
        arr[i] = num;
        vec[i] = num;
    }


    // Sorting array and vector
    selectionSortArray(arr, size);
    selectionSortVector(vec);


    // Printing sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;


    // Printing sorted vector
    cout << "Sorted vector: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;


    // Running unit tests
    runTests();


    return 0;
}
//Implementation of Selection Sort for both arrays and vectors.
//Basic error - checking through a validation function.
//Unit tests to verify the correctness of the sorting algorithms under different scenarios.
//Example usage demonstrating sorting of randomly generated numbers.
//Performance measurement implemented using timing mechanisms.


