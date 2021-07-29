#include <iostream>
#include <cstring>

using namespace std;

int R, C, T;
int office[50][50];
int dust_value_to_added[50][50] = {0, };
pair<int, int> north_point = {-1, -1};
pair<int, int> south_point = {-1, -1};

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void spread_dust(int x, int y) {
    int dust_value = office[y][x] / 5;
    
    for(int i = 0; i < 4; i++) {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        if(next_x < 0 || next_y < 0 || next_x >= C || next_y >= R)
            continue;
        if(office[next_y][next_x] == -1)
            continue;
        
        office[y][x] -= dust_value;
        dust_value_to_added[next_y][next_x] += dust_value;
    }
}

void add_dust_value() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            office[i][j] += dust_value_to_added[i][j];
        }
    }
    memset(dust_value_to_added, 0, sizeof(dust_value_to_added));
}

void find_spread_dust() {
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(office[i][j] != -1 && office[i][j] != 0)
                spread_dust(j, i);
        }
    }
}

void turn_air_purifier() {
    // 윗 부분
    // 공기청정기 왼쪽
    for(int i = north_point.second - 1; i > 0; i--) {
        office[i][0] = office[i - 1][0];
    }
    
    // 공기청정기 위쪽
    for(int i = 0; i < C - 1; i++) {
        office[0][i] = office[0][i + 1];
    }
    
    // 공기청정기 오른쪽
    for(int i = 0; i < north_point.second; i++) {
        office[i][C - 1] = office[i + 1][C - 1];
    }
    
    // 공기청정기 아래쪽
    for(int i = C - 1; i > north_point.first + 1; i--) {
        office[north_point.second][i] = office[north_point.second][i - 1];
    }
    office[north_point.second][north_point.first + 1] = 0;
    
    // 아래 부분
    // 공기청정기 왼쪽
    for(int i = south_point.second + 1; i < R - 1; i++) {
        office[i][0] = office[i + 1][0];
    }
    
    // 공기청정기 아래쪽
    for(int i = 0; i < C - 1; i++) {
        office[R - 1][i] = office[R - 1][i + 1];
    }
    
    // 공기청정기 오른쪽
    for(int i = R - 1; i > south_point.second; i--) {
        office[i][C - 1] = office[i - 1][C - 1];
    }
    
    // 공기청정기 위쪽
    for(int i = C - 1; i > south_point.first + 1; i--) {
        office[south_point.second][i] = office[south_point.second][i - 1];
    }
    office[south_point.second][south_point.first + 1] = 0;
}

int print_remain_dust() {
    int result = 0;
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(office[i][j] != -1)
                result += office[i][j];
        }
    }
    
    return result;
}

int main(void) {
    cin >> R >> C >> T;
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> office[i][j];
            
            if(office[i][j] == -1) {
                if(north_point.first == -1 && south_point.second == -1) {
                    north_point = {j, i};
                    continue;
                }
                
                if(south_point.first == -1 && south_point.second == -1) {
                    south_point = {j, i};
                    continue;
                }
            }
        }
    }
    
    while(T--) {
        find_spread_dust();
        add_dust_value();
        turn_air_purifier();
    }
    cout << print_remain_dust() << '\n';
}
