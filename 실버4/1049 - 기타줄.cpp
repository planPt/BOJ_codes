#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int broke, brand;
	cin >> broke >> brand;
	vector<int> sixstring(brand);
	vector<int> onestring(brand);
	for (int i = 0; i < brand;i++) {
		cin >> sixstring[i] >> onestring[i];
	}
	sort(sixstring.begin(), sixstring.end());
	sort(onestring.begin(), onestring.end());
	int ans[3];
	ans[0] = (broke / 6) * sixstring[0] + (broke % 6) * onestring[0];
	ans[1] = broke * onestring[0];
	ans[2] = (broke / 6 + 1) * sixstring[0];
	sort(ans, ans + 3);
	cout << ans[0];
	return 0;
}