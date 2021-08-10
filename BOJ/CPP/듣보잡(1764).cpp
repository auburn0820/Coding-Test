///*
// 
// */
//
//
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//
//std::vector<std::string> Heard;
//std::vector<std::string> Saw;
//std::vector<std::string> result;
//std::string doNotHeard;
//std::string doNotSaw;
//
//int main(void) {
//    int N, M;
//    std::cin >> N >> M;
//    
//    while(N--) {
//        std::cin >> doNotHeard;
//        Heard.push_back(doNotHeard);
//        doNotHeard.clear();
//    }
//    
//    sort(Heard.begin(), Heard.end());
//    
//    while(M--) {
//        std::cin >> doNotSaw;
//        Saw.push_back(doNotSaw);
//        doNotSaw.clear();
//    }
//    
//    sort(Saw.begin(), Saw.end());
//
//    std::set_intersection(Heard.begin(), Heard.end(), Saw.begin(), Saw.end(), back_inserter(result));
//    
//    std::cout << result.size() << '\n';
//    for(int i = 0; i < result.size(); i++) {
//        std::cout << result[i] << '\n';
//    }
//}
