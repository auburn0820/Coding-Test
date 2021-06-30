//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//int n;
//int dp[52];
//int arr[52][26];
//string str;
//string word[52];
//
//bool check(int alphabet[]) {
//    for(int i = 0; i < 26; i++)
//        if(alphabet[i])
//            return false;
//    return true;
//}
//
//int wordCost(int index) {
//    if(index == str.size()) return 0;
//    if(index > str.size()) return 9999;
//    int &returnValue = dp[index];
//    
//    if(returnValue != -1)
//        return returnValue;
//    
//    returnValue = 9999;
//    
//    for(int i = 0; i < n; i++){
//        int alphabet[26] = {};
//        int num = 0;
//        for(int j=0; j< (int)word[i].size(); j++){
//            alphabet[str[index + j]-'a'] += 1;
//            alphabet[word[i][j] - 'a'] -= 1;
//            if(str[index + j] != word[i][j])
//                num += 1;
//        }
//        if(check(alphabet))
//            returnValue = min(returnValue, num + wordCost(index + (int)word[i].size()));
//    }
//    
//    return returnValue;
//}
//
//int main(void) {
//    
//    cin >> str >> n;
//    
//    memset(dp, -1, sizeof(dp));
//    
//    for(int i = 0; i < n; i++) {
//        cin >> word[i];
//    }
//    
//    int returnValue = wordCost(0);
//    
//    if(returnValue == 9999)
//        cout << -1 << '\n';
//    else
//        cout << returnValue << '\n';
//}
