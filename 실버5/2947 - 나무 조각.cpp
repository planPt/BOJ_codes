#include <iostream>
using namespace std;

int main() {
	int arr[5] = { 0 };
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	for (int i = 4; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				for (int k = 0; k < 5; k++) {	//Ãâ·Â
					cout << arr[k] << " ";
				}
				cout << endl;
			}
		}
	}
}