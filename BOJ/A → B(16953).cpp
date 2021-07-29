#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    
    int cnt = 0;
    
    while(true) {
        if(a == b)
            break;
        else if(b < a) {
            cnt = -2;
            break;
        }
        
        // 짝수일 경우
        if(b % 2 == 0)
            b /= 2;
        // 일의 자리수가 1일 경우
        else if(b % 10 == 1)
            b /= 10;
        // 홀수이며, 일의 자리수가 1이 아닐 경우
        else {
            cnt = -2;
            break;
        }
        cnt++;
    }
    
    cout << cnt + 1 << '\n';
}
