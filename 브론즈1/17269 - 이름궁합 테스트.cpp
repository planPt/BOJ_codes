#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int alpha[26] = { 3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1 };
vector<int> v;

void namesum(vector<int> v) {	//벡터에서 계속 궁합을 보는 함수
	if (v.size() == 2) {	// 정답 벡터의 길이가 2일때
		int ans = 10 * v[0] + v[1];	
		cout << ans << "%";		//출력
		return;
	}
	vector<int> vv;	//한번 합쳐져서 길이가 1 줄어든 벡터
	for (int i = 1; i < v.size(); i++) {
		vv.push_back((v[i] + v[i - 1]) % 10); // 합하고 벡터에 입력
	}
	namesum(vv);		//재귀로 길이가 2 될때까지 반복
}

int main() {
	
	string nameone, nametwo;
	int lengthone, lengthtwo;
	cin >> lengthone >> lengthtwo;
	cin >> nameone >> nametwo;
	int maxlength = max(lengthone, lengthtwo);
	for (int i = 0; i < maxlength; i++) {	//벡터에 첫 획수 입력
		if (lengthone > i) {
			v.push_back(alpha[int(nameone[i]) - 65]);
		}
		if (lengthtwo > i) {
			v.push_back(alpha[int(nametwo[i]) - 65]);
		}
	}
	//이름 합하기
	namesum(v);
}