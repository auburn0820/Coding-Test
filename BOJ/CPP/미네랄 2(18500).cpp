//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <queue>
//
//using namespace std;
//
//int R, C, N;
//char cave[101][101];
//char caveCpy[101][101];
//int numberOfCluster[101][101];
//vector<int> heights;
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//bool visit[101][101];
//
//void seperateBFS(int x, int y, int num) {
//    queue<pair<int, int>> q;
//    q.push({x, y});
//    visit[y][x] = true;
//    
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int curY = q.front().second;
//        numberOfCluster[curY][curX] = num;
//        q.pop();
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX < 0 || nextX >= C || nextY < 0 || nextY >= R)
//                continue;
//            if(visit[nextY][nextX])
//                continue;
//            if(caveCpy[nextY][nextX] == '.')
//                continue;
//            
//            q.push({nextX, nextY});
//            visit[nextY][nextX] = true;
//        }
//    }
//}
//
//bool checkClusterFalling(int cnt) {
//    for(int i = 0; i < R; i++) {
//        for(int j = 0; j < C; j++) {
//            if(numberOfCluster[i][j] != cnt)
//                continue;
//            
//            if(i == (R - 1))
//                return true;
//        }
//    }
//    
//    return false;
//}
//
//bool checkAllClusterIsSafe(int cnt) {
//    if(!checkClusterFalling(cnt))
//        return true;
//    
//    return false;
//}
//
//bool isLanded(int cnt) {
//    for(int i = (R - 1); i >= 0; i--) {
//        for(int j = 0; j < C; j++) {
//            if(numberOfCluster[i][j] != cnt)
//                continue;
//            if((numberOfCluster[i + 1][j] != 0 && numberOfCluster[i + 1][j] != cnt) || i == (R - 1)) {
//                return true;
//            }
//        }
//    }
//    
//    return false;
//}
//
//void moveCluster(int cnt) {
//    for(int i = (R - 1); i >= 0; i--) {
//        for(int j = 0; j < C; j++) {
//            if(numberOfCluster[i][j] == cnt && i + 1 < R && cave[i + 1][j] == '.') {
//                cave[i + 1][j] = 'x';
//                cave[i][j] = '.';
//                numberOfCluster[i + 1][j] = cnt;
//                numberOfCluster[i][j] = 0;
//            }
//        }
//    }
//}
//
//void fallCluster(int cnt) {
//    while(true) {
//        if(!isLanded(cnt)) {
//            moveCluster(cnt);
//        } else
//            break;
//    }
//}
//
//void seperateCluster() {
//    memcpy(caveCpy, cave, sizeof(caveCpy));
//    memset(visit, false, sizeof(visit));
//    memset(numberOfCluster, 0, sizeof(numberOfCluster));
//    
//    int cnt = 1;
//    
//    for(int i = 0; i < R; i++) {
//        for(int j = 0; j < C; j++) {
//            if(!visit[i][j] && caveCpy[i][j] == 'x') {
//                seperateBFS(j, i, cnt++);
//            }
//        }
//    }
//    
//    for(int i = 1; i < cnt; i++) {
//        if(!checkClusterFalling(i))
//            fallCluster(i);
//    }
//}
//
//void moveStick(int height, bool turn) {
//    int x, y;
//    if(turn) {
//        x = 0;
//        y = height;
//        
//        while(true) {
//            if(cave[y][x] == 'x') {
//                cave[y][x] = '.';
//                break;
//            } else if(x >= C)
//                break;
//            x++;
//        }
//    }
//    else {
//        x = C - 1;
//        y = height;
//        
//        while(true) {
//            if(cave[y][x] == 'x') {
//                cave[y][x] = '.';
//                break;
//            } else if(x < 0)
//                break;
//            x--;
//        }
//    }
//}
//
//void throwStick() {
//    bool turn = true;;
//    for(auto &i : heights) {
//        int height = R - i;
//        
//        if(turn) {
//            moveStick(height, turn);
//            turn = false;
//        }
//        else {
//            moveStick(height, turn);
//            turn = true;
//        }
//        
//        seperateCluster();
//    }
//}
//
//int main(void) {
//    cin >> R >> C;
//    
//    for(int i = 0; i < R; i++) {
//        string str;
//        cin >> str;
//        for(int j = 0; j < C; j++) {
//            cave[i][j] = str[j];
//        }
//    }
//    
//    cin >> N;
//    
//    for(int i = 0; i < N; i++) {
//        int height;
//        cin >> height;
//        heights.push_back(height);
//    }
//    
//    throwStick();
//    
//    for(int i = 0; i < R; i++) {
//        for(int j = 0; j < C; j++) {
//            cout << cave[i][j];
//        }
//        cout << '\n';
//    }
//}
