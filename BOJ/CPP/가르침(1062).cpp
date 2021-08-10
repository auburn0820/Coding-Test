//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int N, K;
//vector<string> words;
//bool isLearnedAlphabet[26];
//int result;
//
//int checkCanReadWord() {
//    int cnt = 0;
//    
//    bool flag;
//    for(auto str : words) {
//        flag = true;
//        for(int i = 0; i < (int)str.length(); i++) {
//            int idx = str[i] - 'a';
//            if(!isLearnedAlphabet[idx]) {
//                flag = false;
//                break;
//            }
//        }
//        if(flag) {
//            cnt++;
//        }
//    }
//    
//    return cnt;
//}
//
//void combinationAlphabet(int idx, int cnt) {
//    if(cnt == K) {
//        result = max(result, checkCanReadWord());
//        return;
//    }
//    
//    for(int i = idx; i < 26; i++) {
//        if(!isLearnedAlphabet[i]) {
//            isLearnedAlphabet[i] = true;
//            combinationAlphabet(i, cnt + 1);
//            isLearnedAlphabet[i] = false;
//        }
//    }
//}
//
//int main(void) {
//    cin >> N >> K;
//    
//    isLearnedAlphabet['a' - 'a'] = true;
//    isLearnedAlphabet['c' - 'a'] = true;
//    isLearnedAlphabet['i' - 'a'] = true;
//    isLearnedAlphabet['n' - 'a'] = true;
//    isLearnedAlphabet['t' - 'a'] = true;
//    
//    for(int i = 0; i < N; i++) {
//        string str;
//        cin >> str;
//        words.push_back(str);
//    }
//    
//    if(K < 5) {
//        cout << 0 << '\n';
//        return 0;
//    }
//    
//    combinationAlphabet(0, 5);
//    
//    cout << result << '\n';
//}
