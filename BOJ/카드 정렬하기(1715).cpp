//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int N, result;
//priority_queue<int, vector<int>, greater<int>> pq;
//
//int main(void) {
//    cin >> N;
//
//    for(int i = 0; i < N; i++) {
//        int n;
//        cin >> n;
//        pq.push(n);
//    }
//
//    while(pq.size() != 1) {
//        int a = pq.top();
//        pq.pop();
//        int b = pq.top();
//        pq.pop();
//
//        result += a + b;
//        pq.push(a + b);
//    }
//
//    cout << result << '\n';
//}
