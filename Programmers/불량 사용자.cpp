#include <string>
#include <vector>
#include <set>
#include <bitset>
#include <iostream>

using namespace std;

bool is_visit[10] = {false, };
set<int> s;

bool is_banned_user(const string &user_id, const string &banned_id) {
    if(user_id.size() != banned_id.size())
        return false;
    for(size_t i = 0; i < user_id.size(); i++) {
        if(user_id[i] != banned_id[i] && banned_id[i] != '*')
            return false;
    }
    return true;
}

void combination(size_t idx, vector<string> &user_id, vector<string> &banned_id, int &answer) {
    if(idx == banned_id.size()) {
        
        int key = 0;
        
        for(size_t i = 0; i < user_id.size(); i++) {
            if(is_visit[i]) {
                key <<= 1;
                key += 1;
            }
            else {
                key <<= 1;
                key += 0;
            }
        }
        
        auto it = s.find(key);
        
        if(it == s.end()) {
            answer++;
            s.insert(key);
        }
        
        return;
    }
    
    for(size_t i = 0; i < user_id.size(); i++) {
        if(is_visit[i] || !is_banned_user(user_id[i], banned_id[idx]))
            continue;
        
        is_visit[i] = true;
        combination(idx + 1, user_id, banned_id, answer);
        is_visit[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    combination(0, user_id, banned_id, answer);
    return answer;
}
