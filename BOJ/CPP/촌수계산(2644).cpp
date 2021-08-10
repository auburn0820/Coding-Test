//#include <iostream>
//#include <vector>
//
//#define MAX 987654321
//
//using namespace std;
//
//vector<int> v[101];
//bool visit[101] = {false, };
//int ans = MAX;
//
//int n, a, b, m;
//
//void DFS(int cur, int cnt) {
//    if(cur == b) {
//        ans = min(ans, cnt);
//        return;
//    }
//    
//    for(int i = 0; i < (int)v[cur].size(); i++) {
//        if(!visit[v[cur][i]]) {
//            visit[v[cur][i]] = true;
//            DFS(v[cur][i], cnt + 1);
//            visit[v[cur][i]] = false;
//        }
//    }
//}
//
//int main(void) {
//    cin >> n >> a >> b >> m;
//    
//    while(m--) {
//        int x, y;
//        cin >> x >> y;
//        v[x].push_back(y);
//        v[y].push_back(x);
//    }
//    
//    if((int)v[a].size() != 0) {
//        visit[a] = true;
//        DFS(a, 0);
//    }
//    
//    if(ans != MAX)
//        visit[b] = true;
//    
//    if(!visit[a] || !visit[b])
//        cout << -1 << '\n';
//    else {
//        cout << ans << '\n';
//    }
//}
