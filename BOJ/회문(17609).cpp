#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string &s) {
    int start = 0;
    int end = (int)s.length() - 1;
    
    while(start < end) {
        if(s[start] != s[end])
            return false;
        
        start++;
        end--;
    }
    
    return true;
}

bool can_palindrome_left(string& s) {
    int idx = 0;
    int reverse_idx = (int)s.length() - 1;
    int remove_cnt = 0;
    
    while(idx < reverse_idx) {
        if(s[idx] != s[reverse_idx]) {
            remove_cnt++;
            idx++;
            continue;
        }
        
        if(remove_cnt > 1)
            return false;
        
        idx++;
        reverse_idx--;
    }
    
    return true;
}

bool can_palindrome_right(string &s) {
    int idx = 0;
    int reverse_idx = (int)s.length() - 1;
    int remove_cnt = 0;
    
    while(idx < reverse_idx) {
        if(s[idx] != s[reverse_idx]) {
            remove_cnt++;
            reverse_idx--;
            continue;
        }
        
        if(remove_cnt > 1)
            return false;
        
        idx++;
        reverse_idx--;
    }
    
    return true;
}

int main(void) {
    int T;
    cin >> T;
    
    while(T--) {
        string s;
        cin >> s;
        
        if(is_palindrome(s))
            cout << 0 << '\n';
        else if(can_palindrome_left(s) || can_palindrome_right(s))
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }
}
