#include <iostream>
#include <string>
#include <cctype>
#include <iomanip> 

using namespace std;

double extractNumeric(const string& input) {
    bool hasDecimalPoint = false; 
    bool hasDigit = false;         
    double result = 0.0;         
    int sign = 1;               
    int i = 0;

    while (i < input.length() && input[i] == ' ') {
        i++;
    }

    if (i < input.length() && (input[i] == '+' || input[i] == '-')) {
        if (input[i] == '-') {
            sign = -1; 
        }
        i++;
    }

    // Process the digits before the decimal point
    while (i < input.length() && isdigit(input[i])) {
        hasDigit = true;
        result = result * 10 + (input[i] - '0');
        i++;
    }

    // Handle the decimal point
    if (i < input.length() && input[i] == '.') {
        hasDecimalPoint = true;
        i++; 
        double decimalPlace = 0.1; // To handle fractional digits
        while (i < input.length() && isdigit(input[i])) {
            result += (input[i] - '0') * decimalPlace;
            decimalPlace /= 10;
            i++;
        }
    }

    // If no digits are found, it's invalid
    if (!hasDigit) {
        return -999999.99;
    }

    // Check for any extra invalid characters
    while (i < input.length()) {
        if (!isspace(input[i])) {
            return -999999.99; // Invalid input
        }
        i++;
    }

    // Return the result considering the sign
    return result * sign;
}

int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        getline(cin, input);

        if (input == "END") {
            break;
        }
        double number = extractNumeric(input);

        // Display the result
        if (number == -999999.99) {
            cout << "The input is invalid." << endl;
        } else {
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        }
    }

    return 0;
}
