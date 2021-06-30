///*
// 경우의 수를 계산하는 문제이므로 조합을 이용해야겠다는 생각으로 접근했다. 조합을 구현하려면 DFS로 짜야했다.
// 또한 가로, 세로, 대각선인 경우의 수를 모두 조건문으로 만들었고, 각 조건문마다 어떻게 옮기는 지에 대한 조건문도 넣었다.
// 코드 결과물이 굉장히 복잡하고 깔끔함과는 거리가 멀다. 조금 더 짧게 짤 수 있는 방법을 생각해야겠다.
// */
//
//#include <iostream>
//
//typedef struct {
//    int x, y;
//}direction;
//
//int maps[17][17] = {0, };
//int cnt = 0;
//direction dir[] = {{1, 0}, {0, 1}, {1, 1}};
//
//void DFS(int x, int y, int N, int direction) {
//    if(x == N - 1 && y == N - 1) {
//        cnt += 1;
//        return;
//    }
//    
//    if(x >= N || y >= N)
//        return;
//    
//    if(direction == 1) { // 가로
//        if(maps[x][y + 1] == 0)
//            DFS(x, y + 1, N, 1);
//        if(maps[x + 1][y] == 0 && maps[x][y + 1] == 0 && maps[x + 1][y + 1] == 0)
//            DFS(x + 1, y + 1, N, 3);
//    }
//    else if(direction == 2) { // 세로
//        if(maps[x + 1][y] == 0)
//            DFS(x + 1, y, N, 2);
//        if(maps[x + 1][y] == 0 && maps[x][y + 1] == 0 && maps[x + 1][y + 1] == 0)
//            DFS(x + 1, y + 1, N, 3);
//    }
//    else if(direction == 3) { // 대각
//        if(maps[x][y + 1] == 0)
//            DFS(x, y + 1, N, 1);
//        if(maps[x + 1][y] == 0)
//            DFS(x + 1, y, N, 2);
//        if(maps[x + 1][y] == 0 && maps[x][y + 1] == 0 && maps[x + 1][y + 1] == 0)
//            DFS(x + 1, y + 1, N, 3);
//    }
//}
//
//int main(void) {
//    int N;
//    std::cin >> N;
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            std::cin >> maps[i][j];
//        }
//    }
//    
//    DFS(0, 1, N, 0);
//    
//    std::cout << cnt << '\n';
//}
