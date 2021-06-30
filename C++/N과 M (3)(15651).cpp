//#include <iostream>
//
//using namespace std;
//
//int N, M;
//int arr[7];
//
//void permutation(int cur, int cnt) {
//    
//    arr[cnt - 1] = cur;
//    
//    if(cnt == M) {
//        for(int i = 0; i < M; i++) {
//            cout << arr[i] << ' ';
//        }
//        cout << '\n';
//        return;
//    }
//    
//    for(int i = 0; i < N; i++) {
//        permutation(i + 1, cnt + 1);
//    }
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < N; i++) {
//        permutation(i + 1, 1);
//    }
//}
