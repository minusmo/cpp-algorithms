#include <iostream>
#include <math.h>
using namespace std;

void merge(int *find_at, int beg, int mid, int end) {
    int l = mid - beg + 1;
    int r = end - mid;
    int i = 0, j = 0;

    int *lArray = new int[l];
    int *rArray = new int[r];

    for (i=0;i<l;i++) lArray[i] = find_at[beg+i];
    for (j=0;j<r;j++) rArray[j] = find_at[mid+1+j];

    int k = beg;
    i = 0;
    j = 0;
    
    while (i<l && j<r) {
        if (lArray[i] <= rArray[j]) {
            find_at[k] = lArray[i];
            i++;
        }
        else {
            find_at[k] = rArray[j];
            j++;
        }
        k++;
    }

    while (i < l) {
        find_at[k] = lArray[i];
        i++;
        k++;
    }

    while (j < r) {
        find_at[k] = rArray[j];
        j++;
        k++;
    }

    delete[] lArray;
    delete[] rArray;
}

void mergeSort(int *find_at, int beg, int end) {
    if (beg < end) {
        int mid = (beg + end-1) / 2;
        mergeSort(find_at, beg, mid);
        mergeSort(find_at, mid+1, end);
        merge(find_at, beg, mid, end);
    }
}

int meanValue(int nums[], int length) {
    int sum = 0;
    for (int i=0;i<length;i++) {
        sum += nums[i];
    }
    return round((float)sum/length);
}

int middleValue(int nums[], int length) {
    mergeSort(nums, 0, length-1);
    return nums[length/2];
}

int mostValue(int nums[], int length) {
    int mostAppear = 0;
    int currAppear = 0;
    int mostAppearVal;
    int mostAppearVals = 1;

    for (int i=0;i<length;i++) {
        currAppear++;
        if (i == length-1 || nums[i] != nums[i+1]) {
            if (currAppear > mostAppear) {
                mostAppear = currAppear;
                mostAppearVal = nums[i];
                mostAppearVals = 1;
            }
            else if (currAppear == mostAppear) {
                if (mostAppearVals < 2) {
                    mostAppearVal = nums[i];
                    mostAppearVals++;
                }
            }
            currAppear = 0;
        }
    }
    return mostAppearVal;
}

int maxRange(int nums[], int length) {
    int range = nums[length-1] - nums[0];
    return range;
}

int main() {
    int N;
    int *nums;
    scanf("%d", &N);
    nums = new int[N];
    for (int i=0;i<N;i++) {
        scanf("%d", &nums[i]);
    }

    printf("%d\n", meanValue(nums, N));
    printf("%d\n", middleValue(nums, N));
    printf("%d\n", mostValue(nums, N));
    printf("%d\n", maxRange(nums, N));


    delete[] nums;
    return 0;
}