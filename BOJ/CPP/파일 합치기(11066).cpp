#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int T, K;
vector<int> files;
vector<vector<int>> DP;
vector<int> costs;

int main(void) {
    cin >> T;
    while(T--) {
        cin >> K;
        files.clear();
        costs.clear();
        DP.clear();
        
        files.resize(K + 1);
        costs.resize(K + 1, 0);
        DP.resize(K + 1, vector<int>(K + 1));
        
        for(int i = 1; i <= K; i++) {
            cin >> files[i];
            costs[i] = costs[i - 1] + files[i];
        }
        
        for(int i = 1; i < K; i++) {
            for(int j = 1; j + i <= K; j++) {
                DP[j][i + j] = INT_MAX;
                for(int k = j; k < i + j; k++) {
                    DP[j][i + j] = min(DP[j][i + j], DP[j][k] + DP[k + 1][i + j] + costs[i + j] - costs[j - 1]);
                }
            }
        }
        
        cout << DP[1][K] << '\n';
    }
}
