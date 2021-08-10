//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, C;
//int last;
//vector<int> v;
//
//int installHub(int distance) {
//    int cnt = 1;
//    int startingPoint = v.at(0);
//    
//    for(int i = 1; i < N; i++) {
//        int distanceBetweenHub = v.at(i) - startingPoint;
//        if(distance <= distanceBetweenHub) {
//            cnt++;
//            startingPoint = v.at(i);
//        }
//    }
//    
//    return cnt;
//}
//
//int binarySearch(int left, int right) {
//    int result = 0;
//    while(left <= right) {
//        int mid = (left + right) / 2;
//        int cnt = installHub(mid);
//        
//        if(cnt >= C) {
//            left = mid + 1;
//            result = mid;
//        } else {
//            right = mid - 1;
//        }
//    }
//    
//    return result;
//}
//
//int main(void) {
//    cin >> N >> C;
//    
//    for(int i = 0; i < N; i++) {
//        int n;
//        cin >> n;
//        v.push_back(n);
//    }
//    
//    sort(v.begin(), v.end());
//    
//    cout << binarySearch(1, v.at(N - 1) - v.at(0)) << '\n';
//}
