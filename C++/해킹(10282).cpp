//#include <iostream>
//#include <queue>
//#include <vector>
//#include <climits>
//#include <algorithm>
//
//using namespace std;
//
//const int maxNode = 10001;
//int t, n, d, c, a, b, s;
//vector<pair<int, int>> adj[maxNode];
//int dist[maxNode];
//int result, totalCost = -1;
//
//void djikstra(const int start) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    dist[start] = 0;
//    pq.push({start, 0});
//    
//    while(!pq.empty()) {
//        int here = pq.top().first;
//        int cost = pq.top().second;
//        
//        pq.pop();
//        
//        if(dist[here] < cost)
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
//}
//
//int main(void) {
//    cin >> t;
//    
//    while(t--) {
//        fill(dist, dist + maxNode, INT_MAX);
//        for(auto &i : adj)
//            i.clear();
//        
//        result = 0;
//        totalCost = -1;
//        cin >> n >> d >> c;
//        for(int i = 0; i < d; i++) {
//            cin >> a >> b >> s;
//            adj[b].push_back({a, s});
//        }
//        
//        djikstra(c);
//        
//        for(int i = 1; i <= n; i++) {
//            if(dist[i] == INT_MAX)
//                continue;
//            
//            result++;
//            totalCost = max(totalCost, dist[i]);
//        }
//        
//        cout << result << ' ' << totalCost << '\n';
//    }
//}
