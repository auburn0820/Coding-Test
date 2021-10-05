#include <iostream>
#include <algorithm>

using namespace std;

int N;
int DP[1500051] = {0, };
int works[1500051][2] = {0, };

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> works[i][0] >> works[i][1];
    }
    
    int max_val = 0;
    for(int i = 0; i <= N; i++) {
        int a = works[i][0];
        int b = works[i][1];
        
        max_val = max(max_val, DP[i]);
        
        if(i + a > N)
            continue;
        if(DP[i + a] < max_val + b) {
            DP[i + a] = max_val + b;
        }
    }
    
    cout << max_val << '\n';
}
