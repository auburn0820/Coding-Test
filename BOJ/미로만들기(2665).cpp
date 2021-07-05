//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int n;
//int room[50][50];
//bool visit[50][50];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//
//struct LocInfo {
//    int x, y, cnt;
//};
//
//void getMinCost() {
//    deque<LocInfo> q;
//    
//    q.push_back({0, 0, 0});
//    
//    while(!q.empty()) {
//        int curX = q.front().x;
//        int curY = q.front().y;
//        int curCnt = q.front().cnt;
//        
//        q.pop_front();
//        
//        if(curX == n - 1 && curY == n - 1) {
//            cout << curCnt << '\n';
//            return;
//        }
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= n)
//                continue;
//            if(visit[nextY][nextX])
//                continue;
//            
//            if(room[nextY][nextX] == 1)
//                q.push_front({nextX, nextY, curCnt});
//            else
//                q.push_back({nextX, nextY, curCnt + 1});
//            visit[nextY][nextX] = true;
//        }
//    }
//}
//
//int main(void) {
//    cin >> n;
//    
//    for(int i = 0; i < n; i++) {
//        string str;
//        cin >> str;
//        for(int j = 0; j < n; j++) {
//            room[i][j] = str[j] - '0';
//        }
//    }
//    
//    getMinCost();
//}
