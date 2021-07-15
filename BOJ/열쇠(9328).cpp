#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int t, h, w;
char maps[102][102];
bool visit[102][102];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int result = 0;

struct LocInfo {
    int x, y;
};

void set_starting_points() {
    for(int i = 0; i <= w + 1; i++) {
        maps[0][i] = '.';
    }
    
    for(int i = 0; i <= w + 1; i++) {
        maps[h + 1][i] = '.';
    }
    
    for(int i = 0; i <= h + 1; i++) {
        maps[i][0] = '.';
    }
    
    for(int i = 0; i <= h + 1; i++) {
        maps[i][w + 1] = '.';
    }
}

void remove_door(char key) {
    key = key - 32;
    
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            if(maps[i][j] == key) {
                maps[i][j] = '.';
            }
        }
    }
}

void find_secret_paper(int start_x, int start_y) {
    queue<LocInfo> q;
    
    q.push({start_x, start_y});
    visit[start_y][start_x] = true;
    
    while(!q.empty()) {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            
            if(next_x < 0 || next_y < 0 || next_x > w + 1 || next_y > h + 1)
                continue;
            if(visit[next_y][next_x])
                continue;
            if(maps[next_y][next_x] == '*')
                continue;
            if(maps[next_y][next_x] >= 'A' && maps[next_y][next_x] <= 'Z')
                continue;
            if(maps[next_y][next_x] >= 'a' && maps[next_y][next_x] <= 'z') {
                remove_door(maps[next_y][next_x]);
                maps[next_y][next_x] = '.';
                
                memset(visit, false, sizeof(visit));
                
                while(!q.empty())
                    q.pop();
                q.push({0, 0});
                continue;
            }
            if(maps[next_y][next_x] == '$') {
                maps[next_y][next_x] = '.';
                result++;
            }
            
            visit[next_y][next_x] = true;
            q.push({next_x, next_y});
        }
    }
}

int main(void) {
    cin >> t;
    while(t--) {
        cin >> h >> w;
        
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                cin >> maps[i][j];
            }
        }
        
        set_starting_points();
        
        string keys_str;
        cin >> keys_str;
        
        for(int i = 0; i < (int)keys_str.length(); i++) {
            if(keys_str == "0")
                break;
            remove_door(keys_str[i]);
        }
        
        find_secret_paper(0, 0);
        
        cout << result << '\n';

        result = 0;
        memset(visit, false, sizeof(visit));
        memset(maps, 0, sizeof(maps));
    }
}
