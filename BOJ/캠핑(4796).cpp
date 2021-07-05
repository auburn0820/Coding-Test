//#include <iostream>
//
//using namespace std;
//
//int main(void) {
//    int P, L, V;
//    int caseCount = 1;
//
//    while(true) {
//        cin >> L >> P >> V;
//
//        if(P == 0 && L == 0 && V == 0)
//            break;
//
//        int result = L * (V / P);
//
//        if((V % P) > L) {
//            result += L;
//        } else {
//            result += V % P;
//        }
//
//        cout << "Case " << caseCount++ << ": " << result << '\n';
//    }
//}
