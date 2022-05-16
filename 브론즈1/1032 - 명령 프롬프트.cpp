#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> arr(s.length());
    for (int i = 0; i < s.length(); i++) {
        arr[i] = s[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] != arr[j]) {
                arr[j] = '?';
            }
        }
    }
    for (int i = 0; i < s.length(); i++) {
        cout << arr[i];
    }
}