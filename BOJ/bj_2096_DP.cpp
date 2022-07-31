#include <stdio.h>
#include <iostream>
#define MAXSIZE 100000
using namespace std;

int calculateMinVal(int numbers[MAXSIZE][3], const int N);
int calculateMaxVal(int numbers[MAXSIZE][3], const int N);

int main() {
    int minVal = 900001; 
    int maxVal = 0;
    int N;
    int numbers[MAXSIZE][3];
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> numbers[i][0] >> numbers[i][1] >> numbers[i][2];
    }
    minVal = calculateMinVal(numbers, N);
    maxVal = calculateMaxVal(numbers, N);

    cout << maxVal << ' ' << minVal << endl;
    return 0;
}

int calculateMinVal(int numbers[MAXSIZE][3], const int N) {
    int minMaxVals[6] = {numbers[0][0],numbers[0][1],numbers[0][2],numbers[0][0],numbers[0][1],numbers[0][2]};
    for (int i=1;i<N;i++) {
        minMaxVals[0] = numbers[i][0] + std::min(minMaxVals[1], minMaxVals[2]);
        minMaxVals[1] = numbers[i][1] + std::min(minMaxVals[0], minMaxVals[2]);
        minMaxVals[2] = numbers[i][2] + std::min(minMaxVals[0], minMaxVals[1]);
        minMaxVals[3] = numbers[i][0] + std::max(minMaxVals[4], minMaxVals[5]);
        minMaxVals[4] = numbers[i][1] + std::max(minMaxVals[4], minMaxVals[5]);
        minMaxVals[5] = numbers[i][2] + std::max(minMaxVals[3], minMaxVals[4]);
    }

}