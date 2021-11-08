#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

int DP[61][61][61];
int numbers[3];
vector<int> cases = {1, 3, 9};
int N;

int attack_scv(int a, int b, int c) {
    if(a < 0)
        return attack_scv(0, b, c);
    if(b < 0)
        return attack_scv(a, 0, c);
    if(c < 0)
        return attack_scv(a, b, 0);
    
    if(a == 0 && b == 0 && c == 0)
        return 0;
    
    
    if(DP[a][b][c] != -1)
        return DP[a][b][c];
    
    DP[a][b][c] = INT_MAX;

    do {
        DP[a][b][c] = min(DP[a][b][c], attack_scv(a - cases[0], b - cases[1], c - cases[2]) + 1);
    } while(next_permutation(cases.begin(), cases.end()));
    
    return DP[a][b][c];
}

int main(void) {
    cin >> N;
    
    memset(DP, -1, sizeof(DP));
    memset(numbers, 0, sizeof(numbers));
    
    for(int i = 0; i < N; i++)
        cin >> numbers[i];
    
    cout << attack_scv(numbers[0], numbers[1], numbers[2]) << '\n';
}
