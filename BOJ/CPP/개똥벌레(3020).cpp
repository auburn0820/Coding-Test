//#include <iostream>
//#include <vector>
//#include <climits>
//#include <algorithm>
//
//using namespace std;
//
//int N, H;
//vector<int> stalactite;
//vector<int> stalagmite;
//vector<int> answer;
//
//int countCollision(int height) {
//    int ans = 0;
//    
//    ans += lower_bound(stalagmite.begin(), stalagmite.end(), height) - stalagmite.begin();
//    ans += upper_bound(stalactite.begin(), stalactite.end(), H - height) - stalactite.begin();
//    
//    return N - ans;
//}
//
//int main(void) {
//    cin >> N >> H;
//    
//    for(int i = 0; i < N; i++) {
//        int n;
//        cin >> n;
//        if(i % 2 == 0)
//            stalagmite.push_back(n);
//        else {
//            stalactite.push_back(n);
//        }
//    }
//    
//    sort(stalagmite.begin(), stalagmite.end());
//    sort(stalactite.begin(), stalactite.end());
//    
//    int ans = INT_MAX;
//    int cnt = 1;
//    
//    for(int i = 1; i <= H; i++) {
//        answer.push_back(countCollision(i));
//    }
//    
//    sort(answer.begin(), answer.end());
//    
//    ans = answer.at(0);
//    answer.erase(answer.begin());
//    
//    for(auto &i : answer) {
//        if(ans == i)
//            cnt++;
//    }
//    
//    cout << ans << ' ' << cnt << '\n';
//}
