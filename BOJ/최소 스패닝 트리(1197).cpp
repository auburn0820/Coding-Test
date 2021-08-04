#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dst, cost;
};

int V, E;
int set[10001];
vector<Edge> edges;

bool cmp(Edge &a, Edge &b) {
    return a.cost < b.cost;
}

int get_parent(int node) {
    if(node == set[node])
        return node;
    else
        return set[node] = get_parent(set[node]);
}

bool is_same_parent(int node1, int node2) {
    node1 = get_parent(node1);
    node2 = get_parent(node2);
    
    if(node1 == node2)
        return true;
    else
        return false;
}

void union_parent(int node1, int node2) {
    node1 = get_parent(node1);
    node2 = get_parent(node2);
    
    if(node1 < node2)
        set[node2] = node1;
    else
        set[node1] = node2;
}

int main(void) {
    cin >> V >> E;
    
    for(int i = 0; i < E; i++) {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edges.push_back({src, dst, cost});
    }
    
    for(int i = 0; i <= V; i++) {
        set[i] = i;
    }
    
    sort(edges.begin(), edges.end(), cmp);
    
    int edge_cost = 0;
    
    for(int i = 0; i < (int)edges.size(); i++) {
        if(!is_same_parent(edges[i].src, edges[i].dst)) {
            edge_cost += edges[i].cost;
            union_parent(edges[i].src, edges[i].dst);
        }
    }
    
    cout << edge_cost << '\n';
}
