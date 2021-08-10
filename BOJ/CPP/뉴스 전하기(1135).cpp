#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int staff_num;
    vector<int> subordinates;
};

Node nodes[50];
int N;

int DFS(int num) {
    vector<int> ch;
    for(auto &i : nodes[num].subordinates) {
        ch.push_back(DFS(i));
    }
    if(ch.empty())
        return 0;
    sort(ch.begin(), ch.end());
    int ret = ch.back() + 1;
    
    int cnt = 1;
    for(int i = (int)ch.size() - 2; i >= 0; i--, cnt++) {
        if(ch[i] + 1 > ret - cnt) {
            ret += (ch[i] + 1 - ret + cnt);
        }
    }
    
    return ret;
}

int main(void) {
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int senior;
        cin >> senior;
        nodes[i].staff_num = i;
        if(senior != -1) {
            nodes[senior].subordinates.push_back(i);
        }
    }
    
    cout << DFS(0) << '\n';
}
