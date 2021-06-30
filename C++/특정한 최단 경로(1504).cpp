//#include <iostream>
//#include <vector>
//#include <queue>
//#include <climits>
//
//using namespace std;
//
//int N, E, path1, path2;
//vector<pair<int, int>> adj[801];
//vector<int> dist;
//int minCost1, minCost2;
//int result;
//
//void djikstra(int src, int dst) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    dist.clear();
//    dist.resize(801, 800001);
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
//}
//
//int main(void) {
//    cin >> N >> E;
//
//    for(int i = 0; i < E; i++) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        adj[a].push_back({b, c});
//        adj[b].push_back({a, c});
//    }
//
//    cin >> path1 >> path2;
//
//    djikstra(1, N);
//    minCost1 += dist[path1];
//    minCost2 += dist[path2];
//
//    djikstra(path1, N);
//    minCost1 += dist[path2];
//    minCost2 += dist[N];
//
//    djikstra(path2, N);
//    minCost1 += dist[N];
//    minCost2 += dist[path1];
//
//    result = min(minCost1, minCost2);
//
//    if(result > 80001)
//        cout << - 1 << '\n';
//    else
//        cout << result << '\n';
//}
