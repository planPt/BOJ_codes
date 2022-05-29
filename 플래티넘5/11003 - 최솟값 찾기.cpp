#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N, L;
	cin >> N >> L;
	//우선순위 큐<자료형, 구현체, 비교연산자>
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		pq.push({ tmp,i });	//{value, idx}
		int start = i - L + 1;
		while (start > 0 && start > pq.top().second) {
			//내림차순으로 정렬된 pq에서 유의미한 값인
			//최솟값의 idx가 범위 바깥으로 나가면 pop
			pq.pop();
		}
		cout << pq.top().first << " ";
	}
}