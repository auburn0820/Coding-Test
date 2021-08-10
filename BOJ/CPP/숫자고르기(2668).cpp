//#include <iostream>
//
//using namespace std;
//
//int N;
//int cnt;
//int v[101];
//bool visit[101];
//bool cycle[101];
//
//bool findMaxValue(int start, int curPos) {
//   if(visit[curPos])
//       return false;
//    
//    visit[curPos] = true;
//    
//    if(start == curPos || findMaxValue(start, v[curPos])) {
//        cnt++;
//        cycle[curPos] = true;
//        return true;
//    }
//    
//    return false;
//}
//
//int main(void) {
//    cin >> N;
//    
//    for(int i = 1; i <= N; i++) {
//        cin >> v[i];
//    }
//    
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++) {
//            visit[j] = cycle[j];
//        }
//        findMaxValue(i, v[i]);
//    }
//    
//    cout << cnt << '\n';
//    
//    for(int i = 1; i <= N; i++) {
//        if(cycle[i])
//            cout << i << '\n';
//    }
//}
