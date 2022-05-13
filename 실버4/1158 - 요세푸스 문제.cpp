#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, k, tmp;
	cin >> n >> k;
	queue<int> yo;
	vector<int> yovec;
	for (int i = 1; i < n + 1; i++) {
		yo.push(i);
	}
	while (!yo.empty()) {
		for (int i = 0; i < k; i++) {
			if (i == k - 1) {
				tmp = yo.front();
				yo.pop();
				yovec.push_back(tmp);
			}
			else {
				tmp = yo.front();
				yo.pop();
				yo.push(tmp);
			}
		}
	}
	cout << "<";
	for (int i = 0; i < n - 1; i++) {
		cout << yovec[i] << ", ";
	}
	cout << yovec[n - 1] << ">";
}