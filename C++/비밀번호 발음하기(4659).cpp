//#include <iostream>
//
//using namespace std;
//
//bool isMoeum(char ch) {
//    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
//        return true;
//    return false;
//}
//
//bool checkPassword(string &s) {
//    bool moeum = false;
//    int moeumCnt = 0;
//    int zaeumCnt = 0;
//    
//    for(int i = 0; i < (int)s.length(); i++) {
//        if(isMoeum(s[i])) {
//            moeum = true;
//            if(++moeumCnt == 3)
//                return false;
//            zaeumCnt = 0;
//        } else {
//            if(++zaeumCnt == 3)
//                return false;
//            moeumCnt = 0;
//        }
//        
//        if(s[i] == s[i + 1]) {
//            if(s[i] != 'e' && s[i + 1] != 'o')
//                return false;
//        }
//    }
//    
//    if(!moeum)
//        return false;
//    
//    return true;
//}
//
//int main(void) {
//    while(true) {
//        string str;
//        cin >> str;
//        
//        if(str == "end")
//            break;
//        
//        if(checkPassword(str))
//            cout << '<' << str << "> is acceptable.\n";
//        else
//            cout << '<' << str << "> is not acceptable.\n";
//    }
//}
