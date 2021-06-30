//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//int N, M;
//long long result = LONG_LONG_MIN;
//vector<int> v;
//
//long long cutTree(int height) {
//    long long wood = 0;
//
//    for(int i = 0; i < (int)v.size(); i++) {
//        if(v[i] > height)
//            wood += v[i] - height;
//    }
//
//    return wood;
//}
//
//void binarySearch(int left, int right) {
//    int mid = 0;
//
//    while(left <= right) {
//        mid = (left + right) / 2;
//        long long tree = cutTree(mid);
//
//        if(tree < M) {
//            right = mid - 1;
//        } else {
//            left = mid + 1;
//            result = max(result, (long long)mid);
//        }
//    }
//}
//
//int main(void) {
//    cin >> N >> M;
//
//    for(int i = 0; i < N; i++) {
//        int n;
//        cin >> n;
//        v.push_back(n);
//    }
//
//    binarySearch(0, 1000000000);
//
//    cout << result << '\n';
//}
