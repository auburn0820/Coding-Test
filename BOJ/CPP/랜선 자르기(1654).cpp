//#include <iostream>
//#include <vector>
//#include <climits>
//
//using namespace std;
//
//int K, N, maxNum = INT_MIN;
//vector<int> v;
//
//long long cutLanCable(long long length) {
//    long long result = 0;
//    
//    for(auto i : v) {
//        result += (i / length);
//    }
//    
//    return result;
//}
//
//long long binarySearch(long long left, long long right) {
//    long long result = INT_MIN;
//    while(left <= right) {
//        long long mid = (left + right) / 2;
//        long long numberOfCable = cutLanCable(mid);
//        
//        if(numberOfCable < N) {
//            right = mid - 1;
//        } else {
//            left = mid + 1;
//            result = max(result, mid);
//        }
//    }
//    
//    return result;
//}
//
//int main(void) {
//    cin >> K >> N;
//    
//    for(int i = 0; i < K; i++) {
//        int n;
//        cin >> n;
//        v.push_back(n);
//        maxNum = max(maxNum, n);
//    }
//    
//    cout << binarySearch(1, maxNum) << '\n';
//}
