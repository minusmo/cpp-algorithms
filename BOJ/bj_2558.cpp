#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<char> newWord;
    string word;
    getline(cin,word);
    for (auto character = word.begin();character != word.end();character++)
    {
        if (isupper(*character))
        {
            newWord.push_back(tolower(*character));
        }
        else
        {
            newWord.push_back(toupper(*character));
        }
    }

    for (auto character = newWord.begin();character != newWord.end();character++)
    {
        printf("%c", *character);
    }
    printf("\n");
    return 0;
}