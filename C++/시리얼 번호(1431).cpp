///*
// sort 함수에 대해 더 자세히 알게됐다. 조건을 넣어주는 게 가능한 것을 이 문제를 통해 알았다. 앞으로 STL을 더 자세히
// 알아보고 적용해보는 게 필요할 것 같다.
// */
//
//
//
//#include <iostream>
//#include <deque>
//#include <algorithm>
//
//std::string serialNumber;
//std::deque<std::string> dq;
//
//int sum(std::string str) {
//    
//    int result = 0;
//    
//    for(int i = 0; i < str.size(); i++) {
//        if(str[i] >= 48 && str[i] <= 57) {
//            result += (str[i] - 48);
//        }
//    }
//    
//    return result;
//}
//
//bool condition(std::string first, std::string second) {
//    if(first.size() == second.size()) {
//        int firstSize = sum(first);
//        int secondSize = sum(second);
//    
//        if(firstSize == secondSize) {
//            return first < second;
//        }
//        else {
//            return firstSize < secondSize;
//        }
//    }
//    else {
//        return first.size() < second.size();
//    }
//}
//
//
//int main(void) {
//    int t;
//    std::cin >> t;
//    
//    while(t--) {
//        std::cin >> serialNumber;
//        dq.push_back(serialNumber);
//        serialNumber.clear();
//    }
//    
//    sort(dq.begin(), dq.end(), condition);
//    
//    for(int i = 0; i < dq.size(); i++) {
//        std::cout << dq[i] << '\n';
//    }
//}
