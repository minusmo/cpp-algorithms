#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAXSIZE 1000
#define MAXCOST 100000
using namespace std;

void getMinCost(const int start, const int end, vector<pair<int,int> > adjacencyList[MAXSIZE+1], int costs[MAXSIZE+1]);
int main() {
    int N, M;
    vector<pair<int,int> > adjacencyList[MAXSIZE+1];
    int start, end;
    int source, destination, cost;
    int costs[MAXSIZE+1];
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i=1;i<N+1;i++) {
        vector<pair<int, int> > newVector;
        adjacencyList[i] = newVector;
        costs[i] = MAXSIZE * MAXCOST;
    }
    for (int i=1; i<M+1;i++) {
        bool inserted = false;
        scanf("%d %d %d", &source, &destination, &cost);
        for (auto adjacencyVertex = adjacencyList[source].begin(); adjacencyVertex != adjacencyList[source].end(); adjacencyVertex++) {
            if ((*adjacencyVertex).second == destination && (*adjacencyVertex).first > cost) {
                (*adjacencyVertex).first = cost;
                inserted = true;
                break;
            }
        }
        if (inserted == false){
            adjacencyList[source].push_back({cost, destination});
        }
    }
    scanf("%d %d", &start, &end);

    getMinCost(start, end, adjacencyList, costs);
    cout << costs[end] << endl;
    return 0;
}

void getMinCost(const int start, const int end, vector<pair<int,int> > adjacencyList[MAXSIZE+1], int costs[MAXSIZE+1]) {
    costs[start] = 0;
    priority_queue<pair<int,int> > pq;
    pair<int, int> vertex;
    pq.push({0,start});
    while (pq.empty() == false)
    {
        vertex = pq.top();
        pq.pop();
        for (auto adjacentPair = adjacencyList[vertex.second].begin(); adjacentPair != adjacencyList[vertex.second].end(); adjacentPair++) {
            int newCost = -1 * vertex.first + (*adjacentPair).first;
            int adjacentVertex = (*adjacentPair).second;
            if (costs[adjacentVertex] > newCost) {
                costs[adjacentVertex] = newCost;
                pq.push({-1 * newCost, adjacentVertex});
            }
        }
    }
}