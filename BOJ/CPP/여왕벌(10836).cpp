#include <iostream>
#include <vector>

using namespace std;

int M, N;
vector<int> grow;

int main(void) {
    cin >> M >> N;
    
    grow.resize(2 * M - 1, 1);
    
    while(N--) {
        int zero_cnt, one_cnt, two_cnt;
        cin >> zero_cnt >> one_cnt >> two_cnt;
        
        for(int i = zero_cnt; i < zero_cnt + one_cnt; i++) {
            grow[i] += 1;
        }
        
        for(int i = zero_cnt + one_cnt; i < 2 * M - 1; i++) {
            grow[i] += 2;
        }
    }
    
    for(auto &i : grow)
        cout << i << ' ';
    cout << endl;
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            if(j == 0)
                cout << grow[M - i - 1] << ' ';
            else
                cout << grow[M + j - 1] << ' ';
        }
        cout << '\n';
    }
}
