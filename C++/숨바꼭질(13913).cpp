//#include <iostream>
//#include <queue>
//#include <vector>
//
//using namespace std;
//
//int N, K;
//bool visit[100001];
//vector<int> v;
//int path[100001];
//
//void BFS(int x, int t) {
//    queue<pair<int, int>> q;
//    q.push({x, t});
//    
//    while(!q.empty()) {
//        int curX = q.front().first;
//        int time = q.front().second;
//        /*
//         여기서 visit[curX] = true를 선언한다면, q 사이즈가 커지고, 이 문제에서는 path 배열이 계속 쌓인다.
//         그러므로 올바른 경로가 다른 데이터로 바뀐다는 것이다.
//         그러므로 queue에 데이터를 삽입하는 동시에 visit 배열도 true로 채워주자.
//         */
//        q.pop();
//        
//        if(curX == K) {
//            cout << time << '\n';
//            int t = curX;
//            while(t != N) {
//                v.push_back(t);
//                t = path[t];
//            }
//            
//            v.push_back(t);
//            
//            for(int i = (int)v.size() - 1; i >= 0; i--) {
//                cout << v[i] << ' ';
//            }
//            cout << '\n';
//            return;
//        }
//        
//        
//        if(curX + 1 <= 100000) {
//            if(!visit[curX + 1]) {
//                visit[curX + 1] = true;
//                path[curX + 1] = curX;
//                q.push({curX + 1, time + 1});
//            }
//        }
//        if(curX - 1 >= 0) {
//            if(!visit[curX - 1]) {
//                visit[curX - 1] = true;
//                path[curX - 1] = curX;
//                q.push({curX - 1, time + 1});
//            }
//        }
//        if(curX * 2 <= 100000) {
//            if(!visit[curX * 2]) {
//                visit[curX * 2] = true;
//                path[curX * 2] = curX;
//                q.push({curX * 2, time + 1});
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
