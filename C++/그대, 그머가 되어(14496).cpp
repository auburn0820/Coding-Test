//#include <iostream>
//#include <queue>
//#include <climits>
//
//using namespace std;
//
//int a, b, N, M;
//vector<int> adj[1001];
//vector<int> dist(10001, INT_MAX);
//
//int djikstra() {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    
//    dist[a] = 0;
//    pq.push({a, 0});
//    
//    while(!pq.empty()) {
//        int source = pq.top().first;
//        int distance = pq.top().second;
//        
//        pq.pop();
//        
//        if(distance > dist[source])
//            continue;
//        
//        for(int i = 0; i < (int)adj[source].size(); i++) {
//            int destination = adj[source][i];
//            int cost = distance + 1;
//            
//            if(dist[destination] > cost) {
//                dist[destination] = cost;
//                pq.push({destination, cost});
//            }
//        }
//    }
//    
//    if(dist[b] == INT_MAX)
//        return -1;
//    else
//        return dist[b];
//}
//
//int main(void) {
//    cin >> a >> b >> N >> M;
//    
//    for(int i = 0; i < M; i++) {
//        int n, k;
//        cin >> n >> k;
//        adj[n].push_back(k);
//        adj[k].push_back(n);
//    }
//    
//    cout << djikstra() << '\n';
//}
