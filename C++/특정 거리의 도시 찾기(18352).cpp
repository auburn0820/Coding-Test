//#include <iostream>
//#include <queue>
//#include <climits>
//#include <vector>
//
//#define INF INT_MAX
//
//using namespace std;
//
//int N, M, K, X;
//
//vector<pair<int, int>> adj[300001];
//vector<int> dist(300001, INF);
//
//void dijkstra() {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    dist[X] = 0;
//
//    pq.push({0, X});
//
//    while(!pq.empty()) {
//        int cost = pq.top().first;
//        int idx = pq.top().second;
//        pq.pop();
//
//        if(dist[idx] < cost)
//            continue;
//
//        for(int i = 0; i < (int)adj[idx].size(); i++) {
//            int dst = adj[idx][i].first;
//            int newCost = cost + adj[idx][i].second;
//
//            if(dist[dst] > newCost) {
//                dist[dst] = newCost;
//                pq.push({newCost, dst});
//            }
//        }
//    }
//}
//
//int main(void) {
//    cin >> N >> M >> K >> X;
//
//    for(int i = 0; i < M; i++) {
//        int a, b;
//        cin >> a >> b;
//        adj[a].push_back({b, 1});
//    }
//
//    dijkstra();
//
//    bool flag = false;
//
//    for(int i = 1; i <= N; i++) {
//        if(dist[i] == K) {
//            cout << i << '\n';
//            flag = true;
//        }
//    }
//
//    if(!flag)
//        cout << -1 << '\n';
//}
