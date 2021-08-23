#include <iostream>
#include <algorithm>

using namespace std;

int N;
string pattern;

int main(void) {
    cin >> N;
    cin >> pattern;
    
    string left = "";
    string right = "";
    int i = 0;
    for(; pattern[i] != '*'; i++)
        left += pattern[i];
    
    i++;
    
    for(; i < (int)pattern.length(); i++)
        right += pattern[i];
    
    reverse(right.begin(), right.end());
    
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        
        if(str.substr(0, (int)left.length()) == left) {
            str = str.substr((int)left.length(), (int)str.length());
            reverse(str.begin(), str.end());
            
            if(str.substr(0, (int)right.length()) == right) {
                cout << "DA\n";
                continue;
            }
        }
        
        cout << "NE\n";
    }
}
