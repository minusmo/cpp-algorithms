#include <stdio.h>
#include <queue>
#include <array>
#define MAXSIZE 100001
using namespace std;
struct Item
{
    int n;
    int g;
    int estimation;

    bool operator< (const Item & item)const {
        if (estimation == item.estimation) {
            return g > item.g;
        }
        else {
            return estimation > item.estimation;
        }
    }
};

int calculateMinTime(const int N, const int K);
int estimateMinTime(const int n, const int g, const int K);
struct Item makeItem(int n, int g, int estimation);

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int minTime = calculateMinTime(N,K);
    printf("%d\n", minTime);
    return 0;
}

int calculateMinTime(const int N, const int K) {
    array<int, MAXSIZE*2> costs;
    array<int, MAXSIZE*2> calculated;
    costs.fill(MAXSIZE);
    calculated.fill(false);
    if (N > K) {
        return N - K;
    }
    int minTime = MAXSIZE;
    int currentNumber;
    queue<int> q;
    q.push(N);
    costs[N] = 0;
    calculated[N] = true;
    while (q.empty() == false) {
        currentNumber = q.front();
        q.pop();
        if (currentNumber == K) {
            if (costs[currentNumber] < minTime) {
                minTime = costs[currentNumber];
                break;
            }
        }
        else {
            if (calculated[currentNumber + 1] == false && currentNumber <= K) {
                costs[currentNumber+1] = costs[currentNumber] + 1;
                calculated[currentNumber+1] = true;
                q.push(currentNumber+1);
            }
            if (calculated[currentNumber - 1] == false && currentNumber >= 1) {
                costs[currentNumber-1] = costs[currentNumber] + 1;
                calculated[currentNumber-1] = true;
                q.push(currentNumber -1);
            }
            if (calculated[currentNumber * 2] == false && currentNumber*2 <= 100000 && currentNumber > 0) {
                costs[currentNumber*2] = costs[currentNumber];
                calculated[currentNumber*2] = true;
                q.push(currentNumber*2);
            }
        }
    }
    return minTime;
}

struct Item makeItem(int n, int g, int estimation) {
    struct Item item = {n,g,estimation};
    return item;
}

int estimateMinTime(const int n, const int g, const int K) {
    int estimation = g;
    int h = 0;
    int N = n;
    int doubles = 0;
    
    if (n > K) {
        h += n - K;
    }
    else if (n == 0) {
        h = K - n;
    }
    else {
        while (N < K)
        {
            N = N * 2;
            doubles += 1;
        }
        h += doubles;
    }
    estimation += h;
    return estimation;
}