//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//bool checkNumber(vector<string> v) {
//    sort(v.begin(), v.end());
//    for(int i = 0; i < (int)v.size() - 1; i++) {
//        if(v[i].length() < v[i + 1].length()) {
//            if(v[i + 1].substr(0, v[i].length()) == v[i])
//                return false;
//        }
//    }
//
//    return true;
//}
//
//int main(void) {
//    int t, n;
//    cin >> t;
//
//    while(t--) {
//        vector<string> v;
//        cin >> n;
//        for(int i = 0; i < n; i++) {
//            string number;
//            cin >> number;
//            v.push_back(number);
//        }
//
//        if(checkNumber(v))
//            cout << "YES\n";
//        else
//            cout << "NO\n";
//    }
//}
