#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int fivo[41];
	fivo[0] = 0;
	fivo[1] = 1;
	for (int i = 0; i < 39; i++) {
		fivo[i + 2] = fivo[i + 1] + fivo[i];
	}
	int T;
	cin >> T;
	int N;
	for (int i = 0; i < T; i++) {
		cin >> N;
		if (N == 0) {
			cout << "1 0\n";
		}
		else {
			cout << fivo[N - 1] << " " << fivo[N]<<"\n";
		}
	}
}
/*
0 1 0 0
1 0 1 1
2 1 1 1
3 1 2 2
4 2 3 3 
5 3 5 5
6 5 8 8
n fivo(n-1) fivo(n)


*/