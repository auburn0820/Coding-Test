//#include <iostream>
//#include <vector>
//#include <climits>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//int N, M, minNum = INT_MAX;
//vector<pair<int, int>> v;
//
//bool comp(pair<int, int> &a, pair<int, int> &b) {
//    return a.second < b.second;
//}
//
//int getMinDistance(int x, int y) {
//    int sum = 0;
//
//    for(auto i : v) {
//        int difX = abs(i.first - x);
//        int difY = abs(i.second - y);
//        sum += difX + difY;
//    }
//
//    return sum;
//}
//
//int getMedian() {
//    int x, y;
//    x = y = 0;
//
//    sort(v.begin(), v.end());
//
//    if((int)v.size() % 2 == 0) {
//        x = (v[(int)v.size() / 2].first + v[((int)v.size() / 2) - 1].first) / 2;
//    } else {
//        x = v[(int)v.size() / 2].first;
//    }
//
//    sort(v.begin(), v.end(), comp);
//
//    if((int)v.size() % 2 == 0) {
//        y = (v[(int)v.size() / 2].second + v[((int)v.size() / 2) - 1].second) / 2;
//    } else {
//        y = v[(int)v.size() / 2].second;
//    }
//
//
//    return getMinDistance(x, y);
//}
//
//int main(void) {
//    cin >> N >> M;
//
//    for(int i = 0; i < M; i++) {
//        int a, b;
//        cin >> a >> b;
//        v.push_back({a, b});
//    }
//
//    minNum = min(minNum, getMedian());
//
//    cout << minNum << '\n';
//}
