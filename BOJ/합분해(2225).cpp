//#include <iostream>
//
//long long arr[201][201] = {0, };
//
//int main(void) {
//    const int mod = 1000000000;
//    int N, K;
//
//    std::cin >> N >> K;
//
//    for(int i = 0; i <= N; i++)
//        arr[1][i] = 1;
//
//    for(int i = 2; i <= K; i++) {
//        for(int j = 0; j <= N; j++) {
//            for(int k = 0; k <= j; k++) {
//                arr[i][j] += arr[i - 1][j - k];
//                arr[i][j] %= mod;
//            }
//        }
//    }
//
//    std::cout << arr[K][N] << '\n';
//}
