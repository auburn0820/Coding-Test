//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//int maps[50][4] = {0, };
//int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
//
//int draw(int r, int c) {
//    int n = std::max(abs(r), abs(c));
//    
//    int lastOfTonado = (n * 2 + 1) * (n * 2 + 1);
//    
//    
//    if(-n == r) {
//        return lastOfTonado - (4 * n) - (n + c);
//    }
//    else if(n == r) {
//        return lastOfTonado - (n - c);
//    }
//    else if(n == c) {
//        return lastOfTonado - (6 * n) - (n + r);
//    }
//    else { // 왼쪽 변수
//        return lastOfTonado - (2 * n) - (n - r);
//    }
//}
//
//int main(void) {
//    int r1, c1, r2, c2;
//    std::cin >> r1 >> c1 >> r2 >> c2;
//    int max = 0;
//    
//    for(int i = r1; i <= r2; i++) {
//        for(int j = c1; j <= c2; j++) {
//            if(draw(i, j) > max)
//                max = draw(i, j);
//        }
//    }
//    
//    std::string str = std::to_string(max);
//    std::string comp;
//    int size = (int)str.size();
//    int compSize;
//    
//    for(int i = r1; i <= r2; i++) {
//        for(int j = c1; j <= c2; j++) {
//            comp = std::to_string(draw(i, j));
//            compSize = (int)comp.size();
//            for(int k = 0; k < size - compSize; k++)
//                std::cout << ' ';
//            std::cout << draw(i, j) << ' ';
//        }
//        std::cout << '\n';
//    }
//    
//}
