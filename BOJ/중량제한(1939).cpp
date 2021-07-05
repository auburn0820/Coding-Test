//#include <iostream>
//#include <queue>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//int N, M, A, B;
//vector<pair<int, int>> v[100001];
//bool visit[100001];
//
//bool findMaxCost(int weight) {
//    memset(visit, false, sizeof(visit));
//    queue<int> q;
//    q.push(A);
//    visit[A] = true;
//    
//    while(!q.empty()) {
//        int curPos = q.front();
//        q.pop();
//        
//        if(curPos == B)
//            return true;
//        
//        for(int i = 0; i < (int)v[curPos].size(); i++) {
//            int nextPos = v[curPos][i].first;
//            int nextCost = v[curPos][i].second;
//            
//            if(visit[nextPos])
//                continue;
//            if(weight > nextCost)
//                continue;
//            
//            q.push(nextPos);
//            visit[nextPos] = true;
//        }
//    }
//    
//    return false;
//}
//
//int binarySearch(int left, int right) {
//    while(left <= right) {
//        int mid = (left + right) / 2;
//        
//        if(findMaxCost(mid)) {
//            left = mid + 1;
//        } else {
//            right = mid - 1;
//        }
//    }
//    
//    return right;
//}
//
//int main(void) {
//    cin >> N >> M;
//    int maxWeight = 0;
//    
//    for(int i = 0; i < M; i++) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        v[a].push_back({b, c});
//        v[b].push_back({a, c});
//        maxWeight = max(c, maxWeight);
//    }
//    
//    cin >> A >> B;
//    
//    cout << binarySearch(0, maxWeight) << '\n';
//}
