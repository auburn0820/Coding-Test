#include <iostream>
#include <algorithm>

using namespace std;

int r, c, k;
int arr[101][101];
pair<int, int> number_count[101];
int row = 3, col = 3;

void set_number_count_arr() {
    for(int i = 0; i < 101; i++)
        number_count[i] = {i, 0};
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second)
        return a.first < b.first;
    else
        
        return a.second < b.second;
}

void set_row_to_zero(int row_loc) {
    for(int j = 0; j < 101; j++) {
        arr[row_loc][j] = 0;
    }
}

void set_col_to_zero(int col_loc) {
    for(int j = 0; j < 101; j++) {
        arr[j][col_loc] = 0;
    }
}

void process_row_op() {
    int max_col = col;
    for(int i = 0; i < row; i++) {
        set_number_count_arr();
        for(int j = 0; j < 101; j++) {
            if(arr[i][j] == 0)
                continue;
            number_count[arr[i][j]].second++;
        }
        
        sort(begin(number_count), end(number_count), cmp);
        
        set_row_to_zero(i);
        
        for(int k = 0, j = 0; k < 100 && j < 101; j++) {
            if(number_count[j].first == 0 || number_count[j].second == 0)
                continue;
            arr[i][k] = number_count[j].first;
            arr[i][k + 1] = number_count[j].second;
            k += 2;
            
            max_col = max(max_col, k);
        }
    }
    
    col = max_col;
}

void process_col_op() {
    int max_row = row;
    
    for(int i = 0; i < col; i++) {
        set_number_count_arr();
        for(int j = 0; j < 101; j++) {
            if(arr[j][i] == 0)
                continue;
            number_count[arr[j][i]].second++;
        }
        
        sort(begin(number_count), end(number_count), cmp);
        
        set_col_to_zero(i);
        
        for(int k = 0, j = 0; k < 100 && j < 101; j++) {
            if(number_count[j].first == 0 || number_count[j].second == 0)
                continue;
            arr[k][i] = number_count[j].first;
            arr[k + 1][i] = number_count[j].second;
            k += 2;
            
            max_row = max(max_row, k);
        }
    }
    
    row = max_row;
}

int process_turn() {
    int turn_count = 0;
    
    while(turn_count <= 100) {
        if(arr[r - 1][c - 1] == k)
            return turn_count;
        
        turn_count++;
        
        if(row >= col) {
            process_row_op();
        }
        else {
            process_col_op();
        }
    }
    
    return -1;
}

int main(void) {
    cin.sync_with_stdio(false);
    cin >> r >> c >> k;
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << process_turn() << '\n';
}
