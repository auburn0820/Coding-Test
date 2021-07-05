//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//    int N;
//    cin >> N;
//    int ans;
//    
//    if(N < 100)
//        ans = N;
//    else {
//        int a, b, c;
//        int cnt = 0;
//        for(int i = 100; i <= N; i++) {
//            a = i / 100;
//            b = (i / 10) % 10;
//            c = i % 10;
//            
//            if((a - b) == (b - c))
//                cnt++;
//        }
//        ans = cnt + 99;
//    }
//    
//    cout << ans << '\n';
//}
