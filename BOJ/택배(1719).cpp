//#include <iostream>
//#include <vector>
//#include <queue>
//#include <climits>
//#include <string>
//
//using namespace std;
//
//int n, m;
//vector<pair<int, int>> adj[201];
//string ans[201][201];
//int path[201];
//
//void djikstra(const int start) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
//    vector<int> dist(n + 1, INT_MAX);
//    
//    dist[start] = 0;
//    pq.push({start, 0});
//    
//    while(!pq.empty()) {
//        int here = pq.top().first;
//        int cost = pq.top().second;
//        pq.pop();
//        
//        if(cost > dist[here])
//            continue;
//        
//        for(int i = 0; i < (int)adj[here].size(); i++) {
//            int there = adj[here][i].first;
//            int thereCost = adj[here][i].second + cost;
//            
//            if(thereCost < dist[there]) {
//                dist[there] = thereCost;
//                pq.push({there, thereCost});
//                path[there] = here;
//            }
//        }
//    }
//    
//    for(int i = 1; i < n + 1; i++) {
//        if(start == i)
//            ans[start][i] = "-";
//        else {
//            int t = i;
//            while(path[t] != start) {
//                t = path[t];
//            }
//            ans[start][i] = to_string(t);
//        }
//    }
//}
//
//int main(void) {
//    cin >> n >> m;
//    
//    for(int i = 0; i < m; i++) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        adj[a].push_back({b, c});
//        adj[b].push_back({a, c});
//    }
//    
//    for(int i = 1; i < n + 1; i++) {
//        djikstra(i);
//    }
//    
//    for(int i = 1; i < n + 1; i++) {
//        for(int j = 1; j < n + 1; j++) {
//            cout << ans[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//}
