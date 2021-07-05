//#include <iostream>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//char room[20][20];
//bool visit[20][20][1 << 10];
//int startX, startY;
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int w, h;
//int dustCnt;
//
//struct Status {
//    int x, y, cnt, dust;
//};
//
//int countBit(int num) {
//    if(num == 0)
//        return 0;
//    else
//        return num % 2 + countBit(num / 2);
//}
//
//int BFS() {
//    queue<Status> q;
//    q.push({startX, startY, 0, 0});
//    visit[startY][startX][0] = true;
//    
//    while(!q.empty()) {
//        int curX = q.front().x;
//        int curY = q.front().y;
//        int curCnt = q.front().cnt;
//        int curDust = q.front().dust;
//        q.pop();
//        
//        if(countBit(curDust) == dustCnt)
//            return curCnt;
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if((nextX < w && nextY < h && nextX >= 0 && nextY >= 0) && !visit[nextY][nextX][curDust]) {
//                if(room[nextY][nextX] >= 'a' && room[nextY][nextX] <= 'j') {
//                    q.push({nextX, nextY, curCnt + 1, curDust | (1 << (room[nextY][nextX] - 'a'))});
//                    visit[nextY][nextX][curDust | (1 << (room[nextY][nextX] - 'a'))] = true;
//                }
//                else if(room[nextY][nextX] == '.') {
//                    q.push({nextX, nextY, curCnt + 1, curDust});
//                    visit[nextY][nextX][curDust] = true;
//                }
//            }
//        }
//    }
//    
//    return -1;
//}
//
//int main(void) {
//    while(true) {
//        memset(visit, false, sizeof(visit));
//        memset(room, ' ', sizeof(room));
//        
//        cin >> w >> h;
//        
//        if(!(w && h))
//            break;
//        
//        dustCnt = 0;
//        int dust = 'a';
//        for(int i = 0; i < h; i++) {
//            for(int j = 0; j < w; j++) {
//                cin >> room[i][j];
//                if(room[i][j] == 'o') {
//                    startX = j;
//                    startY = i;
//                    room[i][j] = '.';
//                }
//                else if(room[i][j] == '*') {
//                    room[i][j] = dust;
//                    dust++;
//                    dustCnt++;
//                }
//            }
//        }
//        cout << BFS() << '\n';
//    }
//}
