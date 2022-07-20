#include <iostream>
using namespace std;

int main() {
    int n,m;
    int nums[10000] = {0,};
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
        scanf("%d", &m);
        nums[m-1] += 1;
    }
    for (int k = 0; k < 10000; k++) {
        for (int l = 0; l < nums[k]; l++) {
            printf("%d\n", k+1);
        }
    }
    return 0;
}