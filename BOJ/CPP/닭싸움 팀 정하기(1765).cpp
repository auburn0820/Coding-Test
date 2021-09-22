#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M;
vector<vector<pair<char, int>>> nodes;
vector<int> nodes_marked_friend;
set<int> teams;

void find_friend(const bool is_enermy, const int start_node, const int cur_node) {
    if(!is_enermy)
        nodes_marked_friend[cur_node] = start_node;
    
    for(int i = 0; i < nodes[cur_node].size(); i++) {
        char relation = nodes[cur_node][i].first;
        int next_node = nodes[cur_node][i].second;
        
        if(nodes_marked_friend[next_node] == start_node)
            continue;
        
        if(is_enermy && relation == 'E')
            find_friend(false, start_node, next_node);
        else if(is_enermy && relation == 'F')
            continue;
        else if(!is_enermy && relation == 'F')
            find_friend(false, start_node, next_node);
        else if(!is_enermy && relation == 'E')
            find_friend(true, start_node, next_node);
    }
}

int main(void) {
    cin >> N >> M;
    nodes.resize(N + 1);
    nodes_marked_friend.resize(N + 1, 0);
    
    for(int i = 0; i < M; i++) {
        char r;
        int p, q;
        
        cin >> r >> p >> q;
        
        nodes[p].push_back(make_pair(r, q));
        nodes[q].push_back(make_pair(r, p));
    }
    
    for(int i = 1; i <= N; i++) {
        if(nodes_marked_friend[i] > 0)
            continue;
        find_friend(false, i, i);
    }
    
    for(int i = 1; i <= N; i++) {
        teams.insert(nodes_marked_friend[i]);
    }
    cout << teams.size() << '\n';
}
