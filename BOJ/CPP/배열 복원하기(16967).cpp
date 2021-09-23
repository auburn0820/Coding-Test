#include <iostream>
#include <vector>

using namespace std;

int H, W, X, Y;
vector<vector<int>> arr;

int main(void) {
    cin >> H >> W >> X >> Y;
    
    arr.resize(H + X, vector<int>(W + Y, 0));
    
    for(int i = 0; i < H + X; i++) {
        for(int j = 0; j < W + Y; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            arr[i + X][j + Y] -= arr[i][j];
        }
    }
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
