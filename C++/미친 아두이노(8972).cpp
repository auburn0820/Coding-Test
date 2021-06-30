//#include <iostream>
//#include <cmath>
//#include <climits>
//#include <queue>
//#include <cstring>
//
//using namespace std;
//
//int R, C;
//char map[101][101];
//int numberOfArduino[101][101];
//queue<pair<int, int>> arduinoLoc;
//pair<int, int> curLoc;
//string str;
//int dx[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
//int dy[] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
//
//int getMinDistance(const int x1, const int y1, const int x2, const int y2) {
//    return abs(x1 - x2) + abs(y1 - y2);
//}
//
//void printMap() {
//    for(int i = 1; i <= R; i++) {
//        for(int j = 1; j <= C; j++) {
//            cout << map[i][j];
//        }
//        cout << '\n';
//    }
//}
//
//pair<int, int> getMinDistanceLoc(const int x, const int y) {
//    int minDistance = INT_MAX;
//    
//    pair<int, int> result;
//    
//    for(int i = 0; i < 9; i++) {
//        int arduinoNextX = x + dx[i];
//        int arduinoNextY = y + dy[i];
//        
//        if(arduinoNextX < 0 || arduinoNextY < 0 || arduinoNextX > C || arduinoNextY > R)
//            continue;
//        
//        int distance = getMinDistance(curLoc.first, curLoc.second, arduinoNextX, arduinoNextY);
//        
//        if(minDistance > distance) {
//            result = {arduinoNextX, arduinoNextY};
//            minDistance = distance;
//        }
//    }
//    
//    return result;
//}
//
//void playGame() {
//    int cnt = 0;
//    
//    for(int i = 0; i < (int)str.length(); i++) {
//        int curX = curLoc.first;
//        int curY = curLoc.second;
//        int nextX = curX + dx[str[i] - '1'];
//        int nextY = curY + dy[str[i] - '1'];
//        
//        cnt++;
//        
//        if(map[nextY][nextX] == 'R') {
//            cout << "kraj " << cnt << '\n';
//            return;
//        }
//        
//        map[curY][curX] = '.';
//        map[nextY][nextX] = 'I';
//        curLoc = {nextX, nextY};
//        
//        int size = (int)arduinoLoc.size();
//        
//        memset(numberOfArduino, 0, sizeof(numberOfArduino));
//        
//        while(size--) {
//            int arduinoCurX = arduinoLoc.front().first;
//            int arduinoCurY = arduinoLoc.front().second;
//            arduinoLoc.pop();
//            
//            pair<int, int> arduinoNextLoc = getMinDistanceLoc(arduinoCurX, arduinoCurY);
//            
//            if(map[arduinoNextLoc.second][arduinoNextLoc.first] == 'I') {
//                cout << "kraj " << cnt << '\n';
//                return;
//            }
//            numberOfArduino[arduinoNextLoc.second][arduinoNextLoc.first]++;
//            arduinoLoc.push({arduinoNextLoc.first, arduinoNextLoc.second});
//        }
//        size = (int)arduinoLoc.size();
//        for(int j = 1; j <= R; j++) {
//            fill(begin(map[j]), end(map[j]), '.');
//        }
//        map[curLoc.second][curLoc.first] = 'I';
//        
//        while(size--) {
//            int arduinoX = arduinoLoc.front().first;
//            int arduinoY = arduinoLoc.front().second;
//            arduinoLoc.pop();
//            
//            if(numberOfArduino[arduinoY][arduinoX] == 1) {
//                map[arduinoY][arduinoX] = 'R';
//                arduinoLoc.push({arduinoX, arduinoY});
//            } else
//                map[arduinoY][arduinoX] = '.';
//            
//        }
//    }
//    
//    printMap();
//}
//
//int main(void) {
//    cin >> R >> C;
//    
//    for(int i = 1; i <= R; i++) {
//        cin >> str;
//        for(int j = 1; j <= C; j++) {
//            map[i][j] = str[j - 1];
//            if(map[i][j] == 'I') {
//                curLoc = {j, i};
//            } else if(map[i][j] == 'R') {
//                arduinoLoc.push({j, i});
//                numberOfArduino[i][j] = 1;
//            }
//        }
//    }
//    
//    cin >> str;
//    
//    playGame();
//}
