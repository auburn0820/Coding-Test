//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int arr[100000] = {0, };
//
//int main(void) {
//    int N;
//    cin >> N;
//    
//    for(int i = 0; i < N; i++) {
//        cin >> arr[i];
//    }
//    
//    sort(begin(arr), begin(arr) + N);
//    
//    int cnt = N;
//    int val = 0;
//    for(int i = 0; i < N; i++) {
//        int maxWeight = arr[i] * cnt--;
//        val = max(val, maxWeight);
//    }
//    cout << val << '\n';
//}
