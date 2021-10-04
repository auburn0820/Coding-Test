#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    
    if(a < b)
        swap(a, b);
    
    int gcd = 1;
    int lsb = 1;
    for(int i = 1; i <= b; i++) {
        if(a % i == 0 && b % i == 0) {
            gcd = i;
            lsb = max(lsb, gcd);
        }
    }
    
    lsb *= (a / lsb) * (b / lsb);
    
    cout << gcd << '\n' << lsb << '\n';
}
