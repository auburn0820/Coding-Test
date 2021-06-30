//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//int N, M, X, Y;
//vector<pair<int, int>> adj[10001];
//pair<int, int> dist[1001];
//bool visit[1001];
//
//void fillDistArr() {
//    for(int i = 0; i < N; i++) {
//        dist[i].first = INT_MAX;
//    }
//}
//
//void djikstra() {
//    fillDistArr();
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//
//    pq.push({Y, 0});
//    dist[Y].first = 0;
//    dist[Y].second = Y;
//
//    while(!pq.empty()) {
//        int here = pq.top().first;
//        int cost = pq.top().second;
//        pq.pop();
//
//        if(cost > dist[here].first)
//            continue;
//
//        for(int i = 0; i < (int)adj[here].size(); i++) {
//            int there = adj[here][i].first;
//            int thereCost = cost + adj[here][i].second;
//
//            if(thereCost < dist[there].first) {
//                dist[there].first = thereCost;
//                dist[there].second = there;
//                pq.push({there, thereCost});
//            }
//        }
//    }
//}
//
//bool comp(pair<int, int> &a, pair<int, int> &b) {
//    return a.first < b.first;
//}
//
//int main(void) {
//    cin >> N >> M >> X >> Y;
//
//    for(int i = 0; i < M; i++) {
//        int A, B, C;
//        cin >> A >> B >> C;
//
//        adj[A].push_back({B, C});
//        adj[B].push_back({A, C});
//    }
//
//    djikstra();
//
//    int cnt = 1;
//    int canGoDistancePerDay = X;
//
//    sort(dist, dist + N, comp);
//
//    for(int i = 0; i < N; i++) {
//        if((dist[i].first * 2) > X) {
//            cnt = -1;
//            break;
//        }
//        if(canGoDistancePerDay < (dist[i].first * 2)) {
//            cnt++;
//            i--;
//            canGoDistancePerDay = X;
//            continue;
//        }
//        canGoDistancePerDay -= (dist[i].first * 2);
//    }
//
//
//    cout << cnt << '\n';
//}
