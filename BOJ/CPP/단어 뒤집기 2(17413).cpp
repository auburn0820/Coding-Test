//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//    string str;
//    getline(cin, str);
//
//    for(int i = 0; i < (int)str.length(); i++) {
//        if(str[i] == '<') {
//            int idx = i;
//            while(str[idx] != '>')
//                idx++;
//            i = idx;
//        }
//        else if(str[i] != ' ') {
//            int idx = i;
//            while(str[idx] != ' ' && str[idx] != '<' && str[idx] != '\0') {
//                idx++;
//            }
//            string temp = str.substr(i, idx - i);
////            cout << temp << '\n';
//            reverse(temp.begin(), temp.end());
//            str.replace(str.begin() + i, str.begin() + i + (int)temp.length(), temp);
//            i = --idx;
//        }
//    }
//
//    cout << str << '\n';
//}
