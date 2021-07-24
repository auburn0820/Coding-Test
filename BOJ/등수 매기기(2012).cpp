#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int *predict_grade;
int *grade;

int main(void) {
    cin >> N;
    
    predict_grade = new int[N];
    grade = new int[N];
    
    memset(predict_grade, 0, sizeof(int) * N);
    memset(grade, 0, sizeof(int) * N);
    
    for(int i = 0; i < N; i++) {
        cin >> predict_grade[i];
    }
    
    sort(predict_grade, predict_grade + N);
    
    for(int i = 0; i < N; i++) {
        if(grade[i] == 0) {
            grade[i] = predict_grade[i];
        } else {
            int idx = i;
            
            while(idx++ < N - 1) {
                if(grade[idx] == 0) {
                    grade[idx] = predict_grade[i];
                    break;
                }
            }
        }
    }
    
    long long result = 0;
    
    for(int i = 0; i < N; i++) {
        result += abs(i + 1 - grade[i]);
    }
    
    cout << result << '\n';
}
