#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int arr[51][2] = {};
	int res[51];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
		res[i] = 1;		//결과 배열 초기화
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
				res[i]++;
		}
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << '\n';
}