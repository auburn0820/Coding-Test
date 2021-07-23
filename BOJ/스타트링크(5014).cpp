#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
bool visit[1000001] = {false, };

int BFS() {
    
    queue<pair<int, int>> q;
    
    q.push({S, 0});
    visit[S] = true;
    
    while(!q.empty()) {
        int curFloor = q.front().first;
        int curCnt = q.front().second;
        q.pop();
        
        if(curFloor == G) {
            return curCnt;
        }
        else {
            if(curFloor + U <= F && !visit[curFloor + U]) {
                q.push({curFloor + U, curCnt + 1});
                visit[curFloor + U] = true;
            }
            
            if(curFloor - D >= 1 && !visit[curFloor - D]) {
                q.push({curFloor - D, curCnt + 1});
                visit[curFloor - D] = true;
            }
        }
    }
    
    return -1;
}

int main(void) {
    
    cin >> F >> S >> G >> U >> D;
    
    int ans = BFS();
    
    if(ans == -1) {
        cout << "use the stairs\n";
    }
    else
        cout << ans << '\n';
}
