#include <iostream>

using namespace std;

int N, K;
int kit[8] = {0, };
bool is_used[8] = {false, };
int result = 0;

void find_cases(int weights, int day) {
    if(weights < 500) {
        return;
    }
    
    if(day == N) {
        result++;
        return;
    }
    
    for(int i = 0; i < N; i++) {
        if(is_used[i])
            continue;
        is_used[i] = true;
        find_cases(weights - K + kit[i], day + 1);
        is_used[i] = false;
    }
}

int main(void) {
    cin >> N >> K;
    
    for(int i = 0; i < N; i++) {
        cin >> kit[i];
    }
    
    find_cases(500, 0);
    
    cout << result << '\n';
}
