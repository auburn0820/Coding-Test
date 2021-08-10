//#include <iostream>
//
//using namespace std;
//
//int N;
//int result;
//int romeNum[] = {1, 5, 10, 50};
//int selectedNum[20];
//bool visit[1001];
//
//
//void combinationWithRepetition(int cnt, int idx) {
//    if(cnt == N) {
//        int num = 0;
//        for(int i = 0; i < N; i++) {
//            num += selectedNum[i];
//        }
//        
//        if(!visit[num])
//            result++;
//        visit[num] = true;
//        return;
//    }
//    
//    for(int i = idx; i < 4; i++) {
//        selectedNum[cnt] = romeNum[i];
//        combinationWithRepetition(cnt + 1, i);
//    }
//}
//
//int main(void) {
//    cin >> N;
//    
//    combinationWithRepetition(0, 0);
//    
//    cout << result << '\n';
//}
