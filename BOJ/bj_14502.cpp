#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
#define MAX_SIZE 8

void getMaxSafeArea(const int N,const int M,const int W,const int w,const int v,int p,int map[MAX_SIZE][MAX_SIZE],vector<tuple <int,int> > paths,vector<tuple <int,int> > viruses,vector<int>& walls,int* maxSafeArea);
int simulateInfection(const int N, const int M, int map[MAX_SIZE][MAX_SIZE], vector<tuple <int,int> > viruses, vector<int> walls, vector<tuple<int,int> > paths);
int calculateInfectedArea(int totalInfection, const int N, const int M, const int W, const int w, const int v);
int bfs(int infectedMap[MAX_SIZE][MAX_SIZE], tuple <int,int> virus, const int N, const int M);
bool isInBound(const int r, const int c, const int N, const int M);

int main() {
    int N, M, W, w, v;
    int map[MAX_SIZE][MAX_SIZE];
    int maxSafeArea = 0;
    W = 3;
    w = 0;
    v = 0;
    vector<tuple <int,int> > paths;
    vector<tuple <int,int> > viruses;
    vector<int> walls;
    scanf("%d %d", &N, &M);
    for (int r=0;r<N;r++) {
        for (int c=0;c<M;c++) {
            scanf("%d", &(map[r][c]));
            if (map[r][c] == 0) {
                paths.push_back(make_tuple(r,c));
            }
            else if (map[r][c] == 1)
            {
                w += 1;
            }
            else if (map[r][c] == 2)
            {
                viruses.push_back(make_tuple(r,c));
                v += 1;
            }
        }
    }
    getMaxSafeArea(N,M,W,w,v,0,map,paths,viruses,walls,&maxSafeArea);
    printf("%d\n", maxSafeArea);
    return 0;
}

void getMaxSafeArea(const int N,const int M,const int W,const int w,const int v,int p, int map[MAX_SIZE][MAX_SIZE],vector<tuple <int,int> > paths,vector<tuple <int,int> > viruses,vector<int>& walls,int* maxSafeArea) {
    if (walls.size() == W) {
        int totalInfection = simulateInfection(N,M,map,viruses,walls,paths);
        int safeArea = calculateInfectedArea(totalInfection,N,M,W,w,v);
        if (safeArea > *maxSafeArea) {
            *maxSafeArea = safeArea;
        }
        return;
    }
    else {
        for (int i=p;i<paths.size();i++) {
            bool isInWalls;
            for (auto j=walls.begin();j!=walls.end();j++) {
                if (*j == i) {
                    isInWalls = true;
                }
                else {
                    isInWalls = false;
                }
            }
            if (isInWalls == false) {
                walls.push_back(i);
                getMaxSafeArea(N,M,W,w,v,i+1,map,paths,viruses,walls,maxSafeArea);
                walls.pop_back();
            }
        }
        return;
    }
}

int simulateInfection(const int N, const int M, int map[MAX_SIZE][MAX_SIZE], vector<tuple <int,int> > viruses, vector<int> walls, vector<tuple<int,int> > paths) {
    int infectedMap[MAX_SIZE][MAX_SIZE];
    int totalInfection = 0;
    int infection;
    int r, c;
    for (r=0;r<N;r++) {
        for (c=0;c<M;c++) {
            infectedMap[r][c] = map[r][c];
        }
    }
    for (auto wall=walls.begin();wall != walls.end();wall++) {
        r = get<0>(paths[*wall]);
        c = get<1>(paths[*wall]);
        infectedMap[r][c] = 1;
    }
    for (auto virus = viruses.begin();virus != viruses.end();virus++) {
        infection = bfs(infectedMap,*virus, N, M);
        totalInfection += infection;
    }
    return totalInfection;
}

int bfs(int infectedMap[MAX_SIZE][MAX_SIZE], tuple <int,int> virus, const int N, const int M) {
    tuple <int,int> path;
    queue<tuple <int,int>> q;
    int moves[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int infection = 0;
    q.push(virus);
    while (q.size() != 0) {
        path = q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            int r = moves[i][0] + get<0>(path);
            int c = moves[i][1] + get<1>(path);
            if (isInBound(r,c,N,M) && infectedMap[r][c] == 0) {
                infection += 1;
                infectedMap[r][c] = 2;
                q.push(make_tuple(r,c));
            }
        }
    }
    return infection;
}

bool isInBound(const int r, const int c, const int N, const int M) {
    if (r < 0 || r >= N || c < 0 || c >= M) {
        return false;
    }
    else {
        return true;
    }
}

int calculateInfectedArea(int totalInfection, const int N, const int M, const int W, const int w, const int v) {
    return N*M - W - w - v - totalInfection;
}