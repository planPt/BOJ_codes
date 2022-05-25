#include <iostream>
#include <queue>
using namespace std;

int main() {
	int cnt = 0;
	int T;	//테스트 케이스의 수
	cin >> T;
	int n, m, imp;
	for (int i = 0; i < T; i++) {
		cnt = 0;
		cin >> n >> m;
		queue<pair<int, int>>q;
		priority_queue<int>pq;
		for (int j = 0; j < n; j++) {
			cin >> imp;
			q.push({ j,imp });
			pq.push(imp);
		}
		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if (pq.top() == val) {
				pq.pop();
				cnt += 1;
				if (idx == m) {
					cout << cnt << endl;
					break;
				}
			}
			else {
				q.push({ idx,val });
			}
		}
	}
}