#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXSIZE 50
using namespace std;

void predictDust(const int R, const int C, const int T, int* dust, int map[MAXSIZE][MAXSIZE]);
void simulateDust();
void simulateAirPurifier();
int main() {
    int R,C,T,totalDust;
    int map[MAXSIZE][MAXSIZE];
    vector<pair<int, int> > dusts;
    cin >> R >> C >> T;
    for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
        {
            cin >> map[i][j];
        }
    }
    cout << totalDust << endl;
    return 0;
}