#include <iostream>
#include <vector>
using namespace std;
int DP[10001];	// DP[i]= 동전 i 원을 만드는 경우의 수
	// DP[k]=시그마(i=0, i=>n){DP[k-coins[i]]}
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {	//입력을 받음
		cin >> coins[i];
	}
	DP[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = coins[i]; j <= k; j++) {
			DP[j] += DP[j-coins[i]];
		}
	}
	cout<<DP[k];
}