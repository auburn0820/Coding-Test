#include <iostream>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

int N, K;
string dir;
set<tuple<int, int, int>> ad_dir; // minus
set<tuple<int, int, int>> bc_dir; // plus
int cur_x, cur_y;
int x_pos, y_pos;

void find_final_position() {
    for(auto &i : dir) {
        cur_x = x_pos;
        cur_y = y_pos;
        if(i == 'A') {
            auto it = ad_dir.find(make_tuple(cur_x - cur_y, cur_x, cur_y));
            
            if(it == prev(ad_dir.end()))
                continue;
            
            int val, next_x, next_y;
            tie(val, next_x, next_y) = *next(it);
            
            if(val != (cur_x - cur_y))
                continue;
            
            ad_dir.erase(it);
            bc_dir.erase(make_tuple(cur_x + cur_y, cur_x, cur_y));
            x_pos = next_x;
            y_pos = next_y;
        }
        else if(i == 'B') {
            auto it = bc_dir.find(make_tuple(cur_x + cur_y, cur_x, cur_y));
            
            if(it == prev(bc_dir.end()))
                continue;
            
            int val, next_x, next_y;
            tie(val, next_x, next_y) = *next(it);
            
            if(val != (cur_x + cur_y))
                continue;
            
            bc_dir.erase(it);
            ad_dir.erase(make_tuple(cur_x - cur_y, cur_x, cur_y));
            x_pos = next_x;
            y_pos = next_y;
        }
        else if(i == 'C') {
            auto it = bc_dir.find(make_tuple(cur_x + cur_y, cur_x, cur_y));
            
            if(it == bc_dir.begin())
                continue;
            
            int val, next_x, next_y;
            tie(val, next_x, next_y) = *prev(it);
            
            if(val != (cur_x + cur_y))
                continue;
            
            bc_dir.erase(it);
            ad_dir.erase(make_tuple(cur_x - cur_y, cur_x, cur_y));
            x_pos = next_x;
            y_pos = next_y;
        }
        else if(i == 'D') {
            auto it = ad_dir.find(make_tuple(cur_x - cur_y, cur_x, cur_y));
            
            if(it == ad_dir.begin())
                continue;
            
            int val, next_x, next_y;
            tie(val, next_x, next_y) = *prev(it);
            
            if(val != (cur_x - cur_y))
                continue;
            
            ad_dir.erase(it);
            bc_dir.erase(make_tuple(cur_x + cur_y, cur_x, cur_y));
            x_pos = next_x;
            y_pos = next_y;
        }
    }
    
    cout << x_pos << ' ' << y_pos << '\n';
}

int main(void) {
    cin >> N >> K;
    cin >> dir;
    
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        
        if(i == 0) {
            x_pos = x;
            y_pos = y;
        }
        
        ad_dir.insert(make_tuple(x - y, x, y));
        bc_dir.insert(make_tuple(x + y, x, y));
    }
    
    find_final_position();
}
