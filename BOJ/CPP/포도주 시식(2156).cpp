//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//int wine[10003];
//int arr[10003];
//
//
//int main(void) {
//    cin >> N;
//    
//    for(int i = 3; i < N + 3; i++) {
//        cin >> wine[i];
//    }
//    
//    for(int i = 3; i < N + 3; i++) {
//        arr[i] = max(arr[i - 2] + wine[i], arr[i - 3] + wine[i - 1] + wine[i]);
//        arr[i] = max(arr[i - 1], arr[i]);
//    }
//    
//    cout << arr[N + 2] << '\n';
//}
