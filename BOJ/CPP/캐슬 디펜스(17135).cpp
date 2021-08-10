#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int N, M, D;
int board[15][15];
int copied_board[15][15];
vector<pair<int, int>> archer_positions;
int max_result = INT_MIN;

int get_distance(int archer_x, int archer_y, int enermy_x, int enermy_y) {
    return abs(archer_x - enermy_x) + abs(archer_y - enermy_y);
}

bool is_game_ended() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(copied_board[i][j] == 1)
                return false;
        }
    }
    return true;
}

void find_enermy_to_attack(pair<int, int> archer_position, vector<pair<int, int>> &enermy_positions) {
    pair<int, int> enermy_to_attack_position = {INT_MAX, INT_MAX};
    int min_distance_between_enermy = INT_MAX;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(copied_board[i][j] == 1) {
                int distance = get_distance(archer_position.first, archer_position.second, j, i);
                
                if(distance > D)
                    continue;
                if(min_distance_between_enermy > distance) {
                    min_distance_between_enermy = distance;
                    enermy_to_attack_position = {j, i};
                } else if(min_distance_between_enermy == distance && j < enermy_to_attack_position.first) {
                    min_distance_between_enermy = distance;
                    enermy_to_attack_position = {j, i};
                }
            }
        }
    }
    
    if(min_distance_between_enermy != INT_MAX) {
        enermy_positions.push_back(enermy_to_attack_position);
    }
}

void move_enermy() {
    for(int i = 0; i < M; i++) {
        for(int j = N - 1; j > 0; j--) {
            copied_board[j][i] = copied_board[j - 1][i];
        }
    }
    
    for(int i = 0; i < M; i++) {
        copied_board[0][i] = 0;
    }
}

void copy_board() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            copied_board[i][j] = board[i][j];
        }
    }
}

int process_turn() {
    vector<pair<int, int>> enermry_to_attack_positions;
    int cnt = 0;
    
    while(!is_game_ended()) {
        enermry_to_attack_positions.clear();
        for(auto &archer_position : archer_positions) {
            find_enermy_to_attack(archer_position, enermry_to_attack_positions);
        }
        
        for(auto &enermy_to_attack_position: enermry_to_attack_positions) {
            if(copied_board[enermy_to_attack_position.second][enermy_to_attack_position.first] == 1) {
                copied_board[enermy_to_attack_position.second][enermy_to_attack_position.first] = 0;
                cnt++;
            }
        }
        move_enermy();
    }
    
    return cnt;
}

void assign_archer(int idx, int cnt) {
    if(cnt == 3) {
        copy_board();
        int result = process_turn();
        max_result = max(max_result, result);
        return;
    }
    
    for(int i = idx; i < M; i++) {
        archer_positions.push_back({i, N});
        assign_archer(i + 1, cnt + 1);
        archer_positions.pop_back();
    }
}

int main(void) {
    cin >> N >> M >> D;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    assign_archer(0, 0);
    cout << max_result << '\n';
}
