//#include <iostream>
//
//using namespace std;
//
//int N, M;
//int basckets[100];
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < N; i++) {
//        basckets[i] = i + 1;
//    }
//    
//    for(int i = 0; i < M; i++) {
//        int a, b;
//        cin >> a >> b;
//        swap(basckets[a - 1], basckets[b - 1]);
//    }
//    
//    for(int i = 0; i < N; i++) {
//        cout << basckets[i] << ' ';
//    }
//    cout << '\n';
//}
