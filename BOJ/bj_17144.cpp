#include <stdio.h>
#include <iostream>
#include <vector>
#define MAXSIZE 50
using namespace std;

void predictDust(const int R, const int C, const int T, int* dust, int map[MAXSIZE][MAXSIZE], int purifier);
void simulateDust(const int R, const int C, const int T, int map[MAXSIZE][MAXSIZE], int purifier);
void simulateAirPurifier(const int R, const int C, int map[MAXSIZE][MAXSIZE], int purifier);
void simulateUpside(const int R, const int C, int map[MAXSIZE][MAXSIZE], const int purifier);
void simulateDownside(const int R, const int C, int map[MAXSIZE][MAXSIZE], const int purifier);
void calculateDust(const int R, const int C, int map[MAXSIZE][MAXSIZE], int* totalDust);

int main() 
{
    int R,C,T,totalDust;
    int map[MAXSIZE][MAXSIZE];
    int purifier = -1;
    cin >> R >> C >> T;
    for (int i=0;i<R;i++)
    {
        for (int j=0;j<C;j++)
        {
            cin >> map[i][j];
            if (map[i][j] == -1 && purifier == -1)
            {   
                purifier = i;
            }
        }
    }
    predictDust(R,C,T,&totalDust,map, purifier);
    cout << totalDust << endl;
    return 0;
}

void predictDust(const int R, const int C, const int T, int* dust, int map[MAXSIZE][MAXSIZE], const int purifier)
{
    for (int t=0;t<T;t++)
    {
        simulateDust(R,C,T, map, purifier);
        simulateAirPurifier(R,C, map, purifier);
    }
    calculateDust(R,C, map, dust);
}

void simulateDust(const int R, const int C, const int T, int map[MAXSIZE][MAXSIZE], const int purifier)
{   int newR, newC;
    int variation[R][C];
    for (int r=0;r<R;r++) 
    {
        for (int c=0;c<C;c++)
        {
            variation[r][c] = 0;
        }
    }

    pair<int,int> moves[4] = {{0,-1}, {1,0}, {0,1}, {-1,0}};

    for (int r=0;r<R;r++)
    {
        for (int c=0;c<C;c++)
        {
            if (map[r][c] != 0 && map[r][c] != -1)
            {
                int distribution = map[r][c] / 5;
                int totalDistribution = 0;
                for (int m=0;m<4;m++) 
                {
                    newR = moves[m].first + r;
                    newC = moves[m].second + c;
                    if (newR >= R || newR < 0 || newC >= C || newC < 0) 
                    {
                        continue;
                    }
                    else if (map[newR][newC] == -1)
                    {
                        continue;
                    }
                    else 
                    {
                        variation[newR][newC] += distribution;
                        totalDistribution += distribution;
                    }
                }
                variation[r][c] -= totalDistribution;
            }
        }
    }
    for (int r=0;r<R;r++)
    {
        for (int c=0;c<C;c++)
        {
            map[r][c] += variation[r][c];
        }
    }
}

void simulateAirPurifier(const int R, const int C, int map[MAXSIZE][MAXSIZE], int purifier)
{
    simulateUpside(R,C,map,purifier);
    simulateDownside(R,C,map,purifier);
}

void simulateUpside(const int R, const int C, int map[MAXSIZE][MAXSIZE], int purifier)
{
    int currPosition = purifier - 1;
    while (currPosition > 0)
    {
        map[currPosition][0] = map[currPosition-1][0];
        currPosition -= 1;
    }
    while (currPosition < C-1)
    {
        map[0][currPosition] = map[0][currPosition+1];
        currPosition += 1;
    }
    currPosition = 0;
    while (currPosition < purifier)
    {
        map[currPosition][C-1] = map[currPosition+1][C-1];
        currPosition += 1;
    }
    currPosition = C-1;
    while (currPosition > 0)
    {
        if (currPosition == 1)
        {
            map[purifier][currPosition] = 0;
            break;
        }
        map[purifier][currPosition] = map[purifier][currPosition-1];
        currPosition -= 1;
    }
}

void simulateDownside(const int R, const int C, int map[MAXSIZE][MAXSIZE], int purifier)
{
    int currPosition = purifier + 2;
    while (currPosition < R-1)
    {
        map[currPosition][0] = map[currPosition+1][0];
        currPosition += 1;
    }
    currPosition = 0;
    while (currPosition < C-1)
    {
        map[R-1][currPosition] = map[R-1][currPosition+1];
        currPosition += 1;
    }
    currPosition = R-1;
    while (currPosition > purifier+1)
    {
        map[currPosition][C-1] = map[currPosition-1][C-1];
        currPosition -= 1;
    }
    currPosition = C-1;
    while (currPosition > 0)
    {
        if (currPosition == 1)
        {
            map[purifier+1][currPosition] = 0;
            break;
        }
        map[purifier+1][currPosition] = map[purifier+1][currPosition-1];
        currPosition -= 1;
    }
}

void calculateDust(const int R, const int C, int map[MAXSIZE][MAXSIZE], int* totalDust)
{   int sum = 0;
    for (int r=0;r<R;r++)
    {
        for (int c=0;c<C;c++)
        {
            if (map[r][c] != -1)
            {
                sum += map[r][c];
            }
        }
    }
    *totalDust = sum;
}