//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//#define INF 999999
//
//int maps[1001][1001] = {0, };
//bool visit[1001] = {false, };
//int d1[1001];
//int d2[1001];
//
//void Dijkstra(int *d, int N, int start) {
//    memset(visit, false, sizeof(visit));
//    for(int i = 1; i <= N; i++) {
//        d[i] = INF;
//    } // 거리 초기화
//    
//    d[start] = 0;
//    
//    int cnt = 0;
//    while(cnt != N) {
//        int v;
//        int min = INF;
//        
//        for(int j = 1; j <= N; j++) {
//            if(!visit[j] && min > d[j]) {
////                cout << d[j] << '\n';
//                min = d[j];
//                v = j;
//            }
//        }
//        
//        visit[v] = true;
//        cnt += 1;
//        
//        for(int j = 1; j <= N; j++) {
//            if(!visit[j] && maps[v][j]) {
//                if(d[j] > d[v] + maps[v][j]) {
//                    d[j] = d[v] + maps[v][j];
//                }
//            }
//        }
//    }
//}
//
//int main(void) {
//    int N, M, X;
//    cin >> N >> M >> X;
//    int start, end, cost;
//    
//    while(M--) {
//        cin >> start >> end >> cost;
//        maps[start][end] = cost;
//    }
//    
//    Dijkstra(d1, N, X);
//    
//    
//    for(int i = 1; i <= N; i++) {
//        for(int j = i + 1; j <= N; j++) {
//            int temp = maps[i][j];
//            maps[i][j] = maps[j][i];
//            maps[j][i] = temp;
//        }
//    }
//    
//    Dijkstra(d2, N, X);
//    
//    int max = -9999;
//    
//    
//    for(int i = 1; i <= N; i++) {
//        if(max < d1[i] + d2[i])
//            max = d1[i] + d2[i];
//    }
//
//    cout << max << '\n';
//}
