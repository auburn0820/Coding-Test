#include <iostream>
#include <stack>
#include <memory>

using namespace std;

int N;
stack<int> st;
unique_ptr<int[]> histogram;

int main(void) {
    cin >> N;
    
    histogram = make_unique<int[]>(N + 2);
    
    for(int i = 1; i <= N; i++) {
        int height;
        cin >> height;
        histogram[i] = height;
    }
    
    int ans = 0;
    
    st.push(0);
    for(int i = 1; i <= N + 1; i++) {
        while(!st.empty() && histogram[st.top()] > histogram[i]) {
            int for_check = st.top();
            st.pop();
            ans = max(ans, histogram[for_check] * (i - st.top() - 1));
        }
        st.push(i);
    }
    
    cout << ans << '\n';
    histogram.reset();
}
