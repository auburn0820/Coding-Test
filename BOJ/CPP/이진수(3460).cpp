#include <iostream>
#include <algorithm>

using namespace std;

void convert_to_binary(int num) {
    string binary = "";
    while(num > 0) {
        binary += to_string(num % 2);
        num /= 2;
    }
    
    for(size_t i = 0; i < binary.length(); i++) {
        if(binary[i] == '1') {
            cout << i << ' ';
        }
    }
    cout << '\n';
}

int main(void) {
    int T;
    cin >> T;
    
    while(T--) {
        int num;
        cin >> num;
        convert_to_binary(num);
    }
}
