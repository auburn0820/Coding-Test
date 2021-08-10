//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//int alphabet[26] = {0, };
//
//void checkAlphabet(string str) {
//    for(int i = 0; i < str.length(); i++) {
//        if(str[i] >= 'A' && str[i] <= 'Z') {
//            alphabet[str[i] - 'A']++;
//        }
//        else if(str[i] >= 'a' && str[i] <= 'z') {
//            alphabet[str[i] - 'a']++;
//        }
//    }
//}
//
//string checkString() {
//    int zero, one, two, three;
//    
//    zero = one = two = three = 0;
//    
//    for(int i = 0; i < 26; i++) {
//        if(alphabet[i] >= 3)
//            three++;
//        
//        if(alphabet[i] >= 2)
//            two++;
//        
//        if(alphabet[i] >= 1)
//            one++;
//        
//        if(alphabet[i] < 1)
//            zero++;
//    }
//    
//    if(zero != 0)
//        return "Not a pangram";
//    else if(three == 26)
//        return "Triple pangram!!!";
//    else if(two == 26)
//        return "Double pangram!!";
//    else if(one == 26)
//        return "Pangram!";
//    else
//        return "Not a pangram";
//}
//
//int main(void) {
//    int N;
//    cin >> N;
//    cin.ignore();
//    
//    for(int i = 1; i <= N; i++) {
//        memset(alphabet, 0, sizeof(alphabet));
//        string str;
//        getline(cin, str, '\n');
//        
//        checkAlphabet(str);
//        
//        cout << "Case " << i << ": " << checkString() << '\n';
//    }
//}
