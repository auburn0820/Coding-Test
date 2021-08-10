//#include <iostream>
//#include <queue>
//#include <cmath>
//
//using namespace std;
//
//int N;
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//
//int main(void) {
//    cin >> N;
//    
//    for(int i = 0; i < N; i++) {
//        int x;
//        cin >> x;
//        
//        if(x == 0) {
//            if(pq.empty())
//                cout << 0 << '\n';
//            else {
//                cout << pq.top().second << '\n';
//                pq.pop();
//            }
//        } else {
//            pq.push({abs(x), x});
//        }
//    }
//}
