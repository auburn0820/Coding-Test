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
//vector<int> path;
//int foot[1001];
//
//int djikstra() {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    
//    dist[src] = 0;
//    pq.push({src, 0});
////    path.push_back(src);
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
//                foot[there] = here;
//            }
//        }
//    }
//    
//    int here = dst;
//    while(here != src) {
//        path.push_back(here);
//        here = foot[here];
//    }
//    path.push_back(src);
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
//    }
//    
//    cin >> src >> dst;
//    
//    cout << djikstra() << '\n';
//    
//    cout << (int)path.size() << '\n';
//    
//    for(int i = (int)path.size() - 1; i >= 0; i--) {
//        cout << path.at(i) << ' ';
//    }
//    cout << '\n';
//}
