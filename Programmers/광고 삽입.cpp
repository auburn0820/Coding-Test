#include <string>
#include <vector>
#include <iostream>

using namespace std;

int ad[360000] = {0, };

int to_sec(string time) {
    string hour = time.substr(0, 2);
    string min = time.substr(3, 2);
    string sec = time.substr(6, 2);
    
    return stoi(hour) * 3600 + stoi(min) * 60 + stoi(sec);
}

string make_answer(int time) {
    string hour;
    string min;
    string sec;
    
    if(time / 3600 < 10)
        hour = "0" + to_string(time / 3600);
    else
        hour = to_string(time / 3600);
    time %= 3600;
    if(time / 60 < 10)
        min = "0" + to_string(time / 60);
    else
        min = to_string(time / 60);
    time %= 60;
    if(time < 10)
        sec = "0" + to_string(time);
    else
        sec = to_string(time);
    
    return hour + ":" + min + ":" + sec;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    int n = logs.size();
    
    for(int i = 0; i < n; i++) {
        int start = to_sec(logs[i].substr(0, 8));
        int end = to_sec(logs[i].substr(9, 8));
        
        for(int j = start; j < end; j++)
            ad[j]++;
    }
    
    int play_len = to_sec(play_time);
    int adv_len = to_sec(adv_time);
    long long max_cnt = 0;
    long long cnt = 0;
    int max_idx = 0;
    // cout << play_len << ' ' << adv_len << '\n';
    
    for(int i = 0; i < adv_len; i++) {
        max_cnt += ad[i];
    }
    
    cnt = max_cnt;
    
    int left = 0, right = adv_len - 1;
    
    for(int i = adv_len; i < play_len; i++) {
        cnt -= ad[left++];
        cnt += ad[++right];
        
        if(cnt > max_cnt) {
            max_cnt = cnt;
            max_idx = i - adv_len + 1;
        }
    }
    
    answer = make_answer(max_idx);
    
    return answer;
}
