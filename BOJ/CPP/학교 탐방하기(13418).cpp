#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Edge {
    int src, dst, cost;
};

int N, M;
int set[1001];
vector<Edge> edges;

bool cmp_best(Edge &a, Edge &b) {
    return a.cost < b.cost;
}

bool cmp_worst(Edge &a, Edge &b) {
    return a.cost > b.cost;
}

int get_parent(int node) {
    if(node == set[node])
        return node;
    else
        return set[node] = get_parent(set[node]);
}

void union_parent(int node1, int node2) {
    node1 = get_parent(node1);
    node2 = get_parent(node2);
    
    if(node1 < node2)
        set[node2] = node1;
    else
        set[node1] = node2;
}

bool is_same_parent(int node1, int node2) {
    if(get_parent(node1) == get_parent(node2))
        return true;
    else
        return false;
}

long long get_cost(bool (*cmp)(Edge& a, Edge& b)) {
    sort(edges.begin(), edges.end(), cmp);
    
    for(int i = 0; i <= N; i++) {
        set[i] = i;
    }
    
    long long number_of_uphill_road = 0;
    
    for(int i = 0; i < (int)edges.size(); i++) {
        if(!is_same_parent(edges[i].src, edges[i].dst)) {
            union_parent(edges[i].src, edges[i].dst);

            number_of_uphill_road += edges[i].cost;
        }
    }
    
    return pow(number_of_uphill_road, 2);
}

int main(void) {
    cin >> N >> M;
    
    int src, dst, cost;
    for(int i = 0; i <= M; i++) {
        cin >> src >> dst >> cost;
        edges.push_back({src, dst, !cost});
    }
    
    long long best = get_cost(cmp_best);
    long long worst = get_cost(cmp_worst);
    
    cout << abs(worst - best) << '\n';
}
