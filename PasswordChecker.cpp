#include <iostream>
#include <string>

using namespace std;

// Function to check the strength of the password
bool isPasswordStrong(const string& password) {
    // Criteria flags
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;

    // Check for minimum length
    if (password.length() < 8) return false;

    // Special characters
    string specialChars = "!@#$%^&*()-+";

    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        else if (isupper(ch)) hasUpper = true;
        else if (isdigit(ch)) hasDigit = true;
        else if (specialChars.find(ch) != string::npos) hasSpecial = true;

        // If all criteria are met, no need to check further
        if (hasLower && hasUpper && hasDigit && hasSpecial) return true;
    }

    // Return false if any of the criteria is not met
    return false;
}

int main() {
    string password;

    cout << "Enter your password: ";
    cin >> password;

    if (isPasswordStrong(password)) {
        cout << "Password is strong." << endl;
    } else {
        cout << "Password is weak. Make sure it includes at least 8 characters, lowercase and uppercase letters, numbers, and special characters." << endl;
    }

    return 0;
}

