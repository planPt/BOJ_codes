#include <iostream>
using namespace std;
int N;
long long threewall[35];
//threewall[i]= 3*iũ���� ���� 2*1, 1*2 ũ���� Ÿ�Ϸ� ä��� ����� ��
//Ȧ���϶� 0����
//i�� ¦���϶� ���� ����� ������� �ʴ� 
// �������� 3*i ����� 2���� �����Ѵ�.(i�� 2���϶� 3����)
//threewall[i]=[i-2]*threewall[2] + [i-4]*2+ ...+ [i-i+2]*2 + [i-i]*2
//[4]=[4-2]*[2]+[4-4]*2
int main() {
	int N;
	cin >> N;
	if (N % 2 == 1) {	//N�� Ȧ���϶�
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