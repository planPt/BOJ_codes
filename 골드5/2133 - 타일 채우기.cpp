#include <iostream>
using namespace std;
int N;
long long threewall[35];
//threewall[i]= 3*i크기의 벽을 2*1, 1*2 크기의 타일로 채우는 경우의 수
//홀수일때 0가지
//i가 짝수일때 이전 모양을 사용하지 않는 
// 독자적인 3*i 모양은 2개가 존재한다.(i가 2개일땐 3가지)
//threewall[i]=[i-2]*threewall[2] + [i-4]*2+ ...+ [i-i+2]*2 + [i-i]*2
//[4]=[4-2]*[2]+[4-4]*2
int main() {
	int N;
	cin >> N;
	if (N % 2 == 1) {	//N이 홀수일때
		cout << 0;
		return 0;
	}
	else {
		threewall[0] = 1;
		threewall[1] = 0;
		threewall[2] = 3;
		for (int i = 4; i < 31; i+=2) {
			threewall[i] += threewall[i - 2] * 3;
			for (int j = i - 4; j >= 0;j-=2) {
				threewall[i] += threewall[j] * 2;
			}
		}
		cout << threewall[N];
	}
}