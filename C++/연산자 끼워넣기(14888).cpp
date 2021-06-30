//#include <iostream>
//#include <deque>
//#include <algorithm>
//
//using namespace std;
//
//int n;
//int op[4];
//int temp[4];
//deque<int> v;
//deque<string> numbers;
//long long maxNum = -1000000000;
//long long minNum = 1000000000;
//
//long long calExpression() {
//    deque<string> temp(numbers.size());
//    copy(numbers.begin(), numbers.end(), temp.begin());
//    int ret = stoi(temp.front());
//    temp.pop_front();
//    for(int i = 0; i < (int)v.size(); i++) {
//        if(v[i] == 0) {
//            ret += stoi(temp.front());
//            temp.pop_front();
//        } else if(v[i] == 1) {
//            ret -= stoi(temp.front());
//            temp.pop_front();
//        } else if(v[i] == 2) {
//            ret *= stoi(temp.front());
//            temp.pop_front();
//        } else if(v[i] == 3) {
//            ret /= stoi(temp.front());
//            temp.pop_front();
//        }
//    }
//    
//    return ret;
//}
//
//void permutation(int cur, int cnt) {
//    if(temp[cur] == 0) {
//        return;
//    }
//    
//    v.push_back(cur);
//    temp[cur]--;
//    
//    if(cnt == (n - 1)) {
//        long long num = calExpression();
//        maxNum = max(maxNum, num);
//        minNum = min(minNum, num);
//        v.pop_back();
//        temp[cur]++;
//        return;
//    }
//    
//    for(int i = 0; i < 4; i++) {
//        permutation(i, cnt + 1);
//    }
//    
//    v.pop_back();
//    temp[cur]++;
//}
//
//int main(void) {
//    cin >> n;
//    for(int i = 0; i < n; i++) {
//        string num;
//        cin >> num;
//        numbers.push_back(num);
//    }
//    
//    for(int i = 0; i < 4; i++) {
//        cin >> op[i];
//    }
//    
//    for(int i = 0; i < 4; i++) {
//        copy(op, op + 4, temp);
//        permutation(i, 1);
//    }
//    
//    cout << maxNum << '\n' << minNum << '\n';
//}
