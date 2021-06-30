//#include <iostream>
////#include <algorithm>
//
//using namespace std;
//
//int N, M, X, Y, K;
//int maps[20][20];
//int dice[4][3] = {0, };
//
//bool rollDice(int direction) {
//    bool flag = true;
//    
//    if(direction == 1) {
//        X++;
//        if(X < 0 || X >= M) {
//            X--;
//            flag = false;
//            return flag;
//        }
//        swap(dice[1][0], dice[1][1]);
//        swap(dice[1][1], dice[3][1]);
//        swap(dice[1][1], dice[1][2]);
//    }
//    else if(direction == 2) {
//        X--;
//        if(X < 0 || X >= M) {
//            X++;
//            flag = false;
//            return flag;
//        }
//        swap(dice[1][2], dice[1][1]);
//        swap(dice[1][1], dice[3][1]);
//        swap(dice[1][0], dice[1][1]);
//        
//    }
//    else if(direction == 3) {
//        Y--;
//        if(Y < 0 || Y >= N) {
//            Y++;
//            flag = false;
//            return flag;
//        }
//        int temp = dice[3][1];
//        for(int i = 3; i >= 0; i--) {
//            dice[i][1] = dice[i - 1][1];
//        }
//        dice[0][1] = temp;
//    }
//    else if(direction == 4) {
//        Y++;
//        if(Y < 0 || Y >= N) {
//            Y--;
//            flag = false;
//            return flag;
//        }
//        int temp = dice[0][1];
//        for(int i = 0; i <= 3; i++) {
//            dice[i][1] = dice[i + 1][1];
//        }
//        dice[3][1] = temp;
//    }
//    
//    return flag;
//}
//
//int main(void) {
//    cin >> N >> M >> Y >> X >> K;
//    
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            cin >> maps[i][j];
//        }
//    }
//    
//    if(maps[Y][X] != 0) {
//        dice[1][1] = maps[Y][X];
//    }
//
//    int direction;
//
//    while(K--) {
//        cin >> direction;
//        if(rollDice(direction) == false) {
//            continue;
//        }
//        
//        if(maps[Y][X] == 0) {
//            maps[Y][X] = dice[1][1];
//        }
//        else {
//            dice[1][1] = maps[Y][X];
//            maps[Y][X] = 0;
//        }
//        
//        cout << dice[3][1] << '\n';
//    }
//}
