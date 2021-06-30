//#include <iostream>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//int maps[1001][1001];
//bool visit[1001][1001][2] = {false, };
//int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//int N, M;
//
//struct Location {
//    int x, y, cnt, destroy;
//};
//
//int BFS() {
//    queue<Location> q;
//    
//    q.push({1, 1, 1, 0});
//    
//    visit[1][1][0] = true;
//    
//    while(!q.empty()) {
//        int curX = q.front().x;
//        int curY = q.front().y;
//        int curCnt = q.front().cnt;
//        int des = q.front().destroy;
//        q.pop();
//        
//        if(curX == N && curY == M)
//            return curCnt;
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX < 1 || nextY < 1 || nextX > N || nextY > M)
//                continue;
//            if(maps[nextX][nextY] == 1 && des == true)
//                continue;
//            
//            if(maps[nextX][nextY] == 1 && des == 0) {
//                q.push({nextX, nextY, curCnt + 1, des + 1});
//                visit[nextX][nextY][des + 1] = true;
//            }
//            else if(maps[nextX][nextY] == 0 && !visit[nextX][nextY][des]) {
//                q.push({nextX, nextY, curCnt + 1, des});
//                visit[nextX][nextY][des] = true;
//            }
//        }
//    }
//    
//    return -1;
//}
//
//int main(void) {
//    
//    cin >> N >> M;
//    
//    for(int i = 1; i <= N; i++) {
//        string str;
//        cin >> str;
//        for(int j = 0; j < M; j++) {
//            maps[i][j + 1] = str[j] - '0';
//        }
//    }
//    
//    cout << BFS() << '\n';
//}
