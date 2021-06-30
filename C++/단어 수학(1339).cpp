//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//
//using namespace std;
//
//pair<int, int> alphabet[26] = {{0, 0}, };
//int mappedAlphabet[26] = {0, };
//
//bool cmp(pair<int, int> &a, pair<int, int> &b) {
//    return a.first > b.first;
//}
//
//int main(void) {
//    int N;
//    vector<string> v;
//    cin >> N;
//    
//    for(int i = 0; i < N; i++) {
//        string s;
//        cin >> s;
//        v.push_back(s);
//    }
//    
//    for(int i = 0; i < 26; i++) {
//        alphabet[i].second = i;
//    }
//    
//    for(int i = 0; i < (int)v.size(); i++) {
//        for(int j = 0; j < (int)v[i].length(); j++) {
//            alphabet[v[i][j] - 'A'].first += pow(10, ((int)v[i].length() - 1) - j);
//        }
//    }
//    
//    sort(begin(alphabet), end(alphabet), cmp);
//    
//    int cnt = 9;
//    int result = 0;
//    for(int i = 0; (i < 26 && alphabet[i].first != 0); i++) {
//        mappedAlphabet[alphabet[i].second] = cnt--;
//        result += alphabet[i].first * mappedAlphabet[alphabet[i].second];
//    }
//    
//    cout << result << '\n';
//}
