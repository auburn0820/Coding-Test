//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int getMinStrLen(string &s) {
//    int answer = (int)s.length();
//    string ans = "";
//    
//    for(int i = 1; i <= ((int)s.length() / 2); i++) {
//        int pos = 0;
//        int cnt = 0;
//        
//        while(1) {
//            string unit = s.substr(pos, i);
//            pos += i;
//            
//            if(pos >= (int)s.length())
//                break;
//            
//            while(1) {
//                if(unit == s.substr(pos, i)) {
//                    cnt++;
//                } else
//                    break;
//            }
//            
//            ans += to_string(cnt + 1);
//        }
//    }
//    
//    return answer;
//}
//
//int main(void) {
//    string s;
//    cin >> s;
//    
//    cout << getMinStrLen(s) << '\n';
//}
