#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Using sorting
bool areAnagramsSorted(string str1, string str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    return str1 == str2;
}

// Using character frequency count
bool areAnagramsCount(const string& str1, const string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }
    
    unordered_map<char, int> charCount;
    
    for (char c : str1) {
        charCount[c]++;
    }
    
    for (char c : str2) {
        charCount[c]--;
        if (charCount[c] < 0) {
            return false;
        }
    }
    
    return true;
}

void testAnagrams() {
    string str1 = "listen";
    string str2 = "silent";
    
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;
    cout << "Are anagrams (sorted): " << (areAnagramsSorted(str1, str2) ? "Yes" : "No") << endl;
    cout << "Are anagrams (count): " << (areAnagramsCount(str1, str2) ? "Yes" : "No") << endl;
}

int main() {
    cout << "Additional Problem 3: String Anagrams" << endl;
    testAnagrams();
    cout << endl;
}