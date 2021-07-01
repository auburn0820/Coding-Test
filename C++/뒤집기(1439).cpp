#include <iostream>

using namespace std;

int getCountOfNumber(string &s, int num) {
    int cnt = 0;
    bool isFirst = true;
    for(int i = 0; i < (int)s.length(); i++) {
        if(s[i] == (char)(num + '0')) {
            if(isFirst == true) {
                cnt++;
                isFirst = false;
            }
        } else
            isFirst = true;
    }
    
    return cnt;
}

int main(void) {
    string s;
    cin >> s;
    
    int zeroCnt = getCountOfNumber(s, 0);
    int oneCnt = getCountOfNumber(s, 1);
    
    if(zeroCnt < oneCnt)
        cout << zeroCnt << '\n';
    else
        cout << oneCnt << '\n';
}
