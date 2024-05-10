#include <iostream>
#include <locale>


using namespace std;


int main()
{
    // Set the locale to handle Unicode characters
    setlocale(LC_ALL, "");
    // ”Locale Category All” set locale to environment/default. Sets locale to all aspects of program

     // Prompt user for input in Japanese
    wcout << L"Enter text in Japanese: ";


    // Read user input
    wstring userInput;
    wcin >> userInput;


    // Display the input
    wcout << userInput << L"\nThe above text is in Japanese.\n" << endl;
    return 0;
}
