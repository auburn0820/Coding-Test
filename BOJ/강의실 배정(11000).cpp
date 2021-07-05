#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        if(a.first == b.first)
            return a.second > b.second;
        
        return a.first > b.first;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
priority_queue<int, vector<int>, greater<int>> class_pq;

int main(void) {
    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int s, t;
        cin >> s >> t;
        pq.push({s, t});
    }
    
    while(!pq.empty()) {
        pair<int, int> lecture = pq.top();
        pq.pop();
        
        if(class_pq.empty()) {
            class_pq.push(lecture.second);
        } else {
            if(class_pq.top() <= lecture.first) {
                class_pq.pop();
                class_pq.push(lecture.second);
            } else {
                class_pq.push(lecture.second);
            }
        }
    }
    
    cout << class_pq.size() << '\n';
}
