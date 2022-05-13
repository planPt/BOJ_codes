#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "*";
    }
    else {
        for (int i = 0; i < n - 1; i++) {
            cout << " ";
        }
        cout << "*" << "\n";

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2 - i; j++) {
                cout << " ";
            }
            cout << "*";
            for (int j = 0; j < 2 * i + 1; j++) {
                cout << " ";
            }
            cout << "*" << "\n";
        }
        cout << "*";
        for (int i = 0; i < 2 * n - 3; i++) {
            cout << " ";
        }
        cout << "*";
    }
}