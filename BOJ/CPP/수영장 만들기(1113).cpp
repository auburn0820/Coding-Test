#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> pool;
vector<vector<int>> water;
int max_height = 0;
int min_height = 10;
bool is_visit[51][51] = {false, };
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void remove_water(int x, int y, int height) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    is_visit[y][x] = true;
    
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        
        q.pop();
        
        water[cur_y][cur_x]--;
        
        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
                continue;
            if(is_visit[next_y][next_x])
                continue;
            
            if(pool[next_y][next_x] + water[next_y][next_x] == height && water[next_y][next_x] > 0) {
                q.push(make_pair(next_x, next_y));
                is_visit[next_y][next_x] = true;
            }
        }
    }
}

int check_water() {
    for(int h = max_height; h >= min_height; h--) {
        memset(is_visit, false, sizeof(is_visit));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(water[i][j] > 0 && !is_visit[i][j]) {
                    for(int k = 0; k < 4; k++) {
                        int next_x = j + dx[k];
                        int next_y = i + dy[k];
                        
                        if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N || pool[i][j] + water[i][j] > pool[next_y][next_x] + water[next_y][next_x]) {
                            remove_water(j, i, h);
                            // break를 하지 않으면 같은 위치에서 물을 두 번 빼는 경우도 발생함.
                            break;
                        }
                    }
                }
            }
        }
    }
    
    
    int water_size = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            water_size += water[i][j];
        }
    }
    
    return water_size;
}

int main(void) {
    cin >> N >> M;
    pool.resize(N, vector<int>(M));
    water.resize(N, vector<int>(M));
    
    for(int i = 0; i < N; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < M; j++) {
            pool[i][j] = input[j] - '0';
            max_height = max(max_height, pool[i][j]);
            min_height = min(min_height, pool[i][j]);
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            water[i][j] = max_height - pool[i][j];
        }
    }
    
    cout << check_water() << '\n';
}
