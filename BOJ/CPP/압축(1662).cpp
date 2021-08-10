//#include <iostream>
//
//using namespace std;
//
//bool visit[50];
//
//int decompression(string &s, int idx) {
//    
//    int cnt = 0;
//    
//    for(int i = idx; i < (int)s.length(); i++) {
//        if(!visit[i]) {
//            if(s[i] == '(') {
//                visit[i] = true;
//                cnt += (s[i - 1] - '0') * decompression(s, i) - 1;
//            } else if(s[i] == ')') {
//                visit[i] = true;
//                return cnt;
//            } else {
//                cnt++;
//                visit[i] = true;
//            }
//        }
//    }
//   
//    return cnt;
//}
//
//int main(void) {
//    string s;
//    cin >> s;
//    
//    cout << decompression(s, 0) << '\n';
//}
