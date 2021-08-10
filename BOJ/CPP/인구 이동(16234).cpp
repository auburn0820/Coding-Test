//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cmath>
//#include <cstring>
//
//using namespace std;
//
//int N, L, R;
//int result;
//int uni = 1;
//int isMoved;
//int arr[50][50];
//int map[50][50];
//bool visit[50][50];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//
//bool movePopulation(int x, int y) {
//    vector<pair<int, int>> v;
//    queue<pair<int, int>> q;
//    int uniNum = map[x][y];
//    int sum = 0;
//    int pop;
//    
//    q.push({x, y});
//    visit[x][y] = true;
//    
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int curY = q.front().second;
//        v.push_back({curX, curY});
//        sum += arr[curX][curY];
//        q.pop();
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
//                continue;
//            if(visit[nextX][nextY])
//                continue;
//            if(map[nextX][nextY] != uniNum)
//                continue;
//            
//            q.push({nextX, nextY});
//            visit[nextX][nextY] = true;
//        }
//    }
//    
//    if((int)v.size() > 1) {
//        pop = sum / (int)v.size();
//        for(auto i : v) {
//            arr[i.first][i.second] = pop;
//        }
//        return true;
//    }
//    else
//        return false;
//}
//
//void openBorder(int x, int y, int uni) {
//    queue<pair<int, int>> q;
//    
//    q.push({x, y});
//    visit[x][y] = true;
//    map[x][y] = uni;
//    
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int curY = q.front().second;
//        q.pop();
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            int differencePopulation = abs(arr[curX][curY] - arr[nextX][nextY]);
//            
//            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
//                continue;
//            if(visit[nextX][nextY])
//                continue;
//            if(differencePopulation < L || differencePopulation > R)
//                continue;
//            
//            q.push({nextX, nextY});
//            visit[nextX][nextY] = true;
//            map[nextX][nextY] = uni;
//        }
//    }
//}
//
//int main(void) {
//    cin >> N >> L >> R;
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            cin >> arr[i][j];
//        }
//    }
//    
//    while(true) {
//        isMoved = 0;
//        uni = 1;
//        memset(visit, false, sizeof(visit));
//        memset(map, 0, sizeof(map));
//        
//        for(int i = 0; i < N; i++) {
//            for(int j = 0; j < N; j++) {
//                if(map[i][j] == 0) {
//                    openBorder(i, j, uni++);
//                }
//            }
//        }
//        
//        memset(visit, false, sizeof(visit));
//        
//        for(int i = 0; i < N; i++) {
//            for(int j = 0; j < N; j++) {
//                if(map[i][j] > 0) {
//                    if(movePopulation(i, j)) {
//                        isMoved++;
//                    }
//                }
//            }
//        }
//        
//        if(isMoved > 0) {
//            result++;
//        } else
//            break;
//    }
//    
//    cout << result << '\n';
//}
