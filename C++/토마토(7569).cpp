//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int tomato[100][100][100] = {0, };
//int dx[] = {1, -1, 0, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};
//int N, M, H;
//int day = 0;
//
//typedef struct {
//    int x, y, z;
//} Location;
//
//queue<Location> q;
//
//void BFS(int x, int y, int z) {
//    int curX = x;
//    int curY = y;
//    int curZ = z;
//    q.pop();
//
//    for(int i = 0; i < 6; i++) {
//        int nextX = curX + dx[i];
//        int nextY = curY + dy[i];
//        int nextZ = curZ + dz[i];
//
//        if(nextX >= 0 && nextY >= 0 && nextZ >= 0 && nextX < N && nextY < M && nextZ < H) {
//            if(tomato[nextX][nextY][nextZ] == 0) {
//                q.push({nextX, nextY, nextZ});
//                tomato[nextX][nextY][nextZ] = 1;
//            }
//        }
//    }
//}
//
//int main(void) {
//
//    cin >> M >> N >> H;
//
//    bool flag = true;
//
//    for(int k = 0; k < H; k++) {
//        for(int i = 0; i < N; i++) {
//            for(int j = 0; j < M; j++) {
//                cin >> tomato[i][j][k];
//                if(tomato[i][j][k] == 0)
//                    flag = false;
//                else if(tomato[i][j][k] == 1)
//                    q.push({i, j, k});
//            }
//        }
//    }
//
//    if(flag) {
//        cout << 0 << '\n';
//        exit(0);
//    }
//
//    while(!q.empty()) {
//        int qSize = (int)q.size();
//        for(int i = 0; i < qSize; i++) {
//            int x = q.front().x;
//            int y = q.front().y;
//            int z = q.front().z;
//            BFS(x, y, z);
//        }
//        day++;
//    }
//
//    bool checkFlag = true;
//
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            for(int k = 0; k < H; k++) {
//                if(tomato[i][j][k] == 0)
//                    checkFlag = false;
//            }
//        }
//    }
//
//    if(!checkFlag)
//        cout << -1 << '\n';
//    else
//        cout << day - 1 << '\n';
//}
