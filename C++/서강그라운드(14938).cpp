//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//int n, m, r;
//int items[101];
//vector<pair<int, int>> adj[101];
//vector<int> dist(101);
//int ans = INT_MIN;
//
//void checkCanGetItems() {
//    int itemCnt = 0;
//
//    for(int i = 1; i <= n; i++) {
//        if(dist[i] <= m)
//            itemCnt += items[i];
//    }
//
//    ans = max(ans, itemCnt);
//}
//
//void djikstra(int start) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//
//    pq.push({start, 0});
//    dist[start] = 0;
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
//            int thereCost = cost + adj[here][i].second;
//
//            if(thereCost < dist[there]) {
//                dist[there] = thereCost;
//                pq.push({there, thereCost});
//            }
//        }
//    }
//}
//
//int main(void) {
//    cin >> n >> m >> r;
//
//    for(int i = 1; i <= n; i++) {
//        int t;
//        cin >> t;
//        items[i] = t;
//    }
//
//    for(int i = 0; i < r; i++) {
//        int a, b, l;
//        cin >> a >> b >> l;
//        adj[a].push_back({b, l});
//        adj[b].push_back({a, l});
//    }
//
//    for(int i = 1; i <= n; i++) {
//        fill(dist.begin(), dist.end(), INT_MAX);
//        djikstra(i);
//        checkCanGetItems();
//    }
//
//    cout << ans << '\n';
//}
