//#include <iostream>
//
//using namespace std;
//
//int n, m;
//bool number[10];
//int ans;
//
//bool checkPassword(string &s) {
//    for(int i = 0; i < (int)s.length(); i++) {
//        if(!number[s[i] - '0'])
//            return false;
//    }
//    
//    return true;
//}
//
//void findPassword(int cnt, string &s) {
//    if(cnt == n) {
//        if(checkPassword(s)) {
//            cout << s << '\n';
//            ans++;
//        }
//        return;
//    }
//    
//    for(int i = 0; i <= 9; i++) {
//        string str = s + to_string(i);
//        findPassword(cnt + 1, str);
//    }
//}
//
//int main(void) {
//    cin >> n >> m;
//    
//    for(int i = 0; i < n; i++) {
//        int n;
//        cin >> n;
//        number[n] = true;
//    }
//    
//    string str = "";
//    findPassword(0, str);
//    
//    cout << ans << '\n';
//}
