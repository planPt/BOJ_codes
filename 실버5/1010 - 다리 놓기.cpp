#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        long long ans = 1;
        int temp, r;
        if (n > m - n) {
            r = m - n;
        }
        else {
            r = n;
        }
        temp = m;    //tempCr;
        for (int j = temp; j > temp - r; j--) ans *= j;
        for (int k = r; k >= 1; k--)ans /= k;
        cout << ans << "\n";
    }
}