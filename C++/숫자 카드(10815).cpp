//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int N, M;
//vector<int> cards;
//vector<int> cardsToFind;
//
//int binarySearch(int card, int n) {
//    int mid;
//    int minIdx = 0;
//    int maxIdx = n - 1;
//    
//    while(minIdx <= maxIdx) {
//        mid = (minIdx + maxIdx) / 2;
//        
//        if(card > cards[mid])
//            minIdx = mid + 1;
//        else if(card < cards[mid])
//            maxIdx = mid - 1;
//        else
//            return 1;
//    }
//    
//    return 0;
//}
//
//int main(void) {
//    cin >> N;
//    cards.resize(N);
//    
//    for(int i = 0; i < N; i++) {
//        cin >> cards[i];
//    }
//    
//    sort(cards.begin(), cards.end());
//    
//    cin >> M;
//    
//    cardsToFind.resize(M);
//    
//    for(int i = 0; i < M; i++) {
//        cin >> cardsToFind[i];
//    }
//    
//    for(auto &i : cardsToFind) {
//        cout << binarySearch(i, (int)cards.size()) << ' ';
//    }
//    cout << '\n';
//}
