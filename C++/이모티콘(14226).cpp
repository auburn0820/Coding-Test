//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int S;
//bool visit[1001][1001];
//
//struct Data {
//    int display, clipboard, count;
//};
//
//Data initData(int display, int clipboard, int count) {
//    Data data;
//    
//    data.display = display;
//    data.clipboard = clipboard;
//    data.count = count;
//    
//    return data;
//}
//
//void findMinValue() {
//    queue<Data> q;
//    q.push(initData(1, 0, 0));
//    visit[1][0] = true;
//    
//    while(!q.empty()) {
//        int curDisplay = q.front().display;
//        int curClipboard = q.front().clipboard;
//        int curCnt = q.front().count;
//        q.pop();
//        
//        if(curDisplay == S) {
//            cout << curCnt << '\n';
//            return;
//        }
//        
//        for(int i = 0; i < 3; i++) {
//            if(i == 0) {
//                if(!visit[curDisplay][curDisplay]) {
//                    q.push(initData(curDisplay, curDisplay, curCnt + 1));
//                    visit[curDisplay][curDisplay] = true;
//                }
//            } else if(i == 1) {
//                if(!visit[curDisplay + curClipboard][curClipboard] && (curDisplay + curClipboard <= 1000) && curClipboard > 0) {
//                    q.push(initData(curDisplay + curClipboard, curClipboard, curCnt + 1));
//                    visit[curDisplay + curClipboard][curClipboard] = true;
//                }
//            } else if(i == 2) {
//                if(!visit[curDisplay - 1][curClipboard] && (curDisplay - 1) >= 1) {
//                    q.push(initData(curDisplay - 1, curClipboard, curCnt + 1));
//                    visit[curDisplay - 1][curClipboard] = true;
//                }
//            }
//        }
//    }
//}
//
//int main(void) {
//    cin >> S;
//    
//    findMinValue();
//}
