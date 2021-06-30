//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//string s;
//string bomb;
//stack<char> st;
//
//int main(void) {
//    cin >> s >> bomb;
//    char result[1000001];
//
//    int idx = 0;
//    for(int i = 0; i < (int)s.length(); i++) {
//        result[idx++] = s[i];
//
//        if(result[idx - 1] == bomb[bomb.length() - 1]) {
//            if(idx < (int)bomb.length())
//                continue;
//
//            bool flag = true;
//            for(int j = 0; j < (int)bomb.length(); j++) {
//                if(result[idx - 1 - j] != bomb[bomb.length() - 1 - j]) {
//                    flag = false;
//                    break;
//                }
//            }
//            if(flag)
//                idx -= (int)bomb.length();
//        }
//    }
//
//    if(idx == 0)
//        cout << "FRULA";
//    else
//        for(int i = 0; i < idx; i++) {
//            cout << result[i];
//        }
//    cout << '\n';
//}
