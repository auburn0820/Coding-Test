#include <string>
#include <vector>

using namespace std;

int cal_numbers(vector<int> &numbers) {
    int sum = 0;
    for(int i = 0; i < numbers.size(); i++)
        sum += numbers[i];
    
    return sum;
}

void get_cases(int idx, int &answer, int &target, vector<int> &cases, vector<int> &numbers) {
    if(cases.size() == numbers.size()) {
        if(cal_numbers(cases) == target)
            answer++;
        
        return;
    }
    
    for(int i = 0; i < 2; i++) {
        if(i == 0) {
            cases.push_back(-numbers[idx]);
            idx++;
            get_cases(idx, answer, target, cases, numbers);
        }
        else if(i == 1) {
            cases.push_back(numbers[idx]);
            idx++;
            get_cases(idx, answer, target, cases, numbers);
        }
        cases.pop_back();
        idx--;
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int> cases;
    
    get_cases(0, answer, target, cases, numbers);
    
    return answer;
}
