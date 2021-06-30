//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int checkWord(string &s) {
//    // 1: C++, 2: Java, 3: Error
//    if(s[0] >= 'A' && s[0] <= 'Z')
//        return 3;
//    
//    // C++ 형식을 만족하는지 확인
//    if(s.find('_') != string::npos) {
//        for(int i = 0; i < (int)s.length(); i++) {
//            if(s[i] >= 'A' && s[i] <= 'Z')
//                return 3;
//        }
//        
//        if(s.find("__") != string::npos)
//            return 3;
//        if(s[s.length() - 1] == '_')
//            return 3;
//        if(s[0] == '_')
//            return 3;
//        
//        return 1;
//    }
//    // Java 형식을 만족하는지 확인
//    else {
//        return 2;
//    }
//}
//
//void convertVariableType(string &s, int type) {
//    if(type == 1) {
//        for(int i = 0; i < (int)s.length(); i++) {
//            if(s[i] == '_') {
//                s[i + 1] -= 32;
//                s.erase(s.begin() + i);
//            }
//        }
//        
//        cout << s << '\n';
//    }
//    else if(type == 2) {
//        for(int i = 0; i < (int)s.length(); i++) {
//            if(s[i] >= 'A' && s[i] <= 'Z') {
//                s[i] += 32;
//                s.insert(s.begin() + i, '_');
//            }
//        }
//        cout << s << '\n';
//    }
//    else {
//        cout << "Error!\n";
//    }
//}
//
//int main(void) {
//    string str;
//    cin >> str;
//    
//    convertVariableType(str, checkWord(str));
//}
