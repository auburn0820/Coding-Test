//#include <iostream>
//#include <queue>
//#include <cstring>
//#include <vector>
//
//using namespace std;
//
//int N;
//int cave[125][125];
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//
//struct LocInfo {
//    int cost, x, y;
//};
//
//struct comp {
//    bool operator() (const LocInfo &a, const LocInfo &b) {
//        return a.cost >= b.cost;
//    }
//};
//
//void djikstra(int *idx) {
//    priority_queue<LocInfo, vector<LocInfo>, comp> pq;
//    int dist[125][125];
//    memset(dist, -1, sizeof(dist));
//    
//    dist[0][0] = cave[0][0];
//    pq.push({cave[0][0], 0, 0});
//    
//    while(!pq.empty()) {
//        int curX = pq.top().x;
//        int curY = pq.top().y;
//        int curCost = pq.top().cost;
//        pq.pop();
//        
//        if(curX == N - 1 && curY == N - 1) {
//            cout << "Problem " << *idx << ": " << dist[N - 1][N - 1] << '\n';
//            (*idx)++;
//            return;
//        }
//        
//        if(cave[curY][curX] != -1 && dist[curY][curX] < curCost)
//            continue;
//        
//        for(int i = 0; i < 4; i++) {
//            int nextX = curX + dx[i];
//            int nextY = curY + dy[i];
//            
//            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
//                continue;
//            int nextCost = curCost + cave[nextY][nextX];
//            
//            if(nextCost < dist[nextY][nextX] || dist[nextY][nextX] == -1) {
//                dist[nextY][nextX] = nextCost;
//                pq.push({nextCost, nextX, nextY});
//            }
//            
//        }
//    }
//}
//
//int main(void) {
//    int idx = 1;
//    do {
//        cin >> N;
//        for(int i = 0; i < N; i++) {
//            for(int j = 0; j < N; j++) {
//                cin >> cave[i][j];
//            }
//        }
//        djikstra(&idx);
//    } while(N != 0);
//}
