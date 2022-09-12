#include <iostream>
#include <math.h>
#define MAX 15
using namespace std;

void visitZ(int N,int stR, int stC, const int R, const int C, int* visits);
int main() 
{
    int N,R,C;
    int visits = 0;
    cin >> N >> R >> C;
    visitZ(N,0,0,R,C,&visits);
    return 0;
}

void visitZ(int N,int stR, int stC, const int R, const int C, int* visits)
{
    if (N == 1)
    {
        for (int r = stR;r < stR + 2; r++)
        {
            for (int c = stC; c < stC + 2; c++)
            {
                if (r == R && c == C)
                {
                    printf("%d\n", *visits);
                }
                *visits += 1;
            }
        }
    }
    else
    {
        int power2 = (int)pow(2,N-1);
        visitZ(N-1, 0,0, R,C,visits);
        visitZ(N-1, 0, stC + power2, R,C,visits);
        visitZ(N-1, stR + power2,0, R,C,visits);
        visitZ(N-1, stR + power2, stC + power2, R,C,visits);
    }
}