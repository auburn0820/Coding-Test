//#include <iostream>
//#include <deque>
//
//using namespace std;
//
//int N, L;
//int arr[5000000];
//
//struct Info {
//    int val, idx;
//};
//
//int main(void) {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    deque<Info> dq;
//
//    cin >> N >> L;
//
//    for(int i = 0; i < N; i++) {
//        cin >> arr[i];
//    }
//
//    for(int i = 0; i < N; i++) {
//        if(!dq.empty() && dq.front().idx <= i - L)
//            dq.pop_front();
//
//        while(!dq.empty() && dq.back().val > arr[i])
//            dq.pop_back();
//
//        dq.push_back({arr[i], i});
//        cout << dq.front().val << ' ';
//    }
//    cout << '\n';
//}
