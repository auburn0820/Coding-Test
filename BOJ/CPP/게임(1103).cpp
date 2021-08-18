#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
char board[50][50];
bool is_visit[50][50];
int DP[50][50];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int ans = -1;

int count_game_turn(int x, int y) {
    if(x < 0 || y < 0 || x >= M || y >= N)
        return 0;
    if(board[y][x] == 'H')
        return 0;
    if(is_visit[y][x])
        return -1;
    if(DP[y][x] != -1)
        return DP[y][x];
    
    is_visit[y][x] = true;
    DP[y][x] = 1;
    
    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i] * (board[y][x] - '0');
        int next_y = y + dy[i] * (board[y][x] - '0');
        
        int result = count_game_turn(next_x, next_y);
        
        if(result == -1)
            return result;
        else
            DP[y][x] = max(DP[y][x], result + 1);
    }
    
    is_visit[y][x] = false;
    return DP[y][x];
}

int main(void) {
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < M; j++) {
            board[i][j] = str[j];
        }
    }
    
    memset(DP, -1, sizeof(DP));
    ans = count_game_turn(0, 0);
    cout << ans << '\n';
}
