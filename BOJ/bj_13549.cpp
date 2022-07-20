#include <stdio.h>
#include <queue>
#include <utility>
#define MAXSIZE 100001
using namespace std;

int calculateMinTime(const int N, const int K);
int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int minTime = calculateMinTime(N,K);
    printf("%d\n", minTime);
}

int calculateMinTime(const int N, const int K) {
    if (N > K) {
        return N - K;
    }
    int minTime;
    pair<int,int> n;
    queue<pair<int,int>> q;
    q.push({N,0});
    while (q.empty() == false) {
        n = q.front();
        q.pop();
        if (n.first == K) {
            if (n.second < minTime) {
                minTime = n.second;
            }
        }
        else {
            int h = std::abs(K - n.first);
        }
    }

}