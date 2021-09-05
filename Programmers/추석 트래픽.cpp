#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

pair<double, double> parse_string(string &line) {
    line.pop_back();
    string time = line.substr(11, 12);
    string process_time = line.substr(24, 5);
    
    double response_complete_time = (stod(time.substr(0, 2)) * 3600)
        + (stod(time.substr(3, 2)) * 60)
        + (stod(time.substr(6, 2))) + (stod(time.substr(9)) / 1000.0);
    double response_time = stod(line.substr(24));
    
    return {response_complete_time - response_time + 0.001, response_complete_time};
}

int solution(vector<string> lines) {
    int answer = 1;
    vector<pair<double, double>> traffics;
    
    for(auto &line : lines) {
        pair<double, double> time = parse_string(line);
        traffics.push_back(time);
    }
    
    for(int i = 0; i < traffics.size(); i++) {
        double start = traffics[i].first;
        double end = traffics[i].second;
        int cnt = 1;
        
        for(int j = i + 1; j < traffics.size(); j++) {
            if(start + 1 >= traffics[j].first || end + 1 > traffics[j].first)
                cnt++;
        }
        
        answer = max(cnt, answer);
    }
    
    return answer;
}
