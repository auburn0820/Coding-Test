#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<pair<int, int>> v;
    int max_count = -1;
    int currnet_count = 0;
    
    for(int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    
    for(auto &i : v) {
        currnet_count -= i.first;
        currnet_count += i.second;
        
        max_count = max(max_count, currnet_count);
    }
    
    cout << max_count << '\n';
}
