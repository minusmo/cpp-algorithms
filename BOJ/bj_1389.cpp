#include <iostream>
#define MAXUSERS 100
#define MAXEDGES 5000
using namespace std;

int main() {
    int N,M,a,b;
    int adjMat[MAXUSERS+1][MAXUSERS+1];
    bool hasFriend[MAXUSERS+1];
    cin >> N >> M;
    for (int i=0;i<M;i++)
    {
        cin >> a >> b;
        hasFriend[a] = true;
        hasFriend[b] = true;
        adjMat[a][b] = 1;
        adjMat[b][a] = 1;
    }
    int minBacon = getMinBacon(adjMat,N,M);
    cout << minBacon << endl;
    return 0;
}

int getMinBacon(bool hasFriend[MAXUSERS+1], int adjMat[MAXUSERS+1][MAXUSERS+1], int N, int M)
{
    int sp[MAXUSERS+1][MAXUSERS+1];
    for (int k=1;k<MAXUSERS+1;k++)
    {
        if (hasFriend[k] == true)
        {
            for (int i=1;i<MAXUSERS+1;i++)
            {
                if (hasFriend[i] == true)
                {
                    
                }
            }
        }
    }
}