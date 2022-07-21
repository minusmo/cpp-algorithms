#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;
struct Item
{
    int n;
    int g;
    int estimation;

    bool operator< (const Item& item)const {
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
    if (N > K) {
        return N - K;
    }
    int minTime = INT_MAX;
    Item currentNumber;
    priority_queue<Item> q;
    q.push({0,N});
    while (q.empty() == false) {
        currentNumber = q.top();
        q.pop();
        if (currentNumber.n == K) {
            if (currentNumber.g < minTime) {
                minTime = currentNumber.g;
            }
        }
        else {
            int estimation1 = estimateMinTime(currentNumber.n + 1, currentNumber.g + 1, K);
            int estimation2 = estimateMinTime(currentNumber.n - 1, currentNumber.g + 1, K);
            int estimation3 = estimateMinTime(currentNumber.n * 2, currentNumber.g , K);
            if (estimation1 < minTime) {
                q.push(makeItem(currentNumber.n + 1, currentNumber.g + 1, estimation1));
            }
            if (estimation2 < minTime) {
                q.push(makeItem(currentNumber.n - 1, currentNumber.g + 1, estimation2));
            }
            if (estimation3 < minTime) {
                q.push(makeItem(currentNumber.n * 2, currentNumber.g, estimation3));
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