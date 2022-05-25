#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	int tile[1001] = { 0 }; // tile[n]은 2*n직사각형을 만드는 방법의 수
	//2*n=> 2*(n-1)+2*1 또는 2*(n-2)+(2*2 or 1*2두개)
	//tile[n]=tile[n-1]+tile[n-2]*2
	tile[1] = 1;
	tile[2] = 3;
	for (int i = 3; i < n+1; i++) {
		tile[i] = (tile[i - 1] + tile[i - 2] * 2) % 10007;
	}
	cout << tile[n];
	return 0;
}