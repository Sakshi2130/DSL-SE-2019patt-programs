//A palindrome is a string of character that‘s the same forward and backward. Typically, 

//punctuation, capitalization, and spaces are ignored. For example, “Poor Dan is in a droop” 

//is a palindrome, as can be seen by examining the characters “poor danisina droop” and 

//observing that they are the same forward and backward. One way to check for a 

//palindrome is to reverse the characters in the string and then compare with them the 

//original-in a palindrome, the sequence will be identical. Write C++ program with 

//functionsa) To print original string followed by reversed string using stack

//b) To check whether given string is palindrome or not

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

// Function to print original and reversed string using stack
void printReversedString(const string& str) {
    stack<char> s;
    
    // Pushing each character into the stack
    for (char ch : str) {
        s.push(ch);
    }
    
    // Printing the original string
    cout << "Original String: " << str << endl;
    
    // Reversing the string using stack and printing the reversed string
    cout << "Reversed String: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

// Function to check whether the string is a palindrome or not
bool isPalindrome(const string& str) {
    int left = 0, right = str.length() - 1;
    
    // Checking the string ignoring spaces and case
    while (left < right) {
        if (!isalnum(str[left])) {
            left++;
        } else if (!isalnum(str[right])) {
            right--;
        } else if (tolower(str[left]) != tolower(str[right])) {
            return false;  // Not a palindrome
        } else {
            left++;
            right--;
        }
    }
    return true;  // It's a palindrome
}

int main() {
    string input;
    
    cout << "Enter a string: ";
    getline(cin, input);
    
    // Call to print the original and reversed string
    printReversedString(input);
    
    // Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "The string is a palindrome." << endl;
    } else {
        cout << "The string is NOT a palindrome." << endl;
    }
    
    return 0;
}
