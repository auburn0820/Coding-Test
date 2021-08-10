#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int W, H;
char map[100][100];
int visit[100][100];
pair<int, int> start_point = {-1, -1};
pair<int, int> end_point = {-1, -1};
int min_mirror_count = INT_MAX;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

struct LaserLocInfo {
    int x, y, mirror_cnt, prev_dir;
};

void set_visit_arr() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            visit[i][j] = INT_MAX;
        }
    }
}

void count_needed_mirror() {
    set_visit_arr();
    
    queue<LaserLocInfo> q;
    
    q.push({start_point.first, start_point.second, 0, -1});
    visit[start_point.second][start_point.first] = 0;
    
    while(!q.empty()) {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_mirror_cnt = q.front().mirror_cnt;
        int cur_dir = q.front().prev_dir;
        
        q.pop();
        
        if(cur_x == end_point.first && cur_y == end_point.second) {
            min_mirror_count = min(min_mirror_count, cur_mirror_cnt);
        }
        
        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            int next_mirror_cnt = cur_mirror_cnt;
            int next_dir = i;
            
            if(cur_dir != -1 && cur_dir != next_dir)
                next_mirror_cnt++;
            if(next_x < 0 || next_y < 0 || next_x >= W || next_y >= H)
                continue;
            if(visit[next_y][next_x] < next_mirror_cnt)
                continue;
            if(map[next_y][next_x] == '*')
                continue;
            
            q.push({next_x, next_y, next_mirror_cnt, next_dir});
            visit[next_y][next_x] = next_mirror_cnt;
        }
    }
}

int main(void) {
    cin >> W >> H;
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> map[i][j];
            
            if(map[i][j] == 'C') {
                if(start_point.first == -1 && start_point.second == -1) {
                    start_point = {j, i};
                    continue;
                }
                
                if(end_point.first == -1 && end_point.second == -1) {
                    end_point = {j, i};
                    continue;
                }
            }
        }
    }
    
    count_needed_mirror();
    cout << min_mirror_count << '\n';
}
