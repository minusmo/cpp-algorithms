#include <stdio.h>
#include <queue>
#include <array>
#define MAXSIZE 100001
using namespace std;

struct Item
{
    int n;
    int g;

    bool operator< (const Item & item)const {
        if (g == item.g) {
            return g > item.g;
        }
        else {
            return n > item.n;
        }
    }
};

int calculateMinTime(const int N, const int K);
struct Item makeItem(int n, int g);

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int minTime = calculateMinTime(N,K);
    printf("%d\n", minTime);
    return 0;
}

int calculateMinTime(const int N, const int K) {
    array<int, MAXSIZE*2> costs;
    costs.fill(MAXSIZE);
    if (N > K) {
        return N - K;
    }
    struct Item currentNumber;
    priority_queue<struct Item> q;
    Item initialItem = {N,0};
    q.push(initialItem);
    costs[N] = 0;
    while (q.empty() == false) {
        currentNumber = q.top();
        q.pop();
        
        if (currentNumber.n <= K && costs[currentNumber.n+1] > currentNumber.g+1) {
            costs[currentNumber.n+1] = currentNumber.g + 1;
            q.push(makeItem(currentNumber.n+1, currentNumber.g+1));
        }
        if (currentNumber.n >= 1 && costs[currentNumber.n-1] > currentNumber.g+1) {
            costs[currentNumber.n-1] = currentNumber.g + 1;
            q.push(makeItem(currentNumber.n-1, currentNumber.g+1));
        }
        if (currentNumber.n *2 <= 100000 && currentNumber.n > 0 && costs[currentNumber.n*2] > currentNumber.g) {
            costs[currentNumber.n*2] = currentNumber.g;
            q.push(makeItem(currentNumber.n*2,currentNumber.g));
        }
    }
    return costs[K];
}

struct Item makeItem(int n, int g) {
    struct Item item = {n,g};
    return item;
}