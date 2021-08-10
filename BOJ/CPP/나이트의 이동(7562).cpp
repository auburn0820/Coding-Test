#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool visit[300][300];
int length;
pair<int, int> start_point;
pair<int, int> end_point;

int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

struct NightLocInfo {
    int x, y, cnt;
};

void find_min_path() {
    queue<NightLocInfo> q;
    
    q.push({start_point.first, start_point.second, 0});
    visit[q.front().y][q.front().x] = true;
    
    while(!q.empty()) {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_cnt = q.front().cnt;
        
        q.pop();
        
        if(cur_x == end_point.first && cur_y == end_point.second) {
            cout << cur_cnt << '\n';
            return;
        }
        
        for(int i = 0; i < 8; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            if(next_x < 0 || next_y < 0 || next_x >= length || next_y >= length)
                continue;
            if(visit[next_y][next_x])
                continue;
            
            q.push({next_x, next_y, cur_cnt + 1});
            visit[next_y][next_x] = true;
        }
    }
}

int main(void) {
    int t;
    cin >> t;
    
    while(t--) {
        cin >> length;
        
        int start_x, start_y, end_x, end_y;
        cin >> start_x >> start_y >> end_x >> end_y;
        
        start_point = {start_x, start_y};
        end_point = {end_x, end_y};
        
        find_min_path();
        
        memset(visit, false, sizeof(visit));
    }
}
