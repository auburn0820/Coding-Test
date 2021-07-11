#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

struct Results {
    int a, b, c;
};

int main(void) {
    int N;
    cin >> N;
    
    int solutions[N];
    
    for(auto &solution : solutions) {
        cin >> solution;
    }
    
    sort(solutions, solutions + N);
    
    long long sum = LONG_LONG_MAX;
    Results result;
    
    for(int left = 0; left < N - 2; left++) {
        int mid = left + 1;
        int right = N - 1;
        
        while(mid < right) {
            long long temp_sum = (long long)solutions[left] + solutions[mid] + solutions[right];
            
            if(abs(sum) > abs(temp_sum)) {
                sum = temp_sum;
                result = {solutions[left], solutions[mid], solutions[right]};
            }
            
            if(temp_sum < 0) {
                mid++;
            } else {
                right--;
            }
        }
    }
    
    cout << result.a << ' ' << result.b << ' ' << result.c << '\n';
}
