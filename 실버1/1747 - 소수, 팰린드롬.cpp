#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[1003002];

bool is_Pal(int n) {		//숫자가 펠린드롬인지 확인
	string originalString = to_string(n);
	string reverseString = to_string(n);
	reverse(reverseString.begin(), reverseString.end());
	if (originalString == reverseString) {
		return true;
	}
	else {
		return false;
	}
}

void isPrime() {		//숫자가 소수인 경우
	for (int i = 0; i < 1003002; i++) {
		arr[i] = i;
	}	
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i * i <= 1003001; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i + i; j <= 1003001; j += i) {
			arr[j] = 0;
		}
	}
}

void pelin() {		//i 가 펠린드롬인지 확인하는 함수
	for (int i = 0; i < 1003002; i++) {
		if (arr[i] != 0) {
			if (is_Pal(i)) {	//펠린드롬일 경우
				continue;
			}
			else {	//펠린드롬이 아니라면 0으로 초기화
				arr[i] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	isPrime();
	pelin();
	int n;
	cin >> n;
	for (int i = n; i<1003002; i++) {
		if (arr[i] != 0) {
			cout << arr[i];
			break;
		}
	}
}