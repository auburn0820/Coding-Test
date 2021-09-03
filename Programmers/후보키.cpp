#include <string>
#include <vector>
#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_candidate[8] = {false, };
int col_size;
int row_size;
set<string> for_min;

bool is_exist_same_tuple(vector<int> &cases, vector<vector<string>> &relation) {
    set<string> for_key;
    
    for(int i = 0; i < row_size; i++) {
        string key = "";
        for(int j = 0; j < cases.size(); j++) {
            if(j == 0) {
                key += relation[i][cases[j]];
            }
            else {
                key += "|" + relation[i][cases[j]];
            }
        }
            
        set<string>::iterator it = for_key.find(key);
            
        if(it == for_key.end()) {
            for_key.insert(key);
        }
        else {
            return false;
        }
    }
    return true;
}

bool is_min_key(vector<int> &cases, string &key) {
    string key_temp(key.begin(), key.end());
            
    sort(key_temp.begin(), key_temp.end());
            
    do {
        string key_for_check;
        for(int i = 0; i < key_temp.size(); i++) {
            key_for_check += key_temp[i];
            set<string>::iterator it = for_min.find(key_for_check);
                    
            if(it != for_min.end()) {
                return false;
            }
        }
    } while(next_permutation(key_temp.begin(), key_temp.end()));
    
    return true;
}

void combination(int idx, int size, vector<int> &cases, vector<vector<string>> &relation) {
    if(cases.size() == size) {
        bool is_unique = is_exist_same_tuple(cases, relation);
        
        if(is_unique) {
            string key;
            
            for(int i = 0; i < cases.size(); i++) {
                key += cases[i] + '0';
            }
            
            bool is_min = is_min_key(cases, key);
            
            if(is_min) {
                for_min.insert(key);
            }
        }
    }
    
    for(int i = idx; i < col_size; i++) {
        if(is_candidate[i])
            continue;
        cases.push_back(i);
        combination(i + 1, size, cases, relation);
        cases.pop_back();
    }
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    col_size = relation[0].size();
    row_size = relation.size();
    
    vector<int> cases;
    for(int i = 1; i <= col_size; i++) {
        combination(0, i, cases, relation);
    }
    
    answer = for_min.size();
    
    return answer;
}
