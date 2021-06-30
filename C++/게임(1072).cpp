//#include <iostream>
//
//using namespace std;
//
//long long x, y, z;
//int result;
//
//void binarySearch(int left, int right) {
//    while(left <= right) {
//        int mid = (left + right) / 2;
//        int winningRate = (int)((y + mid) * 100 / (x + mid));
//        
//        if(z >= winningRate) {
//            result = mid + 1;
//            left = mid + 1;
//        } else {
//            right = mid - 1;
//        }
//    }
//}
//
//int main(void) {
//    cin >> x >> y;
//    
//    z = (y * 100 / x);
//    
//    if(z >= 99) {
//        cout << -1 << '\n';
//        return 0;
//    }
//    
//    binarySearch(0, 1000000000);
//    
//    cout << result << '\n';
//}
