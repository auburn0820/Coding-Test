//#include <iostream>
//#include <vector>
//
//#define MAX 987654321
//
//using namespace std;
//
//int N, M;
//int maps[50][50];
//bool visit[101];
//int totalDistance = MAX;
//
//vector<pair<int, int>> chickenStore;
//vector<pair<int, int>> house;
//
//int getDistance(int x1, int y1, int x2, int y2) {
//    return abs(x1 - x2) + abs(y1 - y2);
//}
//
//int getMinimumTotalDistance() {
//    int ans = 0;
//    
//    for(int i = 0; i < house.size(); i++) {
//        int distance = MAX;
//        for(int j = 0; j < chickenStore.size(); j++) {
//            if(visit[j]) {
//                distance = min(distance, getDistance(house[i].first, house[i].second, chickenStore[j].first, chickenStore[j].second));
//            }
//        }
//        ans += distance;
//    }
//    
//    
//    return ans;
//}
//
//void DFS(int index, int cnt) {
//    if(cnt == M) {
//        totalDistance = min(getMinimumTotalDistance(), totalDistance);
//        return;
//    }
//    
//    if(index >= chickenStore.size())
//        return;
//    
//    visit[index] = true;
//    DFS(index + 1, cnt + 1);
//    visit[index] = false;
//    
//    DFS(index + 1, cnt);
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            cin >> maps[i][j];
//            if(maps[i][j] == 1) {
//                house.push_back({i, j});
//            }
//            else if(maps[i][j] == 2) {
//                chickenStore.push_back({i, j});
//            }
//        }
//    }
//    
//    DFS(0, 0);
//    cout << totalDistance << '\n';
//}
