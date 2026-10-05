#include <page.h>

Page::Page(const std::string &text, int wordCount) {
    this->wordCount = wordCount;
    this->text = text;
}
Page::Page(const std::string &text) {
    this->text = text;
    this->wordCount = countWords();
}

int Page::countWords() {
    int num=0;
    for(short i=0; i<text.size(); i++) {
        if(text.at(i) != ' ') {
            num++;
        }
    }
    return num;
}
std::string Page::getSentence() {
    return text;
}
void Page::setSentence(const std::string &text) {
    this->text = text;
}