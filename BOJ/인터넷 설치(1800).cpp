#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = INT_MAX;

int N, P, K;
vector<pair<int, int>> edges[1001];
int dist[1001];

bool djikstra(int max_value) {
    for(int i = 1; i <= N; i++)
        dist[i] = INF;
    dist[1] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 1});
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur_position = pq.top().second;
        
        pq.pop();
        
        for(int i = 0; i < (int)edges[cur_position].size(); i++) {
            int next_position = edges[cur_position][i].first;
            int next_dist = cost;
            
            if(edges[cur_position][i].second > max_value)
                next_dist += 1;
            else
                next_dist += 0;
            
            if(dist[next_position] > next_dist) {
                dist[next_position] = next_dist;
                pq.push({next_dist, next_position});
            }
        }
    }
    
    if(dist[N] <= K)
        return true;
    else
        return false;
}

int main(void) {
    cin >> N >> P >> K;
    
    int left = 0, right = 0;
    
    for(int i = 0; i < P; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edges[src].push_back({dst, cost});
        edges[dst].push_back({src, cost});
        right = max(right, cost);
    }
    
    int ans = -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(djikstra(mid)) {
            right = mid - 1;
            ans = mid;
        } else
            left = mid + 1;
    }
    
    cout << ans << '\n';
}
