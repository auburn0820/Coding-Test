//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <queue>
//
//using namespace std;
//
//#define INF 99999
//
//vector<pair<int, int>> maps[20001];
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//bool visit[20001];
//int weight[20001];
//int v, e, startVertex;
//
//void Dijkstra() {
//    weight[startVertex] = 0;
//    pq.push({0, startVertex});
//    while(!pq.empty()) {
//        int curVertex;
//        do {
//            curVertex = pq.top().second;
//            pq.pop();
//        } while(!pq.empty() && visit[curVertex]);
//        
//        if(visit[curVertex])
//            break;
//        
//        visit[curVertex] = true;
//        
//        for(auto &destination: maps[curVertex]) {
//            int next = destination.first;
//            int dist = destination.second;
//            
//            if(weight[next] > weight[curVertex] + dist) {
//                weight[next] = weight[curVertex] + dist;
//                pq.push(make_pair(weight[next], next));
//            }
//        }
//    }
//}
//
//
//int main(void) {
//    cin >> v >> e >> startVertex;
//    startVertex--;
//    
//    while(e--) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        maps[a - 1].push_back(make_pair(b - 1, c));
//    }
//    
//    fill(weight, weight + v, INF);
//    memset(visit, false, sizeof(visit));
//    
//    Dijkstra();
//    
//    for(int i = 0; i < v; i++) {
//        if(weight[i] == INF)
//            cout << "INF\n";
//        else
//            cout << weight[i] << '\n';
//    }
//}
