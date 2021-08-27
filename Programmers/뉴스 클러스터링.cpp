#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void to_lower(string &str) {
    for(int i = 0; i < (int)str.length(); i++) {
        str[i] = tolower(str[i]);
    }
}

bool is_char(char ch) {
    if(ch >= 'a' && ch <= 'z')
        return true;
    else
        return false;
}

vector<string> parse_two_elements(string &str) {
    int size = (int)str.length();
    vector<string> v;
    
    for(int i = 0; i < size - 1; i++) {
        if(is_char(str[i]) && is_char(str[i + 1])) {
            v.push_back(str.substr(i, 2));
        }
    }
    
    return v;
}

int count_intersection(vector<string> &v1, vector<string> &v2) {
    int ans = 0;
    
    for(int i = 0; i < (int)v1.size(); i++) {
        for(int j = 0; j < (int)v2.size(); j++) {
            if(v1[i] == v2[j]) {
                ans++;
                v2[j] = " ";
                break;
            }
        }
    }
    
    return ans;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    to_lower(str1);
    to_lower(str2);
    
    vector<string> v1 = parse_two_elements(str1);
    vector<string> v2 = parse_two_elements(str2);
    
    double intersection_cnt = count_intersection(v1, v2);
    double union_cnt = (int)v1.size() + (int)v2.size() - intersection_cnt;
    
    if(union_cnt == 0)
        answer = 65536;
    else
        answer = (intersection_cnt / union_cnt) * 65536;
    
    return answer;
}
