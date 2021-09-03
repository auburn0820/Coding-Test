#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;

void floyd_warshall(vector<vector<int>> &dist, int N) {
    for(int mid = 1; mid <= N; mid++) {
        for(int start = 1; start <= N; start++) {
            for(int end = 1; end <= N; end++) {
                if(start == end)
                    dist[start][end] = 0;
                if(dist[start][end] > dist[start][mid] + dist[mid][end])
                    dist[start][end] = dist[start][mid] + dist[mid][end];
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    
    for(int i = 0; i < road.size(); i++) {
        dist[road[i][0]][road[i][1]] = min(road[i][2], dist[road[i][0]][road[i][1]]);
        dist[road[i][1]][road[i][0]] = min(road[i][2], dist[road[i][1]][road[i][0]]);
    }
    
    floyd_warshall(dist, N);
    
    for(int i = 1; i <= N; i++) {
        if(dist[1][i] <= K)
            answer++;
    }
    
    return answer;
}
