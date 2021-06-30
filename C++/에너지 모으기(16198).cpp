//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int N;
//int maxNum;
//int tempNum;
//vector<int> v;
//
//void check() {
//    if((int)v.size() == 2) {
//        maxNum = max(tempNum, maxNum);
//        return;
//    }
//    
//    for(int i = 1; i < (int)v.size() - 1; i++) {
//        int num = v[i];
//        tempNum += (v[i - 1] * v[i + 1]);
//        v.erase(v.begin() + i);
//        check();
//        v.insert(v.begin() + i, num);
//        tempNum -= (v[i - 1] * v[i + 1]);
//    }
//}
//
//int main(void) {
//    cin >> N;
//    
//    for(int i = 0; i < N; i++) {
//        int a;
//        cin >> a;
//        v.push_back(a);
//    }
//    
//    check();
//    
//    cout << maxNum << '\n';
//}
