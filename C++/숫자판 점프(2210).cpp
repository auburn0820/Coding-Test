//#include <iostream>
//
//using namespace std;
//
//char arr[5][5];
//bool visit[999999];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int result;
//
//void findNum(int x, int y, int cnt, string cur) {
//    
//    cur += arr[x][y];
//    
//    if(cnt == 6) {
//        int curNum = stoi(cur);
//        if(!visit[curNum]) {
//            result++;
//            visit[curNum] = true;
//        }
//        return;
//    }
//    
//    for(int i = 0; i < 4; i++) {
//        int nextX = x + dx[i];
//        int nextY = y + dy[i];
//        
//        if(nextX >= 0 && nextX < 5 && nextY >= 0 && nextY < 5)
//            findNum(nextX, nextY, cnt + 1, cur);
//    }
//}
//
//int main(void) {
//    for(int i = 0; i < 5; i++) {
//        for(int j = 0; j < 5; j++) {
//            cin >> arr[i][j];
//        }
//    }
//    
//    for(int i = 0; i < 5; i++) {
//        for(int j = 0; j < 5; j++) {
//            findNum(i, j, 1, "");
//        }
//    }
//    
//    cout << result << '\n';
//}
