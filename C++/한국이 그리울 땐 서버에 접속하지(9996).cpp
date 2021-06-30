//#include <iostream>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//int main(void) {
////    int N;
////    string pattern;
////    cin >> N >> pattern;
////    vector<char> v;
////    bool exist[100];
////
////    for(int i = 0; i < (int)pattern.length(); i++) {
////        if(pattern[i] != '*')
////            v.push_back(pattern[i]);
////    }
////
////    while(N--) {
////        memset(exist, false, sizeof(exist));
////        string temp;
////        cin >> temp;
////
////        if(v.size() > temp.length())
////            cout << "NE\n"; continue;
////
////        for(int i = 0; i < (int)v.size(); i++) {
////            for(int j = 0; j < (int)temp.size(); j++) {
////                if(v[i] == temp[j]) {
////                    exist[i] = true;
////                    i++;
////                }
////                else
////                    continue;
////            }
////        }
////
////        for(int i = 0; i < (int)v.size(); i++) {
////            if(exist[i] == false)
////                cout << "NE\n";
////            else {
////                if(i == (int)v.size() - 1)
////                    cout << "DA\n";
////            }
////        }
////    }
//}
