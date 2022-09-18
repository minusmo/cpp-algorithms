#include <iostream>
#include <string>
#include <list>
#define MAXT 100
#define MAXP 100000
#define MAXN 100000
#define MAXINTS 100
#define MAXPN 700000
using namespace std;


void callOperations(list<int>& ints, string p);
string stringfy(list<int> ints);
int main()
{
    int T,n;
    string p, integers, stringfiedList;
    list<int> ints;
    cin >> T;
    for (int i=0;i<T;i++)
    {
        cin >> p;
        cin >> n;
        cin >> integers;
        string number;
        if (n != 0)
        {
            for (int i=0;i<integers.size();i++)
            {
                char eachChar = integers[i];
                if (eachChar == '[')
                {
                    continue;
                }
                else if (eachChar == ',' || eachChar == ']')
                {
                    int intNumber = stoi(number);
                    ints.push_back(intNumber);
                    number.clear();
                    continue;
                }
                else
                {
                    number.push_back(eachChar);
                }
            }
        }
        callOperations(ints, p);
        stringfiedList = stringfy(ints);
        cout << stringfiedList << endl;
        ints.clear();
    }
    return 0;
}

void callOperations(list<int>& ints, string p)
{
    for (char op : p)
    {
        if (op == 'R')
        {
            ints.reverse();
        }
        else if (op == 'D')
        {
            if (ints.size() == 0)
            {
                return;
            }
            else
            {
                ints.pop_front();
            }
        }
    }
}

string stringfy(list<int> ints)
{
    if (ints.size() == 0)
    {
        return "error";
    }
    string stringfiedList;
    string stringfiedInt;
    int loops = 0;
    stringfiedList.push_back('[');
    for (int integer : ints)
    {
        loops += 1;
        stringfiedInt = to_string(integer);
        stringfiedList.append(stringfiedInt);
        if (loops == ints.size())
        {
            break;
        }
        else
        {
            stringfiedList.push_back(',');
        }
    }
    stringfiedList.push_back(']');
    return stringfiedList;
}