//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int T, N;
//vector<pair<int, int>> v;
//
//bool comp(pair<int, int> &a, pair<int, int> &b) {
//    return a.first < b.first;
//}
//
//int checkEmployee() {
//    sort(v.begin(), v.end(), comp);
//    int cnt = 1;
//    int bound = v[0].second;
//    
//    for(int i = 1; i < (int)v.size(); i++) {
//        if(v[i].second < bound) {
//            cnt++;
//            bound = v[i].second;
//        }
//    }
//    
//    return cnt;
//}
//
//int main(void) {
//    cin >> T;
//    
//    while(T--) {
//        cin >> N;
//        for(int i = 0; i < N; i++) {
//            int a, b;
//            cin >> a >> b;
//            v.push_back({a, b});
//        }
//        
//        cout << checkEmployee() << '\n';
//        v.clear();
//    }
//}
