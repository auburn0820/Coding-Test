//#include <iostream>
//#include <vector>
//#include <climits>
//#include <queue>
//
//using namespace std;
//
//int N, M, src, dst;
//vector<pair<int, int>> adj[1001];
//vector<int> dist(1001, INT_MAX);
//
//int djikstra() {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    
//    dist[src] = 0;
//    pq.push({src, 0});
//    
//    while(!pq.empty()) {
//        int here = pq.top().first;
//        int cost = pq.top().second;
//        
//        pq.pop();
//        
//        if(cost > dist[here])
//            continue;
//        
//        for(int i = 0; i < (int)adj[here].size(); i++) {
//            int there = adj[here][i].first;
//            int newCost = cost + adj[here][i].second;
//            
//            if(newCost < dist[there]) {
//                dist[there] = newCost;
//                pq.push({there, newCost});
//            }
//        }
//    }
//    
//    return dist[dst];
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < M; i++) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        adj[a].push_back({b, c});
////        adj[b].push_back({a, c});
//    }
//    
//    cin >> src >> dst;
//    
//    cout << djikstra() << '\n';
//}
