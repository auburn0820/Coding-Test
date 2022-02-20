#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;

    vector<pair<int, int>> jewels(N);
    vector<int> bags(K);

    for(int i = 0; i < N; i++) {
        int weight, price;
        cin >> weight >> price;

        jewels[i] = make_pair(weight, price);
    }

    for(int i = 0; i < K; i++) {
        int bag;
        cin >> bag;

        bags[i] = bag;
    }

    sort(bags.begin(), bags.end());
    sort(jewels.begin(), jewels.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) -> bool {
        return lhs.first < rhs.first;
    });
    
    priority_queue<int, vector<int>, less<int>> pq;
    int cursor = 0;
    unsigned long long answer = 0;
    
    for(auto bag : bags) {
        for(; cursor < (int)jewels.size() && jewels[cursor].first <= bag; cursor++) {
            pq.push(jewels[cursor].second);
        }
        
        if(!pq.empty()) {
            answer += (unsigned long long)pq.top();
            pq.pop();
        }
    }
    
    cout << answer << endl;
}
