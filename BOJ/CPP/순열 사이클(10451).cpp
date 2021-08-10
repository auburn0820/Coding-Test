#include <iostream>
#include <cstring>

using namespace std;

int nodes[1001];
bool visit[1001];
bool is_cycled[1001];
int N;
int cycle_count;

void make_cycle(int cur_node) {
    visit[cur_node] = true;
    
    int next_node = nodes[cur_node];
    
    if(!visit[next_node])
        make_cycle(next_node);
    else if(visit[next_node] && !is_cycled[next_node]) {
        cycle_count++;
    }
    
    is_cycled[cur_node] = true;
}

int main(void) {
    int t;
    cin >> t;
    
    while(t--) {
        memset(nodes, 0, sizeof(nodes));
        memset(is_cycled, false, sizeof(is_cycled));
        memset(visit, false, sizeof(visit));
        cycle_count = 0;
        
        cin >> N;
        
        for(int i = 1; i <= N; i++) {
            cin >> nodes[i];
        }
        
        for(int i = 1; i <= N; i++) {
            if(!visit[i])
                make_cycle(i);
        }
        
        cout << cycle_count << '\n';
    }
}
