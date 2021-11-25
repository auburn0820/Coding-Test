#include <iostream>

using namespace std;;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int M;
    cin >> M;

    int bit = 0;

    while(M--) {
        string cmd;
        int num;

        cin >> cmd;

        if(cmd == "add") {
            cin >> num;

            bit = bit | (1 << num);
        }
        else if(cmd == "remove") {
            cin >> num;

            bit = bit & ~(1 << num);
        }
        else if(cmd == "check") {
            cin >> num;
            
            if(bit & (1 << num))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(cmd == "toggle") {
            cin >> num;

            bit = bit ^ (1 << num);
        }
        else if(cmd == "all") {
            bit = (1 << 21) - 1;
        }
        else if(cmd == "empty") {
            bit = 0;
        }
    }
}
