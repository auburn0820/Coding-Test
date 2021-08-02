#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M, H;
int result;
vector<int> v[51];
int DP[51][1001] = {0, };

void string_to_int(string &s, int idx) {
    for(int i = 0; i < (int)s.length(); i++) {
        if(s[i] != ' ') {
            string temp;
            while(s[i] != ' ' && i < (int)s.length()) {
                temp += s[i++];
            }
            
            v[idx].push_back(stoi(temp));
        }
    }
}

int main(void) {
    cin >> N >> M >> H;
    
    cin.ignore();
    
    for(int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        string_to_int(s, i + 1);
    }
    
    for(int i = 0; i < N; i++)
        DP[i][0] = 1;
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= H; j++) {
            for(int k = 0; k < (int)v[i].size(); k++) {
                if(j - v[i][k] >= 0) {
                    DP[i][j] += DP[i - 1][j - v[i][k]];
                    DP[i][j] %= 10007;
                }
            }
            
            DP[i][j] += DP[i - 1][j];
            DP[i][j] %= 10007;
        }
    }
    
    cout << DP[N][H] << '\n';
}
