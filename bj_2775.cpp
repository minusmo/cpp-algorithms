#include <iostream>
using namespace std;

int get_livings(int k, int n) {
    int living = 0;
    if (k == 0) {
        return n;
    }
    for (int i = 0; i < n+1; i++) {
        living += get_livings(k-1, i);
    }
    return living;
}

int main() {
    int T, k, n, livings;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> k;
        cin >> n;
        livings = get_livings(k, n);
        cout << livings << endl;
    }
    return 0;
}

