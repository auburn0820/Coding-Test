//#include <iostream>
//#include <vector>
//
//#define INF 10001
//
//using namespace std;
//
//typedef struct {
//    int dst, consume;
//}vertex;
//
//vector<vertex> v[1001];
//
//bool visit[1001] = {false, };
//int dist[1001];
//int N, M;
//
//void init() {
//    for(int i = 1; i <= N; i++) {
//        dist[i] = INF;
//        visit[N] = false;
//    }
//}
//
//long long prim() {
//    long long ans = 0;
//    
//    init();
//    
//    dist[1] = 0;
//    
//    for(int i = 1; i <= N; i++) {
//        int cur = -1, minDist = INF;
//        for(int j = 1; j <= N; j++) {
//            if(!visit[j] && minDist > dist[j]) {
//                minDist = dist[j];
//                cur = j;
//            }
//        }
//        
//        if(cur < 0)
//            return (long long)INF;
//        
//        ans += minDist;
//        visit[cur] = true;
//        
//        for(auto edge: v[cur]) {
//            dist[edge.dst] = min(dist[edge.dst], edge.consume);
//        }
//    }
//    
//    return ans;
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    init();
//    
//    for(int i = 0; i < M; i++) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        v[a].push_back({b, c});
//        v[b].push_back({a, c});
//    }
//    
//    cout << prim() << '\n';
//}
