#include <iostream>
#include <cstring>

using namespace std;

int M, N;
int board[501][501] = {0, };
int DP[501][501] = {0, };
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int DFS(int x, int y) {
    if(x == N - 1 && y == M - 1)
        return 1;
    if(DP[y][x] != -1)
        return DP[y][x];
    
    int cnt = 0;
    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)
            continue;
        if(board[next_y][next_x] >= board[y][x])
            continue;
        
        cnt += DFS(next_x, next_y);
    }
    
    return DP[y][x] = cnt;
}

int main(void) {
    cin >> M >> N;
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    memset(DP, -1, sizeof(DP));
    
    cout << DFS(0, 0) << '\n';
}
