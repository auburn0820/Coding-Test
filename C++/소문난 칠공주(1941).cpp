//#include <iostream>
//
//using namespace std;
//
//char classRoom[5][5];
//bool visit[1 << 25];
//int ans = 0;
//int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
//
//
//void DFS(int mateCnt, int dasomCnt, int checkAdj) {
//    if(mateCnt == 7) {
//        if(dasomCnt >= 4)
//            ans++;
//        return;
//    }
//    for(int i = 0; i < 25; i++) {
//        if((checkAdj & (1 << i)) == false)
//            continue;
//        
//        int x = i / 5;
//        int y = i % 5;
//        
//        for(int j = 0; j < 4; j++) {
//            int nextX = x + dx[j];
//            int nextY = y + dy[j];
//            
//            if(nextX < 5 && nextX >= 0 && nextY < 5 && nextY >= 0) {
//                int mapping = nextX * 5 + nextY;
//                
//                if(visit[checkAdj | (1 << mapping)])
//                    continue;
//                
//                visit[checkAdj | (1 << mapping)] = true;
//                
//                if(classRoom[nextX][nextY] == 'Y')
//                    DFS(mateCnt + 1, dasomCnt, checkAdj | (1 << mapping));
//                else
//                    DFS(mateCnt + 1, dasomCnt + 1, checkAdj | (1 << mapping));
//            }
//        }
//    }
//}
//
//int main(void) {
//    for(int i = 0; i < 5; i++)
//        cin >> classRoom[i];
//    
//    for(int i = 0; i < 5; i++) {
//        for(int j = 0; j < 5; j++) {
//            visit[1 << (i * 5 + j)] = true;
//            if(classRoom[i][j] == 'S')
//                DFS(1, 1, 1 << (i * 5 + j));
//            else
//                DFS(1, 0, 1 << (i * 5 + j));
//        }
//    }
//    
//    cout << ans << '\n';
//}
