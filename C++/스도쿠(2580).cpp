//#include <iostream>
//using namespace std;
//
//int sudoku[9][9];
//bool square[9][9];
//bool Garo[9][9];
//bool Sero[9][9];
//bool exitFlag = false;
//
//void checkSudoku(int cnt) {
//    int y = cnt / 9;
//    int x = cnt % 9;
//
//    if(cnt == 81) {
//        cout << '\n';
//        for(int i = 0; i < 9; i++) {
//            for(int j = 0; j < 9; j++) {
//                cout << sudoku[i][j] << ' ';
//            }
//            cout << '\n';
//        }
//        exitFlag = true;
//        return;
//    }
//
//    if(sudoku[y][x] == 0) {
//        for(int i = 0; i < 9; i++) {
//            if(exitFlag)
//                return;
//            if(Garo[y][i] == false && Sero[x][i] == false && square[(y / 3) * 3 + (x / 3)][i] == false) {
//                Garo[y][i] = true;
//                Sero[x][i] = true;
//                square[(y / 3) * 3 + (x / 3)][i] = true;
//                sudoku[y][x] = i + 1;
//                checkSudoku(cnt + 1);
//                sudoku[y][x] = 0;
//                Garo[y][i] = false;
//                Sero[x][i] = false;
//                square[(y / 3) * 3 + (x / 3)][i] = false;
//            }
//        }
//    } else
//        checkSudoku(cnt + 1);
//}
//
//
//int main(void) {
//    for(int i = 0; i < 9; i++) {
//        for(int j = 0; j < 9; j++) {
//            cin >> sudoku[i][j];
//            if(sudoku[i][j] != 0) {
//                Garo[i][sudoku[i][j] - 1] = true;
//                Sero[j][sudoku[i][j] - 1] = true;
//                square[(i / 3) * 3 + (j / 3)][sudoku[i][j] - 1] = true;
//            }
//        }
//    }
//
//    checkSudoku(0);
//}
//
//// x와 y 값이 너무 헷갈린다.
