#include <string>
#include <vector>
#include <set>
#include <stack>

using namespace std;

set<int> s;
stack<int> st;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    
    for(int i = 0; i < n; i++) {
        s.insert(i);
    }
    
    auto cur_position = s.find(k);
    for(int i = 0; i < cmd.size(); i++) {
        char ch = cmd[i][0];
        
        if(ch == 'U') {
            int num = stoi(cmd[i].substr(2));
            while(num--)
                cur_position = prev(cur_position);
        }
        else if(ch == 'D') {
            int num = stoi(cmd[i].substr(2));
            while(num--)
                cur_position = next(cur_position);
        }
        else if(ch == 'C') {
            st.push(*cur_position);
            cur_position = s.erase(cur_position);
            if(cur_position == s.end())
                cur_position = prev(cur_position);
        }
        else if(ch == 'Z') {
            s.insert(st.top());
            st.pop();
        }
    }
    
    for(int i = 0; i < n; i++) {
        answer += 'X';
    }
    
    for(auto &i : s) {
        answer[i] = 'O';
    }
    
    return answer;
}
