#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N, L;
	cin >> N >> L;
	//�켱���� ť<�ڷ���, ����ü, �񱳿�����>
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		pq.push({ tmp,i });	//{value, idx}
		int start = i - L + 1;
		while (start > 0 && start > pq.top().second) {
			//������������ ���ĵ� pq���� ���ǹ��� ����
			//�ּڰ��� idx�� ���� �ٱ����� ������ pop
			pq.pop();
		}
		cout << pq.top().first << " ";
	}
}