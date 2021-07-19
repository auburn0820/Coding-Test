#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

#define INF 987654321

int N, M;
int city[101][101];
bool visit[101];
pair<int, int> result_city;
int result_dist = INT_MAX;

void check_chicken_house_distance(int chicken_house_one, int chicken_house_two) {
    int total_distance = 0;
    for(int i = 1; i <= N; i++) {
        if(chicken_house_one == i || chicken_house_one == i)
            continue;
        
        total_distance += min(city[chicken_house_one][i], city[chicken_house_two][i]) * 2;
    }
    
    if(result_dist > total_distance) {
        result_city = {chicken_house_one, chicken_house_two};
        result_dist = total_distance;
    }
}

void get_chicken_house_location() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            check_chicken_house_distance(i, j);
        }
    }
}

void floyd_warshall() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                if(j == k)
                    city[j][k] = 0;
                else
                    city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
            }
        }
    }
}

void set_city_dist() {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            city[i][j] = INF;
        }
    }
}

int main(void) {
    cin >> N >> M;
    
    set_city_dist();
    
    for(int i = 0; i < M; i++) {
        int src, dst;
        cin >> src >> dst;
        
        city[src][dst] = 1;
        city[dst][src] = 1;
    }
    
    floyd_warshall();
    get_chicken_house_location();
    
    cout << result_city.first << ' ' << result_city.second << ' ' << result_dist << '\n';
}
