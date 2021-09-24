#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    string s;
    cin >> s;
    
    bool is_correct = true;
    
    for(int i = 0; i < s.length();) {
        if(s[i] == 'p') {
            if(s.substr(i, 2) != "pi") {
                is_correct = false;
                break;
            }
            else
                i = i + 2;
        }
        else if(s[i] == 'k') {
            if(s.substr(i, 2) != "ka") {
                is_correct = false;
                break;
            }
            else
                i = i + 2;
        }
        else if(s[i] == 'c') {
            if(s.substr(i, 3) != "chu") {
                is_correct = false;
                break;
            }
            else
                i = i + 3;
        }
        else {
            is_correct = false;
            break;
        }
    }
    
    if(is_correct)
        cout << "YES\n";
    else
        cout << "NO\n";
}
