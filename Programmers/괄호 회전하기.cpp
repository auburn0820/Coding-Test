#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string rotate_str(string &s, int x) {
    string s_temp(s.begin(), s.end());
    
    for(int i = 0; i < x; i++) {
        char temp = s_temp.front();
        for(int j = 0; j < s.length() - 1; j++)
        s_temp[j] = s_temp[j + 1];
        s_temp[s.length() - 1] = temp;
    }
    
    return s_temp;
}

bool is_correct_str(string &s) {
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else if(st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')) {
            return false;
        }
        else if((st.top() == '(' && s[i] == ')')
                || (st.top() == '{' && s[i] == '}')
                || (st.top() == '[' && s[i] == ']')) {
            st.pop();
        }
    }
    
    if(st.empty())
        return true;
    else
        return false;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.length(); i++) {
        string s_temp = rotate_str(s, i);
        if(is_correct_str(s_temp))
            answer++;
    }
    
    return answer;
}
