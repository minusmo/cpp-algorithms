#include <stdio.h>
#include <iostream>
#include <array>
#include <string>
using namespace std;
#define MAXSIZE 1000

int calculateLCS(string string1, string string2);
int main() {
    string sequence1; 
    string sequence2;
    getline(cin, sequence1);
    getline(cin, sequence2);
    int LCS = calculateLCS(sequence1, sequence2);
    printf("%d\n", LCS);
    return 0;
}

int calculateLCS(string sequence1, string sequence2) {
    int LCS[MAXSIZE][MAXSIZE];
    bool isSubseq = false;
    for (int i=0;i<sequence1.length();i++) {
        if (isSubseq) {
            LCS[i][0] = 1;
            continue;
        }
        if (sequence1[i] == sequence2[0]) {
            LCS[i][0] = 1;
            isSubseq = true;
        }
    }
    isSubseq = false;
    for (int j=0;j<sequence2.length();j++) {
        if (isSubseq) {
            LCS[0][j] = 1;
            continue;
        }
        if (sequence2[j] == sequence1[0]) {
            LCS[0][j] = 1;
            isSubseq = true;
        }
    }
    for (int i=1;i<sequence1.length();i++) {
        for (int j=1;j<sequence2.length();j++) {
            if (sequence1[i] == sequence2[j]) {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else {
                LCS[i][j] = std::max(LCS[i][j-1],LCS[i-1][j]);
            }
        }
    }
    return LCS[sequence1.length()-1][sequence2.length()-1];
}
