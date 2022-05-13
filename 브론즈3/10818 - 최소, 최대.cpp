#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int tmp;
	int smallest = 1000000;	//입력의 최댓값
	int biggest = -1000000;	//입력의 최솟값
	for (int i = 0; i < N; i++) {	//시간복잡도 O(n)
		cin >> tmp;
		if (tmp > biggest) {	//최대값보다 크면 교체
			biggest = tmp;
		}
		if (tmp < smallest) {	//최소값보다 작으면 교체
			smallest = tmp;
		}
	}
	//출력
	cout << smallest << " " << biggest;
}