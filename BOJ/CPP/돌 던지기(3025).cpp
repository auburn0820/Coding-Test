#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>

using namespace std;

int R, C, N;
vector<vector<char>> board;
set<int> path[32];
stack<pair<int, int>> st[32];

bool is_right_empty(int x, int y) {
    if(board[y - 1][x + 1] == '.' && board[y][x + 1] == '.')
        return true;
    else
        return false;
}

bool is_left_empty(int x, int y) {
    if(board[y - 1][x - 1] == '.' && board[y][x - 1] == '.')
        return true;
    else
        return false;
}

void fall_rock(int x, int y, int origin) {
    int height = *(path[x].upper_bound(y));
    
    if(board[height][x] == 'O') {
        if(is_left_empty(x, height)) {
            st[origin].push(make_pair(x, height - 1));
            fall_rock(x - 1, height - 1, origin);
        }
        else if(is_right_empty(x, height)) {
            st[origin].push(make_pair(x, height - 1));
            fall_rock(x + 1, height - 1, origin);
        }
        else {
            board[height - 1][x] = 'O';
            path[x].erase(height);
            path[x].insert(height - 1);
        }
    }
    else {
        board[height - 1][x] = 'O';
        path[x].erase(height);
        path[x].insert(height - 1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C;
    
    board.resize(R + 2, vector<char>(C + 1, ' '));
    
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> board[i][j];
            
            if(board[i][j] == 'X')
                path[j].insert(i);
        }
    }
    
    for(int i = 1; i <= C; i++)
        path[i].insert(R + 1);
    
    cin >> N;
    
    while(N--) {
        int col;
        cin >> col;
        
        int x = col;
        int y = 1;
        
        while(!st[col].empty()) {
            x = st[col].top().first;
            y = st[col].top().second;
            
            if(board[y][x] != '.')
                st[col].pop();
            else
                break;
        }
        
        if(st[col].empty()) {
            fall_rock(col, 1, col);
        }
        else {
            fall_rock(x, y, col);
        }
    }
    
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
}
