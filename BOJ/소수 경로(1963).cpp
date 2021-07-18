#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

bool prime_array[10000] = {false, };
bool visit[10000] = {false, };

struct Number {
    string number;
    int cnt;
};

void set_eratos() {
    for(int i = 2; i <= 9999; i++) {
        prime_array[i] = true;
    }
    
    for(int i = 2; i * i <= 9999; i++) {
        if(prime_array[i]) {
            for(int j = i * i; j <= 9999; j += i) {
                prime_array[j] = false;
            }
        }
    }
}

int find_min_path(string &src, string &dst) {
    memset(visit, false, sizeof(visit));
    queue<Number> q;
    
    q.push({src, 0});
    visit[stoi(src)] = true;
    
    while(!q.empty()) {
        string cur_password = q.front().number;
        int cur_cnt = q.front().cnt;
        
        q.pop();
        
        if(cur_password == dst) {
            return cur_cnt;
        }
        
        for(int i = 3; i >= 0; i--) {
            for(int j = 0; j <= 9; j++) {
                string next_password = cur_password;
                next_password[i] = j + '0';
                
                if(stoi(next_password) > 9999 || stoi(next_password) < 1000)
                    continue;
                if(!prime_array[stoi(next_password)])
                    continue;
                if(visit[stoi(next_password)])
                    continue;
                
                q.push({next_password, cur_cnt + 1});
                visit[stoi(next_password)] = true;
            }
        }
    }
    
    return -1;
}

int main(void) {
    int t;
    cin >> t;
    
    set_eratos();
    
    while(t--) {
        string src, dst;
        cin >> src >> dst;
        
        int result = find_min_path(src, dst);
        
        if(result == -1)
            cout << "Impossible\n";
        else
            cout << result << '\n';
    }
}
