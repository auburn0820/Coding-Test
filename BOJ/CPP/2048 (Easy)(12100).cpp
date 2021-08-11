#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N;
int board[20][20];
int copied_board[20][20];
bool is_combined[20][20];
int result = -1;
vector<int> directions;

void copy_board() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            copied_board[i][j] = board[i][j];
        }
    }
}

bool is_same_number(int x1, int x2, int y1, int y2) {
    if(copied_board[y1][x1] == copied_board[y2][x2])
        return true;
    else
        return false;
}

void move_number(int direction) {
    memset(is_combined, false, sizeof(is_combined));
    // 오른쪽
    if(direction == 0) {
        for(int i = 0; i < N; i++) {
            for(int j = N - 2; j >= 0; j--) {
                if(copied_board[i][j] == 0)
                    continue;
                int cur_x = j;
                while(cur_x < N - 1) {
                    int next_x = cur_x + 1;
                    
                    if(copied_board[i][next_x] != 0) {
                        if(is_same_number(cur_x, next_x, i, i) && !is_combined[i][next_x]) {
                            copied_board[i][next_x] += copied_board[i][cur_x];
                            copied_board[i][cur_x] = 0;
                            is_combined[i][next_x] = true;
                            break;
                        }
                        else
                            break;
                    } else {
                        copied_board[i][next_x] = copied_board[i][cur_x];
                        copied_board[i][cur_x] = 0;
                        cur_x++;
                    }
                }
            }
        }
    }
    // 왼쪽
    else if(direction == 1) {
        for(int i = 0; i < N; i++) {
            for(int j = 1; j < N; j++) {
                if(copied_board[i][j] == 0)
                    continue;
                int cur_x = j;
                
                while(cur_x > 0) {
                    int next_x = cur_x - 1;
                    
                    if(copied_board[i][next_x] != 0) {
                        if(is_same_number(cur_x, next_x, i, i) && !is_combined[i][next_x]) {
                            copied_board[i][next_x] += copied_board[i][cur_x];
                            copied_board[i][cur_x] = 0;
                            is_combined[i][next_x] = true;
                            break;
                        }
                        else
                            break;
                    } else {
                        copied_board[i][next_x] = copied_board[i][cur_x];
                        copied_board[i][cur_x] = 0;
                        cur_x--;
                    }
                }
            }
        }
    }
    // 아래쪽
    else if(direction == 2) {
        for(int i = 0; i < N; i++) {
            for(int j = N - 2; j >= 0; j--) {
                if(copied_board[j][i] == 0)
                    continue;
                int cur_y = j;
                
                while(cur_y < N - 1) {
                    int next_y = cur_y + 1;
                    
                    if(copied_board[next_y][i] != 0) {
                        if(is_same_number(i, i, next_y, cur_y) && !is_combined[next_y][i]) {
                            copied_board[next_y][i] += copied_board[cur_y][i];
                            copied_board[cur_y][i] = 0;
                            is_combined[next_y][i] = true;
                            break;
                        }
                        else
                            break;
                    } else {
                        copied_board[next_y][i] = copied_board[cur_y][i];
                        copied_board[cur_y][i] = 0;
                        cur_y++;
                    }
                }
            }
        }
    }
    // 위쪽
    else if(direction == 3) {
        for(int i = 0; i < N; i++) {
            for(int j = 1; j < N; j++) {
                if(copied_board[j][i] == 0)
                    continue;
                int cur_y = j;
                
                while(cur_y > 0) {
                    int next_y = cur_y - 1;
                    
                    if(copied_board[next_y][i] != 0) {
                        if(is_same_number(i, i, next_y, cur_y) && !is_combined[next_y][i]) {
                            copied_board[next_y][i] += copied_board[cur_y][i];
                            copied_board[cur_y][i] = 0;
                            is_combined[next_y][i] = true;
                            break;
                        }
                        else
                            break;
                    } else {
                        copied_board[next_y][i] = copied_board[cur_y][i];
                        copied_board[cur_y][i] = 0;
                        cur_y--;
                    }
                }
            }
        }
    }
}

int find_max_number_in_board() {
    int max_num = -1;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            max_num = max(max_num, copied_board[i][j]);
        }
    }
    
    return max_num;
}

void comb_direction(int cnt) {
    if(cnt == 5) {
        copy_board();
        
        for(int i = 0; i < cnt; i++) {
            move_number(directions[i]);
        }
        result = max(result, find_max_number_in_board());
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        directions.push_back(i);
        comb_direction(cnt + 1);
        directions.pop_back();
    }
}

int main(void) {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    
    comb_direction(0);
    cout << result << '\n';
}
