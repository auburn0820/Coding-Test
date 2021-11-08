#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
map<int, int> order;
map<int, int> number;
vector<pair<int, int>> v;

int main(void) {
    cin >> N >> C;
    
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        number[num] = number[num] + 1;
        if(order.find(num) == order.end())
            order[num] = i;
    }
    
    for(auto &i : number) {
        v.push_back(make_pair(i.first, i.second));
    }
    
    sort(v.begin(), v.end(), [](pair<int, int> &lhs, pair<int, int> &rhs) -> bool {
        if(lhs.second == rhs.second)
            return order[lhs.first] < order[rhs.first];
        return lhs.second > rhs.second;
    });
    
    for(auto &i : v) {
        for(int j = 0; j < i.second; j++) {
            cout << i.first << ' ';
        }
    }
    cout << '\n';
}
