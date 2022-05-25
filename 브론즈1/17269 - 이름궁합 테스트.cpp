#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int alpha[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 };
vector<int> v;

void namesum(vector<int> v) {	//���Ϳ��� ��� ������ ���� �Լ�
	if (v.size() == 2) {	// ���� ������ ���̰� 2�϶�
		int ans = 10 * v[0] + v[1];	
		cout << ans << "%";		//���
		return;
	}
	vector<int> vv;	//�ѹ� �������� ���̰� 1 �پ�� ����
	for (int i = 1; i < v.size(); i++) {
		vv.push_back((v[i] + v[i - 1]) % 10); // ���ϰ� ���Ϳ� �Է�
	}
	namesum(vv);		//��ͷ� ���̰� 2 �ɶ����� �ݺ�
}

int main() {
	
	string nameone, nametwo;
	int lengthone, lengthtwo;
	cin >> lengthone >> lengthtwo;
	cin >> nameone >> nametwo;
	int maxlength = max(lengthone, lengthtwo);
	for (int i = 0; i < maxlength; i++) {	//���Ϳ� ù ȹ�� �Է�
		if (lengthone > i) {
			v.push_back(alpha[int(nameone[i]) - 65]);
		}
		if (lengthtwo > i) {
			v.push_back(alpha[int(nametwo[i]) - 65]);
		}
	}
	//�̸� ���ϱ�
	namesum(v);
}