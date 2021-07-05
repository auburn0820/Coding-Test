//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cmath>
//
//using namespace std;
//
//int N;
//
//bool isPrime(int n) {
//    if(n <= 1)
//        return false;
//    for(int i = 2; i <= sqrt(n); i++) {
//        if((n % i) == 0)
//            return false;
//    }
//    
//    return true;
//}
//
//bool isPalindrome(string n) {
//    string temp = n;
//    reverse(begin(temp), end(temp));
//    if(n.compare(temp) == 0)
//        return true;
//    else
//        return false;
//}
//
//int main(void) {
//    cin >> N;
//    
//    for(int i = N; ; i++) {
//        if(isPrime(i) && isPalindrome(to_string(i))) {
//            cout << i << '\n';
//            break;
//        }
//    }
//}
