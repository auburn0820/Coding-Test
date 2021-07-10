#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    int boxes[n];
    
    for(auto &box : boxes)
        cin >> box;
    
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    int result = 1;
    
    for(int i = 1; i < n; i++) {
        int max_box_count = 0;
        for(int j = 0; j < i; j++) {
            if(boxes[i] > boxes[j]) {
                max_box_count = max(max_box_count, dp[j]);
            }
        }
        dp[i] = max_box_count + 1;
        result = max(result, dp[i]);
    }
    
    cout << result << '\n';
}
