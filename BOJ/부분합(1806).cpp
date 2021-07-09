#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(void) {
    int N, S;
    cin >> N >> S;
    
    int numbers[N];
    
    for(auto &number : numbers) {
        cin >> number;
    }
    
    int left, right;
    left = right = 0;
    
    long long sum = numbers[0];
    int number_count = 1;
    int result = INT_MAX;
    
    while(left < N) {
        // 합친 값이 S보다 큰 경우
        if(sum >= S) {
            result = min(result, number_count);
            // left와 right가 같은 경우 같이 증가시킨다.
            if(left == right) {
                left++;
                right++;
                sum = numbers[left];
                number_count = 1;
            } else {
                sum -= numbers[left];
                left++;
                number_count--;
            }
        } else {
            if(right < N - 1) {
                right++;
                sum += numbers[right];
                number_count++;
            } else // sum이 S보다 작고, right 포인터를 더이상 증가시킬 수 없을 때에는 sum이 S보다 커질 수 있는 경우는 절대 없다(더이상 더할 수 없으므로). 그러니 반복문을 종료한다.
                break;
        }
    }
    
    if(result == INT_MAX)
        cout << 0 << '\n';
    else
        cout << result << '\n';
}
