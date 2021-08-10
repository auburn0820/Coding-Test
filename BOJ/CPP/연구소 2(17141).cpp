//#include <iostream>
//#include <queue>
//#include <vector>
//#include <climits>
//#include <cstring>
//
//using namespace std;
//
//int N, M;
//int lab[50][50];
//int cpyLab[50][50];
//vector<pair<int, int>> virusLocation;
//vector<pair<int, int>> virusReleaseSpot;
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int minNum = INT_MAX;
//
//struct virusInfo {
//    int x, y, cnt;
//};
//
//bool isVirusFullySpreaded() {
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            if(cpyLab[i][j] == 0)
//                return false;
//        }
//    }
//    return true;
//}
//
//int spreadVirus() {
//    queue<virusInfo> q;
//    memcpy(cpyLab, lab, sizeof(lab));
//    for(auto i : virusReleaseSpot) {
//        q.push({i.first, i.second, 0});
//        cpyLab[i.first][i.second] = -1;
//    }
//    int cnt = 0;
//    
//    while(!q.empty()) {
//        int idx = (int)q.size();
//        while(idx--) {
//            int curX = q.front().x;
//            int curY = q.front().y;
//            int curCnt = q.front().cnt;
//            cnt = max(curCnt, cnt);
//            q.pop();
//            
//            for(int i = 0; i < 4; i++) {
//                int nextX = curX + dx[i];
//                int nextY = curY + dy[i];
//                
//                if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
//                    continue;
//                if(cpyLab[nextX][nextY] != 0)
//                    continue;
//                
//                q.push({nextX, nextY, curCnt + 1});
//                cpyLab[nextX][nextY] = curCnt + 1;
//            }
//        }
//    }
//    if(isVirusFullySpreaded())
//        return cnt;
//    else
//        return INT_MAX;
//}
//
//void getVirusReleaseSpot(int idx, int cnt) {
//    if(cnt == M) {
//        minNum = min(spreadVirus(), minNum);
//        return;
//    }
//    
//    for(int i = idx; i < (int)virusLocation.size(); i++) {
//        virusReleaseSpot.push_back(virusLocation.at(i));
//        getVirusReleaseSpot(i + 1, cnt + 1);
//        virusReleaseSpot.pop_back();
//    }
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            cin >> lab[i][j];
//            if(lab[i][j] == 1) {
//                lab[i][j] = -2;
//            } else if(lab[i][j] == 2) {
//                virusLocation.push_back({i, j});
//                lab[i][j] = 0;
//            }
//        }
//    }
//    
//    getVirusReleaseSpot(0, 0);
//    
//    if(minNum == INT_MAX)
//        minNum = -1;
//    
//    cout << minNum << '\n';
//}
