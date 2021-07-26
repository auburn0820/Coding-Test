#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

#define WALL -1
#define SLEEPING_VIRUS -2

int N, M;
int lab[50][50];
int copied_lab[50][50];
bool visit[50][50];
vector<pair<int, int>> virus_loc;
vector<pair<int, int>> activated_virus_loc;
int min_result = INT_MAX;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

struct ActivatedVirusLocInfo {
    int x, y, cnt;
};

void copy_lab() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(lab[i][j] == 1)
                copied_lab[i][j] = WALL;
            else if(lab[i][j] == 2)
                copied_lab[i][j] = SLEEPING_VIRUS;
            else
                copied_lab[i][j] = 0;
        }
    }
}

int find_max_value() {
    int max_value = -1;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visit[i][j])
                return -1;
            else if(0 <= copied_lab[i][j])
                max_value = max(copied_lab[i][j], max_value);
        }
    }
    
    return max_value;
}

void set_visit() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(copied_lab[i][j] == WALL)
                visit[i][j] = true;
            else
                visit[i][j] = false;
        }
    }
}

void spread_virus() {
    copy_lab();
    set_visit();
    queue<ActivatedVirusLocInfo> q;
    
    for(auto &i : activated_virus_loc) {
        q.push({i.first, i.second, 0});
        copied_lab[i.second][i.first] = 0;
        visit[i.second][i.first] = true;
    }
    
    while(!q.empty()) {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_cnt = q.front().cnt;
        
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= N)
                continue;
            if(visit[next_y][next_x])
                continue;
            if(copied_lab[next_y][next_x] == SLEEPING_VIRUS)
                copied_lab[next_y][next_x] = 0;
            else if(copied_lab[next_y][next_x] == 0)
                copied_lab[next_y][next_x] = cur_cnt + 1;
            
            q.push({next_x, next_y, cur_cnt + 1});
            visit[next_y][next_x] = true;
        }
    }
}

void comb_activation_virus(int idx, int cnt) {
    if(cnt == M) {
        spread_virus();
        int result = find_max_value();
        
        if(result != -1)
            min_result = min(result, min_result);
        return;
    }
    
    for(int i = idx; i < (int)virus_loc.size(); i++) {
        activated_virus_loc.push_back(virus_loc[i]);
        comb_activation_virus(i + 1, cnt + 1);
        activated_virus_loc.pop_back();
    }
}

int main(void) {
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> lab[i][j];
            
            if(lab[i][j] == 2)
                virus_loc.push_back({j, i});
        }
    }
    
    comb_activation_virus(0, 0);
    
    if(min_result == INT_MAX)
        min_result = -1;
    
    cout << min_result << '\n';
}
