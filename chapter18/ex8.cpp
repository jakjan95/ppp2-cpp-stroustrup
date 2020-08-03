/* 
Programming: Principles and Practice Using C++
Chapter 18 Exercise 8:
    Rewrite all the functions in 18.7 to use the approach of making a backward copy of the string and then comparing: 
    for example, take "home", generate "emoh", and compare those two string to see that they are different, so home isn't a palindrome.
*/

#include <iostream>

int strLen(const char* str) {
    int result = 0;
    while (*str++) {
        result++;
    }
    return result;
}

//------------------------------------------------------------by using strings
bool isPalindromeStr(const std::string& s) {
    std::string ss(s.rbegin(), s.rend());
    return s == ss;
}

void testLoopStrPalindrome() {
    for (std::string s; std::cin >> s && s != "quit!";) {
        std::cout << s << " : ";
        if (!isPalindromeStr(s)) {
            std::cout << "not a ";
        }
        std::cout << "palindrome\n";
    }
}

//------------------------------------------------------------by using arrays
bool isPalindromeArrays(const char s[], int n) {
    int first = 0;
    int last = n - 1;

    char ss[n];

    while (first < n - 1 && last > 0) {
        ss[first] = s[last];
        first++;
        last--;
    }
    return *s == *ss;
}

std::istream& read_word(std::istream& is, char* buffer, int max) {
    is.width(max);
    is >> buffer;
    return is;
}

void testLoopArrayPalindrome() {
    constexpr int max = 128;
    for (char s[max]; read_word(std::cin, s, max);) {
        std::cout << s << " : ";
        if (!isPalindromeArrays(s, strLen(s))) {
            std::cout << " not a ";
        }
        std::cout << " palindrome\n";
    }
}

int main() {
    testLoopStrPalindrome();
    testLoopArrayPalindrome();
    return 0;
}
