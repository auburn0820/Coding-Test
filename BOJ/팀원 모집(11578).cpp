//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <climits>
//#include <algorithm>
//
//using namespace std;
//
//int N, M;
//bool problem[10];
//bool visit[10];
//vector<int> students[10];
//int result = INT_MAX;
//
//bool checkCanSolveProblem() {
//    memset(problem, false, sizeof(problem));
//    
//    for(int i = 0; i < M; i++) {
//        if(visit[i]) {
//            for(int j = 0; j < (int)students[i].size(); j++) {
//                problem[students[i][j] - 1] = true;
//            }
//        }
//    }
//    
//    for(int i = 0; i < N; i++) {
//        if(!problem[i])
//            return false;
//    }
//    
//    return true;
//}
//
//void combination(int cur, int cnt, int size) {
//    if(visit[cur])
//        return;
//    
//    visit[cur] = true;
//    
//    if(cnt == size) {
//        if(checkCanSolveProblem()) {
//            result = min(result, cnt);
//        }
//        visit[cur] = false;
//        return;
//    }
//    
//    for(int i = cur; i < M; i++) {
//        combination(i, cnt + 1, size);
//    }
//    
//    visit[cur] = false;
//}
//
//void findTeamMate() {
//    for(int i = 1; i <= M; i++) {
//        memset(visit, false, sizeof(visit));
//        for(int j = 0; j < M; j++) {
//            combination(j, 1, i);
//        }
//    }
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < M; i++) {
//        int st;
//        cin >> st;
//        
//        while(st--) {
//            int problemStudentCanSolve;
//            cin >> problemStudentCanSolve;
//            students[i].push_back(problemStudentCanSolve);
//        }
//    }
//    
//    findTeamMate();
//    
//    if(result == INT_MAX)
//        cout << -1 << '\n';
//    else
//        cout << result << '\n';
//}
