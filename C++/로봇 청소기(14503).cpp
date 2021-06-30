//#include <iostream>
//#define clean 2
//int maps[50][50] = {0, };
//int cnt = 1;
//const int north = 3, east = 2, south = 1, west = 0;
//int order = 0;
//
//int direction[] = {west, south, east, north}; // +1을 하는 기준으로 맞춰야할 것 같다.
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}; // 각각의 방향에 맞춰 이차원 배열 이동
//int back_X[] = {1, 0, -1, 0}, back_Y[] = {0, -1, 0, 1};
//bool returnFlag = false;
//
//void tracking(int currentDirection, int currentX, int currentY, int N, int M) {
//    
//    maps[currentY][currentX] = clean;
//    
//    
//    for(int i = 0; i < 4; i++) {
//        
//        if(returnFlag)
//            return;
//        
//        int nextDirection = direction[((currentDirection + 1) % 4 + i) % 4];
//        int nextX = currentX + dx[nextDirection];
//        int nextY = currentY + dy[nextDirection];
//        
//        if(maps[nextY][nextX] == 0) {
//            cnt += 1;
//            tracking(nextDirection, nextX, nextY, N, M);
//        }
//    }
//    
//    int backX = currentX + back_X[currentDirection];
//    int backY = currentY + back_Y[currentDirection];
//
//    if(maps[backY][backX] == 1) {
//        returnFlag = true;
//        return;
//    }
//
//    tracking(currentDirection, backX, backY, N, M);
//    return;
//}
//
//int main(void) {
//    int N, M;
//    int r, c, d;
//    
//    
//    std::cin >> N >> M;
//    std::cin >> r >> c >> d;
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            std::cin >> maps[i][j];
//        }
//    }
//    
//    d = direction[3 - d];
//    
//    tracking(d, c, r, N, M);
//    
//    std::cout << cnt << '\n';
//}
