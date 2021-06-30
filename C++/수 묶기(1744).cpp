//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//    int N;
//    cin >> N;
//    
//    int *arr = new int[N];
//    
//    for(int i = 0; i < N; i++) {
//        cin >> arr[i];
//    }
//    
//    sort(arr, arr + N);
//    
//    int left = 0;
//    int right = N - 1;
//    long long result = 0;
//    
//    while(arr[left] < 1 && arr[left + 1] < 1 && left < right) {
//        result += arr[left] * arr[left + 1];
//        
//        left += 2;
//    }
//    
//    while(arr[right] > 1 && arr[right - 1] > 1 && right > left) {
//        result += arr[right] * arr[right - 1];
//        
//        right -= 2;
//    }
//    
//    while(left <= right) {
//        result += arr[left];
//        left++;
//    }
//    
//    cout << result << '\n';
//}
