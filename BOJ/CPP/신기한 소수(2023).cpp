//#include <iostream>
//#include <string>
//#include <cmath>
//
//using namespace std;
//
//int n;
//char num[10];
//
//bool isPrime(int n) {
//    if(n <= 1)
//        return false;
//    for(int i = 2; i <= sqrt(n); i++) {
//        if((n % i) == 0)
//            return false;
//    }
//
//    return true;
//}
//
//
//void dfs(int cnt, string &s) {
//    if(!isPrime(stoi(s)))
//        return;
//
//    if(cnt == n) {
//        cout << s << '\n';
//        return;
//    }
//
//    for(int i = 0; i <= 9; i++) {
//        string str = to_string(i);
//        s += str;
//        dfs(cnt + 1, s);
//        s.erase(s.end() - 1);
//    }
//}
//
//int main(void) {
//    cin >> n;
//
//    for(int i = 0; i <= 9; i++) {
//        num[i] = i + '0';
//    }
//
//    for(int i = 0; i <= 9; i++) {
//        string s = to_string(i);
//        dfs(1, s);
//    }
//}
