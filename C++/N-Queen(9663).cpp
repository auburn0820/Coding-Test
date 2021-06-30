//#include <iostream>
//#include <cmath>
//
//using namespace std;
//
//int N;
//int chessBoard[15];
//int result = 0;
//
//void setQueen(int x) {
//    if(x == N) {
//        result++;
//        return;
//    }
//    
//    for(int i = 0; i < N; i++) {
//        bool flag = true;
//        for(int j = 0; j < x; j++) {
//            if(chessBoard[j] == i || abs(x - j) == abs(i - chessBoard[j])) {
//                flag = false;
//                break;
//            }
//        }
//        if(flag) {
//            chessBoard[x] = i;
//            setQueen(x + 1);
//        }
//    }
//}
//
//int main(void) {
//    cin >> N;
//
//    setQueen(0);
//    
//    cout << result << '\n';
//}
