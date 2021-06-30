//#include <iostream>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//int N, M;
//int sea[301][301];
//bool visit[301][301] = {false, };
//bool checkVisit[301][301] = {false, };
//int numberOfIce;
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//
//void BFS(int x, int y) {
//    queue<pair<int, int>> q;
//    q.push({x, y});
//    visit[y][x] = true;
//    
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int curY = q.front().second;
//        q.pop();
//        
//        for(int i = 0; i < 4; i++) {
//            int meltX = curX + dx[i];
//            int meltY = curY + dy[i];
//            
//            if(sea[meltY][meltX] == 0 && meltX >= 0 && meltX < M && meltY >= 0 && meltY < N) {
//                sea[curY][curX]--;
//                if(sea[curY][curX] <= 0) {
//                    sea[curY][curX] = -1;
//                    break;
//                }
//            }
//        }
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N && !visit[nextY][nextX] && sea[nextY][nextX] != 0) {
//                q.push({nextX, nextY});
//                visit[nextY][nextX] = true;
//            }
//        }
//    }
//}
//
//void modifySea() {
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            if(sea[i][j] == -1) {
//                sea[i][j] = 0;
//            }
//        }
//    }
//}
//
//bool check() {
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            if(sea[i][j] != 0)
//                return false;
//        }
//    }
//    return true;
//}
//
//void checkIceCnt(int x, int y) {
//    numberOfIce++;
//    queue<pair<int, int>> q;
//    q.push({x, y});
//    checkVisit[y][x] = true;
//    
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int curY = q.front().second;
//        q.pop();
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX >= 0 && nextY >= 0 && nextX < M && nextY < N && !checkVisit[nextY][nextX] && sea[nextY][nextX] != 0) {
//                q.push({nextX, nextY});
//                checkVisit[nextY][nextX] = true;
//            }
//        }
//    }
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            cin >> sea[i][j];
//        }
//    }
//    int year = 0;
//    while(true) {
//        year++;
//        numberOfIce = 0;
//        for(int i = 0; i < N; i++) {
//            for(int j = 0; j < M; j++) {
//                if(sea[i][j] != 0 && !visit[i][j]) {
//                    BFS(j, i);
//                }
//            }
//        }
//        
//        modifySea();
//        
//        for(int i = 0; i < N; i++) {
//            for(int j = 0; j < M; j++) {
//                if(sea[i][j] != 0 && !checkVisit[i][j])
//                    checkIceCnt(j, i);
//            }
//        }
//        
//        memset(visit, false, sizeof(visit));
//        memset(checkVisit, false, sizeof(checkVisit));
//        
//        if(numberOfIce > 1) {
//            cout << year << '\n';
//            break;
//        }
//        else if(numberOfIce == 0 && check()) {
//            cout << 0 << '\n';
//            break;
//        }
//    }
//}
