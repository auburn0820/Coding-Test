#include <string>
#include <vector>

using namespace std;

string get_number(int number) {
    string s = "";
    while(number > 0) {
        int remain = number % 3;
        number = number / 3;
        if(remain == 0) {
            s = "4" + s;
            number--;
        }
        else if(remain == 1) {
            s = "1" + s;
        }
        else if(remain == 2) {
            s = "2" + s;
        }
    }
    
    return s;
}

string solution(int n) {
    string answer = "";
    
    answer = get_number(n);
    
    return answer;
}
