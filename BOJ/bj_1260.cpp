#include <iostream>
#include <queue>
#define MAXNODES 1000
#define MAXEDGES 10000
using namespace std;

void dfs(int adjacencyMatrix[MAXNODES+1][MAXNODES+1], bool isVisited[MAXNODES+1][MAXNODES+1], int currentNode);
void bfs(int adjacencyMatrix[MAXNODES+1][MAXNODES+1], bool isVisited[MAXNODES+1][MAXNODES+1], int currentNode);

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
    }

    bool isVisitedDfs[MAXNODES+1][MAXNODES+1];
    for (int i=1;i<MAXNODES+1;i++)
    {
        for (int j=1;j<MAXNODES+1;j++)
        {
            if (j == V)
            {
                isVisitedDfs[i][V] = true;
            }
            else
            {
                isVisitedDfs[i][j] = false;
            }
        }
    }
    dfs(adjacencyMatrix, isVisitedDfs, V);
    printf("\n");

    bool isVisitedBfs[MAXNODES+1][MAXNODES+1];
    for (int i=1;i<MAXNODES+1;i++)
    {
        for (int j=1;j<MAXNODES+1;j++)
        {
            if (j == V)
            {
                isVisitedBfs[i][V] = true;
            }
            else
            {
                isVisitedBfs[i][j] = false;
            }
        }
    }
    bfs(adjacencyMatrix, isVisitedBfs, V);
    printf("\n");
    return 0;
}

void dfs(int adjacencyMatrix[MAXNODES+1][MAXNODES+1], bool isVisited[MAXNODES+1][MAXNODES+1], int currentNode) {
    printf("%d ", currentNode);
    for (int i=1;i<MAXNODES+1;i++)
    {
        if (adjacencyMatrix[currentNode][i] == 1 && isVisited[currentNode][i] == false)
        {
            for (int j=1;j<MAXNODES+1;j++)
            {
                isVisited[j][i] = true;
            }
            dfs(adjacencyMatrix, isVisited, i);
        }   
    }
}

void bfs(int adjacencyMatrix[MAXNODES+1][MAXNODES+1], bool isVisited[MAXNODES+1][MAXNODES+1], int currentNode)
{
    queue<int> q;
    q.push(currentNode);
    while (!q.empty())
    {
        auto visitingNode = q.front();
        q.pop();
        printf("%d ", visitingNode);
        for (int j=1;j<MAXNODES+1;j++)
        {
            isVisited[j][visitingNode] = true;
        }
        for (int i=1;i<MAXNODES+1;i++)
        {
            if (adjacencyMatrix[visitingNode][i] == 1 && isVisited[visitingNode][i] == false)
            {
                q.push(i); 
            }
        }
    }
    
}