#include <iostream>
#include <vector>

using namespace std;

int N, M;
int dist[201][201];
vector<int> cities_to_visit;

void floyd_warshall() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                if(dist[j][k] > dist[j][i] + dist[i][k])
                    dist[j][k] = dist[j][i] + dist[i][k];
            }
        }
    }
}

int main(void) {
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> dist[i][j];
            
            if(dist[i][j] == 0 && i != j)
                dist[i][j] = 987654321;
        }
    }
    
    for(int i = 0; i < M; i++) {
        int city;
        cin >> city;
        cities_to_visit.push_back(city);
    }
    
    floyd_warshall();
    
    bool flag = true;
    
    for(int i = 0; i < (int)cities_to_visit.size() - 1; i++) {
        if(dist[cities_to_visit[i]][cities_to_visit[i + 1]] == 987654321) {
            flag = false;
            break;
        }
    }
    
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}
