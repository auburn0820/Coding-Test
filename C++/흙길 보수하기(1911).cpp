//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//int N, L;
//vector<pair<int, int>> v;
//
//bool comp(pair<int, int> &a, pair<int, int> &b) {
//    return a.first < b.first;
//}
//
//int getLength() {
//    int result = 0;
//    int end = INT_MIN;
//    
//    for(int i = 0; i < (int)v.size(); i++) {
//        if(v[i].first > end)
//            end = v[i].first;
//        
//        while(end < v[i].second) {
//            end += L;
//            result++;
//        }
//    }
//    
//    return result;
//}
//
//int main(void) {
//    cin >> N >> L;
//    
//    for(int i = 0; i < N; i++) {
//        int a, b;
//        cin >> a >> b;
//        v.push_back({a, b});
//    }
//    
//    sort(begin(v), end(v), comp);
//    
//    cout << getLength() << '\n';
//}
