//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//
//int N, M;
//bool visit[8] = {false, };
//vector<int> v;
//
//void permuation(int start, int cur) {
//    if(visit[cur])
//        return;
//    
//    visit[cur] = true;
//    v.push_back(cur + 1);
//    
//    if((int)v.size() == M) {
//        for(auto i : v) {
//            cout << i << ' ';
//        }
//        cout << '\n';
//        visit[cur] = false;
//        v.pop_back();
//        return;
//    }
//    
//    for(int i = 0; i < N; i++) {
//        permuation(start, i);
//    }
//    
//    visit[cur] = false;
//    v.pop_back();
//}
//
//int main(void) {
//    cin >> N >> M;
//    
//    for(int i = 0; i < N; i++) {
//        permuation(i, i);
//    }
//}
