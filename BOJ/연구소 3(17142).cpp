//#include <iostream>
//#include <vector>
//#include <queue>
//#include <cstring>
//#include <climits>
//
//using namespace std;
//
//int N, M;
//int lab[50][50];
//int copyLab[50][50];
//vector<pair<int, int>> virusLocationInfo;
//vector<pair<int, int>> activatedVirusLocationInfo;
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//int minTime = INT_MAX;
//bool flag;
//
//struct VirusInfo {
//    int y, x, cnt;
//};
//
//bool checkIfVirusFullySpread() {
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            if(copyLab[i][j] == 0)
//                return false;
//        }
//    }
//    flag = true;
//    return true;
//}
//
//int spreadActivatedVirus() {
//    queue<VirusInfo> q;
//    int time = -1;
//    for(auto i : activatedVirusLocationInfo) {
//        q.push({i.first, i.second, 0});
//    }
//    
//    while(!q.empty()) {
//        int size = (int)q.size();
//        while(size--) {
//            int curX = q.front().x;
//            int curY = q.front().y;
//            int curCnt = q.front().cnt;
//            q.pop();
//            time = max(time, curCnt);
//            
//            for(int i = 0; i < 4; i++) {
//                int nextX = curX + dx[i];
//                int nextY = curY + dy[i];
//                
//                if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
//                    continue;
//                if(copyLab[nextY][nextX] != 0)
//                    continue;
//                
//                q.push({nextY, nextX, curCnt + 1});
//                copyLab[nextY][nextX] = curCnt + 1;
//            }
//        }
//    }
//    
//    return time;
//}
//
//void activateVirus() {
//    memcpy(copyLab, lab, sizeof(lab));
//    
//    for(auto i : activatedVirusLocationInfo) {
//        int x = i.second;
//        int y = i.first;
//        // 활성 바이러스 -1로 설정
//        copyLab[y][x] = -1;
//    }
//}
//
//void virusCombination(int idx, int cnt) {
//    if(cnt == M) {
//        int time;
//        activateVirus();
//        time = spreadActivatedVirus();
//        if(checkIfVirusFullySpread())
//            minTime = min(minTime, time);
//        return;
//    }
//    
//    for(int i = idx; i < (int)virusLocationInfo.size(); i++) {
//        activatedVirusLocationInfo.push_back({virusLocationInfo.at(i)});
//        virusCombination(i, cnt + 1);
//        activatedVirusLocationInfo.pop_back();
//    }
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            cin >> lab[i][j];
//            if(lab[i][j] == 2) {
//                virusLocationInfo.push_back({i, j});
//                // 바이러스 -2로 설정
//                lab[i][j] = -2;
//            } else if(lab[i][j] == 1) {
//                // 벽
//                lab[i][j] = -3;
//            }
//        }
//    }
//    
//    virusCombination(0, 0);
//    
//    if(minTime == INT_MAX)
//        cout << -1 << '\n';
//    else
//        cout << minTime << '\n';
//}
