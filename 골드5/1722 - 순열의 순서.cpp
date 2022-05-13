#include <iostream>
#include <vector>
using namespace std;
int N;
long long fact[21];	//20!���� �����ϴ� �迭

void findpermu(long long k, int a) {	//���°���� �޾����� �迭�� ���ϱ�
	vector<bool> tmpvec(a);	//�湮 ���θ� ��Ÿ���� ����
	for (int i = 0; i < a; i++) {
		tmpvec[i] = false;
	}
	vector<int> arr(a);	//������ ������ ����
	//fact[N-i-1]�� ���ϴٰ� ���� �ʰ��ϸ� fact[N-i-1]�� ���� 
	//���� Ƚ����ŭ �湮���� ���庤���� �տ��� ���� ���
	long long ans = 0;
	for (int i = 0; i < a; i++) {
		int cnt = 0;
		while (true) {
			ans += fact[N - i - 1];
			if (ans >= k) {		//���� �ʰ��ϸ�
				ans -= fact[N - i - 1];
				break;
			}
			cnt += 1;
		}
		for (int j = 0; j < a; j++) {
			if (!tmpvec[j]) {
				if (cnt == 0) {
					tmpvec[j] = true;
					arr[i] = j + 1;
				}
				cnt -= 1;
			}
		}
	}


	for (int i = 0; i < a; i++) {	//���� ���� ���
		cout << arr[i] << " ";
	}
}

long long permunumber(vector<int> arr, int a) {	//�迭�� �޾����� ���°���� ���ϱ�
	vector<bool> tmpvec(a);	//�湮 ���θ� ��Ÿ���� ����
	for (int i = 0; i < a; i++) {
		tmpvec[i] = false;		//��ü �̹湮���� �ʱ�ȭ
	}
	long long ans = 0;	//��
	for (int i = 0; i < arr.size(); i++) {
		int tr = 0;	// �տ��� ���°���� ��Ÿ���� ����
		for (int j = 0; j < arr[i]-1; j++) {	//arr[i]���� �湮 ���� ���� üũ
			if (!tmpvec[j]) {	//�湮���ߴٸ�
				tr += 1;	//1 ���ϱ�
			}
		}
		ans += fact[N - i - 1] * tr;	//�信 (N-i-1)! ���ϱ�
		tmpvec[arr[i]-1] = true;	// �湮�ߴٴ� ǥ�÷� �ٲٱ�
	}
	return ans + 1;
}

void fa() {	//���丮��
	fact[0] = 1;
	for (int i = 1; i < 21; i++) {
		fact[i] = fact[i - 1] * i;
	}
}

int main() {
	int n;
	long long k;
	cin >> N >> n;
	fa();	// ���������� �Էµ�
	if (n == 1) {	//�ҹ��� ��ȣ 1
		cin >> k;
		findpermu(k,N);
	}
	else {		//�ҹ��� ��ȣ 2
		vector<int> arr(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cout<<permunumber(arr,N);
	}
}