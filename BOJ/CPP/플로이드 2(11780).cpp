#include <iostream>
#include <vector>

using namespace std;

#define INF 987654321

int n, m;
int city[101][101];
int path[101][101];

void floyd_warshall() {
    // i : mid, j : src, k : dst
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(j == k)
                    continue;
                if(city[j][k] > city[j][i] + city[i][k]) {
                    city[j][k] = city[j][i] + city[i][k];
                    path[j][k] = i;
                }
            }
        }
    }
}

void set_arr() {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            city[i][j] = INF;
            path[i][j] = 0;
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

void print_path(int start, int end, vector<int> &v) {
    if(path[start][end] == 0) {
        v.push_back(start);
        v.push_back(end);
        return;
    }
    
    print_path(start, path[start][end], v);
    v.pop_back();
    print_path(path[start][end], end, v);
}

int main(void) {
    cin >> n >> m;
    
    set_arr();
    
    for(int i = 0; i < m; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        
        if(city[src][dst] > cost) {
            city[src][dst] = cost;
        }
    }
    floyd_warshall();
    print_city_arr();
    
    vector<int> v;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j<= n; j++) {
            if(city[i][j] == 0)
                cout << 0 << '\n';
            else {
                v.clear();
                print_path(i, j, v);

                cout << (int)v.size() << ' ';
                for(auto &i : v) {
                    cout << i << ' ';
                }
                cout << '\n';
            }
        }
    }
}
