#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long fivo[46] = { 0 };	//피보나치 수들을 저장할 배열
//fivo[45]=1134903170
void calfivo() {
	fivo[0] = 0;
	fivo[1] = 1;
	for (int i = 2; i < 46; i++) {
		fivo[i] = fivo[i - 1] + fivo[i - 2];
	}
}

void caln(int n) {
	vector<int> v;
	for (int i = 45; i > 0; i--) {
		if (n >= fivo[i]) {
			v.push_back(fivo[i]);
			n -= fivo[i];
		}
	}
	for (int i = 0; i < v.size(); i++) { //현재 v는 내림차순
		cout << v[v.size() - i - 1] << " ";
	}
	cout << endl;
}

int main() {
	calfivo();
	int T, n;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		caln(n);
	}
}
