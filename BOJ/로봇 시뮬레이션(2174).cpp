//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int A, B, N, M;
//char map[101][101];
//vector<pair<int, int>> robotLocation;
//char direction[] = {'N', 'W', 'S', 'E'};
//string ans;
//
//int mappingDirectionToIndex(char direction) {
//    switch (direction) {
//        case 'N':
//            return 0;
//            break;
//        case 'W':
//            return 1;
//            break;
//        case 'S':
//            return 2;
//            break;
//        case 'E':
//            return 3;
//            break;
//        default:
//            return -1;
//            break;
//    }
//}
//
//int findRobot(int x, int y) {
//    for(int i = 0; i < (int)robotLocation.size(); i++) {
//        pair<int, int> loc = robotLocation.at(i);
//        if(loc.first == x && loc.second == y) {
//            return i + 1;
//        }
//    }
//    
//    return -1;
//}
//
//void modifyRobotLocation(int x, int y, int robotNum) {
//    robotLocation[robotNum] = {x, y};
//}
//
//int moveRobot(char direction, int x, int y, int robotNum) {
//    switch (direction) {
//        case 'N':
//            if(y - 1 < 1)
//                return -1;
//            if(map[y - 1][x] != '.') {
//                return findRobot(x, y - 1);
//            }
//            map[y][x] = '.';
//            map[y - 1][x] = direction;
//            modifyRobotLocation(x, y - 1, robotNum);
//            break;
//        case 'S':
//            if(y + 1 > B)
//                return -1;
//            if(map[y + 1][x] != '.') {
//                return findRobot(x, y + 1);
//            }
//            map[y][x] = '.';
//            map[y + 1][x] = direction;
//            modifyRobotLocation(x, y + 1, robotNum);
//            break;
//        case 'W':
//            if(x - 1 < 1)
//                return -1;
//            if(map[y][x - 1] != '.')
//                return findRobot(x - 1, y);
//            map[y][x] = '.';
//            map[y][x - 1] = direction;
//            modifyRobotLocation(x - 1, y, robotNum);
//            break;
//        case 'E':
//            if(x + 1 > A)
//                return -1;
//            if(map[y][x + 1] != '.')
//                return findRobot(x + 1, y);
//            map[y][x] = '.';
//            map[y][x + 1] = direction;
//            modifyRobotLocation(x + 1, y, robotNum);
//            break;
//        default:
//            break;
//    }
//    
//    return 0;
//}
//
//int followOrders(int robotNum, char flag, int rep) {
//    pair<int, int> location = robotLocation.at(robotNum - 1);
//    int directionIndex = mappingDirectionToIndex(map[location.second][location.first]);
//    
//    if(flag == 'L') {
//        for(int i = 0; i < rep; i++) {
//            directionIndex = (directionIndex + 1) % 4;
//        }
//        map[location.second][location.first] = direction[directionIndex];
//    } else if(flag == 'R') {
//        for(int i = 0; i < rep; i++) {
//            directionIndex -= 1;
//            if(directionIndex < 0)
//                directionIndex = 3;
//        }
//        map[location.second][location.first] = direction[directionIndex];
//    } else if(flag == 'F') {
//        for(int i = 0; i < rep; i++) {
//            char direction = map[location.second][location.first];
//            int result = moveRobot(direction, location.first, location.second, robotNum - 1);
//            if(result == -1) {
//                ans = "Robot ";
//                ans += to_string(robotNum);
//                ans += " crashes into the wall\n";
//                return -1;
//            } else if(result > 0) {
//                ans = "Robot ";
//                ans += to_string(robotNum);
//                ans += " crashes into robot ";
//                ans += to_string(result);
//                ans += "\n";
//                return -1;
//            }
//            location = robotLocation.at(robotNum - 1);
//        }
//    }
//    
//    return 0;
//}
//
//int main(void) {
//    cin >> A >> B >> N >> M;
//    
//    for(int i = 1; i <= B; i++) {
//        fill(begin(map[i]), end(map[i]), '.');
//    }
//    
//    for(int i = 0; i < N; i++) {
//        int a, b;
//        char c;
//        
//        cin >> a >> b >> c;
//        
//        robotLocation.push_back({a, B - b + 1});
//        map[B - b + 1][a] = c;
//    }
//    
//    bool flag = false;
//    
//    for(int i = 0; i < M; i++) {
//        int a, b;
//        char c;
//        cin >> a >> c >> b;
//        
//        if(flag)
//            continue;
//        
//        int result = followOrders(a, c, b);
//        
//        if(result == -1)
//            flag = true;
//    }
//    
//    if(flag)
//        cout << ans;
//    else
//        cout << "OK\n";
//}
