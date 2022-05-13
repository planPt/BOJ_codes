#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<string> suffix;
	for (int i = 0; i < s.length(); i++) {
		suffix.push_back(s.substr(i, s.length()));
	}
	sort(suffix.begin(), suffix.end());
	for (int i = 0; i < suffix.size(); i++) {
		cout << suffix[i] << "\n";
	}
}