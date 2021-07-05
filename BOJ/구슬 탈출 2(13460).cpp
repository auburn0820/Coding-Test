//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N, M;
//char maps[10][10];
//pair<int, int> red, blue, hole;
//const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//
//int DFS(int cnt, pair<int, int> R, pair<int, int> B, int direction) {
//    if(cnt > 10)
//        return 9999;
//
//    int redX = R.first;
//    int redY = R.second;
//    int blueX = B.first;
//    int blueY = B.second;
//
//    int ans = 9999;
//
//    if(cnt != 0) {
//        while(true) {
//            if(maps[redX + dx[direction]][redY + dy[direction]] != '.')
//                break;
//
//            redX += dx[direction];
//            redY += dy[direction];
//
//            if(redX == hole.first && redY == hole.second) {
//                ans = cnt;
//                break;
//            }
//        }
//
//        while(true) {
//            if(maps[blueX + dx[direction]][blueY + dy[direction]] != '.')
//                break;
//
//            blueX += dx[direction];
//            blueY += dy[direction];
//
//            if(blueX == hole.first && blueY == hole.second) {
//                return ans = 9999;
//            }
//        }
//
//        if(ans != 9999)
//            return ans;
//
//        if(redX == red.first && redY == red.second && blueX == blue.first && blueY == blue.second)
//            return ans = 9999;
//
//        if(redX == blueX && redY == blueY) {
//            if(direction == 0) {
//                if(R.first > B.first)
//                    blueX--;
//                else
//                    redX--;
//            }
//            else if(direction == 1) {
//                if(R.first < B.first)
//                    blueX++;
//                else
//                    redX++;
//            }
//            else if(direction == 2) {
//                if(R.second > B.second)
//                    blueY--;
//                else
//                    redY--;
//            }
//            else if(direction == 3) {
//                if(R.second < B.second)
//                    blueY++;
//                else
//                    redY++;
//            }
//        }
//    }
//
//    pair<int, int> newRed = {redX, redY};
//    pair<int, int> newBlue = {blueX, blueY};
//
//    for(int i = 0; i < 4; i++) {
//        ans = min(ans, DFS(cnt + 1, newRed, newBlue, i));
//    }
//
//    return ans;
//}
//
//int main(void) {
//    cin >> N >> M;
//
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            cin >> maps[i][j];
//
//            if(maps[i][j] == 'R') {
//                red.first = i;
//                red.second = j;
//                maps[i][j] = '.';
//            }
//            else if(maps[i][j] == 'B') {
//                blue.first = i;
//                blue.second = j;
//                maps[i][j] = '.';
//            }
//            else if(maps[i][j] == 'O') {
//                hole.first = i;
//                hole.second = j;
//                maps[i][j] = '.';
//            }
//        }
//    }
//
//    int ans = DFS(0, red, blue, 0);
//
//    if(ans == 9999)
//        cout << -1 << '\n';
//    else
//        cout << ans << '\n';
//}
