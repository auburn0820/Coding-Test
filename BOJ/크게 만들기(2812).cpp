#include <iostream>
#include <deque>

using namespace std;

int N, K;
string number;

int main(void) {
    cin >> N >> K;
    cin >> number;
    
    deque<int> dq;
    
    int removed_number_count = 0;
    
    dq.push_back(number[0] - '0');
    
    for(int i = 1; i < (int)number.length(); i++) {
        while(!dq.empty() && dq.back() < number[i] - '0' && removed_number_count < K) {
            dq.pop_back();
            removed_number_count++;
        }
        dq.push_back(number[i] - '0');
    }
    
    int print_count = 0;
    
    while(!dq.empty() && print_count < N - K) {
        cout << dq.front();
        dq.pop_front();
        print_count++;
    }
    cout << '\n';
}
