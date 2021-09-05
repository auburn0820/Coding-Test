#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int parse_timetable(string &str) {
    string hour = str.substr(0, 2);
    string min = str.substr(3, 2);
    
    return stoi(hour) * 60 + stoi(min);
}

string time_to_str(int &time) {
    int hour = time / 60;
    int min = time % 60;
    
    string hour_string;
    string min_string;
    
    // 시간 파싱
    if(hour <= 9)
        hour_string = "0" + to_string(hour);
    else
        hour_string = to_string(hour);
    
    // 분 파싱
    if(min <= 9)
        min_string = "0" + to_string(min);
    else
        min_string = to_string(min);
    
    return hour_string + ":" + min_string;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> buses(n);
    vector<vector<int>> people_in_bus(n);
    vector<int> people;
    
    // 시간 단위를 분 단위로 변환
    for(int i = 0; i < timetable.size(); i++)
        people.push_back(parse_timetable(timetable[i]));
    
    // 버스 시간표 Set
    for(int idx = 0, i = 540; i <= 540 + (n - 1) * t; i += t, idx++) {
        buses[idx] = i;
    }
    
    // 변환한 타임 테이블 정렬
    sort(people.begin(), people.end());
    
    int m_cnt = 0;
    
    // 타임 테이블에 맞게 버스 배치
    for(int i = 0, bus_cnt = 0; i < people.size() && bus_cnt < n;) {
        if(people[i] <= buses[bus_cnt]) {
            people_in_bus[bus_cnt].push_back(people[i]);
            i++;
            m_cnt++;
            
            if(m_cnt == m) {
                m_cnt = 0;
                bus_cnt++;
            }
        }
        else if(people[i] > buses[bus_cnt]) {
            m_cnt = 0;
            bus_cnt++;
        }
    }
    
    int time;
    
    if(people_in_bus.back().size() == m) {
        time = people_in_bus.back().back() - 1;
    }
    else if(people_in_bus.back().size() < m) {
        time = buses.back();
    }
    
    answer = time_to_str(time);
    
    return answer;
}
