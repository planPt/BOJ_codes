#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		long long move, max = 0;
		while (max * max <= y - x) {
			max++;
		}
		max--;
		move = max * 2 - 1;
		long long remain = y - x - max * max;
		remain = (long long)ceil((double)remain / (double)max);
		move += remain;
		cout << move << endl;
	}
	return 0;
}