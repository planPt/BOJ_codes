#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];
int cards[1001];
//ī�带 �� n�� �����ؾ���
//dp[n-1]+dp[1], dp[n-2]+dp[2],...,dp[n-n]+dp[n]
//dp[i]�� �������� i��¥�� ī�带 ��� �����̴�.
int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cards[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + cards[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}