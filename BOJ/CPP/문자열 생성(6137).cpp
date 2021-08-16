#include <iostream>
#include <string>

using namespace std;

int N;
string S;

int main(void) {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        char s_char;
        cin >> s_char;
        S.append(1, s_char);
    }

    int idx = 0;
    int first = 0;
    int last = (int)S.size() - 1;
    while(first <= last) {
        if(idx % 80 == 0 && idx != 0)
            cout << '\n';
        
        if(S.at(first) < S.at(last)) {
            cout << S.at(first);
            first++;
        } else if(S.at(first) > S.at(last)){
            cout << S.at(last);
            last--;
        } else {
            bool left = false;
            bool right = false;
            int first_temp = first + 1;
            int last_temp = last - 1;
            
            while(first_temp < last_temp) {
                if(S.at(first_temp) < S.at(last_temp)) {
                    left = true;
                    break;
                } else if(S.at(first_temp) > S.at(last_temp)){
                    right = true;
                    break;
                } else {
                    first_temp++;
                    last_temp--;
                }
            }
            
            if(left) {
                cout << S.at(first);
                first++;
            } else {
                cout << S.at(last);
                last--;
            }
        }
        idx++;
    }
}
