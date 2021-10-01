#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> win_nums_set;

int count_same_number(vector<int> &lottos, vector<int> &win_nums) {
    int count = 0;
    for(int i = 0; i < lottos.size(); i++) {
        if(win_nums_set.find(lottos[i]) != win_nums_set.end())
            count++;
    }
    
    return count;
}

int count_removed_number(vector<int> &lottos) {
    int count = 0;
    for(int i = 0; i < lottos.size(); i++) {
        if(lottos[i] == 0)
            count++;
    }
    
    return count;
}

int get_grade(int same_count) {
    switch(same_count) {
        case 6:
            return 1;
            break;
        case 5:
            return 2;
            break;
        case 4:
            return 3;
            break;
        case 3:
            return 4;
            break;
        case 2:
            return 5;
            break;
        default:
            return 6;
            break;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    for(auto& i : win_nums)
        win_nums_set.insert(i);
    
    int removed_count = count_removed_number(lottos);
    int same_count = count_same_number(lottos, win_nums);
    
    answer.push_back(get_grade(removed_count + same_count));
    answer.push_back(get_grade(same_count));
    
    return answer;
}
