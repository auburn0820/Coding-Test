//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int N, M;
//int arr[101];
//bool visit[101];
//
//void minValue() {
//    queue<pair<int, int>> q;
//    q.push({1, 0});
//    
//    while(!q.empty()) {
//        int curPos = q.front().first;
//        int curCnt = q.front().second;
//        q.pop();
//        
//        if(curPos == 100) {
//            cout << curCnt << '\n';
//            return;
//        }
//        
//        for(int i = 1; i <= 6; i++) {
//            int nextPos = curPos + i;
//            if(nextPos <= 100 && !visit[nextPos]) {
//                if(arr[nextPos] != 0) {
//                    q.push({arr[nextPos], curCnt + 1});
//                    visit[arr[nextPos]] = true;
//                } else {
//                    q.push({nextPos, curCnt + 1});
//                    visit[nextPos] = true;
//                }
//            }
//        }
//    }
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 1; i <= N; i++) {
//        int a, b;
//        cin >> a >> b;
//        arr[a] = b;
//    }
//    
//    for(int i = 1; i <= M; i++) {
//        int a, b;
//        cin >> a >> b;
//        arr[a] = b;
//    }
//    
//    minValue();
//}
