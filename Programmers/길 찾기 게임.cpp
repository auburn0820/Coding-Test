#include <string>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

map<string, int> node;
vector<vector<int>> levels;
queue<int> for_postorder;
queue<int> for_preorder;

void traversal(bool is_preorder, int min, int max, int cur_x, int cur_y) {
    if(cur_x < min || cur_x > max)
        return;
    
    if(is_preorder)
        for_preorder.push(node[to_string(cur_x) + to_string(cur_y)]);
    
    int temp_y = cur_y;
    
    if(temp_y > 0) {
        temp_y--;
    
        while(temp_y > 0 && levels[temp_y].empty())
            temp_y--;

        for(int i = 0; i < levels[temp_y].size(); i++) {
            if(levels[temp_y][i] < cur_x) {
                traversal(is_preorder, min, cur_x, levels[temp_y][i], temp_y);
            }
            else if(levels[temp_y][i] > cur_x) {
                traversal(is_preorder, cur_x, max, levels[temp_y][i], temp_y);
            }
        }
    }
    
    
    if(!is_preorder)
        for_postorder.push(node[to_string(cur_x) + to_string(cur_y)]);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    
    for(int i = 0; i < nodeinfo.size(); i++) {
        string key = to_string(nodeinfo[i][0]) + to_string(nodeinfo[i][1]);
        node[key] = i + 1;
    }
    
    sort(nodeinfo.begin(), nodeinfo.end(), [](const vector<int> &lhs, const vector<int> &rhs) -> bool {
        if(lhs[1] == rhs[1])
            return lhs[0] < rhs[0];
        return lhs[1] > rhs[1];
    });
    
    int root_x = nodeinfo[0][0];
    int root_y = nodeinfo[0][1];
    int root_num = node[to_string(root_x) + to_string(root_y)];
    
    levels.resize(root_y + 1);
    
    for(int i = 0; i < nodeinfo.size(); i++) {
        levels[nodeinfo[i][1]].push_back(nodeinfo[i][0]);
    }
    
    traversal(true, INT_MIN, INT_MAX, root_x, root_y);
    traversal(false, INT_MIN, INT_MAX, root_x, root_y);
    
    while(!for_preorder.empty()) {
        answer[0].push_back(for_preorder.front());
        for_preorder.pop();
    }
    
    while(!for_postorder.empty()) {
        answer[1].push_back(for_postorder.front());
        for_postorder.pop();
    }
    
    return answer;
}
