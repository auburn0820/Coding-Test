#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int dist[501][501];
const int INF = 987654321;

void floyd_warshall() {
    for(int mid = 1; mid <= N; mid++) {
        for(int src = 1; src <= N; src++) {
            for(int dst = 1; dst <= N; dst++) {
                if(dist[src][dst] > dist[src][mid] + dist[mid][dst] && dist[src][mid] != INF) {
                    dist[src][dst] = dist[src][mid] + dist[mid][dst];
                }
            }
        }
    }
    
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++) {
//            cout << dist[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    
}

void set_dist_arr() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
}

int main(void) {
    scanf("%d %d", &N, &M);
    
    set_dist_arr();
    
    for(int i = 0; i < M; i++) {
        int src, dst, cost;
        scanf("%d %d %d", &src, &dst, &cost);
        if(dist[src][dst] != INF)
            dist[src][dst] = min(dist[src][dst], cost);
        else
            dist[src][dst] = cost;
    }
    
    floyd_warshall();
    
    int ans[N + 1];
    
    for(int i = 1; i <= N; i++) {
        if(dist[i][i] < 0 && dist[1][i] != INF) {
            ans[0] = -1;
            continue;
        }
        ans[i] = dist[1][i];
    }
    
    if(ans[0] == -1)
        cout << -1 << '\n';
    else {
        for(int i = 2; i <= N; i++) {
            if(ans[i] == INF)
                cout << -1 << '\n';
            else
                cout << ans[i] << '\n';
        }
    }
}
