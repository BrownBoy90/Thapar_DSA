#include <iostream>

// Helper function to calculate the length of a C-style string
int my_strlen(const char* s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

// (e) Convert an uppercase character to lowercase
char toLowercase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

// Helper function to check if a character is a vowel
bool isVowel(char c) {
    char lowerC = toLowercase(c);
    return lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u';
}

// (a) Concatenate two C-style strings
char* concatenateStrings(const char* str1, const char* str2) {
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    // Allocate memory for the new string (+1 for the null terminator)
    char* result = new char[len1 + len2 + 1];

    int i = 0;
    // Copy first string
    for (int j = 0; j < len1; j++, i++) {
        result[i] = str1[j];
    }
    // Copy second string
    for (int j = 0; j < len2; j++, i++) {
        result[i] = str2[j];
    }
    // Add the null terminator
    result[i] = '\0';
    return result;
}

// (b) Reverse a C-style string
char* reverseString(const char* s) {
    int len = my_strlen(s);
    // Allocate memory for the reversed string
    char* reversed = new char[len + 1];

    for (int i = 0; i < len; i++) {
        reversed[i] = s[len - 1 - i];
    }
    // Add the null terminator
    reversed[len] = '\0';
    return reversed;
}

// (c) Delete all vowels from a C-style string
char* deleteVowels(const char* s) {
    int len = my_strlen(s);
    // Allocate memory (max possible size is the original length)
    char* result = new char[len + 1];
    
    int resultIndex = 0;
    for (int i = 0; i < len; i++) {
        if (!isVowel(s[i])) {
            result[resultIndex] = s[i];
            resultIndex++;
        }
    }
    // Add the null terminator
    result[resultIndex] = '\0';
    return result;
}

int my_strcmp(const char* s1, const char* s2) {
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    // Return difference if one is a prefix of the other
    return s1[i] - s2[i];
}

// (d) Sort an array of C-style strings alphabetically using Bubble Sort
void sortStrings(char* strings[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (my_strcmp(strings[j], strings[j + 1]) > 0) {
                // Swap the pointers
                char* temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }
}

void testStringOperations() {
    // Test concatenation
    char s1[] = "Hello";
    char s2[] = "World";
    char* concatenated = concatenateStrings(s1, s2);
    std::cout << "Concatenation: " << concatenated << std::endl;
    delete[] concatenated;
    
    // Test reverse
    char s3[] = "Programming";
    char* reversed = reverseString(s3);
    std::cout << "Reverse: " << reversed << std::endl;
    delete[] reversed;
    
    // Test delete vowels
    char s4[] = "Beautiful";
    char* noVowels = deleteVowels(s4);
    std::cout << "Delete vowels: " << noVowels << std::endl;
    delete[] noVowels;
    
    // Test sort strings
    char str_a[] = "zebra";
    char str_b[] = "apple";
    char str_c[] = "banana";
    char* strings[] = {str_a, str_b, str_c};
    int n = sizeof(strings) / sizeof(strings[0]);
    
    sortStrings(strings, n);
    std::cout << "Sorted strings: ";
    for (int i = 0; i < n; i++) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;
    
    // Test lowercase
    std::cout << "Lowercase of 'Z': " << toLowercase('Z') << std::endl;
}

int main() {
    std::cout << "Problem 4: String Operations (Manual Implementation)" << std::endl;
    testStringOperations();
    std::cout << std::endl;
    return 0;
}