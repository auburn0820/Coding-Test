#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    
    int *arr = new int[N];
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    int left = 0;
    int right = N - 1;
    int min_val = arr[left] + arr[right];
    pair<int, int> result = {arr[left], arr[right]};
    
    while(left < right - 1) {
        if(abs(arr[left]) > abs(arr[right]))
            left++;
        else
            right--;
        
        int sum = arr[left] + arr[right];
        
        if(abs(sum) < abs(min_val)) {
            min_val = sum;
            result = {arr[left], arr[right]};
        }
    }
    
    cout << result.first << ' ' << result.second << '\n';
    
    delete [] arr;
}
