//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//int N;
//int maps[20][20];
//bool visit[20][20];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int sizeOfShark;
//int ans = 0;
//bool flag = false;
//int eatFish = 0;
//
//int sharkX, sharkY;
//
//struct Status {
//    int x, y, cnt;
//};
//
//vector<Status> v;
//
//bool cmp(const Status &a, const Status &b) {
//    if(a.cnt == b.cnt) {
//        if(a.y == b.y)
//            return a.x < b.x;
//        return a.y < b.y;
//    }
//    return a.cnt < b.cnt;
//}
//
//void BFS(int x, int y) {
//    queue<Status> q;
//
//    q.push({x, y, 0});
//    visit[y][x] = true;
//
//    while(!q.empty()) {
//        int curX = q.front().x;
//        int curY = q.front().y;
//        int curCnt = q.front().cnt;
//        q.pop();
//
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//
//            if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && !visit[nextY][nextX]) {
//                if(sizeOfShark >= maps[nextY][nextX]) {
//                    q.push({nextX, nextY, curCnt + 1});
//                    visit[nextY][nextX] = true;
//                    if(sizeOfShark > maps[nextY][nextX] && maps[nextY][nextX] != 0) {
//                        v.push_back({nextX, nextY, curCnt + 1});
//                    }
//                }
//            }
//        }
//    }
//
//    if(v.empty()) {
//        flag = true;
//        return;
//    }
//
//    Status minDistanceFish;
//    sort(v.begin(), v.end(), cmp);
//    minDistanceFish = v[0];
//
//    eatFish++;
//    maps[minDistanceFish.y][minDistanceFish.x] = 0;
//    ans += minDistanceFish.cnt;
//    v.clear();
//    memset(visit, false, sizeof(visit));
//
//    if(eatFish == sizeOfShark) {
//        eatFish = 0;
//        sizeOfShark++;
//    }
//
//    sharkX = minDistanceFish.x;
//    sharkY = minDistanceFish.y;
//}
//
//int main(void) {
//    cin >> N;
//
//    sizeOfShark = 2;
//
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            cin >> maps[i][j];
//            if(maps[i][j] == 9) {
//                sharkX = j;
//                sharkY = i;
//                maps[i][j] = 0;
//            }
//        }
//    }
//
//    while(true) {
//        BFS(sharkX, sharkY);
//        if(flag)
//            break;
//    }
//
//    cout << ans << '\n';
//}
