//#include <iostream>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//char miro[8][8];
//bool visit[8][8];
//int dx[] = {1, -1, 0, 0, 1, -1, 1, -1, 0}, dy[] = {0, 0, 1, -1, 1, -1, -1, 1, 0};
//
//void downWall(int x, int y) {
//    int sero = y;
//    int garo = x;
//    miro[sero][garo] = '.';
//    
//    if(sero == 7) {
//        return;
//    }
//    
//    miro[++sero][garo] = '#';
//}
//
//bool canGoToDestination() {
//    queue<pair<int, int>> q;
//    
//    q.push({0, 7});
//    
//    while(!q.empty()) {
//        memset(visit, false, sizeof(visit));
//        int size = (int)q.size();
//        while(size--) {
//            int curX = q.front().first;
//            int curY = q.front().second;
//            q.pop();
//            
//            if(miro[curY][curX] == '#')
//                continue;
//            
//            if(curX == 7 && curY == 0) {
//                return true;
//            }
//            
//            for(int i = 0; i < 9; i++) {
//                int nextX = curX + dx[i];
//                int nextY = curY + dy[i];
//                
//                if(nextX < 0 || nextX >= 8 || nextY < 0 || nextY >= 8)
//                    continue;
//                if(visit[nextY][nextX])
//                    continue;
//                if(miro[nextY][nextX] == '#')
//                    continue;
//                
//                q.push({nextX, nextY});
//                visit[nextY][nextX] = true;
//            }
//        }
//        
//        for(int i = 7; i >= 0; i--) {
//            for(int j = 7; j >= 0; j--) {
//                if(miro[i][j] == '#')
//                    downWall(j, i);
//            }
//        }
//    }
//    return false;
//}
//
//int main(void) {
//    for(int i = 0; i < 8; i++) {
//        string str;
//        cin >> str;
//        for(int j = 0; j < 8; j++) {
//            miro[i][j] = str[j];
//        }
//    }
//    
//    cout << canGoToDestination() << '\n';
//}
