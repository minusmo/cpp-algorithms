#include <iostream>
#include <math.h>

using namespace std;

void findPrime(int nums[], int length) {
    int primes = 0;
    int j;
    for (int i=0;i<length;i++) {
        if (nums[i] == 1) {
            continue;
        }
        for (j=2;j<(int)sqrt(nums[i])+1;j++) {
            if (nums[i] % j == 0) {
                break;
            }
        }
        if (j == (int)sqrt(nums[i])+1) {
            primes++;
        }
    }
    printf("%d\n", primes);
}
int main() {
    int N;
    int *nums;

    scanf("%d", &N);
    nums = new int[N];

    for (int i=0;i<N;i++) {
        scanf("%d", &nums[i]);
    }
    findPrime(nums, N);
    delete[] nums;
    return 0;
}