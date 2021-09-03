#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool is_correct(string &s) {
    stack<char> st;
    
    for(size_t i = 0; i < s.length(); i++) {
        if(st.empty() && s[i] == ')') {
            return false;
        }
        else if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')' && st.top() == '(') {
            st.pop();
        }
    }
    
    if(st.empty())
        return true;
    else
        return false;
}

bool solution(string s)
{
    bool answer = true;

    answer = is_correct(s);

    return answer;
}
