#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int map[1001][1001];
int is_visit[1001][1001];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool is_daytime = true;

typedef struct HumanInfo {
    int x, y, k_cnt, move_cnt;
} HumanInfo;

int find_min_path() {
    queue<HumanInfo> q;
    
    q.push({0, 0, 0, 1});
    is_visit[0][0] = 0;
    
    while(!q.empty()) {
        int q_size = (int)q.size();
        
        while(q_size--) {
            int cur_x = q.front().x;
            int cur_y = q.front().y;
            int cur_k_cnt = q.front().k_cnt;
            int cur_move_cnt = q.front().move_cnt;
            
            q.pop();
            
            if(cur_x == M - 1 && cur_y == N - 1) {
                return cur_move_cnt;
            }
            
            for(int i = 0; i < 4; i++) {
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];
                
                if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
                    continue;
                
                if(map[next_y][next_x] == 1) {
                    if(cur_k_cnt >= K)
                        continue;
                    if(is_daytime == false) {
                        q.push({cur_x, cur_y, cur_k_cnt, cur_move_cnt + 1});
                        continue;
                    }
                    if(is_visit[next_y][next_x] > cur_k_cnt + 1) {
                        q.push({next_x, next_y, cur_k_cnt + 1, cur_move_cnt + 1});
                        is_visit[next_y][next_x] = cur_k_cnt + 1;
                        continue;
                    }
                } else {
                    if(is_visit[next_y][next_x] > cur_k_cnt) {
                        q.push({next_x, next_y, cur_k_cnt, cur_move_cnt + 1});
                        is_visit[next_y][next_x] = cur_k_cnt;
                        continue;
                    }
                }
            }
        }
        is_daytime = !is_daytime;
    }
    
    return -1;
}

void set_visit_arr() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            is_visit[i][j] = 987654321;
        }
    }
}

int main(void) {
    cin >> N >> M >> K;
    
    set_visit_arr();
    
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < M; j++) {
            map[i][j] = str[j] - '0';
        }
    }
    
    cout << find_min_path() << '\n';
}
