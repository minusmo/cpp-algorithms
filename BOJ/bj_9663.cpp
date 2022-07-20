#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int nqueen(int n);
bool isAvailable(vector<int> currentCandidate, int currentCol);
int dfs(int n, int currentRow, vector<int> currentCandidate);

int main() {
    int n;
    cin >> n;
    int ways = nqueen(n);
    cout << ways;
    return 0;
}

int nqueen(int n) {
    vector<int> currentCandidate;
    return dfs(n,0,currentCandidate);
}

bool isAvailable(vector<int> currentCandidate, int currentCol) {
    int currentRow = currentCandidate.size();
    for (int i=0;i<currentRow;i++) {
        if ((currentCandidate[i]==currentCol) || (abs(currentCandidate[i]-currentCol) == (currentRow-i))) {
            return false;
        }
    }
    return true;
}

int dfs(int n, int currentRow, vector<int> currentCandidate) {
    int ways = 0;
    if (currentRow == n) {
        return 1;
    }

    for (int i=0;i<n;i++) {
        if (isAvailable(currentCandidate, i) == true) {
            currentCandidate.push_back(i);
            int cands = dfs(n, currentRow+1, currentCandidate);
            ways += cands;
            currentCandidate.pop_back();
        }
    }
    return ways;
}