#include <stdio.h>
#include <cmath>
#define MAX 15
using namespace std;

void visitZ(int N,int stR, int stC, const int R, const int C, int* visits, int* isFound);
int main() 
{
    int N,R,C;
    int visits = 0;
    int isFound = 0;
    scanf("%d %d %d", &N, &R, &C);
    visitZ(N,(int)pow(2,N),(int)pow(2,N),R,C,&visits, &isFound);
    return 0;
}

void visitZ(int N,int stR, int stC, const int R, const int C, int* visits, int* isFound)
{
    if (*isFound == 1)
    {
        return;
    }
    else if (N > 0)
    {
        if (R >= stR || C >= stC)
        {
            *visits += N * N;
            return;
        }
        visitZ(N-1, stR/2, stC/2, R,C,visits, isFound);
        visitZ(N-1, stR/2, stC, R,C,visits, isFound);
        visitZ(N-1, stR,stC/2, R,C,visits, isFound);
        visitZ(N-1, stR, stC, R,C,visits, isFound);
    }
    else
    {
        if (stR-1 == R && stC-1 == C)
        {
            printf("%d\n", *visits);
            *isFound = 1;
            return;
        }
        *visits += 1;
    }
}