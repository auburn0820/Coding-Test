//#include <iostream>
//
//using namespace std;
//
//int getMinResult(string &str) {
//    int result = 0;
//    string temp = "";
//    bool bIsMinus = false;
//    
//    for(int i = 0; i <= (int)str.length(); i++) {
//        if(str[i] == '+' || str[i] == '-' || str[i] == '\0') {
//            if(bIsMinus) {
//                result -= stoi(temp);
//            } else {
//                result += stoi(temp);
//            }
//            
//            if(str[i] == '-')
//                bIsMinus = true;
//            temp = "";
//        } else {
//            temp += str[i];
//        }
//    }
//    
//    return result;
//}
//
//int main(void) {
//    string str;
//    cin >> str;
//    
//    cout << getMinResult(str) << '\n';
//}
