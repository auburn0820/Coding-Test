//#include <iostream>
//
//using namespace std;
//
//int N, K;
//
//int getBinomialCoefficient(int n, int r) {
//    if(n == r || r == 0)
//        return 1;
//    
//    return getBinomialCoefficient(n - 1, r - 1) + getBinomialCoefficient(n - 1, r);
//}
//
//int main(void) {
//    cin >> N >> K;
//    
//    cout << getBinomialCoefficient(N, K) << '\n';
//}
