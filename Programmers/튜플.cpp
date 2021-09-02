#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> return_vector;

vector<vector<int>> split_string(string &s) {
    for(int i = 1; i < s.length(); i++) {
        if(s[i - 1] == '}' && s[i] == ',') {
            s[i] = ' ';
        }
    }
    
    vector<string> v;
    
    stringstream ss(s);
    string data;
    while(getline(ss, data, ' ')) {
        for(int i = 0; i < data.size(); i++) {
            if(data[i] == '{' || data[i] == '}') {
                data.erase(data.begin() + i);
                i--;
            }
            else if(data[i] == ',') {
                data[i] = ' ';
            }
        }
        
        v.push_back(data);
    }
    
    sort(v.begin(), v.end(), [](string &a, string &b) {
        return a.size() < b.size();
    });
    
    vector<vector<int>> ret_vector;
    ret_vector.resize(v.size());
    
    for(int i = 0; i < v.size(); i++) {
        stringstream ss(v[i]);
        string data;
        while(getline(ss, data, ' ')) {
            ret_vector[i].push_back(stoi(data));
        }
    }
    
    return ret_vector;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> numbers;
    numbers = split_string(s);
    
    set<int> sets;
    
    set<int>::iterator it;
    for(int i = 0; i < numbers.size(); i++) {
        for(int j = 0; j < numbers[i].size(); j++) {
            it = sets.find(numbers[i][j]);
            if(it == sets.end()) {
                sets.insert(numbers[i][j]);
                answer.push_back(numbers[i][j]);
            }
        }
    }
    
    return answer;
}
