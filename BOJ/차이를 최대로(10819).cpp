//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <cstring>
//
//using namespace std;
//
//int N, maxResult;
//bool *visit;
//vector<int> numbers;
//vector<int> expression;
//
//int calExpression() {
//    int result = 0;
//    
//    for(int i = 0; i < (int)expression.size() - 1; i++) {
//        result += abs(expression.at(i) - expression.at(i + 1));
//    }
//    
//    return result;
//}
//
//void getCases(int cnt) {
//    if(cnt == N) {
//        maxResult = max(calExpression(), maxResult);
//        return;
//    }
//    
//    for(int i = 0; i < (int)numbers.size(); i++) {
//        if(visit[i])
//            continue;
//        expression.push_back(numbers.at(i));
//        visit[i] = true;
//        getCases(cnt + 1);
//        expression.pop_back();
//        visit[i] = false;
//    }
//}
//
//int main(void) {
//    cin >> N;
//    
//    visit = new bool[N];
//    memset(visit, false, sizeof(bool) * N);
//    
//    for(int i = 0; i < N; i++) {
//        int n;
//        cin >> n;
//        numbers.push_back(n);
//    }
//    
//    getCases(0);
//    
//    delete [] visit;
//    
//    cout << maxResult << '\n';
//}
