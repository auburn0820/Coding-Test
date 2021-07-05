//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int T;
//int n, m, t;
//int s, g, h;
//int a, b, d;
//int x;
//
//vector<pair<int, int>> adj[20001];
//vector<int> dst;
//
//vector<int> djikstra(const int start) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    
//    vector<int> dist(n + 1, INT_MAX);
//    
//    dist[start] = 0;
//    pq.push({0, start});
//    
//    while(!pq.empty()) {
//        int here = pq.top().second;
//        int cost = pq.top().first;
//        pq.pop();
//        
//        if(cost > dist[here])
//            continue;
//        
//        for(auto &i : adj[here]) {
//            int there = i.second;
//            int thereCost = cost + i.first;
//            
//            if(thereCost < dist[there]) {
//                dist[there] = thereCost;
//                pq.push({there, thereCost});
//            }
//        }
//    }
//    
//    return dist;
//}
//
//int main(void) {
//    cin >> T;
//    
//    while(T--) {
//        cin >> n >> m >> t;
//        cin >> s >> g >> h;
//        int distance = 0;
//        int start;
//        int result = 0;
//        
//        dst.clear();
//        for(auto &i : adj) {
//            i.clear();
//        }
//        
//        for(int i = 0; i < m; i++) {
//            cin >> a >> b >> d;
//            adj[a].push_back({b, d});
//            adj[b].push_back({a, d});
//        }
//        
//        for(int i = 0; i < t; i++) {
//            cin >> x;
//            dst.push_back(x);
//        }
//        vector<int> v;
//        v = djikstra(s);
//        if(v[g] < v[h]) {
//            start = g;
//            distance += v[g];
//            djikstra(start);
//            distance += v[h];
//            start = h;
//        } else {
//            start = h;
//            distance += v[h];
//            djikstra(start);
//            distance += v[g];
//            start = g;
//        }
//        v.clear();
//        v = djikstra(start);
//        int minDistance = INT_MAX;
//        int idx = -1;
//        for(int i = 1; i <= n; i++) {
//            for(int j = 0; j < (int)dst.size(); j++) {
//                if(dst[j] == i) {
//                    minDistance = min(minDistance, v[dst[j]]);
//                    idx = dst[j];
//                }
//            }
//        }
//        
//        vector<int> ans;
//
//        cout << "index : " << idx << '\n';
//        cout << "minDistance : " << minDistance << '\n';
////        cout << v[5] << '\n';
//        
//        for(int i = 1; i <= n; i++) {
//            if(minDistance == v.at(i) && i != g && i != h) {
//                ans.push_back(i);
//            }
//        }
//        
//        sort(ans.begin(), ans.end());
//        
//        for(auto &i : ans) {
//            cout << i << ' ';
//        }
//        cout << '\n';
//    }
//}
