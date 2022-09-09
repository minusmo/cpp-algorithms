#include <iostream>
#define MAXUSERS 100
#define MAXEDGES 5000
using namespace std;

int getMinBacon(int adjMat[MAXUSERS+1][MAXUSERS+1], int N, int M);
int main() {
    int N,M,a,b;
    int adjMat[MAXUSERS+1][MAXUSERS+1];
    cin >> N >> M;
    for (int i=0;i<N+1;i++)
    {
        for (int j=0;j<N+1;j++)
        {
            adjMat[i][j] = 100;
        }
    }
    for (int i=0;i<M;i++)
    {
        cin >> a >> b;
        adjMat[a][b] = 1;
        adjMat[b][a] = 1;
    }
    int minBaconIdx = getMinBacon(adjMat,N,M);
    cout << minBaconIdx << endl;
    return 0;
}

int getMinBacon(int adjMat[MAXUSERS+1][MAXUSERS+1], int N, int M)
{
    for (int k=1;k<N+1;k++)
    {
        for (int i=1;i<N+1;i++)
        {   
            for (int j=1;j<N+1;j++)
            {   
                int cost = adjMat[i][k] + adjMat[k][j];
                if (adjMat[i][j] > cost)
                {
                    adjMat[i][j] = cost;
                }
            }   
        }
    }

    int minBaconIdx = 0;
    int minBaconCost = 99 * 100;
    for (int i=1;i<N+1;i++)
    {
        int baconCost = 0;
        for (int j=1;j<N+1;j++)
        {
            baconCost += adjMat[i][j];
        }
        if (baconCost < minBaconCost)
        {
            minBaconCost = baconCost;
            minBaconIdx = i;
        }
    }
    return minBaconIdx;
}