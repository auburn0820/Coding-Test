#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main(void) {
    cin.sync_with_stdio(false);
    cin >> N;
    
    v.resize(N);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    for(auto &i : v) {
        cout << i << '\n';
    }
}
