#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool can_remove(vector<string> &board, int x, int y) {
    char kakao_char = board[y][x];
    
    if(board[y][x] == kakao_char
       && board[y + 1][x] == kakao_char
       && board[y][x + 1] == kakao_char
       && board[y + 1][x + 1] == kakao_char) {
        return true;
    } else {
        return false;
    }
}

int count_block(vector<string> &copied_board, int x, int y) {
    int ans = 0;
    
    for(int i = y; i <= y + 1; i++) {
        for(int j = x; j <= x + 1; j++) {
            if(copied_board[i][j] != ' ')
                ans++;
        }
    }
    return ans;
}

void remove_block(vector<string> &copied_board, int x, int y) {
    for(int i = y; i <= y + 1; i++) {
        for(int j = x; j <= x + 1; j++) {
            copied_board[i][j] = ' ';
        }
    }
}

void drop_block(vector<string> &board) {
    for(int i = board.size() - 1; i >= 0; i--) {
        for(int j = 0; j < board[i].size(); j++) {
            if(board[i][j] == ' ')
                continue;
            
            int y = i;
            
            while(y < board.size() - 1) {
                if(board[y + 1][j] == ' ') {
                    board[y + 1][j] = board[y][j];
                    board[y][j] = ' ';
                    y++;
                }
                else
                    break;
            }
        }
    }
}

int process_turn(vector<string> &board) {
    int ans = 0;
    vector<string> copied_board(board.begin(), board.end());
    
    while(true) {
        bool is_removed = false;
        for(int i = 0; i < board.size() - 1; i++) {
            for(int j = 0; j < (int)board[i].size() - 1; j++) {
                if(board[i][j] == ' ')
                    continue;
                if(can_remove(board, j, i)) {
                    ans += count_block(copied_board, j, i);
                    remove_block(copied_board, j, i);
                    is_removed = true;
                }
            }
        }

        if(!is_removed)
            break;
        
        drop_block(copied_board);
        
        board.clear();
        board = vector<string>(copied_board.begin(), copied_board.end());
    }
    
    return ans;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    answer = process_turn(board);
    
    return answer;
}
