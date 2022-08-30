#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    char line[n];
    for (int i=1;i<n+1;i++)
    {
        for (int j=0;j<n-i;j++)
        {
            line[j] = ' ';
        }
        for (int k=0;k<i;k++)
        {
            line[n-i+k] = '*';
        }
        for (int l=0;l<n;l++)
        {
            printf("%c",line[l]);
        }
        printf("\n");

    }
    return 0;
}
