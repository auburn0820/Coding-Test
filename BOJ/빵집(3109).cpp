#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int R, C;
char map[10001][501];
bool is_visited[10001][501];
int move_dir[] = {-1, 0, 1};
int result = 0;
bool is_search_ended = false;

void find_path(int x, int y) {
    is_visited[y][x] = true;
    
    if(x == C - 1) {
        result++;
        is_search_ended = true;
        return;
    }
    
    for(int i = 0; i < 3; i++) {
        if(is_search_ended)
            return;
        
        int next_x = x + 1;
        int next_y = y + move_dir[i];
        
        if(next_y < 0 || next_y >= R || next_x >= C)
            continue;
        if(is_visited[next_y][next_x])
            continue;
        if(map[next_y][next_x] == 'x')
            continue;
        
        find_path(next_x, next_y);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C;
    
    for(int i = 0; i < R; i++) {
        string input;
        cin >> input;
        for(int j = 0; j < C; j++) {
            map[i][j] = input[j];
        }
    }
    
    for(int i = 0; i < R; i++) {
        is_search_ended = false;
        find_path(0, i);
    }
    
    cout << result << '\n';
}
