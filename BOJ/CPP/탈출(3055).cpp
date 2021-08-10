#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct HedgehogLocInfo {
    int x, y, cnt;
};

int R, C;
char maps[50][50];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
vector<pair<int, int>> waters;
queue<HedgehogLocInfo> q;

void water_bfs() {
    queue<pair<int, int>> q;
    
    for(auto &i : waters) {
        q.push({i.first, i.second});
    }
    
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            if(next_x < 0 || next_y < 0 || next_x >= C || next_y >= R)
                continue;
            if(maps[next_y][next_x] != '.')
                continue;
            
            waters.push_back({next_x, next_y});
            maps[next_y][next_x] = '*';
        }
    }
}

int hedgehog_bfs() {
    int size = (int)q.size();
    while(size--) {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_cnt = q.front().cnt;
        
        q.pop();
        
        if(maps[cur_y][cur_x] == 'D') {
            return cur_cnt;
        }
        
        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            if(next_x < 0 || next_y < 0 || next_x >= C || next_y >= R)
                continue;
            if(maps[next_y][next_x] == '*' || maps[next_y][next_x] == 'X' || maps[next_y][next_x] == 'S')
                continue;
            
            q.push({next_x, next_y, cur_cnt + 1});
            if(maps[next_y][next_x] != 'D') {
                maps[next_y][next_x] = 'S';
            }
        }
    }
    
    return -1;
}

int main(void) {
    cin >> R >> C;
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> maps[i][j];
            
            if(maps[i][j] == 'S')
                q.push({j, i, 0});
            else if(maps[i][j] == '*')
                waters.push_back({j, i});
        }
    }
    
    while(true) {
        water_bfs();
        
        int result = hedgehog_bfs();
        
        if(result != -1) {
            cout << result << '\n';
            break;
        }
        
        if(q.empty()) {
            cout << "KAKTUS\n";
            break;
        }
    }
}
