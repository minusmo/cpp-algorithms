#include <iostream>
#include <vector>
#define MAXNODES 1000
#define MAXEDGES 500000
using namespace std;

int getConnectedComponents(vector<int> adjlist[MAXNODES+1], int N, int M);
void dfs(vector<int> adjlist[MAXNODES+1], bool isVisited[MAXNODES+1], int currentNode);
int main() {
    int N,M,a,b;
    cin >> N >> M;
    vector<int> adjlist[MAXNODES+1];
    for (int i=0;i<M;i++)
    {
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    int connectedComponents = getConnectedComponents(adjlist,N,M);
    cout << connectedComponents << endl;
    return 0;
}

int getConnectedComponents(vector<int> adjlist[MAXNODES+1], int N, int M)
{
    bool isVisited[MAXNODES+1];
    int connectedComponents = 0;
    for (int i=1;i<N+1;i++)
    {
        isVisited[i] = false;
    }

    for (int j=1;j<N+1;j++)
    {
        if (isVisited[j] == false)
        {
            dfs(adjlist, isVisited, j);
            connectedComponents += 1;
        }
    }
    return connectedComponents;
}

void dfs(vector<int> adjlist[MAXNODES+1], bool isVisited[MAXNODES+1], int currentNode)
{
    isVisited[currentNode] = true;
    for (auto adjnode : adjlist[currentNode])
    {
        if (isVisited[adjnode] == false)
        {
            dfs(adjlist, isVisited, adjnode);
        }
    }
}