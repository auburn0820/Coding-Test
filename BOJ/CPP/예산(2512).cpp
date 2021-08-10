//#include <iostream>
//#include <vector>
//#include <climits>
//
//using namespace std;
//
//int N, M;
//vector<int> v;
//
//long long calBudget(int limit) {
//    long long result = 0;
//    
//    for(auto i : v) {
//        if(i < limit)
//            result += i;
//        else
//            result += limit;
//    }
//    
//    return result;
//}
//
//int binarySearch(int left, int right) {
//    long long result;
//    int ans = INT_MIN;
//    
//    while(left <= right) {
//        int mid = (left + right) / 2;
//        result = calBudget(mid);
//        
//        if(result > M) {
//            right = mid - 1;
//        } else {
//            left = mid + 1;
//            ans = max(ans, mid);
//        }
//    }
//    
//    return ans;
//}
//
//int main(void) {
//    cin >> N;
//    int maxBudget = 0;
//    for(int i = 0; i < N; i++) {
//        int n;
//        cin >> n;
//        v.push_back(n);
//        maxBudget = max(maxBudget, n);
//    }
//    
//    cin >> M;
//    
//    cout << binarySearch(0, maxBudget) << '\n';
//}
