//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int n, result;
//int arr[500][500];
//int dist[500][500];
//
//int main(void) {
//    cin >> n;
//    
//    for(int i = 1; i <= n; i++) {
//        int idx = 0;
//        while(idx++ < i) {
//            int data;
//            cin >> data;
//            arr[i - 1][idx - 1] = data;
//        }
//    }
//    
//    dist[0][0] = arr[0][0];
//    
//    for(int i = 1; i < n; i++) {
//        for(int j = 0; j <= i; j++) {
//            if(j == 0) {
//                dist[i][j] = dist[i - 1][j] + arr[i][j];
//            } else if(j == i) {
//                dist[i][j] = dist[i - 1][j - 1] + arr[i][j];
//            } else {
//                dist[i][j] = max(dist[i - 1][j - 1] + arr[i][j], dist[i - 1][j] + arr[i][j]);
//            }
//        }
//    }
//    
//    result = *max_element(begin(dist[n - 1]), end(dist[n - 1]));
//    
//    cout << result << '\n';
//}
