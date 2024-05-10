#include <iostream>   // Include the input/output stream library: used for functions such as cout and cin
#include <fstream>    // Include the file stream library: functionality for reading from and writing to files and includes classes such as ifstream and ofstream for writing to files
#include <sstream>    // Include the string stream library: functionality for manipulating strings as streams, includes classes like stringstream to read from and write to strings as streams
#include <vector>     // Include the vector library: functionality for dynamic arrays (vectors). Dynamic resizing and efficient random access to mutable arrays.
#include <string>     // Include the string library: representing and manipulating strings
/* The program includes necessary header files for input/output operations (iostream), file handling (fstream), string stream processing (sstream), vector operations (vector), and string manipulation (string). */
using namespace std;


// Function to parse data from file into vector of strings
// What is a vector? Dynamic array by the standard template library (STL) that allows people to create arrays to dynamically resize themselves (like a Turing machine but efficient and with automatic adjustments?). Makes it easier for the programmer to manage and manipulate data collections.
// & used for memory management through retrieving the memory address
vector<string> parseFile(const string& filename) {
    vector<string> data;
    // Create an empty vector of strings to store parsed data
    ifstream file(filename);
    // Open the input file stream with the given filename
    if (!file.is_open()) {
        // Check if the file is successfully opened
        cerr << "Error opening file " << filename << endl;
        // Display error message to standard error stream
        exit(1);
        // Exit the program with error status
    }


    string line;
    // Declare a string variable to store each line of the file
    while (getline(file, line)) {
        // Read each line of the file until the end
        stringstream ss(line);
        // Create a string stream object from the current line
        string word;
        // Declare a string variable to store each word
        while (getline(ss, word, ',')) {
            // Tokenize the line using ',' as delimiter
            data.push_back(word);
            // Add each word to the vector
        }
    }


    file.close();
    // Close the file stream
    return data;
    // Return the parsed data vector
}


// Function to print data to screen and output to file
void printAndOutput(const vector<string>& data) {
    ofstream outFile("A7-out.txt");
    // Open the output file stream
    if (!outFile.is_open()) {
        // Check if the output file is successfully opened
        cerr << "Error opening output file" << endl;
        // Display error message to standard error stream
        exit(1);
        // Exit the program with error status
    }


    for (const auto& word : data) {
        // Iterate through each word in the data vector. Learned about similar iteration through arrays from AP Computer Science A (Java). Use of const auto& learned from the lesson about error handling and try-catch blocks.
        cout << word << endl;
        // Print the word to the console
        outFile << word << endl;
        // Write the word to the output file
    }


    outFile.close();
    // Close the output file stream
}


int main() {
    // File reading and parsing
    vector<string> parsedData = parseFile("input.txt");  // Parse data from input file into vector
    // Print data to the screen and output to file
    printAndOutput(parsedData);
    // Call function to print and output parsed data


    return 0;
    // Return success status
}
//The parseFile function reads data from a file specified by the filename parameter, tokenizes each line using commas as delimiters, and stores the tokens in a vector of strings.
//Error handling is implemented to check if the file is successfully opened.If not, an error message is displayed, and the program exits with an error status.
//The printAndOutput function prints the data to the console and writes it to an output file named "A7-out.txt".
//Similar error handling is implemented for opening the output file.
//In the main function, data is parsed from the input file "input.txt" using the parseFile function, and then printed and outputted using the printAndOutput function.
