#include <stdio.h>
#include <cmath>
#define MAX 15
using namespace std;

void visitZ(int N,int stR, int stC, const int R, const int C, long* visits, int* isFound);
int main() 
{
    int N,R,C;
    long visits = 0;
    int isFound = 0;
    scanf("%d %d %d", &N, &R, &C);
    int width = (int)pow(2,N)-1;
    visitZ(N,width,width,R,C,&visits, &isFound);
    return 0;
}

void visitZ(int N,int stR, int stC, const int R, const int C, long* visits, int* isFound)
{
    if (*isFound == 1)
    {
        return;
    }
    else if (N > 1)
    {
        if (R > stR || C > stC)
        {
            int width = (int)pow(2,N);
            *visits += width * width;
            return;
        }
        int halfWidth = (int)pow(2,N-1);
        visitZ(N-1, stR - halfWidth, stC - halfWidth, R,C,visits, isFound);
        visitZ(N-1, stR - halfWidth, stC, R,C,visits, isFound);
        visitZ(N-1, stR,stC - halfWidth, R,C,visits, isFound);
        visitZ(N-1, stR, stC, R,C,visits, isFound);
    }
    else
    {
        for (int r = stR-1; r < stR+1; r++)
        {
            for (int c = stC-1; c < stC+1; c++)
            {
                if (r == R && c == C)
                {
                    printf("%ld\n", *visits);
                    *isFound = 1;
                    return;
                }
                *visits += 1;
            }
            
        }
        
    }
}