#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
char maps[1001][1001];
bool visit[1001][1001][11];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

struct LocInfo {
    int x, y, dist_cnt, k_cnt;
};

int find_min_path() {
    queue<LocInfo> q;
    
    q.push({1, 1, 1, 0});
    visit[1][1][0] = true;
    
    while(!q.empty()) {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_dist_cnt = q.front().dist_cnt;
        int cur_k_cnt = q.front().k_cnt;
        
        q.pop();
        
        if(cur_x == M && cur_y == N) {
            return cur_dist_cnt;
        }
        
        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            if(next_x < 1 || next_y < 1 || next_x > M || next_y > N)
                continue;
            if(maps[next_y][next_x] == '1' && cur_k_cnt < K && !visit[next_y][next_x][cur_k_cnt + 1]) {
                q.push({next_x, next_y, cur_dist_cnt + 1, cur_k_cnt + 1});
                visit[next_y][next_x][cur_k_cnt + 1] = true;
            }
            if(maps[next_y][next_x] == '0' && !visit[next_y][next_x][cur_k_cnt]) {
                q.push({next_x, next_y, cur_dist_cnt + 1, cur_k_cnt});
                visit[next_y][next_x][cur_k_cnt] = true;
            }
        }
    }
    return -1;
}

int main(void) {
    cin >> N >> M >> K;
    
    for(int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < M; j++) {
            maps[i][j + 1] = s[j];
        }
    }
    
    cout << find_min_path() << '\n';
}
