//#include <iostream>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//
//int N, M, K;
//bool laptop[40][40];
//bool sticker[100][40][40] = {false, };
//
//pair<int, int> checkStickerSize(bool arr[40][40]) {
//    int width = 0;
//    int height = 0;
//
//    for(int i = 0; i < 40; i++) {
//        for(int j = 0; j < 40; j++) {
//            if(arr[i][j]) {
//                width = max(width, j);
//                height = max(height, i);
//            }
//        }
//    }
//
//    return {width + 1, height + 1};
//}
//
//void printLapTop() {
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < M; j++) {
//            cout << laptop[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//}
//
//void addStickerToLapTop() {
//    for(int k = 0; k < K; k++) {
//        pair<int, int> sizeOfSticker = checkStickerSize(sticker[k]);
//        bool stickerCpy[sizeOfSticker.second][sizeOfSticker.first];
//
//        // 스티커 복사
//        for(int i = 0; i < sizeOfSticker.second; i++) {
//            for(int j = 0; j < sizeOfSticker.first; j++) {
//                stickerCpy[i][j] = sticker[k][i][j];
//            }
//        }
//
//        // 노트북 확인
//        int idx = 4;
//        while(idx--) {
//            bool flag = false; // 안됐을 때, 스티커 옮김용
//            bool successFlag = false; // 다음 스티커로 넘어갈 때용
//            bool laptopCpy[40][40];
//            memcpy(laptopCpy, laptop, sizeof(laptop));
//            for(int i = 0; i < N; i++) {
//                for(int j = 0; j < M; j++) {
//                    if(successFlag)
//                        break;
//                    // (i, j)에 스티커가 없을 경우, 전체 부분 확인
//                    if(!laptop[i][j]) {
//                        for(int a = i; a < i + sizeOfSticker.second; a++) {
//                            for (int b = j; b < j + sizeOfSticker.first; b++) {
//                                if(laptop[a][b]) {
//                                    flag = true;
//                                    break;
//                                }
//                                if(!laptop[a][b] && stickerCpy[a][b])
//                                    laptopCpy[a][b] = true;
//
//                                if(a + 1 == i + sizeOfSticker.second && b + 1 == j + sizeOfSticker.first) {
//                                    successFlag = true;
//                                    break;
//                                }
//                            }
//                            if(flag || successFlag)
//                                break;
//                        }
//                    }
//                }
//            }
//
//            if(successFlag) {
//                for(int i = 0; i < N; i++) {
//                    for(int j = 0; j < M; j++) {
//                        laptop[i][j] = laptopCpy[i][j];
//                    }
//                }
//                break;
//            }
//
//            if(flag) {
//                flag = false;
//                continue;
//            }
//        }
//        cout << '\n';
//        printLapTop();
//    }
//
//
//}
//
//int main(void) {
//    cin >> N >> M >> K;
//
//    for(int i = 0; i < K; i++) {
//        int R, C;
//        cin >> R >> C;
//        for(int j = 0; j < R; j++) {
//            for(int k = 0; k < C; k++) {
//                cin >> sticker[i][j][k];
//            }
//        }
//    }
//
//    addStickerToLapTop();
//}
