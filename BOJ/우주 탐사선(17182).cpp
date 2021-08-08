#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, K;
int planets[10][10] = {0, };
int result = INT_MAX;
bool is_visit[10];
vector<int> path;

void floyd_warshall() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                if(planets[j][k] > planets[j][i] + planets[i][k]) {
                    planets[j][k] = planets[j][i] + planets[i][k];
                }
            }
        }
    }
}

void comb_path() {
    if((int)path.size() == N) {
        int distance = 0;
        
        for(int i = 0; i < N - 1; i++) {
            distance += planets[path.at(i)][path.at(i + 1)];
        }
        
        result = min(result, distance);
        return;
    }
    
    for(int i = 0; i < N; i++) {
        if(i == K || is_visit[i])
            continue;
        
        path.push_back(i);
        is_visit[i] = true;
        comb_path();
        is_visit[i] = false;
        path.pop_back();
    }
}

int main(void) {
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> planets[i][j];
        }
    }
    
    path.push_back(K);
    floyd_warshall();
    comb_path();
    
    cout << result << '\n';
}
