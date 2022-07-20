#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    for (int i=1; i<c; i++) {
        if ((a*i-b*(i-1)) >= c) {
            cout << i << endl;
            break;
        }
        else if ((a*i-b*i) >= c) {
            cout << i << endl;
            break;
        }
    }
}