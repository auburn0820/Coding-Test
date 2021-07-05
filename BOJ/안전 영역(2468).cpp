//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int maps[101][101];
//int N;
//bool visit[101][101] = {false, };
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//
//void DFS(int x, int y) {
//    for(int i = 0; i < 4; i++) {
//        int nextX = x + dx[i];
//        int nextY = y + dy[i];
//
//        if(nextX >= 0 && nextY >= 0 && nextX < N && nextY < N && !visit[nextY][nextX] && maps[nextY][nextX] != -1) {
//            visit[nextY][nextX] = true;
//            DFS(nextX, nextY);
//        }
//    }
//}
//
//void checkMaps(int waterHeight) {
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            if(maps[i][j] <= waterHeight) {
//                maps[i][j] = -1;
//            }
//        }
//    }
//}
//
//int main(void) {
//    cin >> N;
//    int maxHeight = 100;
//    int waterHeight = 0;
//    int area = 0;
//
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            cin >> maps[i][j];
//        }
//    }
//
//    while(maxHeight--) {
//        memset(visit, false, sizeof(visit));
//        checkMaps(waterHeight);
//        int cnt = 0;
//        for(int i = 0; i < N; i++) {
//            for(int j = 0; j < N; j++) {
//                if(maps[i][j] != -1 && !visit[i][j]) {
//                    cnt++;
//                    visit[i][j] = true;
//                    DFS(j, i);
//                }
//            }
//        }
//
//        area = max(cnt, area);
//        waterHeight++;
//    }
//
//    cout << area << '\n';
//}
