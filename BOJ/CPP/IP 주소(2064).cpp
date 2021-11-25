#include <iostream>

using namespace std;

string convert_binary_to_decimal_address(const int address) {
    int shift = 24;
    string decimal_address = "";
    for(int i = 0; i < 4; i++, shift -= 8) {
        decimal_address += to_string((address >> shift) & ((1 << 8) - 1)) + ".";
    }
    
    decimal_address.pop_back();
    
    return decimal_address;
}

int main(void) {
    int n;
    int addresses[1000] = {0, };
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            int address_block;
            cin >> address_block;
            getchar();
            
            addresses[i] <<= 8;
            addresses[i] |= address_block;
        }
    }
    
    int subnet_address = 0;
    for(int i = 31; i >= 0; i--) {
        int bit_for_check = 1 << i;
        bool is_different = false;
        
        for(int j = 1; j < n; j++) {
            if((addresses[0] & bit_for_check) != (addresses[j] & bit_for_check)) {
                is_different = true;
                break;
            }
        }
        
        if(is_different) {
            break;
        }
        else {
            subnet_address |= bit_for_check;
        }
    }
    
    cout << convert_binary_to_decimal_address(addresses[0] & subnet_address) << '\n';
    cout << convert_binary_to_decimal_address(subnet_address) << '\n';
}
