#include <iostream>
using namespace std;


int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 5 * n; i++) {
        for (int j = 1; j <= 5 * n; j++) {
            if (i>=5*n-n+1||j<=n) cout << "@";
        }
        cout << "\n";
    }
}