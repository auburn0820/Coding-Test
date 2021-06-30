//#include <iostream>
//
//using namespace std;
//
//int N, K;
//int electronicUsingOrder[100];
//int multiOutletStates[100];
//
//bool isExist(int val) {
//    for(int i = 0; i < N; i++) {
//        if(multiOutletStates[i] == val)
//            return true;
//    }
//
//    return false;
//}
//
//bool isEmpty(int idx) {
//    for(int i = 0; i < N; i++) {
//        if(multiOutletStates[i] == 0) {
//            multiOutletStates[i] = electronicUsingOrder[idx];
//            return true;
//        }
//    }
//    
//    return false;
//}
//
//int proceedElectronicOrder() {
//    int result = 0;
//    for(int i = 0; i < K; i++) {
//        if(isExist(electronicUsingOrder[i]))
//            continue;
//        
//        if(isEmpty(i))
//            continue;
//        
//        int changeIdx, val = -1;
//        for(int j = 0; j < N; j++) {
//            int comp = 0;
//            for(int k = i + 1; k < K && multiOutletStates[j] != electronicUsingOrder[k]; k++) {
//                comp++;
//            }
//            if(val < comp) {
//                changeIdx = j;
//                val = comp;
//            }
//        }
//        
//        multiOutletStates[changeIdx] = electronicUsingOrder[i];
//        result++;
//    }
//    
//    return result;
//}
//
//int main(void) {
//    cin >> N >> K;
//    
//    for(int i = 0; i < K; i++) {
//        cin >> electronicUsingOrder[i];
//    }
//    
//    cout << proceedElectronicOrder() << '\n';
//}
