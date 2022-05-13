#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[1000001];

void isPrime() {		//에라토스테네스의 체
	for (int i = 0; i < 1000001; i++) {
		arr[i] = i;
	}
	for (int i = 3; i * i <= 1000000; i++) {
		if (arr[i]==0) {
			continue;
		}
		for (int j = i + i; j <= 1000000; j += i) {
			arr[j] = 0;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	isPrime();
	int n;
	while (true) {
		int a, b;
		cin >> n;
		bool succ = false;
		if (n == 0) {
			break;
		}
		for (int i = 1; i < (n / 2); i++) {
			a = 2 * i + 1;	//홀수 소수 2개
			b = n - a;
			if (arr[a]==a && arr[b]==b) {		//첫번째 홀수소수들의 합에서 break
				cout << n << " = " << a << " + " << b << "\n";
				succ = true;
				break;
			}
		}
		if (!succ) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
}