#include <iostream>
#include <vector>

using namespace std;

int N, B, C;
vector<int> v;

int main(void) {
    cin >> N;
    
    v.resize(N);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    cin >> B >> C;
    
    
    long long cnt = 0;
    for(int i = 0; i < N; i++) {
        v[i] -= B;
        cnt++;
        
        if(v[i] > 0) {
            if(v[i] % C == 0)
                cnt += v[i] / C;
            else
                cnt += v[i] / C + 1;
        }
    }
    
    cout << cnt << '\n';
}
