#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> edges[101];
int relation_count[101];
bool is_visited[101];

void check_relation(int cur, int start) {
    relation_count[cur]--;
    relation_count[start]--;
    
    for(int i = 0; i < (int)edges[cur].size(); i++) {
        if(is_visited[edges[cur][i]])
            continue;
        is_visited[edges[cur][i]] = true;
        check_relation(edges[cur][i], start);
    }
}

int main(void) {
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int src, dst;
        cin >> src >> dst;
        edges[src].push_back(dst);
    }
    
    for(int i = 1; i <= N; i++)
        relation_count[i] = N + 1;
    
    for(int i = 1; i <= N; i++) {
        memset(is_visited, false, sizeof(is_visited));
        is_visited[i] = true;
        check_relation(i, i);
    }
    
    for(int i = 1; i <= N; i++)
        cout << relation_count[i] << '\n';
}
