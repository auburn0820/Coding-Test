#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

bool is_exist(string &word, map<string, int> &words) {
    map<string, int>::iterator it = words.find(word);
    
    if(it != words.end())
        return true;
    else
        return false;
}

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> words;
    
    for(int i = 0; i < 26; i++) {
        char alphabet = 'A' + i;
        string word = "";
        word += alphabet;
        words[word] = i + 1;
    }
    
    for(int i = 0; i < msg.size(); i++) {
        int size = 1;
        while(true) {
            string word_to_find = msg.substr(i, size);
            
            if(is_exist(word_to_find, words) && i + size <= msg.size()) {
                size++;
            }
            else {
                string key = msg.substr(i, size - 1);
                answer.push_back(words[key]);
                int number = words.size() + 1;
                words[word_to_find] = number;
                i = i + size - 2;
                break;
            }
        }
    }
    
    return answer;
}
