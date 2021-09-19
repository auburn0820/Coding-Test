#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    while(n--) {
        int p;
        cin >> p;
        
        int price = 0;
        string name = "";
        
        while(p--) {
            int temp_price;
            string temp_name;
            
            cin >> temp_price >> temp_name;
            
            if(temp_price > price) {
                name = temp_name;
                price = temp_price;
            }
        }
        
        cout << name << '\n';
    }
}
