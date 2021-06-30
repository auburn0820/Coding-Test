//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N, M;
//int arr[1001][1001];
//int candy[1001][1001];
//
//int maxValue(int a, int b, int c) {
//    int val = a;
//    val = max(val, b);
//    val = max(val, c);
//    
//    return val;
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= M; j++) {
//            cin >> arr[i][j];
//        }
//    }
//    
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= M; j++) {
//            if(i == 1 && j > 1) {
//                candy[i][j] = candy[i][j - 1] + arr[i][j];
//            } else if(i > 1 && j == 1) {
//                candy[i][j] = candy[i - 1][j] + arr[i][j];
//            } else {
//                candy[i][j] = arr[i][j] + maxValue(candy[i - 1][j - 1], candy[i - 1][j], candy[i][j - 1]);
//            }
//        }
//    }
//    
//    cout << candy[N][M] << '\n';
//}
