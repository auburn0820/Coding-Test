#include <iostream>

using namespace std;

int findMaxTemptrue(const int *arr, const int &N, const int &K) {
    int first = 0;
    int last = K;
    int maxSum = 0;
    int savedSum = 0;
    
    for(int i = 0; i < K; i++) {
        maxSum += arr[i];
        savedSum += arr[i];
    }
    
    while(last < N) {
        int curSum = savedSum - arr[first] + arr[last];
        savedSum = curSum;
        
        if(curSum > maxSum)
            maxSum = curSum;
        
        first++;
        last++;
    }
    
    return maxSum;
}

int main(void) {
    int N, K;
    cin >> N >> K;
    
    int *arr = new int[N];
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << findMaxTemptrue(arr, N, K) << '\n';
    
    delete [] arr;
}
