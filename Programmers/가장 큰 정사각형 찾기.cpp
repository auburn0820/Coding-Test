#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    int row = (int)board.size();
    int col = (int)board[0].size();
    int DP[1001][1001];
    
    memset(DP, 0, sizeof(DP));
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            DP[i + 1][j + 1] = board[i][j];
        }
    }
    
    for(int i = 1; i <= row; i++) {
        for(int j = 1; j <= col; j++) {
            if(DP[i][j] != 0) {
                DP[i][j] = min(min(DP[i - 1][j - 1], DP[i - 1][j]), DP[i][j - 1]) + 1;
                answer = max(answer, DP[i][j]);
            }
        }
    }

    return answer * answer;
}
