#include <iostream>
#include <cstring>

using namespace std;

long long DP[31][31];

void set_DP_arr(int N) {
    memset(DP, 0, sizeof(DP));
    for(int i = 1; i <= N; i++) {
        DP[1][i] = i;
    }
}

long long get_number_of_str(int N) {
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i > j)
                continue;
            DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
        }
    }
    
    return DP[N][N];
}

int main(void) {
    int N;
    
    cin >> N;
    while(N != 0) {
        set_DP_arr(N);
        cout << get_number_of_str(N) << '\n';
        cin >> N;
    }
}
