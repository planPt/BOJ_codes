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
	node* header;	//header��� ������
	node* trailer;	//trailer��� ������
	int n;		//����Ʈ�� ����� ������ ����
public:
	nodeList() {	//�⺻ ������
		header = new node();	
		trailer = new node();
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
		n = 0;
	}

	node* begin() {		//ù��° ����(header�� ���� ���)�� �ּ� ��ȯ
		return header->next;
	}

	node* end() {	//����Ʈ�� ������ ������ ����(trailer)�ּҸ� ��ȯ
		return trailer;
	}

	void insert(node* pos, char data) {	//pos�տ� data ����
		node* newNode = new node();
		newNode->data = data;
		newNode->prev = pos->prev;
		newNode->next = pos;
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}

	void insertBack(char data) {	//�������� data ����
		insert(end(), data);		//trailer ������ ����
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
	//���� Ŀ���� list�� �ڿ� ��ġ��
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