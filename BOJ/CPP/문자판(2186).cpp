#include <iostream>
#include <cstring>

using namespace std;

int N, M, K;
string str_to_find;
char char_board[100][100];
int DP[100][100][80];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int ans = 0;

int find_path(int x, int y, int idx) {
    if(DP[y][x][idx] != -1)
        return DP[y][x][idx];
    if(idx >= (int)str_to_find.length())
        return 1;
    
    DP[y][x][idx] = 0;
    
    for(int i = 0; i < 4; i++) {
        for(int j = 1; j <= K; j++) {
            int next_x = x + dx[i] * j;
            int next_y = y + dy[i] * j;
            
            if(next_x < 0 || next_y < 0 || next_x >= M || next_y >= N)
                continue;
            if(str_to_find[idx] != char_board[next_y][next_x])
                continue;
            
            DP[y][x][idx] = DP[y][x][idx] + find_path(next_x, next_y, idx + 1);
        }
    }
    return DP[y][x][idx];
}

int main(void) {
    cin >> N >> M >> K;
    
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < M; j++) {
            char_board[i][j] = s[j];
        }
    }
    cin >> str_to_find;
    
    memset(DP, -1, sizeof(DP));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(char_board[i][j] == str_to_find[0]) {
                ans += find_path(j, i, 1);
            }
        }
    }
    
    cout << ans << '\n';
}
