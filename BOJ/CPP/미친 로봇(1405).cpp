///*
// DFS 부분이 이해가 안 됨. 다시 꼭 이해할 것.
// */
//
//#include <iostream>
//#include <queue>
//
//std::queue<std::pair<int, int>> robotLocation;
//
//bool maps[30][30] = {false, };
//
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
//
//int probability[4];
//double result = 0.0;
//
//void DFS(int x, int y, int cnt, int N, double percent) {
//    if(cnt == N) {
//        result += percent;
//        return;
//    }
//
//    maps[x][y] = true;
//    
//    for(int i = 0; i < 4; i++) {
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//
//        if(maps[nx][ny] == true)
//            continue;
//
//        double per = probability[i] / 100.0;
//
//        DFS(nx, ny, cnt + 1, N, percent * per);
//    }
//
//    maps[x][y] = false;
//}
//
//int main(void) {
//    int N;
//    std::cin >> N;
//
//    for(int i = 0; i < 4; i++) {
//        std::cin >> probability[i]; //EWSN
//    }
//
//    DFS(14, 14, 0, N, 1.0);
//
//    std::cout.precision(9);
//    std::cout << (double) result << '\n';
//}
