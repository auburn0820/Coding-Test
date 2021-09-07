#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cstring>

using namespace std;

set<string> for_unique;
bool *is_visit;

bool is_same_size(string &user_id, string &banned_id) {
    if(user_id.size() == banned_id.size())
        return true;
    else
        return false;
}

bool is_same_type(string &user_id, string &banned_id) {
    size_t length = user_id.size();
    
    for(int i = 0; i < length; i++) {
        if(banned_id[i] == '*')
            continue;
        if(user_id[i] != banned_id[i])
            return false;
    }
    return true;
}

bool is_banned_id(string &user_id, string &banned_id) {
    if(!is_same_size(user_id, banned_id))
        return false;
    if(!is_same_type(user_id, banned_id))
        return false;
    
    return true;
}

void comb(int cur, vector<string> &user_id, vector<string> &banned_id, vector<string> id, int &answer) {
    // 경우의 수를 뽑은 경우
    if(id.size() == banned_id.size()) {
        int banned_id_cnt = 0;
        
        vector<string> temp_id(id.begin(), id.end());
        
        // 제재 당한 아이디와 형식이 일치하는 아이디를 찾음
        for(int i = 0; i < banned_id.size(); i++) {
            for(int j = 0; j < temp_id.size();) {
                if(is_banned_id(temp_id[j], banned_id[i])) {
                    banned_id_cnt++;
                    temp_id.erase(temp_id.begin() + j);
                    break;
                }
                else
                    j++;
            }
        }
        
        temp_id = vector<string>(id.begin(), id.end());
        
        // 제재당한 아이디가 일치하는 경우의 수를 뽑은 경우
        if(banned_id_cnt == banned_id.size()) {
            string key;
            
            // 순열을 통해 뽑기 때문에 같은 경우가 있는지 확인
            for(auto &i : temp_id)
                key += i;
            
            auto it = for_unique.find(key);
            
            // 유일한 경우를 뽑았을 때
            if(it == for_unique.end()) {
                answer++;
                
                sort(temp_id.begin(), temp_id.end());
                
                // 순열을 통해 키 값을 섞은 후, Set에 삽입
                do {
                    key.clear();
                    for(int i = 0; i < temp_id.size(); i++) {
                        key += temp_id[i];
                    }
                    for_unique.insert(key);
                } while(next_permutation(temp_id.begin(), temp_id.end()));
            }
        }
        return;
    }
    
    for(int i = 0; i < (int)user_id.size(); i++) {
        if(is_visit[i])
            continue;
        
        is_visit[i] = true;
        id.push_back(user_id[i]);
        comb(i + 1, user_id, banned_id, id, answer);
        id.pop_back();
        is_visit[i] = false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    vector<string> v;
    is_visit = new bool[user_id.size()];
    memset(is_visit, false, sizeof(bool) * user_id.size());
    
    comb(0, user_id, banned_id, v, answer);
    
    return answer;
}
