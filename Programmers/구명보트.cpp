#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), [](const int &a, const int &b) {
        return a < b;
    });
    
    int left = 0;
    int right = (int)people.size() - 1;
    
    while(left < right) {
        int weight = people[left] + people[right];
        
        if(weight > limit) {
            right--;
        }
        else {
            left++;
            right--;
        }
        
        answer++;
    }
    
    if(left == right)
        answer++;
    
    return answer;
}
