#include <string>
#include <vector>

using namespace std;

int find_element(vector<string> &cache, string element) {
    for(int i = 0; i < (int)cache.size(); i++) {
        if(cache[i] == element)
            return i;
    }
    return -1;
}

void to_lower(string &s) {
    for(int i = 0; i < (int)s.length(); i++) {
        s[i] = tolower(s[i]);
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    if(cacheSize == 0) {
        return 5 * (int)cities.size();
    }
    
    for(int i = 0; i < (int)cities.size(); i++) {
        to_lower(cities[i]);
        int idx = find_element(cache, cities[i]);
        
        if(idx == -1) {
            answer += 5;
            if(cache.size() < cacheSize) {
                cache.push_back(cities[i]);
            }
            else {
                for(int i = 0; i < (int)cache.size() - 1; i++) {
                    cache[i] = cache[i + 1];
                }
                cache[cache.size() - 1] = cities[i];
            }
        }
        else {
            answer += 1;
            cache.erase(cache.begin() + idx);
            cache.push_back(cities[i]);
        }
    }
    
    return answer;
}
