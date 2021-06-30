//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//int N;
//int S[20][20];
//bool team[20];
//vector<int> combination;
//
//int checkTeamGap() {
//    int team1, team2;
//    team1 = team2 = 0;
//    
//    for(int i = 0; i < N; i++) {
//        if(team[i]) {
//            for(int j = i; j < N; j++) {
//                if(i == j)
//                    continue;
//                if(team[j]) {
//                    team1 += (S[i][j] + S[j][i]);
//                }
//            }
//        } else {
//            for(int j = i; j < N; j++) {
//                if(i == j)
//                    continue;
//                if(!team[j]) {
//                    team2 += (S[i][j] + S[j][i]);
//                }
//            }
//        }
//    }
//    
//    if(team1 > team2)
//        return team1 - team2;
//    else
//        return team2 - team1;
//}
//
//int divideTeam() {
//    int result = 9999;
//    sort(combination.begin(), combination.end());
//    do {
//        memset(team, false, sizeof(team));
//        for(int i = 0; i < N; i++) {
//            if(combination[i] == 1) {
//                team[i] = true;
//            }
//        }
//        result = min(result, checkTeamGap());
//    } while(next_permutation(combination.begin(), combination.end()));
//    
//    return result;
//}
//
//int main(void) {
//    cin >> N;
//    combination.resize(N);
//    
//    for(int i = 0; i < N; i++) {
//        if(i < (N/2))
//            combination[i] = 1;
//        else
//            combination[i] = 0;
//    }
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            cin >> S[i][j];
//        }
//    }
//    
//    cout << divideTeam() << '\n';
//}
