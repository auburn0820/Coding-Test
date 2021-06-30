//#include <iostream>
//
//using namespace std;
//
//int getDigit(int num) {
//    int digit = 0;
//    
//    while(num != 0) {
//        num /= 10;
//        digit++;
//    }
//    
//    return digit;
//}
//
//int getDigitNumber(int num, int index) {
//    int digit = 0;
//    
//    for(int i = 0; i < index; i++) {
//        digit = num % 10;
//        num /= 10;
//    }
//    
//    return digit;
//}
//
//int main(void) {
//    int N;
//    cin >> N;
//    
//    int digit = getDigit(N);
//    int range = 9 * digit;
//    int minValue = N - range;
//    
//    while(true) {
//        int minValueSum = minValue;
//        
//        for(int i = 1; i <= digit; i++) {
//            minValueSum += getDigitNumber(minValue, i);
//        }
//        
//        if(minValueSum == N) {
//            cout << minValue << '\n';
//            break;
//        } else if(minValue == N) {
//            cout << 0 << '\n';
//            break;
//        } else {
//            minValue++;
//        }
//    }
//}
