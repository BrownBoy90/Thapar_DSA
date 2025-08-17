#include <iostream>
#include <string>
using namespace std;

bool canSplitString(const string& s) {
    int n = s.length();
    // Try all possible splits into three non-empty parts
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            string part1 = s.substr(0, i);
            string part2 = s.substr(i, j - i);
            string part3 = s.substr(j);
            // Check if one part is a substring of both others
            if ((part2.find(part1) != string::npos && part3.find(part1) != string::npos) ||
                (part1.find(part2) != string::npos && part3.find(part2) != string::npos) ||
                (part1.find(part3) != string::npos && part2.find(part3) != string::npos)) {
                return true;
            }
        }
    }
    return false;
}

void testStringSplit() {
    string s = "abcabc";
    cout << "String: " << s << endl;
    cout << "Can split: " << (canSplitString(s) ? "Yes" : "No") << endl;
}

int main() {
    testStringSplit();
    // You can add more test cases here if needed
    return 0;
}