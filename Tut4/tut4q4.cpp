#include <iostream>
using namespace std;

void firstNonRepeatingCharacter(string str) {
    queue<char> q;
    int charCount[26] = {0}; // For lowercase letters a-z
    
    cout << "Processing string: " << str << endl;
    cout << "Output: ";
    
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        
        // Skip spaces
        if (ch == ' ') continue;
        
        // Add character to queue and increment frequency
        q.push(ch);
        charCount[ch - 'a']++;
        
        // Remove characters from front that have frequency > 1
        while (!q.empty() && charCount[q.front() - 'a'] > 1) {
            q.pop();
        }
        
        // Print first non-repeating character or -1
        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string str = "aabc";
    firstNonRepeatingCharacter(str);
    return 0;
}
