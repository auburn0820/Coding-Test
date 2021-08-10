//#include <iostream>
//#include <queue>
//#include <climits>
//
//using namespace std;
//
//int N, K;
//bool visit[100001];
//int minTime = INT_MAX;
//int numberOfCases;
//
//void getMinTimeAndCases() {
//    queue<pair<int, int>> q;
//    q.push({N, 0});
//    
//    while(!q.empty()) {
//        int curPostion = q.front().first;
//        int curCnt = q.front().second;
//        visit[curPostion] = true;
//        q.pop();
//        
//        if(curPostion == K) {
//            minTime = min(minTime, curCnt);
//            if(minTime == curCnt) {
//                numberOfCases++;
//                continue;
//            }
//        }
//        
//        
//        if(curPostion + 1 <= 100000 && !visit[curPostion + 1]) {
//            q.push({curPostion + 1, curCnt + 1});
//        }
//        if(curPostion - 1 >= 0 && !visit[curPostion - 1]) {
//            q.push({curPostion - 1, curCnt + 1});
//        }
//        if(curPostion * 2 <= 100000 && !visit[curPostion * 2]) {
//            q.push({curPostion * 2, curCnt + 1});
//        }
//    }
//}
//
//int main(void) {
//    cin >> N >> K;
//    
//    getMinTimeAndCases();
//    
//    cout << minTime << '\n' << numberOfCases << '\n';
//}
