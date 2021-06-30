//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//char field[12][6];
//bool visit[12][6];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//
//void dropPuyo() {
//    for(int i = 0; i < 6; i++) {
//        for(int j = 10; j >= 0; j--) {
//            if(field[j][i] != '.') {
//                int height = j;
//                char puyo = field[j][i];
//                field[j][i] = '.';
//                
//                while(height < 11 && field[height + 1][i] == '.')
//                    height++;
//                
//                field[height][i] = puyo;
//            }
//        }
//    }
//}
//
//void removePuyo(vector<pair<int, int>> &v) {
//    for(auto i : v) {
//        field[i.first][i.second] = '.';
//    }
//}
//
//int findCanRemovePuyo(int x, int y, char puyo) {
//    queue<pair<int, int>> q;
//    vector<pair<int, int>> v;
//    q.push({x, y});
//    v.push_back({x, y});
//    visit[x][y] = true;
//    
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int curY = q.front().second;
//        q.pop();
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX < 0 || nextY < 0 || nextX >= 12 || nextY >= 6)
//                continue;
//            if(visit[nextX][nextY])
//                continue;
//            if(field[nextX][nextY] != puyo)
//                continue;
//            
//            q.push({nextX, nextY});
//            v.push_back({nextX, nextY});
//            visit[nextX][nextY] = true;
//        }
//    }
//    
//    if((int)v.size() >= 4) {
//        removePuyo(v);
//        return 1;
//    }
//    return 0;
//}
//
//int main(void) {
//    
//    int result = 0;
//    vector<pair<int, int>> v;
//    
//    for(int i = 0; i < 12; i++) {
//        for(int j = 0; j < 6; j++) {
//            cin >> field[i][j];
//        }
//    }
//    
//    while(true) {
//        int flag = 0;
//        for(int i = 0; i < 12; i++) {
//            for(int j = 0; j < 6; j++) {
//                if(field[i][j] != '.') {
//                    v.push_back({i, j});
//                }
//            }
//        }
//        
//        if((int)v.size() == 0)
//            break;
//        
//        for(auto i : v) {
//            if(!visit[i.first][i.second]) {
//                flag += findCanRemovePuyo(i.first, i.second, field[i.first][i.second]);
//            }
//        }
//        
//        if(flag > 0) {
//            result++;
//            dropPuyo();
//        } else
//            break;
//        
//        v.clear();
//        memset(visit, false, sizeof(visit));
//    }
//    
//    cout << result << '\n';
//}
