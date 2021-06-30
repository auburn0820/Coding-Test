//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool comp(const pair<int, int> &a, const pair<int, int> &b) {
//    if(a.second < b.second)
//        return true;
//    else if(a.second == b.second)
//        return a.first < b.first;
//    return false;
//}
//
//int main(void) {
//    vector<pair<int, int>> v;
//    int N, cnt = 0, end = 0;
//    cin >> N;
//    
//    while(N--) {
//        int a, b;
//        cin >> a >> b;
//        v.push_back({a, b});
//    }
//    
//    sort(v.begin(), v.end(), comp);
//    
//    for(int i = 0; i < (int)v.size(); i++) {
//        if(v[i].first >= end) {
//            cnt++;
//            end = v[i].second;
//        }
//    }
//    
//    cout << cnt << '\n';
//}
