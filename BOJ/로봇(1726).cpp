#include <iostream>
#include <queue>

using namespace std;

struct LocationInfo {
    int x, y, dir, cnt;
};

int N, M;
int dx[] = {0, 1, -1, 0, 0}, dy[] = {0, 0, 0, 1, -1};
int factory[101][101];
int visit[101][101][5];
int start_x, start_y, start_dir;
int end_x, end_y, end_dir;

void find_min_cmd_path() {
    queue<LocationInfo> q;
    
    q.push({start_x, start_y, start_dir, 0});
    visit[start_y][start_x][start_dir] = true;
    
    while(!q.empty()) {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_dir = q.front().dir;
        int cur_cnt = q.front().cnt;
        
        q.pop();
        
        if(cur_x == end_x && cur_y == end_y && cur_dir == end_dir) {
            cout << cur_cnt << '\n';
            return;
        }
        
        for(int i = 1; i <= 3; i++) {
            int next_x = cur_x + dx[cur_dir] * i;
            int next_y = cur_y + dy[cur_dir] * i;
            
            if(next_x < 1 || next_y < 1 || next_x > M || next_y > N)
                break;
            if(factory[next_y][next_x] == 1)
                break;
            if(visit[next_y][next_x][cur_dir])
                continue;
            
            visit[next_y][next_x][cur_dir] = true;
            q.push({next_x, next_y, cur_dir, cur_cnt + 1});
        }
        
        for(int i = 1; i <= 4; i++) {
            if(cur_dir == i)
                continue;
            if(visit[cur_y][cur_x][i])
                continue;
    
            if((cur_dir == 1 && i == 2) || (cur_dir == 2 && i == 1) || (cur_dir == 3 && i == 4) || (cur_dir == 4 && i == 3))
                q.push({cur_x, cur_y, i, cur_cnt + 2});
            else
                q.push({cur_x, cur_y, i, cur_cnt + 1});
            visit[cur_y][cur_x][i] = true;
        }
    }
}

int main(void) {
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> factory[i][j];
        }
    }
    
    cin >> start_y >> start_x >> start_dir;
    cin >> end_y >> end_x >> end_dir;
    
    find_min_cmd_path();
}
