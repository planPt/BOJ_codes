#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int tmp;
	int smallest = 1000000;	//�Է��� �ִ�
	int biggest = -1000000;	//�Է��� �ּڰ�
	for (int i = 0; i < N; i++) {	//�ð����⵵ O(n)
		cin >> tmp;
		if (tmp > biggest) {	//�ִ밪���� ũ�� ��ü
			biggest = tmp;
		}
		if (tmp < smallest) {	//�ּҰ����� ������ ��ü
			smallest = tmp;
		}
	}
	//���
	cout << smallest << " " << biggest;
}