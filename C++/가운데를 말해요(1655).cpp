//#include <iostream>
//#include <functional>
//#include <queue>
//
//using namespace std;
//
//int main(void) {
//    
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    
//    int N;
//    cin >> N;
//    
//    priority_queue<int, vector<int>, less<int>> maxHeap;
//    priority_queue<int, vector<int>, greater<int>> minHeap;
//    
//    while(N--) {
//        int data;
//        cin >> data;
//        
//        if(maxHeap.empty())
//            maxHeap.push(data);
//        else if(maxHeap.size() == minHeap.size())
//            maxHeap.push(data);
//        else
//            minHeap.push(data);
//        
//        if(!minHeap.empty() && !maxHeap.empty()) {
//            if(minHeap.top() < maxHeap.top()) {
//                int tmp = maxHeap.top();
//                
//                maxHeap.pop();
//                maxHeap.push(minHeap.top());
//                minHeap.pop();
//                minHeap.push(tmp);
//            }
//        }
//        
//        cout << maxHeap.top() << '\n';
//    }
//}
