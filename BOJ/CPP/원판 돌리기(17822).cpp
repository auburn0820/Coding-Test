#include <iostream>

using namespace std;

int N, M, T;
int circle[51][51];
int copied_circle[51][51];

void copy_circle() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            copied_circle[i][j] = circle[i][j];
        }
    }
}

void rotate_counterclockwise(int x, int k) {
    int idx = 1;
    
    while(idx * x <= N) {
        int rotate_circle = idx * x;
        
        int k_temp = k;
        while(k_temp--) {
            int temp = circle[rotate_circle][1];
            for(int i = 1; i < M; i++) {
                circle[rotate_circle][i] = circle[rotate_circle][i + 1];
            }
            circle[rotate_circle][M] = temp;
        }
        
        idx++;
    }
}

void rotate_clockwise(int x, int k) {
    int idx = 1;
    
    while(idx * x <= N) {
        int rotate_circle = idx * x;
        
        int k_temp = k;
        while(k_temp--) {
            int temp = circle[rotate_circle][M];
            for(int i = M; i > 1; i--) {
                circle[rotate_circle][i] = circle[rotate_circle][i - 1];
            }
            circle[rotate_circle][1] = temp;
        }
        
        idx++;
    }
}

void check_adjacent_number() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(copied_circle[i][j] == -1)
                continue;
            
            if(i > 1) {
                if(circle[i - 1][j] == circle[i][j]) {
                    copied_circle[i - 1][j] = 0;
                    copied_circle[i][j] = 0;
                }
            }
            
            if(i < M) {
                if(circle[i + 1][j] == circle[i][j]) {
                    copied_circle[i + 1][j] = 0;
                    copied_circle[i][j] = 0;
                }
            }
            
            if(j == 1) {
                if(circle[i][M] == circle[i][j]) {
                    copied_circle[i][M] = 0;
                    copied_circle[i][j] = 0;
                }
                
                if(circle[i][j + 1] == circle[i][j]) {
                    copied_circle[i][j + 1] = 0;
                    copied_circle[i][j] = 0;
                }
            }
            else if(j == M) {
                if(circle[i][1] == circle[i][j]) {
                    copied_circle[i][1] = 0;
                    copied_circle[i][j] = 0;
                }
                
                if(circle[i][j - 1] == circle[i][j]) {
                    copied_circle[i][j - 1] = 0;
                    copied_circle[i][j] = 0;
                }
            }
            else {
                if(circle[i][j - 1] == circle[i][j]) {
                    copied_circle[i][j - 1] = 0;
                    copied_circle[i][j] = 0;
                }
                
                if(circle[i][j + 1] == circle[i][j]) {
                    copied_circle[i][j + 1] = 0;
                    copied_circle[i][j] = 0;
                }
            }
        }
    }
}

bool check_number_erased() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(copied_circle[i][j] == 0)
                return true;
        }
    }
    
    return false;
}

void erase_number() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(copied_circle[i][j] == 0)
                circle[i][j] = -1;
            else
                circle[i][j] = copied_circle[i][j];
        }
    }
}

void cal_change_number_val() {
    double sum = 0;
    double number_count = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(copied_circle[i][j] != -1) {
                sum += copied_circle[i][j];
                number_count++;
            }
        }
    }
    
    double avg = sum / number_count;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(circle[i][j] != -1) {
                if(circle[i][j] < avg) {
                    circle[i][j]++;
                } else if(circle[i][j] > avg) {
                    circle[i][j]--;
                }
            }
        }
    }
}

void change_number() {
    if(check_number_erased()) {
        erase_number();
    } else {
        cal_change_number_val();
    }
}

int sum_of_circle() {
    int sum = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(circle[i][j] != -1) {
                sum += circle[i][j];
            }
        }
    }
    
    return sum;
}

int main(void) {
    cin >> N >> M >> T;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> circle[i][j];
        }
    }
    
    while(T--) {
        int x, d, k;
        cin >> x >> d >> k;
        
        if(d == 0) {
            rotate_clockwise(x, k);
        }
        else {
            rotate_counterclockwise(x, k);
        }
        
        copy_circle();
        check_adjacent_number();
        change_number();
    }
    
    cout << sum_of_circle() << '\n';
}
