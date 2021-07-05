//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//    int N, K;
//    cin >> N >> K;
//    
//    int cent[N];
//    
//    for(int i = N - 1; i >= 0; i--) {
//        cin >> cent[i];
//    }
//    
//    int cnt = 0;
//    
//    while(K != 0) {
//        for(int i = 0; i < N; i++) {
//            if(cent[i] <= K) {
//                K -= cent[i];
//                cnt++;
//                break;
//            }
//        }
//    }
//    
//    cout << cnt << '\n';
//}
