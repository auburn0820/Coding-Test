//#include <iostream>
//#include <vector>
//#include <cmath>
//
//#define ll long long
//#define MAX 1000000
//
//using namespace std;
//
//ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end) {
//    if(start == end)
//        return tree[node] = arr[start];
//    
//    int mid = (start + end) / 2;
//    
//    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
//}
//
//void update(vector<ll> &tree, int node, int start, int end, ll index, ll diff) {
//    if (index < start || index > end)
//        return;
//    
//    tree[node] += diff;
//    
//    if (start != end) {
//        int mid = (start + end) / 2;
//        update(tree, node * 2, start, mid, index, diff);
//        update(tree, node * 2 + 1, mid + 1, end, index, diff);
//    }
//}
//
//ll sum(vector<ll> &tree, int node, int start, int end, ll left, ll right) {
//    if (left > end || right < start)
//        return 0;
//    
//    if (left <= start && end <= right)
//        return tree[node];
//    
//    int mid = (start + end) / 2;
//    
//    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
//}
//
//int main(void) {
//    vector<ll> arr;
//    vector<ll> tree;
//    
//    int N, M, K;
//    cin >> N >> M >> K;
//    
//    int treeSize = MAX * 4;
//    
//    arr.resize(N + 1);
//    tree.resize(treeSize);
//    
//    for(int i = 1; i <= N; i++) {
//        ll data;
//        cin >> data;
//        arr[i] = data;
//    }
//    
//    init(arr, tree, 1, 1, N);
//    
//    for(int i = 0; i < M + K; i++) {
//        int a;
//        cin >> a;
//        
//        if (a == 1) {
//            int b;
//            ll c;
//            cin >> b >> c;
//            ll diff = c - arr[b];
//            arr[b] = c;
//            update(tree, 1, 1, N, b, diff);
//        } else if (a == 2) {
//            int b, c;
//            cin >> b >> c;
//            cout << sum(tree, 1, 1, N, b, c) << '\n';
//        }
//    }
//}
