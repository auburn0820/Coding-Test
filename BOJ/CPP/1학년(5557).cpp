#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
vector<int> numbers;
long long DP[110][22];

long long count_cases(int i, int j) {
    if (i < 0 || j < 0 || j > 20)
        return 0;
    if(i == 0 && j == numbers[0])
        return 1;
    if(DP[i][j] != -1)
        return DP[i][j];
    
    return DP[i][j] = count_cases(i - 1, j - numbers[i]) + count_cases(i - 1, j + numbers[i]);
}

int main(void) {
    cin >> N;
    numbers.resize(N);
    
    for(int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    memset(DP, -1, sizeof(DP));
    
    cout << count_cases(N - 2, numbers[N - 1]) << '\n';
}
