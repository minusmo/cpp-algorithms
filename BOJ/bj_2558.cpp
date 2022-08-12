#include <stdio.h>
#include <iostream>
#define MAXSIZE 100
using namespace std;

int main() {
    int mat1[MAXSIZE][MAXSIZE];
    int N, M, k;
    cin >> N >> M;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            cin >> mat1[i][j];
        }
    }
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            cin >> k;
            mat1[i][j] += k;
        }
    }
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<M;j++)
        {
            cout << mat1[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}