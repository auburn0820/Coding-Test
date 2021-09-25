#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, W;
long long dist[501];
vector<pair<int, int>> adj[501];
const int INF = 1e9;

bool bellman_ford() {
    bool is_negative_cycle = false;
    
    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= N; j++) {
            for(auto &k : adj[j]) {
                int next = k.first;
                int cost = k.second;
                
                if(dist[j] != INF && dist[next] > dist[j] + cost) {
                    dist[next] = dist[j] + cost;
                }
            }
        }
    }
    
    for(int i = 1; i <= N; i++) {
        for(auto &j : adj[i]) {
            int next = j.first;
            int cost = j.second;

            if(dist[i] != INF && dist[next] > dist[i] + cost) {
                is_negative_cycle = true;
                break;
            }
        }
    }
    
    return is_negative_cycle;
}

int main(void) {
    cin >> T;
    
    while(T--) {
        cin >> N >> M >> W;
        for(int i = 0; i <= N; i++)
            adj[i].clear();
        
        for(int i = 0; i < M; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            adj[S].push_back(make_pair(E, T));
            adj[E].push_back(make_pair(S, T));
        }
        
        for(int i = 0; i < W; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            adj[S].push_back(make_pair(E, -T));
        }
        
        bool result = false;
        
        fill(dist, dist + N + 1, 0);
        if(bellman_ford())
            result = true;
        
        if(result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
