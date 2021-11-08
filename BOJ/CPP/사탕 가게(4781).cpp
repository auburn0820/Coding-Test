#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
    while(true) {
        int n; double m;
        cin >> n >> m;

        if(n == 0 && m == 0)
            break;

        int m_size = (int)(m * 100);

        int calories[n + 1];
        int money[n + 1];
        int DP[m_size + 1];

        memset(DP, 0, sizeof(DP));

        for(int i = 1; i <= n; i++) {
            int c; double p;
            cin >> c >> p;

            calories[i] = c;
            money[i] = p * 100 + 0.5;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = money[i]; j <= m_size; j++) {
                DP[j] = max(DP[j], DP[j - money[i]] + calories[i]);
            }
        }

        cout << DP[m_size] << '\n';
    }
}
