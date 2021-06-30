//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main(void) {
//    int N;
//    cin >> N;
//
//    vector<pair<int, int>> v;
//
//    for(int i = 0; i < N; i++) {
//        int weight, height;
//        cin >> weight >> height;
//        v.push_back({weight, height});
//    }
//    
//    for(int i = 0; i < (int)v.size(); i++) {
//        int cnt = 1;
//        for(int j = 0; j < (int)v.size(); j++) {
//            if(i == j)
//                continue;
//            if(v[i].first < v[j].first && v[i].second < v[j].second)
//                cnt++;
//        }
//        cout << cnt << ' ';
//    }
//    cout << '\n';
//}
