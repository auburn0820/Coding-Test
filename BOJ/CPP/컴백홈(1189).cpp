#include <iostream>

using namespace std;

int R, C, K;
char map[6][6] = {0, };
bool is_visit[6][6] = {false, };
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int answer = 0;


void find_path(int x, int y, int distance) {
    if(distance > K)
        return;
    if(x == C - 1 && y == 0 && distance == K) {
        answer++;
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x < 0 || next_y < 0 || next_x >= C || next_y >= R)
            continue;
        if(is_visit[next_y][next_x])
            continue;
        if(map[next_y][next_x] == 'T')
            continue;
        
        is_visit[next_y][next_x] = true;
        find_path(next_x, next_y, distance + 1);
        is_visit[next_y][next_x] = false;
    }
}

int main(void) {
    cin >> R >> C >> K;
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> map[i][j];
        }
    }
    
    is_visit[R - 1][0] = true;
    find_path(0, R - 1, 1);
    cout << answer << '\n';
}
