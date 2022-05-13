#include <iostream>
using namespace std;

struct node {
	int data;
	node* prev;
	node* next;
};

class nodeList {
private:
	node* header;
	node* trailer;
	int n;
public:
	nodeList() {
		header = new node();
		trailer = new node();
		header->next = trailer;
		trailer->prev = header;
		header->prev = trailer->next = NULL;
		n = 0;
	}
	node* begin() {
		return header->next;
	}

	node* end() {
		return trailer;
	}

	void insert(node* pos, int data) {
		node* newNode = new node();
		newNode->data = data;
		newNode->prev = pos->prev;
		newNode->next = pos;
		pos->prev->next = newNode;
		pos->prev = newNode;
		n++;
	}

	void insertFront(int data) {
		insert(begin(), data);
	}

	void insertBack(int data) {
		insert(end(), data);
	}

	int sum(int x, int month) {
		int ans = x;
		node* newNode = new node();
		newNode->prev = begin()->prev;
		newNode->next = begin();
		for (int i = 0; i < month; i++) {
			ans += newNode->next->data;
			newNode->next = newNode->next->next;
		}
		return ans;
		delete newNode;
	}
};

int main() {
	nodeList month;	//�� ���� ����
	node* p = month.begin();
	month.insertBack(31);
	month.insertBack(28);
	month.insertBack(31);
	month.insertBack(30);
	month.insertBack(31);
	month.insertBack(30);
	month.insertBack(31);
	month.insertBack(31);
	month.insertBack(30);
	month.insertBack(31);
	month.insertBack(30);
	month.insertBack(31);
	int x, y;
	cin >> x >> y;
	int days=month.sum(y, x - 1);
	switch (days % 7) {
		//1��1��=> ������ , 7�� ���ϸ� �Ͽ����̹Ƿ� days%7�� ��¥ ����
	case 0:
		cout << "SUN";
		break;
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	}
}