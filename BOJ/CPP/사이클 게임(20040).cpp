#include <iostream>

using namespace std;

int parent[500000];

int find_parent(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        return parent[x] = find_parent(parent[x]);
    }
}

bool is_same_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    
    if(x == y) {
        return true;
    }
    else {
        return false;
    }
}

void make_union(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    
    if(x < y) {
        parent[x] = y;
    }
    else {
        parent[y] = x;
    }
}

int main(void) {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    int answer = 0;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        
        if(is_same_parent(a, b)) {
            if(answer == 0) {
                answer = i;
            }
        }
        else {
            make_union(a, b);
        }
    }
    
    cout << answer << '\n';
}
