#include <iostream>
#include <map>

using namespace std;

int parent[200001];
int friend_count[200001];
map<string, int> table;

int find_parent(int x) {
    if(parent[x] == x) {
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
    if(is_same_parent(x, y)) {
        return;
    }
    
    x = find_parent(x);
    y = find_parent(y);
    
    if(x < y) {
        parent[y] = x;
        friend_count[x] += friend_count[y];
    }
    else {
        parent[x] = y;
        friend_count[y] += friend_count[x];
    }
}

int main(void) {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        int f;
        cin >> f;
        
        table.clear();
        
        int size = 2 * f;
        for(int i = 0; i < size; i++) {
            parent[i] = i;
            friend_count[i] = 1;
        }
        
        int mapping_idx = 0;
        for(int i = 0; i < f; i++) {
            string a, b;
            cin >> a >> b;
            
            auto it1 = table.find(a);
            auto it2 = table.find(b);
            
            if(it1 == table.end()) {
                table.insert(make_pair(a, mapping_idx++));
                it1 = table.find(a);
            }
            
            if(it2 == table.end()) {
                table.insert(make_pair(b, mapping_idx++));
                it2 = table.find(b);
            }
            
            make_union(it1->second, it2->second);
            
            cout << friend_count[find_parent(it1->second)] << '\n';
        }
    }
}
