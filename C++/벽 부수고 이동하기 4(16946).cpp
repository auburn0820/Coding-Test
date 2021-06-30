//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cstring>
//
//#define MAX 1001
//
//using namespace std;
//
//int N, M;
//int maps[MAX][MAX];
//int cpyMaps[MAX][MAX];
//bool visit[MAX][MAX];
//vector<pair<int, int>> wallLocation;
//int areaNumber[50001];
//bool visitArea[50001];
//
//int moveX[] = {1, -1, 0, 0}, moveY[] = {0, 0, 1, -1};
//
//void findArea(int x, int y, int idx) {
//    int numberOfArea = 0;
//    queue<pair<int, int>> q;
//    q.push({x, y});
//    visit[x][y] = true;
//    
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int curY = q.front().second;
//        q.pop();
//        maps[curX][curY] = idx;
//        numberOfArea++;
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + moveX[i];
//            int nextY = curY + moveY[i];
//            
//            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
//                continue;
//            if(visit[nextX][nextY])
//                continue;
//            if(maps[nextX][nextY] != 0)
//                continue;
//            
//            q.push({nextX, nextY});
//            visit[nextX][nextY] = true;
//        }
//    }
//    areaNumber[idx - '0'] = numberOfArea;
//}
//
//int checkValue(int x, int y) {
//    memset(visitArea, false, sizeof(visitArea));
//    int result = 1;
//    
//    for(int i = 0; i < 4; i++) {
//        int nextX = x + moveX[i];
//        int nextY = y + moveY[i];
//        
//        if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
//            continue;
//        if(visitArea[maps[nextX][nextY] - '0'])
//            continue;
//        if(cpyMaps[nextX][nextY] == 1)
//            continue;
//        
//        visitArea[maps[nextX][nextY] - '0'] = true;
//        result += areaNumber[maps[nextX][nextY] - '0'];
//    }
//    
//    return result % 10;
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < N; i++) {
//        string s;
//        cin >> s;
//        for(int j = 0; j < M; j++) {
//            maps[i][j] = s[j] - '0';
//            if(maps[i][j] == 1)
//                wallLocation.push_back({i, j});
//        }
//    }
//    
//    copy(&maps[0][0], &maps[N][0], &cpyMaps[0][0]);
//    
//    int idx = '0';
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            if(maps[i][j] == 0) {
//                findArea(i, j, idx);
//                idx++;
//            }
//        }
//    }
//    
//    for(auto i : wallLocation) {
//        maps[i.first][i.second] = checkValue(i.first, i.second);
//    }
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            if(cpyMaps[i][j] == 0)
//                maps[i][j] = 0;
//            cout << maps[i][j];
//        }
//        cout << '\n';
//    }
//}
//
