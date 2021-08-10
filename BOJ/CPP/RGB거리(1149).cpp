//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//int house[1001][3];
//int dist[1001][3];
//
//int main(void) {
//    cin >> N;
//    
//    for(int i = 0; i < 1; i++) {
//        for(int j = 0; j < 3; j++) {
//            house[i][j] = 0;
//            dist[i][j] = 0;
//        }
//    }
//    
//    for(int i = 1; i <= N; i++) {
//        for(int j = 0; j < 3; j++) {
//            cin >> house[i][j];
//        }
//    }
//    
//    for(int i = 1; i <= N; i++){
//        for(int j = 0; j < 3; j++) {
//            dist[i][j] = house[i][j];
//            
//            if(j == 0) {
//                dist[i][j] += min(dist[i - 1][1], dist[i - 1][2]);
//            } else if(j == 1) {
//                dist[i][j] += min(dist[i - 1][0], dist[i - 1][2]);
//            } else if(j == 2) {
//                dist[i][j] += min(dist[i - 1][0], dist[i - 1][1]);
//            }
//        }
//    }
//    
//    int result = 999999;
//    
//    for(int i = 0; i < 3; i++) {
//        if(result > dist[N][i])
//            result = dist[N][i];
//    }
//    
//    cout << result << '\n';
//}
