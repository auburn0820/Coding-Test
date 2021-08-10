//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//    int N, count = 0;
//    cin >> N;
//    
//    while(N > 0) {
//        if((N % 5) == 0) {
//            count += (N / 5);
//            N %= 5;
//            break;
//        } else if((N % 3) == 0) {
//            N -= 3;
//            count++;
//        } else {
//            N -= 5;
//            count++;
//        }
//    }
//    
//    if(N == 0)
//        cout << count << '\n';
//    else
//        cout << -1 << '\n';
//}
