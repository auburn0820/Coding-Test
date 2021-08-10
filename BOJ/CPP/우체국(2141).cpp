#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> v;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

int main(void) {
    cin >> N;
    
    long long people_count = 0;
    
    for(int i = 0; i < N; i++) {
        int x, a;
        cin >> x >> a;
        v.push_back({x, a});
        people_count += a;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    long long people_count_temp = 0;
    people_count = (people_count + 1) / 2;
    
    for(int i = 0; i < (int)v.size(); i++) {
        people_count_temp += v[i].second;
        
        if(people_count_temp >= people_count) {
            cout << v[i].first << '\n';
            break;
        }
    }
}
