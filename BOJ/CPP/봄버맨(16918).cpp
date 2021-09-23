#include <iostream>

using namespace std;

int R, C, N;
char map[201][201] = {0, };
int bomb_cnt[201][201] = {0, };
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void reduce_bomb_cnt() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(map[i][j] == 'O')
                bomb_cnt[i][j]--;
        }
    }
}

void set_new_bomb() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(map[i][j] == '.') {
                bomb_cnt[i][j] = 3;
                map[i][j] = 'O';
            }
        }
    }
}

void check_timeout_bomb() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(bomb_cnt[i][j] == 0 && map[i][j] == 'O') {
                map[i][j] = '.';
                for(int k = 0; k < 4; k++) {
                    int bomb_x = j + dx[k];
                    int bomb_y = i + dy[k];
                    
                    if(bomb_x < 0 || bomb_y < 0 || bomb_x >= C || bomb_y >= R)
                        continue;
                    if(bomb_cnt[bomb_y][bomb_x] == 0 && map[bomb_y][bomb_x] == 'O')
                        continue;
                    
                    map[bomb_y][bomb_x] = '.';
                }
                
            }
        }
    }
}

int main(void) {
    cin >> R >> C >> N;
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> map[i][j];
            bomb_cnt[i][j] = 2;
        }
    }
    
    bool flag = false;
    N--;
    while(N--) {
        reduce_bomb_cnt();
        
        if(flag)
            check_timeout_bomb();
        else
            set_new_bomb();
        
        flag = !flag;
    }
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
}
