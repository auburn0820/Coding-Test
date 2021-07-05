//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//char board[51][51];
//int N, M;
//
//string whiteFirstBoard[8] = {
//    { "WBWBWBWB" },
//    { "BWBWBWBW" },
//    { "WBWBWBWB" },
//    { "BWBWBWBW" },
//    { "WBWBWBWB" },
//    { "BWBWBWBW" },
//    { "WBWBWBWB" },
//    { "BWBWBWBW" }
//};
//
//string blackFirstBoard[8] = {
//    { "BWBWBWBW" },
//    { "WBWBWBWB" },
//    { "BWBWBWBW" },
//    { "WBWBWBWB" },
//    { "BWBWBWBW" },
//    { "WBWBWBWB" },
//    { "BWBWBWBW" },
//    { "WBWBWBWB" }
//};
//
//int checkBoard(int x, int y) {
//    int cntBlackFirst = 0;
//    int cntWhiteFirst = 0;
//
//    for(int i = x; i < x + 8; i++) {
//        for(int j = y; j < y + 8; j++) {
//            if(board[i][j] != blackFirstBoard[i - x][j - y])
//                cntBlackFirst++;
//        }
//    }
//
//    for(int i = x; i < x + 8; i++) {
//        for(int j = y; j < y + 8; j++) {
//            if(board[i][j] != whiteFirstBoard[i - x][j - y])
//                cntWhiteFirst++;
//        }
//    }
//
//    return min(cntWhiteFirst, cntBlackFirst);
//}
//
//int main(void) {
//    cin >> N >> M;
//    int ans = 9999;
//
//    for(int i = 0; i < N; i++)
//        cin >> board[i];
//
//    for(int i = 0; i + 7 < N; i++)
//        for(int j = 0; j + 7 < M; j++)
//            ans = min(ans, checkBoard(i, j));
//
//    cout << ans << '\n';
//}
