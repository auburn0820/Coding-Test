///*
// 처음에 어떻게 탐색 알고리즘을 짜야할 지 막막했다. 지훈이와 불, 두 가지 경우가 있었기 때문이었다.
// 하지만, 적절히 반복문이 언제 끝나야하는 지를 제어하니 해결됐다. DFS, BFS 문제를 조금 더 잘 알게 된 계기였다.
// */
//
//
//#include <iostream>
//#include <queue>
//
//char arr[1001][1001];
//int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//std::queue<std::pair<int, int>> jLocation;
//std::queue<std::pair<int, int>> fireLocation;
//int escapeTime = 0;
//
//void BFS(int R, int C) {
//    while(true) {
//        escapeTime += 1;
//        int fireSize = (int)fireLocation.size();
//        while(fireSize--) {
//            int x = fireLocation.front().first;
//            int y = fireLocation.front().second;
//            fireLocation.pop();
//
//            for(int i = 0; i < 4; i++) {
//                int nx = x + dx[i];
//                int ny = y + dy[i];
//
//                if(arr[nx][ny] == 'J' || arr[nx][ny] == '.') {
//                    arr[nx][ny] = 'F';
//                    fireLocation.push(std::make_pair(nx, ny));
//                }
//            }
//        }
//
//        int jSize = (int)jLocation.size();
//        while(jSize--) {
//            int x = jLocation.front().first;
//            int y = jLocation.front().second;
//            jLocation.pop();
//
//            for(int i = 0; i < 4; i++) {
//                int nx = x + dx[i];
//                int ny = y + dy[i];
//
//                if(nx >= R || nx < 0 || ny >= C || ny < 0) {
//                    std::cout << escapeTime << '\n';
//                    return;
//                }
//                if(arr[nx][ny] == '.') {
//                    arr[nx][ny] = 'J';
//                    jLocation.push(std::make_pair(nx, ny));
//                }
//            }
//        }
//
//        if((int)jLocation.size() == 0) {
//            std::cout << "IMPOSSIBLE\n";
//            return;
//        }
//    }
//}
//
//int main(void) {
//    int R, C;
//
//    std::cin >> R >> C;
//
//    for(int i = 0; i < R; i++) {
//        for(int j = 0; j < C; j++) {
//            std::cin >> arr[i][j];
//            if(arr[i][j] == 'J')
//                jLocation.push(std::make_pair(i, j));
//            else if(arr[i][j] == 'F')
//                fireLocation.push(std::make_pair(i, j));
//        }
//    }
//    BFS(R, C);
//
//}
