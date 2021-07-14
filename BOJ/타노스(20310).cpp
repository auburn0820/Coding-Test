#include <iostream>

using namespace std;

int get_count_to_remove_num(char num, string &s) {
    int cnt = 0;
    for(int i = 0; i < (int)s.length(); i++) {
        if(s[i] == num)
            cnt++;
    }
    
    return cnt / 2;
}

int main(void) {
    string s;
    cin >> s;
    
    int zero_cnt_to_remove = get_count_to_remove_num('0', s);
    int one_cnt_to_remove = get_count_to_remove_num('1', s);
    int zero_cnt = 0;
    int one_cnt = 0;
    
    for(int i = (int)s.length() - 1; i >= 0; i--) {
        if(zero_cnt < zero_cnt_to_remove && s[i] == '0') {
            s[i] = ' ';
            zero_cnt++;
        }
    }
    
    for(int i = 0; i < (int)s.length(); i++) {
        if(one_cnt < one_cnt_to_remove && s[i] == '1') {
            s[i] = ' ';
            one_cnt++;
        }
    }
    
    for(int i = 0; i < (int)s.length(); i++) {
        if(s[i] != ' ')
            cout << s[i];
    }
    cout << '\n';
}
