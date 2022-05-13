#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int x1, y1, r1, x2, y2, r2, t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int d = pow((x1 - x2), 2) + pow((y1 - y2), 2);
		if (r1 == r2 && d == 0) {
			cout << -1 << endl;
		}
		else if (d == pow(r1 + r2,2)||d==pow(r1-r2,2)) {
			cout << 1 << endl;
		}
		else if (d < pow(r1 + r2,2)&&d>pow(r1-r2,2)) {
			cout << 2 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
}