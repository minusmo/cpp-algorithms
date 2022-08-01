#include <stdio.h>
#include <iostream>
#define MAXSIZE 100000
using namespace std;

void calculateMinMaxVal(int numbers[MAXSIZE][3], const int N, int* minVal, int* maxVal);
int getMin(const int a, const int b);
int getMax(const int a, const int b);

int main() {
    int minVal; 
    int maxVal;
    int N;
    int numbers[MAXSIZE][3];
    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<3;j++) {
            cin >> numbers[i][j];
        }
    }
    calculateMinMaxVal(numbers, N, &minVal, &maxVal);

    cout << maxVal << ' ' << minVal << endl;
    return 0;
}

void calculateMinMaxVal(int numbers[MAXSIZE][3], const int N, int* minVal, int* maxVal) {
    int min0, min1, min2, max0, max1, max2;
    int maxVals[3] = {numbers[0][0],numbers[0][1],numbers[0][2]};
    int minVals[3] = {numbers[0][0],numbers[0][1],numbers[0][2]};
    for (int i=1;i<N;i++) {
        min0 = minVals[0];
        min1 = minVals[1];
        min2 = minVals[2];
        max0 = maxVals[0];
        max1 = maxVals[1];
        max2 = maxVals[2];
        minVals[0] = numbers[i][0] + getMin(min0, min1);
        minVals[1] = numbers[i][1] + getMin(getMin(min0, min1), min2);
        minVals[2] = numbers[i][2] + getMin(min1, min2);
        maxVals[0] = numbers[i][0] + getMax(max0, max1);
        maxVals[1] = numbers[i][1] + getMax(getMax(max0, max1), max2);
        maxVals[2] = numbers[i][2] + getMax(max1, max2);
    }

    *minVal = getMin(getMin(minVals[0], minVals[1]), minVals[2]);
    *maxVal = getMax(getMax(maxVals[0], maxVals[1]), maxVals[2]);
}

int getMin(const int a, const int b) {
    if (a > b) {
        return b;
    }
    else if (a < b) {
        return a;
    }
    else {
        return a;
    }
}

int getMax(const int a, const int b) {
    if (a < b) {
        return b;
    }
    else if (a > b) {
        return a;
    }
    else {
        return a;
    }
}