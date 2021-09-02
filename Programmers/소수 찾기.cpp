#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

set<int> s;
bool *is_visit;

bool is_prime(int number) {
    if(number <= 1)
        return false;
    else {
        for(int i = 2; i <= sqrt(number); i++) {
            if(number % i == 0)
                return false;
        }
    }
    return true;
}

void get_number_cases(const string &numbers, string cur_num) {
    if(!cur_num.empty() && stoi(cur_num) >= 1 && cur_num.size() <= numbers.size()) {
        int number = stoi(cur_num);
        set<int>::iterator it = s.find(number);
        
        // 중복되는 수가 발생하면 return 하도록 구현했는데, 특정 경우의 수를 더 만들 수 없는 상황이 만들어짐.
        // if(it != s.end())
        //     return;
        
        if(it == s.end() && is_prime(number)) {
            s.insert(number);
        }
    }
    
    for(int i = 0; i < numbers.size(); i++) {
        if(is_visit[i])
            continue;
        
        is_visit[i] = true;
        cur_num.push_back(numbers[i]);
        get_number_cases(numbers, cur_num);
        cur_num.pop_back();
        is_visit[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    
    is_visit = new bool[(int)numbers.size()];
    memset(is_visit, false, sizeof(bool) * numbers.size());
    get_number_cases(numbers, "");
    
    delete[] is_visit;
    
    answer = (int)s.size();
    
    return answer;
}
