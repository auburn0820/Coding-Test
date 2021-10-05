#include <iostream>
#include <algorithm>

using namespace std;

int DP[1001] = {0, };
int numbers[1001] = {0, };
int N;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> numbers[i];
        DP[i] = 1;
    }
    for(int i = 1; i < N; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(numbers[j] > numbers[i] && DP[j] >= DP[i]) {
                DP[i] = DP[j] + 1;
            }
        }
    }
    
    int answer = 0;
    for(int i = 0; i < N; i++) {
        answer = max(answer, DP[i]);
    }
    cout << answer << '\n';
}
