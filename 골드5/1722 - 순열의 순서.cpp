#include <iostream>
#include <vector>
using namespace std;
int N;
long long fact[21];	//20!까지 저장하는 배열

void findpermu(long long k, int a) {	//몇번째인지 받았을때 배열을 구하기
	vector<bool> tmpvec(a);	//방문 여부를 나타내는 벡터
	for (int i = 0; i < a; i++) {
		tmpvec[i] = false;
	}
	vector<int> arr(a);	//정답을 저장할 벡터
	//fact[N-i-1]씩 더하다가 값을 초과하면 fact[N-i-1]을 빼고 
	//더한 횟수만큼 방문여부 저장벡터의 앞에서 가서 출력
	long long ans = 0;
	for (int i = 0; i < a; i++) {
		int cnt = 0;
		while (true) {
			ans += fact[N - i - 1];
			if (ans >= k) {		//값을 초과하면
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


	for (int i = 0; i < a; i++) {	//정답 벡터 출력
		cout << arr[i] << " ";
	}
}

long long permunumber(vector<int> arr, int a) {	//배열을 받았을때 몇번째인지 구하기
	vector<bool> tmpvec(a);	//방문 여부를 나타내는 벡터
	for (int i = 0; i < a; i++) {
		tmpvec[i] = false;		//전체 미방문으로 초기화
	}
	long long ans = 0;	//답
	for (int i = 0; i < arr.size(); i++) {
		int tr = 0;	// 앞에서 몇번째인지 나타내는 변수
		for (int j = 0; j < arr[i]-1; j++) {	//arr[i]까지 방문 안한 개수 체크
			if (!tmpvec[j]) {	//방문안했다면
				tr += 1;	//1 더하기
			}
		}
		ans += fact[N - i - 1] * tr;	//답에 (N-i-1)! 더하기
		tmpvec[arr[i]-1] = true;	// 방문했다는 표시로 바꾸기
	}
	return ans + 1;
}

void fa() {	//팩토리얼
	fact[0] = 1;
	for (int i = 1; i < 21; i++) {
		fact[i] = fact[i - 1] * i;
	}
}

int main() {
	int n;
	long long k;
	cin >> N >> n;
	fa();	// 정상적으로 입력됨
	if (n == 1) {	//소문제 번호 1
		cin >> k;
		findpermu(k,N);
	}
	else {		//소문제 번호 2
		vector<int> arr(N);
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cout<<permunumber(arr,N);
	}
}