#include <iostream>
using namespace std;

int main() {
	int n;
	int minsize = 1000000000;
	int arr[3] = { 0,0,0 };
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i * j > n) {
				break;
			}
			for (int k = 1; k <= n; k++) {
				if (i * j * k > n) {
					break;
				}
				else if (i * j * k < n) {
					continue;
				}
				else {
					int size = i * j * 2 + i * k * 2 + j * k * 2;
					if (size < minsize) {
						minsize = size;
						arr[0] = k;
						arr[1] = j;
						arr[2] = i;
					}
					break;
				}
			}
		}
	}
	cout << arr[0] << " " << arr[1] << " " << arr[2];
}
