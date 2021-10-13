#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

int T, N;
vector<int> stickers[2];
vector<int> DP[2];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    while(T--) {
        cin >> N;
        for(int i = 0; i < 2; i++) {
            stickers[i].clear();
            DP[i].clear();
            stickers[i].resize(N + 1);
            DP[i].resize(N + 1);
        }
        
        for(auto &sticker : stickers) {
            for(int i = 1; i < sticker.size(); i++) {
                cin >> sticker[i];
            }
        }
        
        DP[0][0] = DP[1][0] = 0;
        DP[0][1] = stickers[0][1];
        DP[1][1] = stickers[1][1];
        
        for(int i = 2; i <= N; i++) {
            DP[0][i] = max(DP[1][i - 2], DP[1][i - 1]) + stickers[0][i];
            DP[1][i] = max(DP[0][i - 2], DP[0][i - 1]) + stickers[1][i];
        }
        
        cout << max(DP[0][N], DP[1][N]) << '\n';
    }
}
