//#include <iostream>
//#include <vector>
//#include <climits>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//int V, E;
//int st, stMaxDistance;
//int mc, mcMaxDistance;
//vector<pair<int, int>> vec[10003];
//bool house[10001];
//int minDistance = INT_MAX;
//
//struct comp {
//    bool operator()(pair<int, int> a, pair<int, int> b) {
//        return a.second > b.second;
//    }
//};
//
//void djikstra(int start, int* dist) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
//    
//    dist[start] = 0;
//    pq.push({start, 0});
//    
//    while(!pq.empty()) {
//        int here = pq.top().first;
//        int distance = pq.top().second;
//        pq.pop();
//        
//        if(distance > dist[here])
//            continue;
//        
//        for(int i = 0; i < (int)vec[here].size(); i++) {
//            int there = vec[here][i].first;
//            int thereDistance = vec[here][i].second + distance;
//            
//            if(dist[there] > thereDistance) {
//                dist[there] = thereDistance;
//                pq.push({there, thereDistance});
//            }
//        }
//    }
//}
//
//int getOptimalHouse() {
//    int dist1[10001];
//    int dist2[10001];
//    int result = INT_MAX;
//    
//    fill(begin(dist1), end(dist1), INT_MAX);
//    fill(begin(dist2), end(dist2), INT_MAX);
//    
//    djikstra(10001, dist1);
//    djikstra(10002, dist2);
//    
//    for(int i = 1; i <= V; i++) {
//        if(house[i] == false)
//            continue;
//        else {
//            if(dist1[i] <= stMaxDistance && dist2[i] <= mcMaxDistance) {
//                result = min(dist1[i] + dist2[i], result);
//            }
//        }
//    }
//    
//    if(result != INT_MAX)
//        return result;
//    else
//        return result;
//}
//
//int main(void) {
//    cin >> V >> E;
//    
//    for(int i = 1; i <= V; i++) {
//        house[i] = true;
//    }
//    
//    for(int i = 0; i < E; i++) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        vec[u].push_back({v, w});
//        vec[v].push_back({u, w});
//    }
//    
//    cin >> st >> stMaxDistance;
//    
//    for(int i = 0; i < st; i++) {
//        int stVertex;
//        cin >> stVertex;
//        vec[10001].push_back({stVertex, 0});
//        house[stVertex] = false;
//    }
//    
//    cin >> mc >> mcMaxDistance;
//    
//    for(int i = 0; i < mc; i++) {
//        int mcVertex;
//        cin >> mcVertex;
//        vec[10002].push_back({mcVertex, 0});
//        house[mcVertex] = false;
//    }
//    
//    minDistance = getOptimalHouse();
//    
//    if(minDistance != INT_MAX)
//        cout << minDistance << '\n';
//    else
//        cout << -1 << '\n';
//}
