//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//int arr[10001] = {0, };
//
//int main(void) {
//    int factory;
//    cin >> factory;
//
//    int totalMoney = 0;
//
//    for(int i = 0; i < factory; i++) {
//        cin >> arr[i];
//    }
//
//    for(int i = 0; i < factory; i++) {
//        if(arr[i + 1] > arr[i + 2]) {
//            int two = min(arr[i], arr[i + 1] - arr[i + 2]);
//            totalMoney += 5 * two;
//            arr[i] -= two;
//            arr[i + 1] -= two;
//
//            int three = min(arr[i], min(arr[i + 1], arr[i + 2]));
//            totalMoney += 7 * three;
//            arr[i] -= three;
//            arr[i + 1] -= three;
//            arr[i + 2] -= three;
//        }
//        else {
//            int three = min(arr[i], min(arr[i + 1], arr[i + 2]));
//            totalMoney += 7 * three;
//            arr[i] -= three;
//            arr[i + 1] -= three;
//            arr[i + 2] -= three;
//
//            int two = min(arr[i], arr[i + 1]);
//            totalMoney += 5 * two;
//            arr[i] -= two;
//            arr[i + 1] -= two;
//        }
//
//        totalMoney += 3 * arr[i];
//    }
//
//    cout << totalMoney << '\n';
//}
