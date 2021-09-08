#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> st;

int get_doll_from_board(int loc, vector<vector<int>> &board) {
    int idx = 0;
    while(idx < board.size() && board[idx][loc] == 0) {
        idx++;
    }
    
    if(idx < board.size()) {
        int doll = board[idx][loc];
        board[idx][loc] = 0;
        return doll;
    }
    
    return 0;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    for(int i = 0; i < moves.size(); i++) {
        int doll = get_doll_from_board(moves[i] - 1, board);
        if(doll == 0)
            continue;
        
        if(st.empty()) {
            st.push(doll);
        }
        else if(!st.empty() && st.top() == doll) {
            answer += 2;
            st.pop();
        }
        else if(!st.empty() && st.top() != doll) {
            st.push(doll);
        }
    }
    
    return answer;
}
