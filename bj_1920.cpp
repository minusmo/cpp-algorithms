#include <iostream>
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

int binarySearch(int *find_at, int beg, int end, int target) {
    int mid;
    if (end >= beg) {
        mid = (beg+end)/2;
        if (find_at[mid] == target) {
            return mid;
        }
        else if (find_at[mid] < target) {
            return binarySearch(find_at, mid+1, end, target);
        }
        else {
            return binarySearch(find_at, beg, mid-1, target);
        }
    }
    return -1;
}

int main() {
    int N, M;
    int *find_at, *to_find;

    scanf("%d", &N);
    find_at = new int[N];
    for (int i=0;i<N;i++) scanf("%d", &find_at[i]);
    scanf("%d", &M);
    to_find = new int[M];
    for (int i=0;i<M;i++) scanf("%d", &to_find[i]);

    mergeSort(find_at, 0, N-1);

    for (int i = 0; i < M; i++) {
        int position = binarySearch(find_at, 0, N-1, to_find[i]);
        if (position == -1) {
            printf("%d\n", 0);
        }
        else {
            printf("%d\n", 1);
        }
    }
    
    delete[] find_at;
    delete[] to_find;
    return 0;
}