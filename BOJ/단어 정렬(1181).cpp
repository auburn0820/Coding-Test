//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//bool comp(const string str1, const string str2) {
//    if(str1.size() == str2.size())
//        return str1 < str2;
//    return str1.size() < str2.size();
//}
//
//int main(void) {
//    int N;
//    cin >> N;
//    
//    vector<string> v;
//    
//    while(N--) {
//        string str;
//        cin >> str;
//        
//        v.push_back(str);
//    }
//    
//    sort(v.begin(), v.end(), comp);
//    
//    v.erase(unique(v.begin(), v.end()), v.end());
//    
//    for(int i = 0; i < (int)v.size(); i++)
//        cout << v[i] << '\n';
//}
