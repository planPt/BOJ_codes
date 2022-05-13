#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int d_in_m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    //각 월마다의 날짜 저장
    int d = 0;
    d += y;  //x월의 날짜 저장
    for (int i = 0; i < (x - 1); i++) {     
        //x-1월까지의 날짜를 더함
        d += d_in_m[i];     
        //n-1개의 항목에서 2번씩 연산수행 시간복잡도 O(2n)=>O(n)
    }
    switch (d % 7) {     
        //1월1일=> 월요일 , 7일 더하면 일요일이므로 d%7이 날짜 결정
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