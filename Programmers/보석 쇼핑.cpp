#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> s(gems.begin(), gems.end());
    map<string, int> m;
    
    int left, right;
    left = right = 0;
    
    for(auto &gem : gems) {
        m[gem]++;
        if(m.size() == s.size())
            break;
        right++;
    }
    
    int min_range = right - left;
    answer[0] = left + 1;
    answer[1] = right + 1;
    
    while(right < gems.size()) {
        string key = gems[left];
        m[key]--;
        left++;
        
        if(m[key] == 0) {
            right++;
            for(; right < gems.size(); right++) {
                m[gems[right]]++;
                if(gems[right] == key)
                    break;
            }
            
            if(right == gems.size())
                break;
        }
        
        if(min_range > right - left) {
            min_range = right - left;
            answer[0] = left + 1;
            answer[1] = right + 1;
        }
    }
    
    return answer;
}
