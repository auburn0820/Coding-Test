#include <iostream>

using namespace std;

int N;
int map[16][16] = {0, };
int dist[1 << 16][16] = {0, };
const int INF = 987654321;

int TSP(int visit, int cur) {
    visit |= (1 << cur);
    
    if(visit == (1 << N) - 1) {
        if(map[cur][0] > 0)
            return map[cur][0];
        return INF;
    }
    
    int &ret = dist[visit][cur];
    
    if(ret > 0)
        return ret;
    ret = INF;
    for(int i = 0; i < N; i++) {
        if(i != cur && (visit & (1 << i)) == 0 && map[cur][i] > 0) {
            int temp = TSP(visit, i) + map[cur][i];
            if(ret > temp)
                ret = temp;
        }
    }
    return ret;
}

int main(void) {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    
    int result = TSP(0, 0);
    
    if(result == INF)
        result = -1;
    
    cout << result << '\n';
}
