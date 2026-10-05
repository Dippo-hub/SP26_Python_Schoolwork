#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <string>

class Page {
    private:
        int wordCount;
        std::string text;

    public:
        Page(const std::string &text, int wordCount);
        Page(const std::string &text);

        int countWords();
        std::string getSentence();
        void setSentence(const std::string &text);
};

#endif