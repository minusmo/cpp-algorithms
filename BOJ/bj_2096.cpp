#include <stdio.h>
#include <iostream>
#define MAXSIZE 100000
using namespace std;

void findMinMax(int numbers[MAXSIZE][3], int* minVal, int* maxVal, const int level, const int maxLevel, const int currentVal, const int prevItem);
bool isFeasibleItem(int prevItem, int i, int level);

int main() {
    int minVal = 900001; 
    int maxVal = 0;
    int N;
    int numbers[MAXSIZE][3];
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> numbers[i][0] >> numbers[i][1] >> numbers[i][2];
    }
    findMinMax(numbers, &minVal, &maxVal, 0, N, 0, 0);
    cout << maxVal << ' ' << minVal << endl;
    return 0;
}

void findMinMax(int numbers[MAXSIZE][3], int* minVal, int* maxVal, const int level, const int maxLevel, const int currentVal, const int prevItem) {
    if (level == maxLevel) {
        if (currentVal < *minVal) {
            *minVal = currentVal;
        }
        if (currentVal > *maxVal) {
            *maxVal = currentVal;
        }
        return;
    }
    else {
        for (int i=0;i<3;i++) {
            if (isFeasibleItem(prevItem, i, level)) {
                findMinMax(numbers, minVal, maxVal, level+1, maxLevel, currentVal+numbers[level][i],i);
            }
        }
    }
}

bool isFeasibleItem(int prevItem, int i, int level) {
    if (level == 0) {
        return true;
    }
    if (prevItem == 1) {
        return true;
    }
    else if (prevItem == 0) {
        if (i > 1) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        if (i < 1) {
            return false;
        }
        else {
            return true;
        }
    }
}