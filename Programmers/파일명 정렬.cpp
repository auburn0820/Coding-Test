#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct File {
    string head, number, tail;
} File;

string to_lower(string str) {
    for(int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    
    return str;
}

File parsed_string(string &str) {
    File file;
    
    int idx = 0;
    int i;
    // get head;
    for(i = 0; i < str.size(); i++) {
        if(str[i] < '0' || str[i] > '9')
            idx++;
        else
            break;
    }
    
    string head = str.substr(0, idx);
    
    // get number
    int start_num_idx = idx;
    i = idx;
    idx = 0;
    for(; i < str.length(); i++) {
        if(str[i] >= '0' && str[i] <= '9')
            idx++;
        else
            break;
    }
    
    string number = str.substr(start_num_idx, idx);
    
    // get_tail
    string tail = str.substr(i, str.size() - i);
    
    file = {head, number, tail};
    
    return file;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> parsed_files;
    
    for(int i = 0; i < files.size(); i++) {
        parsed_files.push_back(parsed_string(files[i]));
    }
    
    stable_sort(parsed_files.begin(), parsed_files.end(), [](const File &a, const File &b) -> bool {
        if(to_lower(a.head) == to_lower(b.head)) {
            return stoi(a.number) < stoi(b.number);
        }
        return to_lower(a.head) < to_lower(b.head);
    });
    
    for(auto &i : parsed_files) {
        // cout << i.head << i.number << i.tail << '\n';
        answer.push_back(i.head + i.number + i.tail);
    }
    
    return answer;
}
