//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//char maps[50][50];
//bool visit[50][50][50] = {false, };
//int N, M;
//int numberOfThing = 0;
//int startX, startY;
//
//struct Status {
//    int x, y;
//    int havingThing;
//    int cnt;
//};
//
//int bitCount(int num) {
//    if(num == 0)
//        return 0;
//    else
//        return num % 2 + bitCount(num / 2);
//}
//
//void shortestPath() {
//    queue<Status> q;
//    q.push({startX, startY, 0, 0});
//    visit[startY][startX][0] = true;
//    
//    while(!q.empty()) {
//        int curX = q.front().x;
//        int curY = q.front().y;
//        int curHavingThing = q.front().havingThing;
//        int curCnt = q.front().cnt;
//        q.pop();
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            int nextHavingThing = curHavingThing;
//            
//            if((nextX >= 0 && nextY >= 0 && nextX < N && nextY < M) && !visit[nextY][nextX][curHavingThing]) {
//                if(maps[nextY][nextX] >= 'a' && maps[nextY][nextX] <= 'e') {
//                    nextHavingThing = curHavingThing | (1 << (maps[nextY][nextX] - 'a'));
//                    q.push({nextX, nextY, nextHavingThing, curCnt + 1});
//                    visit[nextY][nextX][nextHavingThing] = true;
//                }
//                else if(maps[nextY][nextX] == 'E' && bitCount(curHavingThing) == numberOfThing) {
//                    cout << curCnt + 1 << '\n';
//                    return;
//                }
//                else if(maps[nextY][nextX] == '.') {
//                    q.push({nextX, nextY, curHavingThing, curCnt + 1});
//                    visit[nextY][nextX][curHavingThing] = true;
//                }
//            }
//        }
//    }
//}
//
//int main(void) {
//    cin >> N >> M;
//    char ASCII = 'a';
//    for(int i = 0; i < M; i++) {
//        for(int j = 0; j < N; j++) {
//            cin >> maps[i][j];
//            if(maps[i][j] == 'X') {
//                numberOfThing++;
//                maps[i][j] = ASCII;
//                ASCII++;
//            }
//            else if(maps[i][j] == 'S') {
//                startX = j;
//                startY = i;
//                maps[i][j] = '.';
//            }
//        }
//    }
//    shortestPath();
//}
