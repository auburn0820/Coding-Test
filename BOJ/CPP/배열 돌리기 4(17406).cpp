#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct OperationInfo {
    int r, c, s;
};

void rotate_arr(vector<vector<int>> &arr, const int r, const int c, const int s) {
    int temp_s = s;
    while(temp_s > 0) {
        int temp = arr[r - temp_s][c - temp_s];
        int x, y;
        
        x = c - temp_s;
        for(int i = r - temp_s; i < r + temp_s; i++) {
            arr[i][x] = arr[i + 1][x];
        }
        
        y = r + temp_s;
        for(int i = c - temp_s; i < c + temp_s; i++) {
            arr[y][i] = arr[y][i + 1];
        }
        
        x = c + temp_s;
        for(int i = r + temp_s; i > r - temp_s; i--) {
            arr[i][x] = arr[i - 1][x];
        }
        
        y = r - temp_s;
        for(int i = c + temp_s; i > c - temp_s; i--) {
            arr[y][i] = arr[y][i - 1];
        }
        
        arr[r - temp_s][c - temp_s + 1] = temp;
        temp_s--;
    }
}

int get_min_value(vector<vector<int>> &arr) {
    size_t row = arr.size();
    size_t col = arr[0].size();
    
    int min_val = INT_MAX;
    
    for(int i = 0; i < row; i++) {
        int sum = 0;
        for(int j = 0; j < col; j++) {
            sum += arr[i][j];
        }
        
        min_val = min(min_val, sum);
    }
    
    return min_val;
}

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int N, M, K;
    vector<int> cases;
    vector<vector<int>> arr;
    vector<vector<int>> copied_arr;
    vector<OperationInfo> operations;
    
    cin >> N >> M >> K;
    
    arr.resize(N, vector<int>(M, 0));
    cases.resize(K);
    operations.resize(K);
    
    for(int i = 0; i < K; i++)
        cases[i] = i;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i = 0; i < K; i++) {
        int r, c, s;
        cin >> r >> c >> s;
        operations[i] = {r - 1, c - 1, s};
    }
    
    int answer = INT_MAX;
    
    do {
        copied_arr.clear();
        copy(arr.begin(), arr.end(), back_inserter(copied_arr));
        
        for(int i = 0; i < K; i++) {
            rotate_arr(copied_arr, operations[cases[i]].r, operations[cases[i]].c, operations[cases[i]].s);
        }
        
        answer = min(answer, get_min_value(copied_arr));
        
    } while(next_permutation(cases.begin(), cases.end()));
    
    cout << answer << '\n';
}
