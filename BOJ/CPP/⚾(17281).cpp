//#include <iostream>
//#include <vector>
//#include <climits>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//int N;
//vector<int> batter[50];
//vector<int> batterOrder;
//bool bVisit[9];
//
//int outCnt;
//bool bRunnerStatus[5];
//int score = 0;
//
//int moveRunner(int flag) {
//    
//    int ininningScore = 0;
//
//    for(int i = 3; i >= 0; i--) {
//        if(bRunnerStatus[i]) {
//            int idx = i + flag;
//            bRunnerStatus[i] = false;
//            if(idx >= 4) {
//                ininningScore++;
//            }
//            else {
//                bRunnerStatus[idx] = true;
//            }
//        }
//    }
//    
//    if(flag == 4)
//        ininningScore++;
//    else
//        bRunnerStatus[flag] = true;
//    
//    return ininningScore;
//}
//
//int playTheInnings() {
//    outCnt = 0;
//    int ininningScore = 0;
//    
//    int idx = 0;
//    for(int i = 0; i < N; i++) {
//        memset(bRunnerStatus, false, sizeof(bRunnerStatus));
//        outCnt = 0;
//        while(outCnt < 3) {
//            if(batter[i][batterOrder[idx]] == 0) {
//                outCnt++;
//                idx = (idx + 1) % 9;
//                continue;
//            }
//            
//            ininningScore += moveRunner(batter[i][batterOrder[idx]]);
//            idx = (idx + 1) % 9;
//        }
//    }
//    
//    return ininningScore;
//}
//
//void setBatterOrder(int cur) {
//    if(bVisit[cur])
//        return;
//    
//    batterOrder.push_back(cur);
//    bVisit[cur] = true;
//    
//    if((int)batterOrder.size() == 8) {
//        batterOrder.insert(batterOrder.begin() + 3, 0);
//        score = max(score, playTheInnings());
//        batterOrder.erase(remove(batterOrder.begin(), batterOrder.end(), 0), batterOrder.end());
//        batterOrder.pop_back();
//        bVisit[cur] = false;
//        return;
//    }
//    
//    for(int i = 1; i < 9; i++) {
//        setBatterOrder(i);
//    }
//    
//    batterOrder.pop_back();
//    bVisit[cur] = false;
//}
//
//int main(void) {
//    cin >> N;
//
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < 9; j++) {
//            int scoreCanGetByBatter;
//            cin >> scoreCanGetByBatter;
//            batter[i].push_back(scoreCanGetByBatter);
//        }
//    }
//    
//    bVisit[0] = true;
//    
//    for(int i = 0; i < 9; i++) {
//        setBatterOrder(i);
//    }
//    
//    cout << score << '\n';
//}
