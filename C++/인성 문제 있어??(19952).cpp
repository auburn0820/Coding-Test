//#include <iostream>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//int T, H, W, O, F, startX, startY, destX, destY;
//int map[101][101];
//bool visit[101][101];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//
//struct InsungInfo {
//    int x, y, power;
//};
//
//bool canInsungGoToDestination() {
//    queue<InsungInfo> q;
//    
//    q.push({startX, startY, F});
//    visit[startX][startY] = true;
//    
//    while(!q.empty()) {
//        int curX = q.front().x;
//        int curY = q.front().y;
//        int curPower = q.front().power;
//        
//        q.pop();
//        
//        if(curX == destX && curY == destY)
//            return true;
//        
//        if(curPower == 0)
//            continue;
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX > H || nextY < 1 || nextY > W || nextX < 1)
//                continue;
//            if(visit[nextX][nextY])
//                continue;
//            if(curPower < (map[nextX][nextY] - map[curX][curY]))
//                continue;
//            
//            q.push({nextX, nextY, curPower - 1});
//            visit[nextX][nextY] = true;
//        }
//    }
//    
//    return false;
//}
//
//int main(void) {
//    cin >> T;
//    while(T--) {
//        cin >> H >> W >> O >> F >> startX >> startY >> destX >> destY;
//        memset(visit, false, sizeof(visit));
//        memset(map, 0, sizeof(map));
//        
//        for(int i = 0; i < O; i++) {
//            int a, b, c;
//            cin >> a >> b >> c;
//            map[a][b] = c;
//        }
//        
//        if(canInsungGoToDestination())
//            cout << "잘했어!!\n";
//        else
//            cout << "인성 문제있어??\n";
//    }
//}
