#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_rule_followed(vector<string> place) {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    bool is_visit[5][5];
    memset(is_visit, false, sizeof(is_visit));
    
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(place[i][j] == 'P') {
                int cur_x = j;
                int cur_y = i;
                
                for(int k = 0; k < 4; k++) {
                    int next_x = cur_x + dx[k];
                    int next_y = cur_y + dy[k];
                    
                    if(next_x >= 5 || next_y >= 5 || next_x < 0 || next_y < 0)
                        continue;
                    if(place[next_y][next_x] == 'O') {
                        if(is_visit[next_y][next_x])
                            return false;
                        
                        is_visit[next_y][next_x] = true;
                        continue;
                    }
                    else if(place[next_y][next_x] == 'X')
                        continue;
                    else if(place[next_y][next_x] == 'P')
                        return false;
                }
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto &place : places) {
        if(is_rule_followed(place))
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}
