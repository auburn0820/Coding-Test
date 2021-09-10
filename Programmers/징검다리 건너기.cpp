#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(int n, int k, vector<int> &v) {
    int count = 0;
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i] - n <= 0)
            count++;
        else
            count = 0;
        if(count >= k)
            return true;
    }
    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int max_val = *max_element(stones.begin(), stones.end());
    
    int left = 1, right = max_val;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(binary_search(mid, k, stones))
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    answer = left;
    
    return answer;
}
