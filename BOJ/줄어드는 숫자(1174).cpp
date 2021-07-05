//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int main(void) {
//    int N;
//    cin >> N;
//
//    vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//    vector<long long> result;
//    for(int i = 1; i < 1024; i++) {
//        long long sum = 0;
//        for(int j = 0; j < 10; j++) {
//            if(i & (1 << j)) {
//                sum = sum * 10 + v[j];
//            }
//        }
//        result.push_back(sum);
//    }
//
////    sort(result.begin(), result.end());
//    
//    for(int i = 0; i < result.size(); i++)
//        cout << result[i] << '\n';
//
//    if(N > result.size())
//        cout << -1 << '\n';
//    else
//        cout << result[N - 1] << '\n';
//}
