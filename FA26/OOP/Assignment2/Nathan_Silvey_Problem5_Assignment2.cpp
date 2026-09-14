#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

void processString(const std::string s) {
    char c;
    short counts[26] = {0};
    for (short i = 0; i<s.length(); i++) {
        c = s.at(i);
        if (std::isupper(c)) 
            c = tolower(c);
        short ascii_index = c - 97;
        counts[ascii_index] += 1;
    }
    for(short j = 0; j<26; j++) {
        char displayChar = 'a' + j;
        if(counts[j]>0)
            std::cout << displayChar << ":" << counts[j] << std::endl;
    }
}

int main() {
    std::string st;
    std::cout << "Enter string: ";
    getline(std::cin, st);

    processString(st);
}