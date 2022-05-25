#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//수빈이 가능한 행동은 3가지 -1,+1,*2
//모든 경우의 수를 다 해보다가 동생의 위치랑 겹치는 상황이 나오면 stop
//queue에 처음 위치를 넣고 -1,+1,*2를 한 결과를 다시 queue에 입력
bool ifsubinloc[100002];	//수빈이 x에 방문했는지 여부

int main() {
	int N, K;
	int ans=0;
	cin >> N >> K;
	queue<pair<int, int>>que;	//pair<수빈의위치,횟수>
	que.emplace(N, 0);	//처음 수빈의 위치 큐에 삽입
	while (!que.empty()) {
		int subinloc = que.front().first;//수빈의 위치
		int movenum = que.front().second;//움직인 횟수
		que.pop();	// 큐에서 제거
		if (subinloc == K) {	//동생과 만났을 때
			ans = movenum;
			break;
		}
		//할 수 있는 행동 3가지
		//조건 따져보고 조건에 맞으면 다시 queue에 삽입
		int firx = subinloc - 1;
		int secx = subinloc + 1;
		int trix = subinloc * 2;

		if (0 <= firx && !ifsubinloc[firx]) {
			// -1이 0보다 크고 방문 안했을때
			ifsubinloc[firx] = true;
			que.emplace(firx, movenum + 1);
		}
		if (K>=secx && !ifsubinloc[secx]) {
			// +1이 K보다 작고 방문 안했을때
			ifsubinloc[secx] = true;
			que.emplace(secx, movenum + 1);
		}
		if (K+1>=trix && !ifsubinloc[trix]) {
			// *2가 K+1보다 작고->( k와 같았으면 두번째 케이스에서 걸러졌을것
			//중복을 막기 위함) 방문 안했을때
			ifsubinloc[trix] = true;
			que.emplace(trix, movenum + 1);
		}
	}
	cout << ans;
}