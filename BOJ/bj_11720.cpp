#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    int N;
    string nums;
    cin >> N;
    cin >> nums;
    int sum = 0;
    for (int it = 0; it < nums.length(); it++)
    {
        int k = nums[it] - '0';
        sum += k;
    }
    cout << sum << endl;
    return 0;
}