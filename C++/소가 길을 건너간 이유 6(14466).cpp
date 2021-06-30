//#include <iostream>
//#include <vector>
//#include <set>
//#include <cstring>
//
//using namespace std;
//
//int N, K, R;
//set<pair<int, int>> s[101][101];
//bool visit[101][101];
//bool isRoad[101][101][101][101];
//int result;
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//
//void getResult(int x, int y) {
//
//    visit[x][y] = true;
//
//    for(int i = 0; i < 4; i++) {
//        int nextX = x + dx[i];
//        int nextY = y + dy[i];
//
//        if(nextX < 1 || nextX > N || nextY < 1 || nextY > N)
//            continue;
//        if(visit[nextX][nextY])
//            continue;
//        if(isRoad[x][y][nextX][nextY])
//            continue;
//
//        getResult(nextX, nextY);
//    }
//}
//
//int main(void) {
//    cin >> N >> K >> R;
//
//    vector<pair<int, int>> cow(K);
//
//    for(int i = 0; i < R; i++) {
//        int a, b, c, d;
//        cin >> a >> b >> c >> d;
//        isRoad[a][b][c][d] = true;
//        isRoad[c][d][a][b] = true;
////        s[a][b].insert({c, d});
////        s[c][d].insert({a, b});
//    }
//
//    for(int i = 0; i < K; i++) {
//        cin >> cow[i].first >> cow[i].second;
//    }
//
//    for(int i = 0; i < K; i++) {
//        memset(visit, false, sizeof(visit));
//        getResult(cow[i].first, cow[i].second);
//        for(int j = i + 1; j < K; j++) {
//            if(!visit[cow[j].first][cow[j].second]) {
//                result++;
//            }
//        }
//    }
//
//    cout << result << '\n';
//}
