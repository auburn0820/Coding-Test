#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b) {
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int main(void) {
    int N;
    cin >> N;
    
    vector<pair<int, int>> v;
    int scores[1000];
    memset(scores, 0, sizeof(scores));
    
    for(int i = 0; i < N; i++) {
        int d, w;
        cin >> d >> w;
        
        v.push_back({d, w});
    }
    
    sort(v.begin(), v.end(), comp);
    
    for(int i = 0; i < (int)v.size(); i++) {
        if(scores[v[i].first - 1] == 0) {
            scores[v[i].first - 1] = v[i].second;
        } else {
            int idx = v[i].first - 1;
            while(idx-- > 0) {
                if(scores[idx] == 0) {
                    scores[idx] = v[i].second;
                    break;
                }
            }
        }
    }
    
    int result = 0;
    
    for(int i = 0; i < 1000; i++) {
        result += scores[i];
    }
    
    cout << result << '\n';
}
