#include <iostream>
#include <string>
using namespace std;

struct node {
	char data;
	node* prev;
	node* next;
};

class nodeList {
private:
	node* header;	//header노드 포인터
	node* trailer;	//trailer노드 포인터
	int n;		//리스트에 저장된 원소의 개수
public:
	nodeList() {	//기본 생성자
		header = new node();	
		trailer = new node();
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
		n = 0;
	}

	node* begin() {		//첫번째 원소(header의 다음 노드)의 주소 반환
		return header->next;
	}

	node* end() {	//리스트의 마지막 원소의 다음(trailer)주소를 반환
		return trailer;
	}

	void insert(node* pos, char data) {	//pos앞에 data 합입
		node* newNode = new node();
		newNode->data = data;
		newNode->prev = pos->prev;
		newNode->next = pos;
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}

	void insertBack(char data) {	//마지막에 data 삽입
		insert(end(), data);		//trailer 이전에 삽입
	}

	void erase(node* pos) {
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		delete pos;
		n--;
	}

	void eraseFront() {
		erase(begin());
	}

	void eraseBack() {
		erase(end()->prev);
	}

	void print() {
		node* newNode = new node();
		newNode->prev = begin()->prev;
		newNode->next = begin();
		for (int i = 0; i < n; i++) {
			cout << newNode->next->data;
			newNode->next = newNode->next->next;
		}
		cout << endl;
		delete newNode;
	}
};

int main() {
	nodeList list;
	node* cursor = list.end();

	string N;
	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < N.length(); i++) {
		list.insertBack(N[i]);
	}
	//현재 커서는 list맨 뒤에 위치함
	char cur, tmp;
	for (int i = 0; i < M; i++) {
		cin >> cur;
		if (cur == 'L') {
			if (cursor != list.begin()) {
				cursor = cursor->prev;
			}
		}
		else if (cur == 'D') {
			if (cursor != list.end()) {
				cursor = cursor->next;
			}
		}
		else if (cur == 'B') {
			if (cursor != list.begin()) {
				list.erase(cursor->prev);
			}
		}
		else if (cur == 'P') {
			cin >> tmp;
			list.insert(cursor, tmp);
		}
	}
	list.print();
}