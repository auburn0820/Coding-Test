//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int N, K;
//bool visit[100001];
//int minTime;
//
//void getMinTimeAndCases() {
//    deque<pair<int, int>> q;
//    q.push_back({N, 0});
//    visit[N] = true;
//
//    while(!q.empty()) {
//        int curPostion = q.front().first;
//        int curCnt = q.front().second;
//        q.pop_front();
//
//        if(curPostion == K) {
//            minTime = curCnt;
//            return;
//        }
//
//        if(curPostion * 2 <= 100000 && !visit[curPostion * 2]) {
//            q.push_front({curPostion * 2, curCnt});
//            visit[curPostion * 2] = true;
//        }
//        if(curPostion + 1 <= 100000 && !visit[curPostion + 1]) {
//            q.push_back({curPostion + 1, curCnt + 1});
//            visit[curPostion + 1] = true;
//        }
//        if(curPostion - 1 >= 0 && !visit[curPostion - 1]) {
//            q.push_back({curPostion - 1, curCnt + 1});
//            visit[curPostion - 1] = true;
//        }
//
//    }
//}
//
//int main(void) {
//    cin >> N >> K;
//
//    getMinTimeAndCases();
//
//    cout << minTime << '\n';
//}
