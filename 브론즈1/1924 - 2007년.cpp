#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int d_in_m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    //�� �������� ��¥ ����
    int d = 0;
    d += y;  //x���� ��¥ ����
    for (int i = 0; i < (x - 1); i++) {     
        //x-1�������� ��¥�� ����
        d += d_in_m[i];     
        //n-1���� �׸񿡼� 2���� ������� �ð����⵵ O(2n)=>O(n)
    }
    switch (d % 7) {     
        //1��1��=> ������ , 7�� ���ϸ� �Ͽ����̹Ƿ� d%7�� ��¥ ����
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