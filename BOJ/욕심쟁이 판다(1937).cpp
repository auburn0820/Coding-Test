//#include <iostream>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//int n;
//int arr[500][500];
//int DP[500][500];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int ans = INT_MIN;
//
//int letsGoGreedyPanda(int x, int y) {
//    if(DP[y][x] != 0)
//        return DP[y][x];
//    DP[y][x] = 1;
//    
//    for(int i = 0; i < 4; i++) {
//        int nextX = x + dx[i];
//        int nextY = y + dy[i];
//        
//        if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= n)
//            continue;
//        if(arr[nextY][nextX] <= arr[y][x])
//            continue;
//        
//        DP[y][x] = max(letsGoGreedyPanda(nextX, nextY) + 1, DP[y][x]);
//    }
//    
//    return DP[y][x];
//}
//
//int main(void) {
//    cin >> n;
//    
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) {
//            cin >> arr[i][j];
//        }
//    }
//    
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) {
//            ans = max(letsGoGreedyPanda(j, i), ans);
//        }
//    }
//    
//    cout << ans << '\n';
//}
