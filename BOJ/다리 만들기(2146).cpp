//#include <iostream>
//#include <queue>
//#include <cstring>
//#include <climits>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//int map[100][100];
//bool visit[100][100];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int ans = INT_MAX;
//
//struct LocInfo {
//    int x, y, cnt;
//};
//
//void seperateIsland(int x, int y, int num) {
//    queue<pair<int, int>> q;
//
//    q.push({x, y});
//    map[y][x] = num;
//    visit[y][x] = true;
//
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int curY = q.front().second;
//
//        q.pop();
//
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//
//            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
//                continue;
//            if(visit[nextY][nextX])
//                continue;
//            if(map[nextY][nextX] == 0)
//                continue;
//
//            q.push({nextX, nextY});
//            visit[nextY][nextX] = true;
//            map[nextY][nextX] = num;
//        }
//    }
//}
//
//void getMinDistance(int x, int y, int num) {
//    memset(visit, false, sizeof(visit));
//
//    queue<LocInfo> q;
//
//    q.push({x, y, 0});
//    visit[y][x] = true;
//
//    while(!q.empty()) {
//        int curX = q.front().x;
//        int curY = q.front().y;
//        int curCnt = q.front().cnt;
//
//        q.pop();
//
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//
//            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
//                continue;
//            if(visit[nextY][nextX])
//                continue;
//
//            if(map[nextY][nextX] == 0) {
//                q.push({nextX, nextY, curCnt + 1});
//                visit[nextY][nextX] = true;
//                continue;
//            }
//
//            if(map[nextY][nextX] != num) {
//                ans = min(ans, curCnt);
//            }
//        }
//    }
//}
//
//int main(void) {
//    cin >> N;
//
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            cin >> map[i][j];
//        }
//    }
//
//    int num = 2;
//
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            if(map[i][j] == 1) {
//                seperateIsland(j, i, num++);
//            }
//        }
//    }
//
////    for(int i = 0; i < N; i++) {
////        for(int j = 0; j < N; j++) {
////            cout << map[i][j] << ' ';
////        }
////        cout << '\n';
////    }
//
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            if(map[i][j] != 0) {
//                getMinDistance(j, i, map[i][j]);
//            }
//        }
//    }
//
//    cout << ans << '\n';
//}
