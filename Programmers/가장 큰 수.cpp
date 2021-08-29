#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> string_numbers;
    
    for(int i = 0; i < numbers.size(); i++)
        string_numbers.push_back(to_string(numbers[i]));
    
    sort(string_numbers.begin(), string_numbers.end(), [](const string &a, const string &b){
        return a + b > b + a;
    });
    
    for(int i = 0; i < string_numbers.size(); i++)
        answer += string_numbers[i];
    
    if(answer[0] == '0')
        answer = "0";
    
    return answer;
}
