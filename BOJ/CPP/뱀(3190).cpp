//#include <iostream>
//#include <deque>
//
//typedef struct {
//    int y, x;
//}direction;
//
//bool apple[101][101] = {false, };
//bool maps[101][101] = {false, };
//
//direction moveDirection[] = {{0 ,1}, {1, 0}, {0, -1}, {-1, 0}}; // R D L U
//
//int main(void) {
//    int N, K, L;
//    int X;
//    char C;
//    
//    std::deque<std::pair<int, char>> turnInfo;
//    std::deque<std::pair<int, int>> sneak;
//    
//    std::cin >> N >> K;
//    
//    while(K--) {
//        int row, col;
//        
//        std::cin >> col >> row;
//        
//        apple[col - 1][row - 1] = true;
//    }
//    std::cin >> L;
//    
//    while(L--) {
//        std::cin >> X >> C;
//        turnInfo.push_back(std::make_pair(X, C));
//    }
//    
//    int time = 0;
//    int index = 0;
//    
//    sneak.push_back(std::make_pair(0, 0));
//    maps[0][0] = true;
//    
//    
//    while(true) {
//        time += 1;
//        
//        std::pair<int, int> befroeLocation = sneak.back();
//        std::pair<int, int> currentLocation = std::make_pair(befroeLocation.first + moveDirection[index].y, befroeLocation.second + moveDirection[index].x);
//        
//        if(currentLocation.first >= N || currentLocation.second >= N || currentLocation.first < 0 || currentLocation.second < 0 || maps[currentLocation.first][currentLocation.second]) {
//            std::cout << time << '\n';
//            break;
//        }
//        
//        maps[currentLocation.first][currentLocation.second] = true;
//        sneak.push_back(std::make_pair(currentLocation.first, currentLocation.second));
//        
//        if(apple[currentLocation.first][currentLocation.second] == true) {
//            apple[currentLocation.first][currentLocation.second] = false;
//        } else {
//            std::pair<int, int> tail = sneak.front();
//            maps[tail.first][tail.second] = false;
//            sneak.pop_front();
//        }
//        
//        
//        if(turnInfo.front().first == time) {
//            if(turnInfo.front().second == 'L') {
//                index = (index + 3) % 4;
//            }
//            else {
//                index = (index + 1) % 4;
//            }
//            turnInfo.pop_front();
//        }
//    }
//}
