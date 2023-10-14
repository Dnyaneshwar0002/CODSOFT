
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int countWords(const string& text) {
    stringstream ss(text);
    string word;
    int count = 0;

    while (ss >> word) {
        count++;
    }

    return count;
}

int main() {
    cout << "Enter a sentence or phrase: ";
    string inputText;
    getline(cin, inputText);

    int wordCount = countWords(inputText);

    cout << "Number of words in the input: " << wordCount << endl;

    return 0;
}
