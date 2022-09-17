#include <iostream>
#include <string>
#include <list>
#define MAXT 100
#define MAXP 100000
#define MAXN 100000
#define MAXINTS 100
#define MAXPN 700000
using namespace std;

int main()
{
    int T,n;
    string p, integers;
    list<int> ints;
    for (int i=0;i<T;i++)
    {
        getline(cin, p);
        cin >> n;
        getline(cin, integers);
        for (char eachChar : integers)
        {
            if (eachChar == '[' || eachChar == ']' || eachChar == ',')
            {
                continue;
            }
            else
            {
                
            }
        }
    }
    return 0;
}