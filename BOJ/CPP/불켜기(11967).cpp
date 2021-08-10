#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
bool is_visited[101][101] = {false, };
bool is_already_turn_switch[101][101] = {false, };
bool is_bright_room[101][101] = {false, };
vector<pair<int, int>> room[101][101];

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void turn_switch(int x, int y) {
    for(auto &i : room[y][x]) {
        is_bright_room[i.second][i.first] = true;
    }
    
    if(!room[y][x].empty())
        memset(is_visited, false, sizeof(is_visited));
    is_already_turn_switch[y][x] = true;
}

void move_room() {
    queue<pair<int, int>> q;
    
    q.push({1, 1});
    is_visited[1][1] = true;
    is_bright_room[1][1] = true;
    
    while(!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        
        q.pop();
        
        if(!is_already_turn_switch[cur_y][cur_x])
            turn_switch(cur_x, cur_y);
        
        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            if(next_x < 1 || next_y < 1 || next_x > N || next_y > N)
                continue;
            if(is_visited[next_y][next_x])
                continue;
            if(!is_bright_room[next_y][next_x])
                continue;
            
            q.push({next_x, next_y});
            is_visited[next_y][next_x] = true;
        }
    }
}

int count_bright_room() {
    int count = 0;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(is_bright_room[i][j])
                count++;
        }
    }
    return count;
}

int main(void) {
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        room[y][x].push_back({a, b});
    }
    
    move_room();
    cout << count_bright_room() << '\n';
}
