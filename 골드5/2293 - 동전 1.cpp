#include <iostream>
#include <vector>
using namespace std;
int DP[10001];	// DP[i]= ���� i ���� ����� ����� ��
	// DP[k]=�ñ׸�(i=0, i=>n){DP[k-coins[i]]}
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> coins(n);
	for (int i = 0; i < n; i++) {	//�Է��� ����
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