//#include <iostream>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//int H, W;
//int cheese[101][101];
//int cheeseCopy[101][101];
//bool visit[101][101];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int ans = 0;
//
//bool checkCheeseMelted() {
//    for(int i = 0; i < H; i++) {
//        for(int j = 0; j < W; j++) {
//            if(cheeseCopy[i][j] != 3)
//                return false;
//        }
//    }
//    return true;
//}
//
//void fillAirArea() {
//    queue<pair<int, int>> q;
//
//    memset(visit, false, sizeof(visit));
//    memcpy(cheeseCopy, cheese, sizeof(cheese));
//
//    q.push({0, 0});
//    visit[0][0] = true;
//
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int curY = q.front().second;
//        cheeseCopy[curY][curX] = 3;
//
//        q.pop();
//
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//
//            if(nextX < 0 || nextY < 0 || nextX >= W || nextY >= H)
//                continue;
//            if(visit[nextY][nextX])
//                continue;
//            if(cheeseCopy[nextY][nextX] != 0)
//                continue;
//
//            q.push({nextX, nextY});
//            visit[nextY][nextX] = true;
//        }
//    }
//}
//
//vector<pair<int, int>> getCheeseThatAirContacted() {
//    vector<pair<int, int>> v;
//    fillAirArea();
//
//    if(checkCheeseMelted())
//        return v;
//
//    for(int i = 0; i < H; i++) {
//        for(int j = 0; j < W; j++) {
//
//            if(cheeseCopy[i][j] != 1)
//                continue;
//
//            for(int k = 0; k < 4; k++) {
//                int nextX = j + dx[k];
//                int nextY = i + dy[k];
//
//                if(nextX < 0 || nextY < 0 || nextX >= W || nextY >= H)
//                    continue;
//
//                if(cheeseCopy[nextY][nextX] == 3) {
//                    v.push_back({j, i});
//                    break;
//                }
//            }
//        }
//    }
//
//    return v;
//}
//
//void meltingCheese() {
//    vector<pair<int, int>> cheeseLocationVec;
//    vector<pair<int, int>> lastLocation;
//
//    while(1) {
//        cheeseLocationVec = getCheeseThatAirContacted();
//
//        if(cheeseLocationVec.empty())
//            break;
//
//        lastLocation.clear();
//
//        for(auto &i : cheeseLocationVec) {
//            int x = i.first;
//            int y = i.second;
//
//            cheese[y][x] = 0;
//            lastLocation.push_back({x, y});
//        }
//
//        ans++;
//    }
//
//    cout << ans << '\n';
//    cout << (int)lastLocation.size() << '\n';
//}
//
//int main(void) {
//    cin >> H >> W;
//
//    for(int i = 0; i < H; i++) {
//        for(int j = 0; j < W; j++) {
//            cin >> cheese[i][j];
//        }
//    }
//
//    meltingCheese();
//}
