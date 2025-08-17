#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// (a) Concatenate strings
string concatenateStrings(const string& str1, const string& str2) {
    return str1 + str2;
}

// (b) Reverse a string
string reverseString(const string& s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

// (c) Delete all vowels
string deleteVowels(const string& s) {
    string result;
    string vowels = "aeiouAEIOU";
    
    for (char c : s) {
        if (vowels.find(c) == string::npos) {
            result += c;
        }
    }
    return result;
}

// (d) Sort strings alphabetically
void sortStrings(vector<string>& strings) {
    sort(strings.begin(), strings.end());
}

// (e) Convert uppercase to lowercase
char toLowercase(char c) {
    return tolower(c);
}

void testStringOperations() {
    // Test concatenation
    cout << "Concatenation: " << concatenateStrings("Hello", "World") << endl;
    
    // Test reverse
    cout << "Reverse: " << reverseString("Programming") << endl;
    
    // Test delete vowels
    cout << "Delete vowels: " << deleteVowels("Beautiful") << endl;
    
    // Test sort strings
    vector<string> strings = {"zebra", "apple", "banana"};
    sortStrings(strings);
    cout << "Sorted strings: ";
    for (const string& s : strings) cout << s << " ";
    cout << endl;
    
    // Test lowercase
    cout << "Lowercase of 'Z': " << toLowercase('Z') << endl;
}

int main() {
    cout << "Problem 4: String Operations" << endl;
    testStringOperations();
    cout << endl;
}