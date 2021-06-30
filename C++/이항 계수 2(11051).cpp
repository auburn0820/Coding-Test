//#include <iostream>
//
//using namespace std;
//
//int N, K;
//long long dp[1001][1001];
//
//long long getBinomialCoefficient(int n, int r) {
//    for(int i = 0; i <= n; i++) {
//        for(int j = 0; j <= min(i, r); j++) {
//            if(j == 0 || j == i)
//                dp[i][j] = 1;
//            else
//                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
//        }
//    }
//    
//    return dp[n][r];
//}
//
//
//int main(void) {
//    cin >> N >> K;
//    
//    cout << getBinomialCoefficient(N, K) << '\n';
//}
