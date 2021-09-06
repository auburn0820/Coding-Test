#include <string>
#include <vector>
#include <stack>

using namespace std;

typedef struct Node {
    int number;
    bool removed;
    Node *prev, *next;
    
    Node(int number) {
        this->number = number;
        this->removed = false;
        this->prev = nullptr;
        this->next = nullptr;
    }
} Node;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');
    vector<Node*> nodes(n);
    stack<int> st;
    
    for(int i = 0; i < n; i++) {
        nodes[i] = new Node(i);
    }
    
    nodes[0]->next = nodes[1];
    nodes[n - 1]->prev = nodes[n - 2];
    
    for(int i = 1; i < n - 1; i++) {
        nodes[i]->next = nodes[i + 1];
        nodes[i]->prev = nodes[i - 1];
    }
    
    auto cur = nodes[k];
    for(int i = 0; i < cmd.size(); i++) {
        char ch = cmd[i][0];
        
        if(ch == 'U') {
            int num = stoi(cmd[i].substr(2));
            
            while(num--) {
                cur = cur->prev;
            }
        }
        else if(ch == 'D') {
            int num = stoi(cmd[i].substr(2));
            
            while(num--) {
                cur = cur->next;
            }
        }
        else if(ch == 'C') {
            st.push(cur->number);
            
            cur->removed = true;
            
            if(cur->prev != nullptr)
                cur->prev->next = cur->next;
            if(cur->next != nullptr)
                cur->next->prev = cur->prev;
            
            if(cur->next == nullptr)
                cur = cur->prev;
            else
                cur = cur->next;
                
        }
        else if(ch == 'Z') {
            int num = st.top();
            st.pop();
            
            nodes[num]->removed = false;
            
            if(nodes[num]->prev != nullptr)
                nodes[num]->prev->next = nodes[num];
            if(nodes[num]->next != nullptr)
                nodes[num]->next->prev = nodes[num];
        }
    }
    
    Node* start;
    
    for(int i = 0; i < n; i++) {
        if(nodes[i]->removed == false) {
            start = nodes[i];
            break;
        }
    }
    
    while(start != nullptr) {
        answer[start->number] = 'O';
        start = start->next;
    }
    
    return answer;
}
