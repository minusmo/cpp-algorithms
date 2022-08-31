#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAXSIZE 50
#define MAXPOS 2500
using namespace std;

int calculateWorms(const int M, const int N, const int K, vector<pair<int, int> > spots,int map[MAXSIZE][MAXSIZE]);
void bfs(int visited[MAXSIZE][MAXSIZE], const int r, const int c, const int M, const int N, int map[MAXSIZE][MAXSIZE]);
int main() 
{
    int T;
    for (int t=0;t<T;t++)
    {
        int M, N, K, r, c;
        cin >> T;
        cin >> M >> N >> K;
        int map[MAXSIZE][MAXSIZE];
        vector<pair<int,int> > spots;
        for (int i=0;i<K;i++)
        {
            cin >> c >> r;
            map[r][c] = 1;
            spots.push_back({r,c});
        }
        int worms = calculateWorms(M,N,K,spots,map);
        cout << worms << endl;
    }
    return 0;
}

int calculateWorms(const int M, const int N, const int K, vector<pair<int, int> > spots, int map[MAXSIZE][MAXSIZE])
{
    int r, c;
    int worms = 0;
    int visited[MAXSIZE][MAXSIZE];
    for (r=0;r<M;r++)
    {
        for (c=0;c<N;c++)
        {
            visited[r][c] = 0;
        }
    }
    for (auto spot : spots)
    {
        r = spot.first;
        c = spot.second;
        if (visited[r][c] == 1)
        {
            continue;
        }
        else {
            bfs(visited,r,c,M,N,map);
            worms += 1;
        }
    }
    return worms;
}

void bfs(int visited[MAXSIZE][MAXSIZE], const int r, const int c, const int M, const int N, int map[MAXSIZE][MAXSIZE])
{
    vector<pair<int,int> > moves = {{0,-1},{1,0},{0,1},{-1,0}};
    queue<pair<int,int> > q;
    q.push({r,c});
    while (!q.empty())
    {
        auto spot = q.front();
        q.pop();
        if (visited[spot.first][spot.second] == 1)
        {
            continue;
        }
        else
        {
            visited[r][c] = 1;
            for (auto move : moves)
            {
                int newr = spot.first + move.first;
                int newc = spot.second + move.second;
                if (newr >= M || newc >= N || newr < 0 || newc < 0)
                {
                    continue;
                }
                else if (map[newr][newc] == 1 && visited[newr][newc] == 0)
                {
                    visited[newr][newc] = 1;
                    q.push({newr,newc});
                }
            }
            
        }
    }
    
}