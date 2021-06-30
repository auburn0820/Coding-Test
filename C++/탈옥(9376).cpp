//#include <iostream>
//#include <deque>
//#include <cstring>
//
//#define MAX 987654321
//
//using namespace std;
//
//int h, w;
//char maps[102][102];
//int visit[102][102][3];
//int sumArr[102][102];
//const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int ans = MAX;
//int x1, y1, x2, y2;
//
//struct Status {
//    int x, y, cnt;
//};
//
//void BFS(int x, int y, int type) {
//    deque<Status> q;
//    
//    q.push_back({x, y, 0});
//    visit[y][x][type] = 0;
//    
//    while(!q.empty()) {
//        int curX = q.front().x;
//        int curY = q.front().y;
//        int cnt = q.front().cnt;
//        q.pop_front();
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX >= 0 && nextX <= w + 1 && nextY >= 0 && nextY <= h + 1) {
//                if(visit[nextY][nextX][type] == -1) {
//                    if(maps[nextY][nextX] == '.' || maps[nextY][nextX] == '$' || maps[nextY][nextX] == ' ') {
//                        visit[nextY][nextX][type] = cnt;
//                        q.push_front({nextX, nextY, cnt});
//                    }
//                    else if(maps[nextY][nextX] == '#') {
//                        visit[nextY][nextX][type] = cnt + 1;
//                        q.push_back({nextX, nextY, cnt + 1});
//                    }
//                }
//            }
//        }
//    }
//}
//
//void init() {
//    ans = MAX;
//    memset(visit, -1, sizeof(visit));
//    memset(maps, ' ', sizeof(maps));
//    memset(sumArr, 0, sizeof(sumArr));
//}
//
//int main(void) {
//    int T;
//    cin >> T;
//    
//    while(T--) {
//        init();
//        cin >> h >> w;
//        
//        bool flag = false;
//        for(int i = 1; i <= h; i++) {
//            for(int j = 1; j <= w; j++) {
//                cin >> maps[i][j];
//                
//                if(maps[i][j] == '$' && flag) {
//                    x1 = j;
//                    y1 = i;
//                }
//                else if(maps[i][j] == '$') {
//                    x2 = j;
//                    y2 = i;
//                    flag = true;
//                }
//            }
//        }
//        
//        BFS(0, 0, 0);
//        BFS(x1, y1, 1);
//        BFS(x2, y2, 2);
//        
//        for(int i = 0; i <= h + 1; i++) {
//            for(int j = 0; j <= w + 1; j++) {
//                if(maps[i][j] == '#') {
//                    sumArr[i][j] -= 2;
//                }
//                for(int k = 0; k < 3; k++) {
//                    sumArr[i][j] += visit[i][j][k];
//                }
//                if(sumArr[i][j] != -3 && sumArr[i][j] < ans)
//                    ans = sumArr[i][j];
//            }
//        }
//        cout << ans << '\n';
//    }
//}
