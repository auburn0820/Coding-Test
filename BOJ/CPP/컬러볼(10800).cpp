#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Ball {
    int idx, color, size;
};

int N;
vector<Ball> balls;
int same_color_ball_size_count[200001] = {0, };
vector<int> ans;

bool cmp(Ball &a, Ball &b) {
    return a.size < b.size;
}

int main(void) {
    cin.sync_with_stdio(false);
    cin >> N;
    
    balls.resize(N);
    ans.resize(N);
    
    for(int i = 0; i < N; i++) {
        int color, size;
        cin >> color >> size;
        balls[i] = {i, color, size};
    }
    
    sort(balls.begin(), balls.end(), cmp);
    
    int sizes = 0;
    for(int i = 0, j = 0; i < N; i++) {
        while(balls[i].size > balls[j].size) {
            sizes += balls[j].size;
            same_color_ball_size_count[balls[j].color] += balls[j].size;
            j++;
        }
        
        int same_color_size_count = same_color_ball_size_count[balls[i].color];
        ans[balls[i].idx] = sizes - same_color_size_count;
    }
    
    for(int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
}
