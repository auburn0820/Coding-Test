//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//int N, M;
//int lab[8][8];
//int copyLab[8][8];
//bool visit[8][8];
//vector<pair<int, int>> virusLocation;
//int maxValue = 0;
//int moveX[] = {1, -1, 0, 0}, moveY[] = {0, 0, 1, -1};
//
//void spreadVirus() {
//    copy(&lab[0][0], &lab[N][0], &copyLab[0][0]);
//    memset(visit, false, sizeof(visit));
//    queue<pair<int, int>> q;
//    
//    for(auto i : virusLocation)
//        q.push(i);
//    
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int curY = q.front().second;
//        copyLab[curX][curY] = 2;
//        q.pop();
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + moveX[i];
//            int nextY = curY + moveY[i];
//            
//            if(visit[nextX][nextY] == true)
//                continue;
//            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
//                continue;
//            if(copyLab[nextX][nextY] == 1)
//                continue;
//            
//            q.push({nextX, nextY});
//            visit[nextX][nextY] = true;
//        }
//    }
//}
//
//int maximumValue() {
//    int result = 0;
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            if(copyLab[i][j] == 0)
//                result++;
//        }
//    }
//    
//    return result;
//}
//
//void wallSpotCombination(int cnt, int x, int y) {
//    lab[x][y] = 1;
//    
//    if(cnt == 3) {
////        printArr();
//        spreadVirus();
//        maxValue = max(maxValue, maximumValue());
//        lab[x][y] = 0;
//        return;
//    }
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            if(lab[i][j] == 0)
//                wallSpotCombination(cnt + 1, i, j);
//        }
//    }
//    lab[x][y] = 0;
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            cin >> lab[i][j];
//            if(lab[i][j] == 2)
//                virusLocation.push_back({i, j});
//        }
//    }
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            if(lab[i][j] == 0)
//                wallSpotCombination(1, i, j);
//        }
//    }
//    
//    cout << maxValue << '\n';
//}
