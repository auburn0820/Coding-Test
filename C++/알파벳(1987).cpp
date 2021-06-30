//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int R, C;
//char board[20][20];
//bool alphabet[26];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int result = 0;
//
//void moveMeeple(int x, int y, int cnt) {
//    if(alphabet[board[y][x] - 'A'])
//        return;
//    
//    result = max(cnt, result);
//    alphabet[board[y][x] - 'A'] = true;
//    
//    for(int i = 0; i < 4; i++) {
//        int nextX = x + dx[i];
//        int nextY = y + dy[i];
//        
//        if(nextX < 0 || nextX >= C || nextY < 0 || nextY >= R)
//            continue;
//        
//        moveMeeple(nextX, nextY, cnt + 1);
//    }
//    
//    alphabet[board[y][x] - 'A'] = false;;
//}
//
//int main(void) {
//    cin >> R >> C;
//    
//    for(int i = 0; i < R; i++) {
//        string str;
//        cin >> str;
//        for(int j = 0; j < C; j++) {
//            board[i][j] = str[j];
//        }
//    }
//    
//    moveMeeple(0, 0, 1);
//    
//    cout << result << '\n';
//}
