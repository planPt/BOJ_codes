#include <iostream>
using namespace std;
//��Ʈ��ŷ
int N;	//1���� N����
int check[8];	//�湮�ߴ� ��ȣ ����
bool visited[8] = { false, };	//�湮 ����

void solve(int cnt) {	// ��ȯ �Լ��� �̿�
	if (cnt == N) {	//N��° ��ȣ���� �湮���� ��
		for (int i = 0; i < N; i++) {	//����ϱ�
			cout << check[i] + 1 << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < N; i++) {	//�� ���ʴ� 1���� N���� ���� üũ
		if (!visited[i]) {	// i���� �湮���� �ʾ�����
			check[cnt] = i;	// cnt��° ĭ�� i ����
			visited[i] = true;	//�湮�ߴٴ� ǥ��
			solve(cnt + 1);	//cnt+1 ��° �湮
			visited[i] = false;	//�����ܰ�� ���ƿ� ���� ��ȣ Ž��
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> N;
	solve(0);
}