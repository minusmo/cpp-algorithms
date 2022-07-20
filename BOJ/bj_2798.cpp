#include <iostream>
using namespace std;

int main() {
    int N, M, maximum, sum; 
    int *cards = NULL;

    cin >> N >> M;
    cards = new int[N];
    for (int j = 0; j < N; j++) {
        cin >> cards[j];
    }

    maximum = 0;
    for (int l=0; l < N-2; l++) {
        sum = 0;
        sum += cards[l];

        for (int k=l+1; k < N-1; k++) {
            sum += cards[k];

            for (int h=k+1; h < N; h++) {
                sum += cards[h];
                if (sum > maximum && sum <= M) {
                    maximum = sum;
                }
                sum -= cards[h];
            }
            sum -= cards[k];
        }
    }
    cout << maximum << endl;
    return 0;
}