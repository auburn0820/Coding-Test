//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#include <cmath>
//
//using namespace std;
//
//int N;
//int area[11][11] = {0, };
//int pop[11];
//bool visit[11];
//
//// 선거구의 인접성을 확인해야 한다.
//int checkAdj(int idx, vector<int> &areaCopy, int areaNumber) {
//    int cnt = 1;
//    visit[idx] = true;
//    
//    for(int i = 1; i <= N; i++) {
//        if(visit[i] == false && areaCopy[i - 1] == areaNumber && area[idx][i] == 1)
//            cnt += checkAdj(i, areaCopy, areaNumber);
//    }
//    return cnt;
//}
//
//int main(void) {
//    cin >> N;
//    
//    for(int i = 1; i <= N; i++)
//        cin >> pop[i];
//    
//    for(int i = 1; i <= N; i++) {
//        int number;
//        cin >> number;
//        
//        for(int j = 0; j < number; j++) {
//            int areaNumber;
//            cin >> areaNumber;
//            area[i][areaNumber] = 1;
//        }
//    }
//    
//    int ans = 987654321;
//    
//    for(int i = 1; i < N; i++) {
//        vector<int> areaCopy(i, 0);
//        
//        for(int j = i + 1; j <= N; j++)
//            areaCopy.push_back(1);
//        
//        do {
//            int firstAreaIndex = -1, secondAreaIndex = -1;
//            for(int j = 0; j < N; j++) {
//                if(areaCopy[j] == 0)
//                    firstAreaIndex = j;
//                else
//                    secondAreaIndex = j;
//                
//                if(firstAreaIndex != -1 && secondAreaIndex != -1)
//                    break;
//            }
//            
//            int firstAreaCnt, secondAreaCnt, firstRes, secondRes;
//            firstAreaCnt = secondAreaCnt = firstRes = secondRes = 0;
//            
//            memset(visit, false, sizeof(visit));
//            firstAreaCnt = checkAdj(firstAreaIndex + 1, areaCopy, 0);
//            memset(visit, false, sizeof(visit));
//            secondAreaCnt = checkAdj(secondAreaIndex + 1, areaCopy, 1);
//            
//            if(firstAreaCnt == i && secondAreaCnt == N - i) {
//                for(int j = 0; j < N; j++) {
//                    if(areaCopy[j] == 0)
//                        firstRes += pop[j + 1];
//                    else
//                        secondRes += pop[j + 1];
//                }
//                    int sub = abs(firstRes - secondRes);
//                    ans = min(ans, sub);
//            }
//        } while(next_permutation(areaCopy.begin(), areaCopy.end()));
//    }
//    
//    if(ans == 987654321)
//        cout << -1 << '\n';
//    else
//        cout << ans << '\n';
//}
