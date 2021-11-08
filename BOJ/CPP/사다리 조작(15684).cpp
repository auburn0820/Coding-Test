#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, H;
int board[31][12] = {0, };
int min_count = INT_MAX;

bool simulate() {
    for(int i = 1; i <= N; i++) {
        int x = i;
        int y = 1;
        
        while(y <= H) {
            if(board[y][x - 1] != 0) {
                x = x - 1;
                y = y + 1;
            }
            else if(board[y][x] != 0) {
                x = x + 1;
                y = y + 1;
            }
            else {
                y = y + 1;
            }
        }
        
        if(x != i) {
            return false;
        }
    }
    
    return true;
}

void find_cases(int height, int cur_count) {
    if(cur_count > 3)
        return;
    
    if(simulate()) {
        min_count = min(min_count, cur_count);
        return;
    }
        
    for(int i = height; i <= H; i++) {
        for(int j = 1; j <= N; j++) {
            if(board[i][j] != 0 || board[i][j - 1] != 0 || board[i][j + 1] != 0)
                continue;
            
            board[i][j] = 1;
            find_cases(i, cur_count + 1);
            board[i][j] = 0;
        }
    }
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> N >> M >> H;
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 1;
    }
    
    find_cases(1, 0);
    
    if(min_count > 3)
        min_count = -1;
    
    cout << min_count << '\n';
}
