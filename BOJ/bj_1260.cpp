#include <iostream>
#include <queue>
#define MAXNODES 1000
#define MAXEDGES 10000
using namespace std;

void dfs(int adjacencyMatrix[MAXNODES+1][MAXNODES+1], bool isVisited[MAXNODES+1], int currentNode);
void bfs(int adjacencyMatrix[MAXNODES+1][MAXNODES+1], bool isVisited[MAXNODES+1], int currentNode);

int main() 
{
    int N,M,V;
    int depart, arrival;
    cin >> N >> M >> V;
    int adjacencyMatrix[MAXNODES+1][MAXNODES+1];
    for (int i=1;i<MAXNODES+1;i++)
    {
        for (int j=1;j<MAXNODES+1;j++)
        {
            adjacencyMatrix[i][j] = 0;
        }
    }
    for (int i=0;i<M;i++)
    {
        cin >> depart >> arrival;
        adjacencyMatrix[depart][arrival] = 1;
        adjacencyMatrix[arrival][depart] = 1;
    }

    bool isVisitedDfs[MAXNODES+1];
    bool isVisitedBfs[MAXNODES+1];
    for (int i=1;i<MAXNODES+1;i++)
    {
            isVisitedDfs[i] = false;
            isVisitedBfs[i] = false;
    }
    dfs(adjacencyMatrix, isVisitedDfs, V);
    printf("\n");

    bfs(adjacencyMatrix, isVisitedBfs, V);
    printf("\n");
    return 0;
}

void dfs(int adjacencyMatrix[MAXNODES+1][MAXNODES+1], bool isVisited[MAXNODES+1], int currentNode) {
    printf("%d ", currentNode);
    isVisited[currentNode] = true;
    for (int i=1;i<MAXNODES+1;i++)
    {
        if (adjacencyMatrix[currentNode][i] == 1 && isVisited[i] == false)
        {
            dfs(adjacencyMatrix, isVisited, i);
        }   
    }
}

void bfs(int adjacencyMatrix[MAXNODES+1][MAXNODES+1], bool isVisited[MAXNODES+1], int currentNode)
{
    queue<int> q;
    q.push(currentNode);
    while (!q.empty())
    {
        auto visitingNode = q.front();
        q.pop();
        if (isVisited[visitingNode] == false)
        {
            printf("%d ", visitingNode);
            isVisited[visitingNode] = true;
            for (int i=1;i<MAXNODES+1;i++)
            {
                if (adjacencyMatrix[visitingNode][i] == 1 && isVisited[i] == false)
                {
                    q.push(i); 
                }
            }
        } 
        
    }
    
}