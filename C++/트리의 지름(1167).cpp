//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<vector<pair<int, int>>> tree;
//vector<bool> visit;
//
//int maxValue = 0;
//int start = 0;
//
//void init() {
//    for(int i = 0; i < (int)visit.size(); i++) {
//        visit[i] = false;
//    }
//}
//
//void DFS(int v, int length) {
//
//    if(visit[v] == true)
//        return;
//
//    if(maxValue < length) {
//        maxValue = length;
//        start = v;
//    }
//
//    visit[v] = true;
//
//    for(int i = 0; i < (int)tree[v].size(); i++) {
//
//        DFS(tree[v][i].first, length + tree[v][i].second);
//    }
//}
//
//int main(void) {
//    int v;
//    cin >> v;
//
//    tree.resize(v + 1);
//    visit.resize(v + 1, false);
//
//    int firstNum;
//
//    for(int i = 0; i < v; i++) {
//        int vNumber;
//        cin >> vNumber;
//
//        if(i == 0)
//            firstNum = vNumber;
//
//        int anotherV, length;
//        while(true) {
//            cin >> anotherV;
//
//            if(anotherV == -1)
//                break;
//
//            cin >> length;
//
//            tree[vNumber].push_back({anotherV, length});
////            tree[anotherV].push_back({vNumber, length});
//        }
//    }
//
//    DFS(1, 0); // 이 구문과
//
//    init();
//
//    DFS(start, 0); // 이 구문을 넣었더니 정답이 떴다.
//
//    cout << maxValue << '\n';
//}
