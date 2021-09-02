#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, vector<int>> m;

void split_string(string &info) {
    stringstream ss(info);
    
    string lang, field, career, food, score;
    
    ss >> lang;
    ss >> field;
    ss >> career;
    ss >> food;
    ss >> score;
    
    // cout << lang << ' ' << field << ' ' << career << ' ' << score << '\n';
    
    string key, temp_lang, temp_field, temp_career, temp_food;
    
    for(int i = 0; i < 2; i++) {
        temp_lang = (i == 0) ? lang : "-";
        for(int j = 0; j < 2; j++) {
            temp_field = (j == 0) ? field : "-";
            for(int k = 0; k < 2; k++) {
                temp_career = (k == 0) ? career : "-";
                for(int l = 0; l < 2; l++) {
                    temp_food = (l == 0) ? food : "-";
                    key = temp_lang + temp_field + temp_career + temp_food;
                    m[key].push_back(stoi(score));
                }
            }
        }
    }
}

pair<string, int> parse_query(string &query) {
    for(int i = 0; i < query.length() - 4; i++) {
        if(query.substr(i, 4) == " and") {
            query.erase(i, 4);
            i--;
        }
    }
    
    string lang, field, career, food, score;
    stringstream ss(query);
    
    ss >> lang;
    ss >> field;
    ss >> career;
    ss >> food;
    ss >> score;
    
    return {lang + field + career + food, stoi(score)};
}

vector<int> solution(vector<string> infos, vector<string> queries) {
    vector<int> answer;
    
    for(auto &info : infos) {
        split_string(info);
    }
    
    // 이 위치에서 map의 모든 값을 정렬하면 시간 초과가 발생하지 않음.
    for(auto it = m.begin(); it != m.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }
    
    for(auto &query: queries) {
        pair<string, int> key_score = parse_query(query);
        string key = key_score.first;
        int score = key_score.second;
        
        // m[key]를 이 위치에서 정렬했을 땐, 효율성 테스트에서 시간 초과가 발생함.
        
        if(m[key].empty()) {
            answer.push_back(0);
        }
        else {
            auto i = lower_bound(m[key].begin(), m[key].end(), score) - m[key].begin();
            int people_cnt = m[key].size() - i;
            
            answer.push_back(people_cnt);
        }
    }
    
    return answer;
}
