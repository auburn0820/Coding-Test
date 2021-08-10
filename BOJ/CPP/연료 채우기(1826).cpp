#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, L, P;
vector<pair<int, int>> v;
priority_queue<int> pq;

int main(void) {
    cin >> N;
    
    v.resize(N);
    
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    cin >> L >> P;
    
    sort(v.begin(), v.end());
    
    int idx = 0;
    int ans = 0;
    
    while(P < L) {
        while(idx < N && P >= v[idx].first) {
            pq.push(v[idx].second);
            idx++;
        }
        
        if(pq.empty()) {
            ans = -1;
            break;
        }
        
        P += pq.top();
        pq.pop();
        ans++;
    }
    
    cout << ans << '\n';
}
