//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int N, K;
//bool visit[100001];
//int moving[] = {1, -1, 2};
//
//void BFS(int x, int t) {
//    queue<pair<int, int>> q;
//    q.push({x, t});
//    
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int time = q.front().second;
//        q.pop();
//        visit[curX] = true;
//        
//        if(curX == K) {
//            cout << time << '\n';
//            return;
//        }
//        
//        for(int i = 0; i < 3; i++) {
//            if(i != 2) {
//                if((curX + moving[i] >= 0) && (curX + moving[i] <= 100000) && !visit[curX + moving[i]])
//                    q.push({curX + moving[i], time + 1});
//            } else {
//                if((curX * moving[i]) <= 100000 && !visit[curX * moving[i]])
//                    q.push({curX * moving[i], time + 1});
//            }
//        }
//    }
//}
//
//int main(void) {
//    cin >> N >> K;
//    
//    BFS(N, 0);
//}
