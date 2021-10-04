#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    int arr[10];
    cin >> T;
    
    while(T--) {
        for(int i = 0; i < 10; i++) {
            cin >> arr[i];
        }
        
        sort(arr, arr + 10, [](const int &lhs, const int &rhs) -> bool {
            return lhs > rhs;
        });
        
        cout << arr[2] << '\n';
    }
}
