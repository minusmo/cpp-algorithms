#include <iostream>
#include <vector>
#include <utility>
#define MAXSIZE 50
#define MAXPOS 2500
using namespace std;

int calculateWorms(const int M, const int N, const int K,int map[MAXSIZE][MAXSIZE]);
void dfs(int visited[MAXSIZE][MAXSIZE], const int r, const int c, const int M, const int N, int map[MAXSIZE][MAXSIZE]);
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
    int visited[MAXSIZE][MAXSIZE];
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
                dfs(visited,r,c,M,N,map);
                worms += 1;
            }
            
        }
    }
    return worms;
}

void dfs(int visited[MAXSIZE][MAXSIZE], const int r, const int c, const int M, const int N, int map[MAXSIZE][MAXSIZE])
{
    visited[r][c] = 1;
    vector<pair<int,int> > moves = {{-1,0},{0,1},{1,0},{0,-1}};
    for (auto move : moves)
    {
        int nextr = r + move.first;
        int nextc = c + move.second;
        if (nextr >= N || nextc >= M || nextr < 0 || nextc < 0)
        {
            continue;
        }
        else if (map[nextr][nextc] == 1 && visited[nextr][nextc] == 0)
        {
            dfs(visited, nextr,nextc, M,N,map);
        }
    }
}