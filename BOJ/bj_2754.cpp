#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string me;
    string you;
    getline(cin, me);
    getline(cin, you);
    if (me.size() >= you.size())
    {
        cout << "go" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}