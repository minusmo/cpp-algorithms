#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAXSIZE 50
#define MAXPOS 2500
using namespace std;

int calculateWorms(const int M, const int N, const int K,int map[MAXSIZE][MAXSIZE]);
void bfs(int visited[MAXSIZE][MAXSIZE], const int r, const int c, const int M, const int N, int map[MAXSIZE][MAXSIZE]);
int main() 
{
    int T;
    scanf("%d", &T);
    int answers[T];
    for (int t=0;t<T;t++)
    {
        int map[MAXSIZE][MAXSIZE];
        int M, N, K, r, c;
        scanf("%d %d %d", &M, &N,&K);
        for (r=0;r<N;r++)
        {
            for (c=0;c<M;c++)
            {
                map[r][c] = 0;
            }
        }
        for (int k=0;k<K;k++)
        {
            scanf("%d %d", &c, &r);
            map[r][c] = 1;
        }
        int worms = calculateWorms(M,N,K,map);
        answers[t] = worms;
    }
    for (int t=0;t<T;t++)
    {
        printf("%d\n", answers[t]);
    }
    return 0;
}

int calculateWorms(const int M, const int N, const int K, int map[MAXSIZE][MAXSIZE])
{
    int r, c;
    int worms = 0;
    int visited[N][M];
    for (r=0;r<N;r++)
    {
        for (c=0;c<M;c++)
        {
            visited[r][c] = 0;
        }
    }
    for (r=0;r<N;r++)
    {
        for (c=0;c<M;c++)
        {
            if (map[r][c] == 1 && visited[r][c] == 0)
            {
                vector<pair<int,int> > moves = {{-1,0},{0,1},{1,0},{0,-1}};
                queue<pair<int,int> > q;
                q.push({r,c});
                while (!q.empty())
                {
                    auto spot = q.front();
                    q.pop();
                    visited[spot.first][spot.second] = 1;
                    for (auto move : moves)
                    {
                        int newr = spot.first + move.first;
                        int newc = spot.second + move.second;
                        if (newr >= N || newc >= M || newr < 0 || newc < 0)
                        {
                            continue;
                        }
                        else if (map[newr][newc] == 1 && visited[newr][newc] == 0)
                        {
                            q.push({newr,newc});
                        }
                    }
                        
                }
                worms += 1;
            }
            
        }
    }
    return worms;
}

void bfs(int visited[MAXSIZE][MAXSIZE], const int r, const int c, const int M, const int N, int map[MAXSIZE][MAXSIZE])
{
    vector<pair<int,int> > moves = {{-1,0},{0,1},{1,0},{0,-1}};
    queue<pair<int,int> > q;
    q.push({r,c});
    while (!q.empty())
    {
        auto spot = q.front();
        q.pop();
        visited[spot.first][spot.second] = 1;
        for (auto move : moves)
        {
            int newr = spot.first + move.first;
            int newc = spot.second + move.second;
            if (newr >= N || newc >= M || newr < 0 || newc < 0)
            {
                continue;
            }
            else if (map[newr][newc] == 1 && visited[newr][newc] == 0)
            {
                q.push({newr,newc});
            }
        }
            
    }
    
}