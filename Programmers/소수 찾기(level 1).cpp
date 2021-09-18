#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool eratos[1000001] = {false, };

void set_eratos(int number) {
    
    for(int i = 2; i <= number; i++)
        eratos[i] = true;
    
    for(int i = 2; i * i <= number; i++) {
        if(eratos[i]) {
            for(int j = i * i; j <= number; j += i) {
                eratos[j] = false;
            }
        }
    }
}

int solution(int n) {
    int answer = 0;
    
    set_eratos(n);
    
    for(int i = 2; i <= n; i++) {
        if(eratos[i])
            answer++;
    }
    
    return answer;
}
