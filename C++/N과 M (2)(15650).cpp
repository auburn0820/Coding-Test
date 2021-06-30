//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N, M;
//int comb[8];
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < M; i++) {
//        comb[i] = 1;
//    }
//    
//    sort(comb, comb + N, greater<>());
//    
//    do {
//        for(int i = 0; i < N; i++) {
//            if(comb[i] == 1)
//                cout << i + 1 << ' ';
//        }
//        cout << '\n';
//    } while(prev_permutation(comb, comb + N));
//}
