#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

constexpr int INF = 987654321;
int dist[201][201];

void floyd_warshall(int n) {
    for(int mid = 1; mid <= n; mid++) {
        for(int src = 1; src <= n; src++) {
            for(int dst = 1; dst <= n; dst++) {
                if(src == dst)
                    dist[src][dst] = 0;
                if(dist[src][dst] > dist[src][mid] + dist[mid][dst])
                    dist[src][dst] = dist[src][mid] + dist[mid][dst];
            }
        }
    }
}

int get_min_distance(const int n, const int s, const int a, const int b) {
    int min_distance = INT_MAX;
    int a_pos, b_pos, total = 0;
    
    // i 지점까지 가서 흩어지는 경우
    for(int i = 1; i <= n; i++) {
        if(dist[s][i] == INF || dist[i][a] == INF || dist[i][b] == INF)
            continue;
        
        total += dist[s][i];
        a_pos = b_pos = i;
        
        total += dist[a_pos][a];
        total += dist[b_pos][b];
        
        min_distance = min(min_distance, total);
        total = 0;
    }
    
    return min_distance;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    // Set dist array
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            dist[i][j] = INF;
        }
    }
    
    // Insert distance data to dist array
    for(size_t i = 0; i < fares.size(); i++) {
        for(size_t j = 0; j < fares[i].size(); j++) {
            int c = fares[i][0];
            int d = fares[i][1];
            int f = fares[i][2];
            
            dist[c][d] = f;
            dist[d][c] = f;
        }
    }
    
    // Get min distance
    floyd_warshall(n);
    
    answer = get_min_distance(n, s, a, b);
    
    return answer;
}
