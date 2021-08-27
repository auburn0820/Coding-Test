#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end(), [](int &a, int &b){
       return a < b;
    });
    
    sort(B.begin(), B.end(), [](int &a, int &b){
       return a > b;
    });
    
    int size = (int)A.size();
    for(int i = 0; i < size; i++) {
        answer += (A[i] * B[i]);
    }

    return answer;
}
