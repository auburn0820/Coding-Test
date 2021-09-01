#include <string>
#include <vector>
#include <stack>

using namespace std;

bool is_correct_string(string &u) {
    stack<char> st;
    
    for(int i = 0; i < u.length(); i++) {
        if(u[i] == '(') {
            st.push(u[i]);
        }
        else if(st.empty() && u[i] == ')') {
            return false;
        }
        else if(st.top() == '(' && u[i] == ')') {
            st.pop();
        }
    }
    
    if(st.empty())
        return true;
    else
        return false;
}

string convert(string &p) {
    // p가 빈 문자열일 경우
    if(p.empty())
        return "";
    
    string u = "";
    string v = "";
    
    // 균형잡힌 괄호 문자열을 찾는다.
    int idx = 0;
    int open_cnt = 0;
    int close_cnt = 0;
    for(int i = 0; i < p.length(); i++) {
        if(p[i] == '(')
            open_cnt++;
        else
            close_cnt++;
        
        if(i % 2 == 1 && open_cnt == close_cnt) {
            idx = i + 1;
            break;
        }
    }
    
    // u와 v를 분리한다.
    u = p.substr(0, idx);
    p.erase(p.begin(), p.begin() + idx);
    v = p;
    
    // u가 올바른 괄호 문자열인지 판단.
    if(is_correct_string(u)) {
        u += convert(v);
        
        return u;
    }
    else {
        string temp = "(";
        temp += convert(v);
        temp += ")";
        u.erase(u.begin(), u.begin() + 1);
        u.pop_back();
        
        for(int i = 0; i < u.length(); i++) {
            if(u[i] == '(')
                u[i] = ')';
            else
                u[i] = '(';
        }
        
        temp += u;
        
        return temp;
    }
}

string solution(string p) {
    string answer = "";
    
    answer = convert(p);
    
    return answer;
}
