#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string parenthesis;
    cin >> parenthesis;
    
    stack<char> st;
    
    int temp = 1;
    int answer = 0;
    
    for(int i = 0; i < parenthesis.size(); i++) {
        if(parenthesis[i] == '(') {
            temp *= 2;
            st.push('(');
        }
        else if(parenthesis[i] == '[') {
            temp *= 3;
            st.push('[');
        }
        else if(parenthesis[i] == ')') {
            if(st.empty() || (st.top() != '(')) {
                cout << 0 << '\n';
                return 0;
            }
            
            if(parenthesis[i - 1] == '(')
                answer += temp;
            temp /= 2;
            st.pop();
        }
        else if(parenthesis[i] == ']') {
            if(st.empty() || (st.top() != '[')) {
                cout << 0 << '\n';
                return 0;
            }
            
            if(parenthesis[i - 1] == '[')
                answer += temp;
            temp /= 3;
            st.pop();
        }
    }
    
    if(!st.empty())
        answer = 0;
    cout << answer << '\n';
}
