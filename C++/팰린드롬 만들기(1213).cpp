//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int alphabet[26];
//bool holsu;
//
//bool checkPalindrome() {
//    for(int i = 0; i < 26; i++) {
//        if(alphabet[i] == 0)
//            continue;
//        if(alphabet[i] % 2 == 1) {
//            if(holsu)
//                return false;
//            else
//                holsu = true;
//        }
//    }
//    
//    return true;
//}
//
//string makeString() {
//    string result = "";
//    
//    if(holsu) {
//        char holsuChar = NULL;
//        for(int i = 0; i < 26; i++) {
//            if(alphabet[i] != 0) {
//                if(alphabet[i] % 2 == 1)
//                    holsuChar = i + 'A';
//                for(int j = 0; j < alphabet[i] / 2; j++) {
//                    result += i + 'A';
//                }
//            }
//        }
//        string re = result;
//        reverse(re.begin(), re.end());
//        result += holsuChar;
//        result += re;
//    } else {
//        for(int i = 0; i < 26; i++) {
//            if(alphabet[i] != 0) {
//                for(int j = 0; j < alphabet[i] / 2; j++) {
//                    result += i + 'A';
//                }
//            }
//        }
//        
//        string re = result;
//        reverse(re.begin(), re.end());
//        result += re;
//    }
//    
//    return result;
//}
//
//int main(void) {
//    string str;
//    cin >> str;
//    
//    for(int i = 0; i < (int)str.length(); i++) {
//        alphabet[str[i] - 'A']++;
//    }
//    
//    if(!checkPalindrome())
//        cout << "I'm Sorry Hansoo\n";
//    else {
//        cout << makeString() << '\n';
//    }
//}
