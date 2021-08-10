//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, M;
//vector<int> v;
//
//bool binarySearch(int val, int first, int last) {
//    while(first <= last) {
//        int mid = (first + last) / 2;
//
//        if(v.at(mid) == val)
//            return true;
//        else if(v.at(mid) < val) {
//            first = mid + 1;
//        } else {
//            last = mid - 1;
//        }
//    }
//    
//    return false;
//}
//
//int main(void) {
//    cin.tie(NULL);
//    ios_base::sync_with_stdio(false);
//    cin >> N;
//
//    while(N--) {
//        int a;
//        cin >> a;
//        v.push_back(a);
//    }
//
//    sort(begin(v), end(v));
//
//    cin >> M;
//
//    while(M--) {
//        int a;
//        cin >> a;
//        cout << binarySearch(a, 0, (int)v.size() - 1) << '\n';
//    }
//}
