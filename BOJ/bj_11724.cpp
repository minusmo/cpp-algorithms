#include <iostream>
#include <queue>
#define MAXNODES 1000
#define MAXEDGES 500000
using namespace std;

int getConnectedComponents(int adjMat[MAXNODES+1][MAXNODES+1], int N, int M);
int main() {
    int N,M,a,b;
    int adjMat[MAXNODES+1][MAXNODES+1];
    cin >> N >> M;
    for (int i=0;i<N+1;i++)
    {
        for (int j=0;j<N+1;j++)
        {
            adjMat[i][j] = 0;
        }
    }
    for (int i=0;i<M;i++)
    {
        cin >> a >> b;
        adjMat[a][b] = 1;
        adjMat[b][a] = 1;
    }
    int connectedComponents = getConnectedComponents(adjMat,N,M);
    cout << connectedComponents << endl;
    return 0;
}

int getConnectedComponents(int adjMat[MAXNODES+1][MAXNODES+1], int N, int M)
{
    bool isVisited[MAXNODES+1];
    for (int i=1;i<N+1;i++)
    {
        isVisited[i] = false;
    }

    for (int j=1;j<N+1;j++)
    {
        if (isVisited[j] == false)
        {
            queue<int> q;
            q.push(j);
            while (!q.empty())
            {
                auto node = q.front();
                q.pop();
                isVisited[node] = true;
                for (int i = 1; i < N+1; i++)
                {
                    if (adjMat[node][i] == 1 && isVisited[i] == false)
                    {
                        q.push(i);
                    }
                }
                
            }
            
        }
    }
}