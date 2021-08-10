//#include <iostream>
//#include <vector>
//
//int numberOfFindString;
//std::vector<int> indexOfFindString;
//
//std::vector<int> getPi(std::string pattern) {
//    int j = 0;
//    std::vector<int> pi(pattern.size(), 0);
//
//    for(int i = 1; i < (int)pattern.size(); i++) {
//        while(j > 0 && pattern[j] != pattern[i])
//            j = pi[j - 1];
//        if(pattern[j] == pattern[i])
//            pi[i] = ++j;
//    }
//    return pi;
//}
//
//void kmp(std::string parent, std::string pattern) {
//    bool flag = false;
//    std::vector<int> table = getPi(pattern);
//    int parentSize = (int) parent.size();
//    int patternSize = (int) pattern.size();
//    int j = 0;
//
//    for(int i = 0; i < parentSize; i++) {
//        while(j > 0 && parent[i] != pattern[j]) {
//            j = table[j - 1];
//        }
//        if(parent[i] == pattern[j]) {
//            if(j == patternSize - 1) {
//                indexOfFindString.push_back(i - patternSize + 2);
//                numberOfFindString += 1;
//                flag = true;
//                j = table[j];
//            } else {
//                j++;
//            }
//        }
//    }
//
//    if(flag == false) {
//        numberOfFindString = 0;
//        std::cout << numberOfFindString << '\n';
//        return;
//    }
//
//    std::cout << numberOfFindString << '\n';
//    for(int i = 0; i < (int)indexOfFindString.size(); i++) {
//        std::cout << indexOfFindString[i] << ' ';
//    }
//    std::cout << '\n';
//}
//
//
//int main(void) {
//    std::string str;
//    std::string comp;
//
//    std::getline(std::cin, str);
//    std::getline(std::cin, comp);
//    kmp(str, comp);
//}
