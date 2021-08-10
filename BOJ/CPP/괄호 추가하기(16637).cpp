//#include <iostream>
//#include <limits>
//
//using namespace std;
//
//int N;
//int maxNum = INT_MIN;
//string number;
//
//int cal(char op, int a, int b) {
//    int ret = a;
//    switch (op) {
//        case '+':
//            ret += b;
//            break;
//        case '-':
//            ret -= b;
//            break;
//        case '*':
//            ret *= b;
//            break;
//    }
//    
//    return ret;
//}
//
//void makeCases(int idx, int sum) {
//    if(idx > N - 1) {
//        maxNum = max(maxNum, sum);
//        return;
//    }
//    char op;
//    if(idx == 0)
//        op = '+';
//    else
//        op = number[idx - 1];
//    
//    if(idx + 2 < N) {
//        int cur = cal(number[idx + 1], number[idx] - '0', number[idx + 2] - '0');
//        makeCases(idx + 4, cal(op, sum, cur));
//    }
//    
//    makeCases(idx + 2, cal(op, sum, number[idx] - '0'));
//}
//
//int main(void) {
//    cin >> N;
//    cin >> number;
//    
//    makeCases(0, 0);
//    
//    cout << maxNum << '\n';
//}
