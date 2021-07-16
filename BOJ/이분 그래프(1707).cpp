#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vertexs;
vector<int> colors;
bool isBipartiteGraph;

void DFS(int start_vertex, int color) {
    colors[start_vertex] = color;
    
    for(int i = 0; i < vertexs[start_vertex].size(); i++) {
        if(colors[vertexs[start_vertex][i]] == color) {
            isBipartiteGraph = false;
            return;
        }
        
        if(colors[vertexs[start_vertex][i]] == 0) {
            DFS(vertexs[start_vertex][i], -color);
        }
    }
}

int main(void) {
    int t;
    cin >> t;
    
    while(t--) {
        isBipartiteGraph = true;
        vertexs.clear();
        colors.clear();
        
        int v, e;
        cin >> v >> e;
        
        vertexs.resize(v + 1);
        colors.resize(v + 1);
        
        for(int i = 1; i <= v; i++) {
            colors[i] = 0;
        }
        
        for(int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            vertexs[a].push_back(b);
            vertexs[b].push_back(a);
        }
        
        for(int i = 1; i <= v; i++) {
            if(!isBipartiteGraph)
                break;
            
            if(colors[i] == 0) {
                DFS(i, 1);
            }
        }
        
        if(isBipartiteGraph)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
