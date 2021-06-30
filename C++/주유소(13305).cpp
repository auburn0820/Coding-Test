//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int dist[100001];
//int price[100001];
//
//int main(void) {
//    int N;
//    cin >> N;
//    
//    for(int i = 0; i < N - 1; i++) {
//        cin >> dist[i];
//    }
//    
//    for(int i = 0; i < N; i++) {
//        cin >> price[i];
//    }
//    
//    long long result = 0;
//    long long minPrice = price[0];
//    
//    for(int i = 0; i < N - 1; i++) {
//        if(minPrice > price[i])
//            minPrice = price[i];
//        
//        result += (minPrice * dist[i]);
//    }
//    
//    cout << result << '\n';
//}
