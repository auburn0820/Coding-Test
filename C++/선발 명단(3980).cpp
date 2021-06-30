//#include <iostream>
//#include <climits>
//#include <algorithm>
//
//using namespace std;
//
//int t;
//int arr[11][11];
//bool visit[11];
//int ans = INT_MIN;
//
//void getMaxOfAbilityValue(int idx, int cnt, int sum) {
//    if(cnt == 11) {
//        ans = max(sum, ans);
//        return;
//    }
//    
//    for(int i = 0; i < 11; i++) {
//        if(visit[i] || arr[idx][i] == 0)
//            continue;
//        visit[i] = true;
//        getMaxOfAbilityValue(idx + 1, cnt + 1, sum + arr[idx][i]);
//        visit[i] = false;
//    }
//}
//
//int main(void) {
//    cin >> t;
//    
//    while(t--) {
//        for(int i = 0; i < 11; i++) {
//            for(int j = 0; j < 11; j++) {
//                cin >> arr[i][j];
//            }
//        }
//        
//        getMaxOfAbilityValue(0, 0, 0);
//        
//        cout << ans << '\n';
//        ans = INT_MIN;
//    }
//}
