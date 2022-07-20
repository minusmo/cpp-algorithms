#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

vector<int> mergesort(vector<int> list) {
    int len = list.size();
    int half;
    vector<int> lefthalf, righthalf, merged(len);
    if (len == 1) {
        merged.operator=(list);
        return merged;
    }
    half = floor(len/2);
    for (int i=0; i<half;i++) {
        lefthalf.push_back(list.at(i));
    }
    for (int i=half;i<len;i++) {
        righthalf.push_back(list.at(i));
    }
    lefthalf.operator=(mergesort(lefthalf));
    righthalf.operator=(mergesort(righthalf));
    merge(lefthalf.begin(),lefthalf.end(),righthalf.begin(),righthalf.end(),merged.begin());
    return merged;
}

int main() {
    int N,j;
    vector<int> nums, sorted;
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> j;
        nums.push_back(j);
    }
    sorted.operator=(mergesort(nums));
    for (vector<int>::iterator itr=sorted.begin();itr!=sorted.end();++itr) {
        cout << *itr << '\n';
    }
    return 0;
}