#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int city[101][101];

#define INF 987654321

void floyd_washall() {
    // i : mid, j : src, k : dst
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
            }
        }
    }
}

void set_city_arr() {
    for(int i = 0; i < 101; i++) {
        for(int j = 0; j < 101; j++) {
            city[i][j] = INF;
        }
    }
}

void print_city_arr() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(city[i][j] == INF || i == j)
                city[i][j] = 0;
            cout << city[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(void) {
    set_city_arr();
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int src, dst, cost;
        
        cin >> src >> dst >> cost;
        
        if(cost < city[src][dst])
            city[src][dst] = cost;
    }
    
    floyd_washall();
    print_city_arr();
}
