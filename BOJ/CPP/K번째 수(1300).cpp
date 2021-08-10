//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int n, k;
//
//void binarySearch(int left, int right) {
//    int ans = 0;
//    while(left <= right) {
//        int mid = (left + right) / 2;
//        long long result = 0;
//        
//        for(int i = 1; i <= n; i++) {
//            result += min(mid / i, n);
//        }
//        
//        if(result < k) {
//            left = mid + 1;
//        } else {
//            ans = mid;
//            right = mid - 1;
//        }
//    }
//    
//    cout << ans << '\n';
//}
//
//int main(void) {
//    scanf("%d\n%d", &n, &k);
//    
//    binarySearch(1, k);
//}
