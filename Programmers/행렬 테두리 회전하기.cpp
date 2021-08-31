#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int rotate_board(vector<vector<int>> &board, vector<int> query) {
    int min_num = INT_MAX;
    
    int x1, y1, x2, y2;
    
    x1 = query[1];
    y1 = query[0];
    x2 = query[3];
    y2 = query[2];
    
    // 위 가로
    int temp = board[y1][x2];
    int temp_x = x2;
    int temp_y = y1 + 1;
    
    for(int i = x2; i > x1; i--) {
        board[y1][i] = board[y1][i - 1];
        min_num = min(min_num, board[y1][i - 1]);
    }
    
    // 왼쪽 세로
    for(int i = y1; i < y2; i++) {
        board[i][x1] = board[i + 1][x1];
        min_num = min(min_num, board[i + 1][x1]);
    }
    
    // 아래 가로
    for(int i = x1; i < x2; i++) {
        board[y2][i] = board[y2][i + 1];
        min_num = min(min_num, board[y2][i + 1]);
    }
    
    // 오른쪽 세로
    for(int i = y2; i > y1; i--) {
        board[i][x2] = board[i - 1][x2];
        min_num = min(min_num, board[i - 1][x2]);
    }
    
    board[temp_y][temp_x] = temp;
    min_num = min(min_num, temp);
    
    return min_num;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows + 1, vector<int>(columns + 1, 0));
    
    int cur_num = 1;
    for(int i = 1; i < board.size(); i++) {
        for(int j = 1; j < board[i].size(); j++) {
            board[i][j] = cur_num++;
        }
    }
    
    for(int i = 0; i < queries.size(); i++) {
        answer.push_back(rotate_board(board, queries[i]));
    }
    
    return answer;
}
