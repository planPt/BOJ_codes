#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//������ ������ �ൿ�� 3���� -1,+1,*2
//��� ����� ���� �� �غ��ٰ� ������ ��ġ�� ��ġ�� ��Ȳ�� ������ stop
//queue�� ó�� ��ġ�� �ְ� -1,+1,*2�� �� ����� �ٽ� queue�� �Է�
bool ifsubinloc[100002];	//������ x�� �湮�ߴ��� ����

int main() {
	int N, K;
	int ans=0;
	cin >> N >> K;
	queue<pair<int, int>>que;	//pair<��������ġ,Ƚ��>
	que.emplace(N, 0);	//ó�� ������ ��ġ ť�� ����
	while (!que.empty()) {
		int subinloc = que.front().first;//������ ��ġ
		int movenum = que.front().second;//������ Ƚ��
		que.pop();	// ť���� ����
		if (subinloc == K) {	//������ ������ ��
			ans = movenum;
			break;
		}
		//�� �� �ִ� �ൿ 3����
		//���� �������� ���ǿ� ������ �ٽ� queue�� ����
		int firx = subinloc - 1;
		int secx = subinloc + 1;
		int trix = subinloc * 2;

		if (0 <= firx && !ifsubinloc[firx]) {
			// -1�� 0���� ũ�� �湮 ��������
			ifsubinloc[firx] = true;
			que.emplace(firx, movenum + 1);
		}
		if (K>=secx && !ifsubinloc[secx]) {
			// +1�� K���� �۰� �湮 ��������
			ifsubinloc[secx] = true;
			que.emplace(secx, movenum + 1);
		}
		if (K+1>=trix && !ifsubinloc[trix]) {
			// *2�� K+1���� �۰�->( k�� �������� �ι�° ���̽����� �ɷ�������
			//�ߺ��� ���� ����) �湮 ��������
			ifsubinloc[trix] = true;
			que.emplace(trix, movenum + 1);
		}
	}
	cout << ans;
}