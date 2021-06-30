//#include <iostream>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//char image[101][101];
//bool visit[101][101] = {false, };
//int ansForColorBlindPerson = 0;
//int ansForNotColorBlindPerson = 0;
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int N;
//
//void countAreaForColorBlindPerson(int x, int y) {
//    queue<pair<int, int>> q;
//    
//    q.push({x, y});
//    visit[x][y] = true;
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
//            if((nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) && !visit[nextX][nextY]) {
//                if(image[curX][curY] == 'R' || image[curX][curY] == 'G') {
//                    if(image[nextX][nextY] == 'R' || image[nextX][nextY] == 'G') {
//                        q.push({nextX, nextY});
//                        visit[nextX][nextY] = true;
//                    }
//                }
//                else if(image[curX][curY] == 'B') {
//                    if(image[nextX][nextY] == 'B') {
//                        q.push({nextX, nextY});
//                        visit[nextX][nextY] = true;
//                    }
//                }
//            }
//        }
//    }
//}
//
//void countAreaForNotColorBlindPerson(int x, int y) {
//    queue<pair<int, int>> q;
//    
//    q.push({x, y});
//    visit[x][y] = true;
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
//            if((nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) && !visit[nextX][nextY]) {
//                if(image[curX][curY] == image[nextX][nextY]) {
//                    q.push({nextX, nextY});
//                    visit[nextX][nextY] = true;
//                }
//            }
//        }
//    }
//}
//
//int main(void) {
//    cin >> N;
//    
//    for(int i = 0; i < N; i++)
//        cin >> image[i];
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            if(!visit[i][j]) {
//                countAreaForColorBlindPerson(i, j);
//                ansForColorBlindPerson++;
//            }
//        }
//    }
//    
//    memset(visit, false, sizeof(visit));
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            if(!visit[i][j]) {
//                countAreaForNotColorBlindPerson(i, j);
//                ansForNotColorBlindPerson++;
//            }
//        }
//    }
//    
//    cout << ansForNotColorBlindPerson << ' ' << ansForColorBlindPerson << '\n';
//}
