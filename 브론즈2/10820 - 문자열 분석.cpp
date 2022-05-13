#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        int so = 0;
        int dae = 0;
        int num = 0;
        int blank = 0;
        for (int i = 0; i < s.length(); i++) {
            if ('a' <= s[i] && s[i] <= 'z') {
                so += 1;
            }
            else if (s[i] >= 'A' && s[i] <= 'Z') {
                dae += 1;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                num += 1;
            }
            else {
                blank += 1;
            }
            
        }
        cout << so << " " << dae << " " << num << " " << blank << "\n";
    }
}