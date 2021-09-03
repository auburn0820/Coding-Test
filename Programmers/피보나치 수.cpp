#include <string>
#include <vector>
#include <cstring>

using namespace std;

int fibonacci(int num) {
    int DP[num + 1];
    memset(DP, 0, sizeof(DP));
    
    DP[0] = 0;
    DP[1] = 1;
    
    for(int i = 2; i <= num; i++) {
        DP[i] = ((DP[i - 1] % 1234567) + (DP[i - 2] % 1234567)) % 1234567;
    }
    
    return DP[num];
}

int solution(int n) {
    int answer = 0;
    
    answer = fibonacci(n);
    
    return answer;
}
