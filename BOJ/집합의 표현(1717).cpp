//#include <iostream>
//
//using namespace std;
//
//int n, m;
//int parent[1000001];
//
//int find(int v) {
//    if(v == parent[v])
//        return v;
//    else
//        return parent[v] = find(parent[v]);
//}
//
//void uni(int a, int b) {
//    a = find(a);
//    b = find(b);
//    parent[a] = b;
//}
//
//int main(void) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    
//    cin >> n >> m;
//    
//    for(int i = 0; i <= n; i++) {
//        parent[i] = i;
//    }
//    
//    for(int i = 0; i < m; i++) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        
//        if(a == 0) {
//            uni(b, c);
//        } else {
//            if(find(b) == find(c))
//                cout << "YES\n";
//            else
//                cout << "NO\n";
//        }
//    }
//}
