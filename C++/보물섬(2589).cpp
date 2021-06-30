//#include <iostream>
//#include <queue>
//#include <climits>
//#include <cstring>
//
//#define MAX(a, b) (a > b ? a : b)
//
//using namespace std;
//
//int N, M;
//char map[51][51];
//bool visit[51][51];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int totalMax = INT_MIN;
//
//struct LocInfo {
//    int x, y, cnt;
//};
//
//void getMinDistance(int startX, int startY) {
//    memset(visit, false, sizeof(visit));
//    queue<LocInfo> q;
//    q.push({startX, startY, 0});
//    visit[startY][startX] = true;
//    
//    int maxDistance = 0;
//    
//    while(!q.empty()) {
//        int curX = q.front().x;
//        int curY = q.front().y;
//        int curCnt = q.front().cnt;
//        q.pop();
//        
//        maxDistance = MAX(curCnt, maxDistance);
//        
//        if(maxDistance > totalMax) {
//            totalMax = maxDistance;
//            
//        }
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX >= M || nextX < 0 || nextY >= N || nextY < 0)
//                continue;
//            if(visit[nextY][nextX])
//                continue;
//            if(map[nextY][nextX] != 'L')
//                continue;
//            
//            q.push({nextX, nextY, curCnt + 1});
//            visit[nextY][nextX] = true;
//        }
//    }
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < N; i++) {
//        string str;
//        cin >> str;
//        for(int j = 0; j < M; j++) {
//            map[i][j] = str[j];
//        }
//    }
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            if(map[i][j] == 'L') {
//                getMinDistance(j, i);
//            }
//        }
//    }
//    cout << totalMax << '\n';
//}
