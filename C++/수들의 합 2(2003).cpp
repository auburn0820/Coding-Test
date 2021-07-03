#include <iostream>

using namespace std;

int main(void) {
    int N, M;
    cin >> N >> M;
    
    int *arr = new int[N];
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int cnt = 0;
    int curSum = arr[0];
    int first = 0;
    int last = 0;
    
    while(last < N) {
        if(curSum == M) {
            curSum -= arr[first];
            cnt++;
            first++;
            if(first > last) {
                last = first;
                curSum += arr[last];
            }
        } else if(curSum < M) {
            last++;
            curSum += arr[last];
        } else {
            curSum -= arr[first];
            first++;
        }
    }
    
    delete[] arr;
    
    cout << cnt << '\n';
}
