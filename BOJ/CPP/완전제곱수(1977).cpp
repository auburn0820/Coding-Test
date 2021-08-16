#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

bool is_perfect_square_number(int number) {
    int idx = 1;
    
    while(idx * idx <= number) {
        if(idx * idx == number)
            return true;
        else
            idx++;
    }
    return false;
}

int main(void) {
    int N, M;
    cin >> N >> M;
    
    int sum = 0;
    int min_num = INT_MAX;
    for(int i = N; i <= M; i++) {
        if(is_perfect_square_number(i)) {
            sum += i;
            min_num = min(i, min_num);
        }
    }
    
    if(sum != 0 && min_num != INT_MAX)
        cout << sum << '\n' << min_num << '\n';
    else
        cout << -1 << '\n';
}
