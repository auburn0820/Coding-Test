#include <iostream>
#include <vector>

using namespace std;

struct ChessmenInfo {
    int x, y, dir, num;
};

int N, K;
int board[14][14];
vector<ChessmenInfo> chessmen_infos[13][13];
int dx[] = {0, 1, -1, 0, 0}, dy[] = {0, 0, 0, -1, 1};

void set_border_line() {
    for(int i = 0; i <= N + 1; i++) {
        board[0][i] = 2;
        board[N + 1][i] = 2;
        board[i][0] = 2;
        board[i][N + 1] = 2;
    }
}

int reverse_direction(int dir) {
    int new_dir = 0;
    switch (dir) {
        case 1:
            new_dir = 2;
            break;
        case 2:
            new_dir = 1;
            break;
        case 3:
            new_dir = 4;
            break;
        case 4:
            new_dir = 3;
            break;
    }
    return new_dir;
}

bool is_game_ended() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if((int)chessmen_infos[i][j].size() >= 4)
                return true;
        }
    }
    return false;
}

bool can_move_chessmen(int x, int y, int num) {
    if(chessmen_infos[y][x].front().num == num)
        return true;
    else
        return false;
}

void move_chessmen(int x, int y) {
    int cur_x = x;
    int cur_y = y;
    int cur_dir = chessmen_infos[y][x].front().dir;
    int next_x = cur_x + dx[cur_dir];
    int next_y = cur_y + dy[cur_dir];
    
    if(board[next_y][next_x] == 0) {
        for(int i = 0; i < (int)chessmen_infos[cur_y][cur_x].size(); i++) {
            chessmen_infos[next_y][next_x].push_back({next_x, next_y, chessmen_infos[cur_y][cur_x][i].dir, chessmen_infos[cur_y][cur_x][i].num});
        }
        chessmen_infos[cur_y][cur_x].clear();
    } else if(board[next_y][next_x] == 1) {
        for(int i = (int)chessmen_infos[cur_y][cur_x].size() - 1; i >= 0; i--) {
            chessmen_infos[next_y][next_x].push_back({next_x, next_y, chessmen_infos[cur_y][cur_x][i].dir, chessmen_infos[cur_y][cur_x][i].num});
        }
        chessmen_infos[cur_y][cur_x].clear();
    } else if(board[next_y][next_x] == 2) {
        cur_dir = reverse_direction(cur_dir);
        next_x = cur_x + dx[cur_dir];
        next_y = cur_y + dy[cur_dir];
        int num = chessmen_infos[cur_y][cur_x].front().num;
        
        chessmen_infos[cur_y][cur_x][0] = {cur_x, cur_y, cur_dir, num};
        
        if(board[next_y][next_x] != 2)
            move_chessmen(cur_x, cur_y);
    }
}

int process_turn() {
    int turn_count = 0;
    while(turn_count <= 1000) {
        if(is_game_ended())
            return turn_count;
        
        turn_count++;
        
        int chessmen_index = 0;
        
        SUCCESS_EXIT:
        while(chessmen_index <= K) {
            chessmen_index++;
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= N; j++) {
                    if(!chessmen_infos[i][j].empty() && can_move_chessmen(j, i, chessmen_index)) {
                        move_chessmen(j, i);
                        if(is_game_ended())
                            return turn_count;
                        goto SUCCESS_EXIT;
                    }
                }
            }
        }
    }
    
    return -1;
}

int main(void) {
    cin >> N >> K;
    
    set_border_line();
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }
    
    for(int i = 1; i <= K; i++) {
        int x, y, dir;
        cin >> y >> x >> dir;
        chessmen_infos[y][x].push_back({x, y, dir, i});
    }
    
    cout << process_turn() << '\n';
}
