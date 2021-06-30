//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> tree[11][11]; // 2차원까지는 지도를 나타내며, 3차원부터는 여러 그루의 나무가 있는 경우를 고려한다.
//int A[11][11] = {0, };
//int nutrient[11][11] = {0, };
//int deadTree[11][11] = {0, };
//pair<int, int> movement[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
//
//void checkTree(int N) {
//    // 봄
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++) {
//            if(!tree[i][j].empty())
//                sort(tree[i][j].begin(), tree[i][j].end());
//            
//            for(int k = 0; k < (int)tree[i][j].size(); k++) {
//                if(nutrient[i][j] < tree[i][j][k]) {
//                    deadTree[i][j] += (tree[i][j][k] / 2); // 양분을 미리 계산하여 추가
//                    tree[i][j].erase(tree[i][j].begin() + k); // 죽은 나무를 벡터에서 뽑는다.
//                    k -= 1;
//                }
//                else {
//                    nutrient[i][j] -= tree[i][j][k];
//                    tree[i][j][k] += 1;
//                }
//            }
//        }
//    }
//
//    //여름
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++) {
//            nutrient[i][j] += deadTree[i][j]; // 봄에 계산해놨던 양분을 다시 공급한다.
//            deadTree[i][j] = 0;
//        }
//    }
//
//    //가을 : 나무가 번식한다.
//    vector<int> temp[11][11];
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++) {
//            for(int k = 0; k < (int)tree[i][j].size(); k++) {
//                temp[i][j].push_back(tree[i][j][k]);
//            }
//        }
//    }
//
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++) {
//            for(int k = 0; k < (int)tree[i][j].size(); k++) {
//                if(tree[i][j][k] % 5 == 0) {
//                    for(int l = 0; l < 8; l++) {
//                        int nx = i + movement[l].first; // 문제점 movement[i]로 하고 있었다.
//                        int ny = j + movement[l].second;
//                        if(nx <= N && ny <= N && nx > 0 && ny > 0)
//                            temp[nx][ny].push_back(1);
//                    }
//                }
//            }
//        }
//    }
//
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++) {
//            tree[i][j].clear();
//            for(int k = 0; k < (int)temp[i][j].size(); k++) {
//                tree[i][j].push_back(temp[i][j][k]);
//            }
//        }
//    }
//
//    // 겨울 : 양분을 추가한다.
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++) {
//            nutrient[i][j] += A[i][j];
//        }
//    }
//}
//
//int main(void) {
//    int N, M, K;
//    int x, y, z;
//
//    cin >> N >> M >> K;
//
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++) {
//            cin >> A[i][j];
//            nutrient[i][j] = 5;
//        }
//    }
//
//    while(M--) {
//        cin >> x >> y >> z;
//        tree[x][y].push_back(z);
//    }
//    for(int i = 0; i < K; i++) {
//        checkTree(N);
//    }
//
//    int numberOfTree = 0;
//
//    for(int i = 1; i <= N; i++) {
//        for(int j = 1; j <= N; j++) {
//            numberOfTree += (int)tree[i][j].size();
//        }
//    }
//    
//    cout << numberOfTree << '\n';
//}
