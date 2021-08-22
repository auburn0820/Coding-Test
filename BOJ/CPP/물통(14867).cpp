#include <iostream>
#include <queue>
#include <map>

using namespace std;

int a_max, b_max, a_des, b_des;
map<pair<int, int>, int> is_visit;

pair<int, int> process_operation(int idx, int a, int b) {
    if(idx == 1) {
        a = a_max;
    }
    else if(idx == 2) {
        a = 0;
    }
    else if(idx == 3) {
        if(a == b_max - b) {
            a = 0;
            b = b_max;
        }
        else if(a > b_max - b) {
            a -= (b_max - b);
            b = b_max;
        }
        else if(a < b_max - b) {
            b += a;
            a = 0;
        }
    }
    else if(idx == 4) {
        b = b_max;
    }
    else if(idx == 5) {
        b = 0;
    }
    else if(idx == 6) {
        if(b == a_max - a) {
            b = 0;
            a = a_max;
        }
        else if(b > a_max - a) {
            b -= (a_max - a);
            a = a_max;
        }
        else if(b < a_max - a) {
            a += b;
            b = 0;
        }
    }
    
    return {a, b};
}

int count_min_time() {
    queue<pair<int, int>> q;
    
    q.push(make_pair(0, 0));
    is_visit[make_pair(0, 0)] = 0;
    
    while(!q.empty()) {
        int cur_a = q.front().first;
        int cur_b = q.front().second;
        int cur_cnt = is_visit[make_pair(cur_a, cur_b)];
        
        q.pop();
        
        if(cur_a == a_des && cur_b == b_des) {
            return cur_cnt;
        }
        
        for(int i = 1; i <= 6; i++) {
            pair<int, int> next = process_operation(i, cur_a, cur_b);
            
            int next_a = next.first;
            int next_b = next.second;
            
            if(is_visit[make_pair(next_a, next_b)] > 0)
                continue;
            
            q.push({next_a, next_b});
            is_visit[make_pair(next_a, next_b)] = cur_cnt + 1;
        }
    }
    
    return -1;
}

int main(void) {
    cin >> a_max >> b_max >> a_des >> b_des;
    
    cout << count_min_time() << '\n';
}
