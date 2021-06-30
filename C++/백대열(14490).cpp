//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//vector<string> splitString(string &s, char sortation) {
//    vector<string> result;
//    int idx = 0;
//    
//    for(int i = 0; i < (int)s.length(); i++) {
//        if(s[i] == sortation) {
//            result.push_back(s.substr(idx, i - idx));
//            idx = i + 1;
//        } else if(i == (int)s.length() - 1) {
//            result.push_back(s.substr(idx, i - idx + 1));
//            break;
//        }
//    }
//    
//    return result;
//}
//
//int findGCD(int a, int b) {
//    int c;
//    
//    while(b != 0) {
//        c = a % b;
//        a = b;
//        b = c;
//    }
//    
//    return a;
//}
//
//int main(void) {
//    string str;
//    cin >> str;
//    
//    vector<string> v = splitString(str, ':');
//    
//    int a = stoi(v[0]);
//    int b = stoi(v[1]);
//    
//    int GCD = findGCD(a, b);
//    
//    cout << a / GCD << ':' << b / GCD << '\n';
//}
