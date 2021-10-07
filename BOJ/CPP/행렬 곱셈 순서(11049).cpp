#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N;
pair<int, int> matrixes[501] = {{0, 0}, };
int DP[501][501] = {0, };

int main(void) {
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        matrixes[i] = make_pair(a, b);
    }
    
    for(int range = 1; range <= N; range++) {
        for(int start = 1; start + range <= N; start++) {
            int end = start + range;
            DP[start][end] = INT_MAX;
            for(int mid = start; mid <= end; mid++) {
                DP[start][end] = min(DP[start][end], DP[start][mid] + DP[mid + 1][end] + matrixes[start].first * matrixes[mid].second * matrixes[end].second);
            }
        }
    }
    
    cout << DP[1][N] << '\n';
}
