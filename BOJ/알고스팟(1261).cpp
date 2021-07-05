//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int M, N;
//int room[100][100];
//bool visit[100][100];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//
//struct LocInfo {
//    int x, y, cnt;
//};
//
//void getMinDistance() {
//    deque<LocInfo> q;
//    
//    q.push_front({0, 0, 0});
//    
//    while(!q.empty()) {
//        int curX = q.front().x;
//        int curY = q.front().y;
//        int curCnt = q.front().cnt;
//        
//        q.pop_front();
//        
//        if(curX == M - 1 && curY == N - 1) {
//            cout << curCnt << '\n';
//            return;
//        }
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX < 0 || nextX >= M || nextY < 0 || nextY >= N)
//                continue;
//            if(visit[nextY][nextX])
//                continue;
//            if(room[nextY][nextX] == 0)
//                q.push_front({nextX, nextY, curCnt});
//            else
//                q.push_back({nextX, nextY, curCnt + 1});
//            
//            visit[nextY][nextX] = true;
//        }
//    }
//}
//
//int main(void) {
//    cin >> M >> N;
//    
//    for(int i = 0; i < N; i++) {
//        string str;
//        cin >> str;
//        for(int j = 0; j < M; j++) {
//            room[i][j] = str[j] - '0';
//        }
//    }
//    
//    getMinDistance();
//}
