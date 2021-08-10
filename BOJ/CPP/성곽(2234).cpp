//#include <iostream>
//#include <queue>
//#include <cstring>
//#include <climits>
//
//using namespace std;
//
//int n, m;
//int castle[50][50];
//int castleCopy[50][50];
//bool visit[50][50];
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}; // 서 북 동 남
//int wallCases[] = {1, 2, 4, 8}; // 서 북 동 남
//bool wallState[4];
//
//int maxRoomSize = INT_MIN;
//int maxRoomSizeIfRemoveOneWall = INT_MIN;
//
//void getWallState(const int num) {
//    memset(wallState, false, sizeof(wallState));
//    
//    for(int i = 0; i < 4; i++) {
//        int wall = (num & wallCases[i]);
//        
//        wallState[i] = wall;
//    }
//}
//
//void getSizeOfRoom(const int startX, const int startY, const bool bFlag) {
//    queue<pair<int, int>> q;
//    int cnt = 0;
//    
//    q.push({startX, startY});
//    visit[startY][startX] = true;
//    
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int curY = q.front().second;
//        q.pop();
//        cnt++;
//        
//        getWallState(castle[curY][curX]);
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            // 해당 방향이 벽으로 막혀있을 경우
//            if(wallState[i])
//                continue;
//            if(nextX < 0 || nextX >= m || nextY < 0 || nextY >= n)
//                continue;
//            if(visit[nextY][nextX])
//                continue;
//            
//            q.push({nextX, nextY});
//            visit[nextY][nextX] = true;
//        }
//    }
//    if(bFlag)
//        maxRoomSize = max(maxRoomSize, cnt);
//    else
//        maxRoomSizeIfRemoveOneWall = max(maxRoomSizeIfRemoveOneWall, cnt);
//}
//
//int getNumberOfRooms() {
//    int cnt = 0;
//    
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            if(!visit[i][j]) {
//                getSizeOfRoom(j, i, true);
//                cnt++;
//            }
//        }
//    }
//    
//    return cnt;
//}
//
//void removeWall() {
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            memset(visit, false, sizeof(visit));
//            getWallState(castle[i][j]);
//            for(int k = 0; k < 4; k++) {
//                if(wallState[k]) {
//                    castle[i][j] -= wallCases[k];
//                    getSizeOfRoom(j, i, false);
//                    castle[i][j] += wallCases[k];
//                }
//            }
//        }
//    }
//}
//
//int main(void) {
//    scanf("%d %d", &m, &n);
//    
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            scanf("%d", &castle[i][j]);
//        }
//    }
//    
//    int numberOfRooms = getNumberOfRooms();
//    removeWall();
//    
//    printf("%d\n%d\n%d\n", numberOfRooms, maxRoomSize, maxRoomSizeIfRemoveOneWall);
//}
